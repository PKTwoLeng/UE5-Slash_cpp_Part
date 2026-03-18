#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "CharacterTypes.h"
#include "Interfaces/PickupInterface.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class Aitem2;
class ASoul;
class ATreasure;
class UAniMontage;
class USlashOverlay;

UCLASS()
class SLASH_API ASlashCharacter : public ABaseCharacter, public IPickupInterface
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump()override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	virtual void SetOverlappingItem(Aitem2* Item)override;
	virtual void AddSouls(ASoul* Soul)override;
	virtual void AddGolds(ATreasure* Treasure)override;
protected:
	virtual void BeginPlay() override;


	
	/*Callbacks for input*/
	void MoveForward(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void MoveRight(float Value);
	void EKeyPressed();
	virtual void Attack()override;
	void Dodge();
	bool HasStamina();
	bool IsOccupied();
	/**Combat*/
	void EquipWeapon(AWeapon* Weapon);
	virtual void AttackEnd()override;
	virtual void DodgeEnd()override;
	virtual bool CanAttack()override;
	void PlayEquipMontage(const FName& SectionName);
	virtual void Die()override;
	bool CanDisarm();
	bool CanArm();
	void Disarm();
	void Arm();



	UFUNCTION(BlueprintCallable)
	void AttachWeaponToBack();
	UFUNCTION(BlueprintCallable)
	void AttachWeaponToHand();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

	UFUNCTION(BlueprintCallable)
	void HitReactEnd();


private:
	void InitializeSlashOverlay();
	void SetHUDHealth();
	bool IsUnoccupied();
	/*Character Components */
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleInstanceOnly)
	Aitem2* OverlappingItem;
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* EquipMontage;
	UPROPERTY(VisibleAnywhere, Category = "Camera") // ºËÐÄÊÇÌí¼Ó BlueprintReadOnly
	UCameraComponent* ViewCamera;
	UPROPERTY(BlueprintReadWrite,meta=(AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY()
	USlashOverlay* SlashOverlay;

public:
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
};



