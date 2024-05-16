// Fill out your copyright notice in the Description page of Project Settings.


#include "03Function/CPP_Function.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPP_Function::ACPP_Function()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Function::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Function::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Function::TestPrintString(FString OutputString)
{
	UKismetSystemLibrary::PrintString(this, OutputString, true, true, FColor::Cyan, 2.f, TEXT("None"));
}

int ACPP_Function::Sum(const int A, const int B)
{
	return (A + B);
}

int ACPP_Function::Sum2(const int A, const int B)
{
	return (A + B);
}