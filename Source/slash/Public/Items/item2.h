// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"        //核心功能
#include "GameFramework/Actor.h"//方便继承actor类
#include "item2.generated.h"


class USphereComponent;

enum class EItemState : uint8
{
	EIS_Hovering,
	EIS_Equipped,
};

UCLASS()
class SLASH_API Aitem2 : public AActor
{
	GENERATED_BODY()     
	
public:	
	
	Aitem2();
	
	virtual void Tick(float DeltaTime) override;

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunningTime;


	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Sine Parameters")
	float Amplitude;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void SpawnPickupSystem();
	virtual void SpawnPickupSound();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;


	EItemState ItemState = EItemState::EIS_Hovering;
	
	UPROPERTY(EditAnywhere)
	class UNiagaraComponent* ItemEffect;

	UPROPERTY(EditAnywhere)
	USoundBase* PickupSound;

private:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* PickupEffect;



};

