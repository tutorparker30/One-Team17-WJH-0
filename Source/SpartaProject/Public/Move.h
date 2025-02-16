
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Move.generated.h"

UCLASS()
class SPARTAPROJECT_API AMove : public AActor
{
	GENERATED_BODY()
	
public:	
	AMove();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxRange;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	FVector StartLocation;

	
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	int32 MoveDirection;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};

