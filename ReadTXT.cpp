 // Fill out your copyright notice in the Description page of Project Settings.


#include "ReadTXT.h"
#include <Runtime\Core\Public\Misc\FileHelper.h>
#include <Runtime\Core\Public\HAL\PlatformFilemanager.h>
#include <Runtime\Core\Public\HAL\FileManagerGeneric.h> 
#include "Containers/UnrealString.h"

FString UReadTXT::LoadFileToString(FString Filename)
{

	FString directory = FPaths::GameSourceDir();
	FString results;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + Filename;
		FFileHelper::LoadFileToString(results, *myFile);
	}

	return results;
}

TArray<FString> UReadTXT::LoadFileToArray(FString Filename)
{
	FString directory = FPaths::GameSourceDir();
	TArray<FString> results;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + Filename;
		
		FFileHelper::LoadFileToStringArray(results, *myFile);
	}

	return results;
}

TArray<FString> UReadTXT::GetTXTFromDir(FString Filename)
{

	// Init ouput
	TArray<FString> files;
	files.Empty();
	// to have the same number of index
	TArray<TArray<FString>> output;
	// point to source directory of the game
	FString Directory = FPaths::GameSourceDir();

	if (FPaths::DirectoryExists(Directory))
	{	// Init the path : source/[directory]/*.txt
		FString path = Directory + "*.txt";
		// search for every files with the .txt extention
		FFileManagerGeneric::Get().FindFiles(files, *path, true, false);

		// fill the list with empty list of strings
		TArray<FString> emptyList;
		output.Init({emptyList}, files.Num());


		for (int i = 0; i < files.Num(); i++)
		{
			// create the path for every files
			files[i] = Directory + files[i];
			//UE_LOG(LogTemp, Warning, TEXT("%s"), *output[i]);

		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Directory Not Found"));
	}

	
	return files;
	
	//return FilePathList;
}
