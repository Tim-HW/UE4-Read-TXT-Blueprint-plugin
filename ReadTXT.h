// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <Runtime\Core\Public\Misc\FileHelper.h>
#include "ReadTXT.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTHOUSEIMPORT_API UReadTXT : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable)
		static FString LoadFileToString(FString Filename);

		UFUNCTION(BlueprintCallable)
		static TArray<FString> LoadFileToArray(FString Filename);


		UFUNCTION(BlueprintCallable)
		static TArray<FString> GetTXTFromDir(FString Filename);
};
