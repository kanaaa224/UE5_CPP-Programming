// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Variable.generated.h"

UCLASS()
class UEC_SHIMABUKUROKANAT_API ACPP_Variable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Variable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	FString default_str;
	float disp_time;

	//UPROPERTY(EditAnywhere) // VisibleAnywhere にすると値は表示されるが、編集ができなくなる
	//FString anywhere_str;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Ref | String")
	FString anywhere_str;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ref | String")
	FString defaults_only_str;

	UPROPERTY(EditInstanceOnly, Category = "Ref | String")
	FString instance_only_str;

public:
	// 親クラスのメンバ関数
	UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint)
	void CallPublicFunc();

	// 親クラスのデータメンバ(Public)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	int VarPublicNum = 10;

protected:
	// 親クラスのメンバ関数(Protected)
	UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint) // UE内で触れてしまう
	void CallProtectedFunc();

	// 親クラスのデータメンバ(Protected)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default) // UE内で触れてしまう
	int VarProtectedNum = 20;

private:
	// 親クラスのメンバ関数(Private)
	//UFUNCTION(BlueprintCallable, Category = CPP_And_Blueprint)
	void CallPrivateFunc();

	// 親クラスのデータメンバ(Private)
	//UPROPERTY(EditAnywhere, Category = Default) // BlueprintReadWrite
	int VarPrivateNum = 30;
};
