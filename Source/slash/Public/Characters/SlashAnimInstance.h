#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Characters/SlashCharacter.h"
#include "CharacterTypes.h"
#include "SlashAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API USlashAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


	UPROPERTY(BlueprintReadOnly)
	class ASlashCharacter* SlashCharacter;

	UPROPERTY(BlueprintReadOnly,category=Movement)
	class UCharacterMovementComponent* SlashCharacterMovement;

	UPROPERTY(BlueprintReadOnly, category = Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, category = Movement)
	bool IsFalling;

	UPROPERTY(BlueprintReadOnly, category = Movement)
	ECharacterState CharacterState;

	UPROPERTY(BlueprintReadOnly, category = Movement)
	EActionState ActionState;
	UPROPERTY(BlueprintReadOnly, category = Movement)
	TEnumAsByte<EDeathPose> DeathPose;

};
