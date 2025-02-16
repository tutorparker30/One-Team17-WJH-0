
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rotating.generated.h"

UCLASS()
class SPARTAPROJECT_API ARotating : public AActor
{
	GENERATED_BODY()
	
public:	

	ARotating();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	FRotator RotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
	bool bUseSineScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
	float ScaleFrequency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
	float ScaleAmplitude;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scale|SinWave")
	FVector InitialScale;

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ChangeColor();

private:
	FTimerHandle ColorChangeTimerHandle;
	FTimerHandle  RepeatingColorChangeTimerHandle;

};
