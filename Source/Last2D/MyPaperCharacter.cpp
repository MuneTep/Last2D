// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaperCharacter.h"


#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"

#include "PaperFlipbookComponent.h"
#include "EnhancedInputComponent.h"

#include "MyPlayerController.h"



AMyPaperCharacter::AMyPaperCharacter()
{
	
    //ī�޶�, �������� ���۳�Ʈ�� �� ����
    // Spring Arm Component
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f;
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

    //�������� ��ġ �ʱ�ȭ
        // Configure character movement
    GetCharacterMovement()->GravityScale = 2.0f;
    GetCharacterMovement()->AirControl = 0.80f;
    GetCharacterMovement()->JumpZVelocity = 1000.f;
    GetCharacterMovement()->GroundFriction = 3.0f;
    GetCharacterMovement()->MaxWalkSpeed = 600.0f;
    GetCharacterMovement()->MaxFlySpeed = 600.0f;
    

    bIsAttacking = false;
    bIsJuming = false;

    PrimaryActorTick.bCanEverTick = true;
}



void AMyPaperCharacter::BeginPlay()
{
	Super::BeginPlay();

    bIsAttacking = false;    

    if (GetSprite() != nullptr)
    {
        GetSprite()->SetFlipbook(FB_Char_Idle);
        //GetSprite �̺�Ʈ �Լ� ���
        GetSprite()->OnFinishedPlaying.AddDynamic(this, &AMyPaperCharacter::OnAttackFinished);

        UE_LOG(LogTemp, Warning, TEXT("OnFinishedPlaying.AddDynamic"));
    }
}


void AMyPaperCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //�߰� �����ϸ� ��.
    UpdateCharacter();

}


void AMyPaperCharacter::Move(float Value)
{
    if (!bIsAttacking && bIsJuming == false)
    {
        //�ɸ��� ���� ��ȯ
        TurnRight(Value);

        APawn::AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
    }
}


void AMyPaperCharacter::TurnRight(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        float fYaw = 0;

        if (Value > 0)
        {
            fYaw = 0;
        }
        else if (Value < 0.0f)
        {
            fYaw = 180;            
        }        

        Controller->SetControlRotation(FRotator(0.0f, fYaw, 0.0f));
    }
}



void AMyPaperCharacter::Walk(const FInputActionValue& Value)
{
    UE_LOG(LogTemp, Warning, TEXT("Walk!"));
}


void AMyPaperCharacter::Jump()
{
    Super::Jump();

    bIsJuming = true;

    if (GetSprite())
    {
        GetSprite()->SetFlipbook(FB_Char_JumpStart);
        GetSprite()->SetLooping(false);
        GetSprite()->Play();
    }

    
}


void AMyPaperCharacter::StopJumping()
{
    if (GetSprite())
    {
        GetSprite()->SetFlipbook(FB_Char_JumpEnd);
        GetSprite()->SetLooping(false);
        GetSprite()->Play();
    }


    bIsJuming = false;
    UE_LOG(LogTemp, Warning, TEXT("StopJumping!"));

    Super::StopJumping();
}

void AMyPaperCharacter::Attack(const FInputActionValue& Value)
{
    // ���� ������ ���⿡ ����
    if (!bIsAttacking && bIsJuming == false)
    {
        bIsAttacking = true;
        GetSprite()->SetFlipbook(FB_Char_Attack01);
        GetSprite()->SetLooping(false);        
        GetSprite()->PlayFromStart();
    }
}


void AMyPaperCharacter::OnAttackFinished()
{
    UE_LOG(LogTemp, Warning, TEXT("OnAttackFinished!"));

    bIsAttacking = false;
    GetSprite()->SetLooping(true);
    GetSprite()->Play();
    UpdateAnimation();

}



void AMyPaperCharacter::UpdateCharacter()
{    
    UpdateAnimation();

}



void AMyPaperCharacter::UpdateAnimation()
{
    
    if (!bIsAttacking && bIsJuming == false)
    {
        const FVector PlayerVelocity = GetVelocity();
        const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();

        // Are we moving or standing still?
        UPaperFlipbook* DesiredAnimation = (PlayerSpeedSqr > 0.0f) ? FB_Char_Run : FB_Char_Idle;
        if (GetSprite()->GetFlipbook() != DesiredAnimation)
        {
            GetSprite()->SetFlipbook(DesiredAnimation);
        }

    }
    
}
