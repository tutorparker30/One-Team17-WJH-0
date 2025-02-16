#include "Move.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AMove::AMove()
{
	PrimaryActorTick.bCanEverTick = true;

	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SetRootComponent(MeshComponent);

	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Plane.Shape_Plane"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}


	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Power_Sphere.M_Power_Sphere"));
	if (MaterialAsset.Succeeded())
	{
		MeshComponent->SetMaterial(0, MaterialAsset.Object);
	}


	MoveSpeed = 200.0f;   
	MaxRange = 500.0f;    
	MoveDirection = 1;    
}

void AMove::BeginPlay()
{
	Super::BeginPlay();

	
	StartLocation = GetActorLocation();
}

void AMove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FVector CurrentLocation = GetActorLocation();

	
	float DistanceMoved = (CurrentLocation - StartLocation).X;

	
	if (FMath::Abs(DistanceMoved) >= MaxRange)
	{
		MoveDirection *= -1;
	}

	FVector NewLocation = CurrentLocation + FVector(MoveSpeed * MoveDirection * DeltaTime, 0.0f, 0.0f);
	SetActorLocation(NewLocation);
}
