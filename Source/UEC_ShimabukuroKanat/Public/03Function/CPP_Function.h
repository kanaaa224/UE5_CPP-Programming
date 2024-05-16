// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Function.generated.h"

UCLASS()
class UEC_SHIMABUKUROKANAT_API ACPP_Function : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Function();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// [|]で文字を区切るとカテゴリの階層を分けられる
	UFUNCTION(BlueprintCallable, Category = "MyBlueprint|test")
	void TestPrintString(FString OutputString);

	// [Pure]化したメンバ関数は実行ピンがないノード
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static int Sum(const int A, const int B);

	// [DisplayName]はC++で宣言したメンバ関数名をBlueprintでは別名として表示
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Add", keywords = "A+B|足す"))
	static int Sum2(const int A, const int B);
};
