//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "Blueprint/UserWidget.h"
//#include "SelectCharacterWidget.generated.h"
//
///**
// * 
// */
//UCLASS()
//class LAST2D_API USelectCharacterWidget : public UUserWidget
//{
//	GENERATED_BODY()
//public:
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
//        TSubclassOf<AMyPaperCharacter_ZD> CharacterClass1;
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
//        TSubclassOf<AMyPaperCharacter_ZD> CharacterClass2;
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
//        TSubclassOf<AMyPaperCharacter_ZD> CharacterClass3;
//
//    UPROPERTY(meta = (BindWidget))
//        class UButton* Button_0;
//
//    UPROPERTY(meta = (BindWidget))
//        class UButton* Button_1;
//
//    UPROPERTY(meta = (BindWidget))
//        class UButton* Button_2;
//public:
//    virtual void NativeConstruct() override;
//
//    UFUNCTION(BlueprintCallable, Category = "Character")
//        void OnCharacter1Selected();
//
//    UFUNCTION(BlueprintCallable, Category = "Character")
//        void OnCharacter2Selected();
//
//    UFUNCTION(BlueprintCallable, Category = "Character")
//        void OnCharacter3Selected();
//
//};