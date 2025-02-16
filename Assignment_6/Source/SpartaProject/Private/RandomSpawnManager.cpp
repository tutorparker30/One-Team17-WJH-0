
#include "RandomSpawnManager.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Rotating.h"
#include "Move.h"

ARandomSpawnManager::ARandomSpawnManager()
{
    PrimaryActorTick.bCanEverTick = false;

    NumberOfActorsToSpawn = 5;
    SpawnRange = 1000.f;
    SpawnZ = 50.f;
}

void ARandomSpawnManager::BeginPlay()
{
    Super::BeginPlay();


    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    if (ActorClassesToSpawn.Num() == 0)
    {
       
        return;
    }

    TArray<FVector> SpawnLocations = GenerateGridSpawnLocations();
    if (SpawnLocations.Num() == 0)
    {
       
        return;
    }

    SpawnActors();
}

TArray<FVector> ARandomSpawnManager::GenerateGridSpawnLocations() const
{
    TArray<FVector> Locations;
    int32 GridCount = FMath::CeilToInt(FMath::Sqrt((float)NumberOfActorsToSpawn));
    float Step = (GridCount > 1) ? (2 * SpawnRange) / (GridCount - 1) : 0.0f;

    for (int32 Row = 0; Row < GridCount; Row++)
    {
        for (int32 Col = 0; Col < GridCount; Col++)
        {
            if (Locations.Num() >= NumberOfActorsToSpawn)
            {
                break;
            }
            float X = -SpawnRange + Col * Step;
            float Y = -SpawnRange + Row * Step;
            Locations.Add(FVector(X, Y, SpawnZ));
        }
    }

    return Locations;
}

void ARandomSpawnManager::SpawnActors()
{
    UWorld* World = GetWorld();
    if (!World) return;

    TArray<FVector> SpawnLocations = GenerateGridSpawnLocations();

    for (const FVector& SpawnLocation : SpawnLocations)
    {
        FRotator SpawnRotation(0.f, FMath::RandRange(0.f, 360.f), 0.f);
        int32 ClassIndex = FMath::RandRange(0, ActorClassesToSpawn.Num() - 1);
        TSubclassOf<AActor> ChosenClass = ActorClassesToSpawn[ClassIndex];

        if (!ChosenClass)
        {
            continue;
        }

        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        AActor* SpawnedActor = World->SpawnActor<AActor>(ChosenClass, SpawnLocation, SpawnRotation, SpawnParams);

        if (SpawnedActor)
        {
          
        }
        else
        {
            
        }
    }
}
