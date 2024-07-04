//// Fill out your copyright notice in the Description page of Project Settings.
//
//
//#include "SelectCharacterWidget.h"
//#include "MyGameModeBase.h"
//#include "Kismet/GameplayStatics.h"
//#include "Components/Button.h"
//
//void USelectCharacterWidget::NativeConstruct()
//{
//    Super::NativeConstruct();
//
//    if (Button_0)
//    {
//        Button_0->OnClicked.AddDynamic(this, &UCharacterSelectWidget::OnCharacter1Selected);
//    }
//
//    if (Button_1)
//    {
//        Button_1->OnClicked.AddDynamic(this, &UCharacterSelectWidget::OnCharacter2Selected);
//    }
//
//    if (Button_2)
//    {
//        Button_2->OnClicked.AddDynamic(this, &UCharacterSelectWidget::OnCharacter3Selected);
//    }
//
//}
//
//void UCharacterSelectWidget::OnCharacter1Selected()
//{
//    AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
//    if (GameMode)
//    {
//        GameMode->SetPlayerCharacter(CharacterClass1);
//        UE_LOG(LogTemp, Warning, TEXT("CharacterClass1 �� ���õǾ����ϴ�."));
//    }
//}
//
//void UCharacterSelectWidget::OnCharacter2Selected()
//{
//    AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
//    if (GameMode)
//    {
//        GameMode->SetPlayerCharacter(CharacterClass2);
//
//        UE_LOG(LogTemp, Warning, TEXT("CharacterClass2 �� ���õǾ����ϴ�."));
//    }
//}
//
//void UCharacterSelectWidget::OnCharacter3Selected()
//{
//    AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
//    if (GameMode)
//    {
//        GameMode->SetPlayerCharacter(CharacterClass3);
//
//        UE_LOG(LogTemp, Warning, TEXT("CharacterClass3 �� ���õǾ����ϴ�."));
//    }
//}
