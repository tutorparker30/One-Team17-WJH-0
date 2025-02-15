
#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

}
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Written by QWE."));
}


