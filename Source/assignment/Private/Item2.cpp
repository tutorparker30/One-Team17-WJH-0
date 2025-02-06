#include "Item2.h"
#include "UObject/ConstructorHelpers.h"

AItem2::AItem2()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Wall_400x200.Wall_400x200"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Static Mesh not found! Check the path."));
	}

	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 300.0f;
	MaxRange = 2300.0f;
	Direction = 1.0f;
}

void AItem2::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AItem2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation.X += MoveSpeed * Direction * DeltaTime;

	if (CurrentLocation.X >= StartLocation.X + MaxRange)
	{
		CurrentLocation.X = StartLocation.X + MaxRange;
		Direction = -1; 
	}
	else if (CurrentLocation.X <= StartLocation.X - MaxRange)
	{
		CurrentLocation.X = StartLocation.X - MaxRange;
		Direction = 1; 
	}
	SetActorLocation(CurrentLocation);
}
