// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedInputTest/CPP_EnhancedInputTest.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

class UInputMappingContext;

// Sets default values
ACPP_EnhancedInputTest::ACPP_EnhancedInputTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	// Input Actionを読み込み
	ActionInput = LoadObject<UInputAction>(NULL, TEXT("/Game/EnhancedInput/Input/Actions/IA_Action"), NULL, LOAD_None, NULL);
	AxisInput = LoadObject<UInputAction>(NULL, TEXT("/Game/EnhancedInput/Input/Actions/IA_Axis"), NULL, LOAD_None, NULL);

	// Input Mapping Contextを読み込み
	DefaultMappingContext = LoadObject<UInputMappingContext>(NULL, TEXT("/Game/EnhancedInput/Input/IMC_Default"), NULL, LOAD_None, NULL);
}

// Called when the game starts or when spawned
void ACPP_EnhancedInputTest::BeginPlay()
{
	Super::BeginPlay();
	
	// Input設定を行う
	SetupInput();
}

// Called every frame
//void ACPP_EnhancedInputTest::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void ACPP_EnhancedInputTest::SetupInput()
{
	// PlayerControllerを取得
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	// 入力を有効にする
	EnableInput(controller);

	if (InputComponent)
	{
		// Set up action bindings
		if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {

			// Input Action
			EnhancedInputComponent->BindAction(ActionInput, ETriggerEvent::Triggered, this, &ACPP_EnhancedInputTest::PressedAction);
			EnhancedInputComponent->BindAction(ActionInput, ETriggerEvent::Completed, this, &ACPP_EnhancedInputTest::ReleasedAction);

			// Input Axis
			EnhancedInputComponent->BindAction(AxisInput, ETriggerEvent::Triggered, this, &ACPP_EnhancedInputTest::PressedAxis);
		}

		// Input Mapping Contextを登録する
		if (APlayerController* PlayerController = Cast<APlayerController>(controller))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void ACPP_EnhancedInputTest::PressedAction()
{
	if (!IsPressed)
	{
		// Pressed
		UKismetSystemLibrary::PrintString(this, TEXT("Pressed"), true, true, FColor::Cyan, 10.0f, TEXT("None"));

		// Press状態に設定
		IsPressed = true;
	}
}

void ACPP_EnhancedInputTest::ReleasedAction()
{
	// Released
	UKismetSystemLibrary::PrintString(this, TEXT("Released"), true, true, FColor::Cyan, 10.0f, TEXT("None"));

	// Press状態を解除
	IsPressed = false;
}

void ACPP_EnhancedInputTest::PressedAxis(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D v = Value.Get<FVector2D>();

	// Axis Input Value
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("X: %f Y: %f"), v.X, v.Y), true, true, FColor::Cyan, 10.0f, TEXT("None"));
}

