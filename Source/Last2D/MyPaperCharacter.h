// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "MyPaperCharacter.generated.h"

class UPaperFlipbook;
class USpringArmComponent;
class UCameraComponent;
class UCharacterMovementComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
template <typename T> struct TObjectPtr;

//class FVector;
//class FVector2D;

/**
 * 
 */
UCLASS()
class LAST2D_API AMyPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	AMyPaperCharacter();


protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
public:

	virtual void Jump() override;
	virtual void StopJumping() override;

	void TurnRight();


	void Move(float Value);

	void Walk(const FInputActionValue& Value);

	//���� Input �̺�Ʈ
	void Attack(const FInputActionValue& Value);
	

	UFUNCTION()	void OnAttackFinished();

private:
	void UpdateCharacter();

	void UpdateAnimation();

private:
	// Movement state
	bool bIsAttacking;
	bool bIsJumping;
	FVector2D MovementInput;
	FVector LastVelocity;
	

private:

	// Flipbook Animations
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Walk;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Run;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_Attack01;


	//JumpStart
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_JumpStart;

	//JumpEnd
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbook> FB_Char_JumpEnd;


	// ī�޶�� Spring Arm Components ��  �߰���.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character Movement", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCharacterMovementComponent> Movement;
	
};
