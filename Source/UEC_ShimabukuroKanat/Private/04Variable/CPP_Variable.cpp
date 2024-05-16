// Fill out your copyright notice in the Description page of Project Settings.


#include "04Variable/CPP_Variable.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPP_Variable::ACPP_Variable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	default_str = TEXT("初期テキスト");
	disp_time = 99.0f;

	anywhere_str = default_str;

	defaults_only_str = default_str;
	instance_only_str = default_str;

}

// Called when the game starts or when spawned
void ACPP_Variable::BeginPlay()
{
	Super::BeginPlay();
	
	//UKismetSystemLibrary::PrintString(
	//	this,         // 表示するレベルのオブジェクト
	//	default_str,  // 表示する文字列
	//	true,         // 画面に表示するか否か
	//	true,         // ログに出力するか否か
	//	FColor::Cyan, // 表示する文字列の色
	//	disp_time,    // 表示する時間
	//	TEXT("None")  // "None"でないキーが指定された場合、メッセージは既存の画面上のメッセージを同じキーに置き換える
	//);

	UKismetSystemLibrary::PrintString(this, anywhere_str, true, true, FColor::Cyan, disp_time, TEXT("None"));

	UKismetSystemLibrary::PrintString(this, defaults_only_str, true, true, FColor::Cyan, disp_time, TEXT("None"));
	UKismetSystemLibrary::PrintString(this, instance_only_str, true, true, FColor::Cyan, disp_time, TEXT("None"));

}

// Called every frame
void ACPP_Variable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Variable::CallPublicFunc()
{
	// Viewportに配置したActorの表示名を取得
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintStringでActor表示名、メンバ関数、データメンバ表示
	UKismetSystemLibrary::PrintString(
		this,
		FString::Printf(TEXT("%s : CallPublicFunc %d"), *name, VarPublicNum),
		true,
		true,
		FColor::Cyan,
		10.f,
		TEXT("None")
	);
}

void ACPP_Variable::CallProtectedFunc()
{
	// Viewportに配置したActorの表示名を取得
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintStringでActor表示名、メンバ関数、データメンバ表示
	UKismetSystemLibrary::PrintString(
		this,
		FString::Printf(TEXT("%s : CallProtectedFunc %d"), *name, VarProtectedNum),
		true,
		true,
		FColor::Cyan,
		10.f,
		TEXT("None")
	);
}

void ACPP_Variable::CallPrivateFunc()
{
	// Viewportに配置したActorの表示名を取得
	FString name = UKismetSystemLibrary::GetDisplayName(this);

	// PrintStringでActor表示名、メンバ関数、データメンバ表示
	UKismetSystemLibrary::PrintString(
		this,
		FString::Printf(TEXT("%s : CallPrivateFunc %d"), *name, VarPrivateNum),
		true,
		true,
		FColor::Cyan,
		10.f,
		TEXT("None")
	);
}