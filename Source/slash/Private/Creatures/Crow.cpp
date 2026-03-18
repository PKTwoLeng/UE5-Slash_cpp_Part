

#include "Creatures/Crow.h"
#include "Components/CapsuleComponent.h"

ACrow::ACrow()
{

	PrimaryActorTick.bCanEverTick = true;


	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);

}

void ACrow::BeginPlay()
{
	Super::BeginPlay();
	
}


void ACrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACrow::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

