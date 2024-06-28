// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPaperCharacter.h"
#include "Engine/LocalPlayer.h"

//���۳�Ʈ
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperFlipbookComponent.h"

//Input
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"


AMyPaperCharacter::AMyPaperCharacter()
{
    //ī�޶�, �������� ���۳�Ʈ�� �� ����
    // Spring Arm Component
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 500.0f;
    SpringArm->SetRelativeRotation(FRotator(-10.0f, -90.0f, 0.0f)); //Ⱦ��ũ�� ȭ�� 
    //SpringArm->SetWorldRotation(FRotator(0.0f, 0.0f, -90.0f));
    SpringArm->bDoCollisionTest = false;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritYaw = false;
    SpringArm->bInheritRoll = false;

    // Camera Component
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

    PrimaryActorTick.bCanEverTick = true;
    bIsAttacking = false;

}

void AMyPaperCharacter::BeginPlay()
{
    Super::BeginPlay();

    bIsAttacking = false;
    GetSprite()->SetFlipbook(FB_Char_Idle);

    //GetSprite �̺�Ʈ �Լ� ���
    GetSprite()->OnFinishedPlaying.AddDynamic(this, &AMyPaperCharacter::OnAttackFinished);
}


void AMyPaperCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //�߰� �����ϸ� ��.
    //UpdateAnimation();

}


void AMyPaperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(IA_Move.Get(), ETriggerEvent::Triggered, this, &AMyPaperCharacter::Move);
        EnhancedInputComponent->BindAction(IA_Attack.Get(), ETriggerEvent::Triggered, this, &AMyPaperCharacter::Attack);
    }

}


void AMyPaperCharacter::Move(const FInputActionValue& Value)
{
    FVector2D MovementVector = Value.Get<FVector2D>();
    AddMovementInput(FVector(MovementVector.X, 0.0f, 0.0f));

    UE_LOG(LogTemp, Warning, TEXT("EnhancedInputComponent"));
}

void AMyPaperCharacter::Attack(const FInputActionValue& Value)
{
    // ���� ������ ���⿡ ����
    if (!bIsAttacking)
    {
        bIsAttacking = true;
        GetSprite()->SetFlipbook(FB_Char_Attack01);
        GetSprite()->SetLooping(false);
        GetSprite()->PlayFromStart();

        UE_LOG(LogTemp, Warning, TEXT("Attack!"));
    }
}


void OnAttackFinished()
{

}




