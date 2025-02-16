#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomSpawnManager.generated.h"

UCLASS()
class SPARTAPROJECT_API ARandomSpawnManager : public AActor
{
    GENERATED_BODY()

public:
    ARandomSpawnManager();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    int32 NumberOfActorsToSpawn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    float SpawnRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    float SpawnZ;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    TArray<TSubclassOf<AActor>> ActorClassesToSpawn;

private:
    TArray<FVector> GenerateGridSpawnLocations() const;
    void SpawnActors();
};
