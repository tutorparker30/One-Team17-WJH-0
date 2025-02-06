#include "Item4.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "UObject/ConstructorHelpers.h"

AItem4::AItem4()
{
	// Create the root component
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Create and attach the static mesh component
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_C.SM_Star_C"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Static Mesh not found! Check the path: /Game/Resources/Props/SM_Star_C.SM_Star_C"));
	}

	// Enable Tick
	PrimaryActorTick.bCanEverTick = true;

	// Default rotation speed
	RotationSpeed = 90.0f;
}

void AItem4::BeginPlay()
{
	Super::BeginPlay();

	// Set initial transform values
	SetActorLocation(FVector(9960.0f, 80.0f, 890.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(5.0f, 5.0f, 5.0f));
}

void AItem4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Apply rotation if the rotation speed is not zero
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}
