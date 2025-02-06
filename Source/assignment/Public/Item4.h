#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item4.generated.h"

UCLASS()
class ASSIGNMENT_API AItem4 : public AActor
{
	GENERATED_BODY()

public:
	AItem4();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item4|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item4|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item4|Properties")
	float RotationSpeed;
};
