
#include "TestActor.h"

ATestActor::ATestActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Written by CGW."));
}
