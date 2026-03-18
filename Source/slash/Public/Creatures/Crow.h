

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Crow.generated.h"



UCLASS()
class SLASH_API ACrow : public APawn
{
	GENERATED_BODY()

public:

	ACrow();

protected:

	virtual void BeginPlay() override;



public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




private:
	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* Capsule;
};
