
#include "Rotating.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Materials/MaterialInstanceDynamic.h"

ARotating::ARotating()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComponent);


	RotationSpeed = FRotator(0.f, 45.f, 0.f);
	bUseSineScale = false;
	ScaleFrequency = 1.f;
	ScaleAmplitude = 0.2f;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Pipe_90.Shape_Pipe_90"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}
}

void ARotating::BeginPlay()
{
	Super::BeginPlay();

	InitialScale = GetActorScale3D();

	GetWorldTimerManager().SetTimer(
		ColorChangeTimerHandle,
		this,
		&ARotating::ChangeColor,
		5.f,
		false
	);

	GetWorldTimerManager().SetTimer(
		RepeatingColorChangeTimerHandle,
		this,
		&ARotating::ChangeColor,
		3.f,
		true
	);
}

void ARotating::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationSpeed * DeltaTime);

	if (bUseSineScale)
	{
		const float Time = GetWorld()->GetTimeSeconds();
		const float SineValue = FMath::Sin(Time * 2.f * PI * ScaleFrequency);
		const float ScaleFactor = 1.f + (ScaleAmplitude * SineValue);
		SetActorScale3D(InitialScale * ScaleFactor);
	}

}

void ARotating::ChangeColor()
{
	if (MeshComponent)
	{
		UMaterialInstanceDynamic* Dynmaterial = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
		if (Dynmaterial)
		{
			const FLinearColor RandomColor = FLinearColor::MakeRandomColor();
			Dynmaterial->SetVectorParameterValue(TEXT("Color"), RandomColor);
		}
	}
}
