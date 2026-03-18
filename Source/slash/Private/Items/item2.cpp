#include "Items/item2.h"
 // DrawDebugHelpers.h
#include "slash/DebugMacros.h"
#include "Components/SphereComponent.h"
#include "Interfaces/PickupInterface.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

Aitem2::Aitem2()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	Amplitude = 0.25f;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	ItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ItemMesh->SetupAttachment(GetRootComponent());
	SetRootComponent(ItemMesh);


	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(ItemMesh);

	ItemEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Embers"));
	ItemEffect->SetupAttachment(GetRootComponent());


}


void Aitem2::BeginPlay()
{
	Super::BeginPlay();

	
	UWorld* World = GetWorld();



	//DRAW_LINE(GetActorLocation(), FVector(0.f, 0.f, 0.f));
	//DRAW_SPHERE(GetActorLocation());
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &Aitem2::OnSphereOverlap);

}

void Aitem2::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface) {

		PickupInterface->SetOverlappingItem(this);


	}


}
void Aitem2::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		PickupInterface->SetOverlappingItem(nullptr);
	}
}

void Aitem2::SpawnPickupSound()
{
	if (PickupSound)
	{
		UGameplayStatics::SpawnSoundAtLocation(
			this,
			PickupSound,
			GetActorLocation()
		);
	}
}

void Aitem2::SpawnPickupSystem()
{
	if (PickupEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			this,
			PickupEffect,
			GetActorLocation()

		);
	}
}


void Aitem2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ItemState == EItemState::EIS_Hovering) {
		FVector Location = GetActorLocation();

		RunningTime += DeltaTime;

		float DeltaZ = Amplitude * FMath::Sin(RunningTime * 5.f);

		AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	}





}

