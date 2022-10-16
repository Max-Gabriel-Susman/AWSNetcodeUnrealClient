// Copyright Epic Games, Inc. All Rights Reserved.

#include "UMGClientCPPGameMode.h"
#include "UMGClientCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUMGClientCPPGameMode::AUMGClientCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AUMGClientCPPGameMode::StartPlay()
{
	Super::StartPlay();
	/*
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();

	TSharedRef<FJsonObject> RequestObj = MakeShared<FJsonObject>();
	RequestObj->SetStringField("title", "foo");

	FString RequestBody;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
	FJsonSerializer::Serialize(RequestObj, Writer);

	Request->OnProcessRequestComplete().BindUObject(this, &AUMGClientCPPGameMode::OnResponseReceived);
	Request->SetURL("https://adafov3c7k.execute-api.us-east-1.amazonaws.com/default/provison-unreal-dedicated-server-lambda");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(RequestBody);
	Request->ProcessRequest();	
	*/
	// get logic
	// / *
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AUMGClientCPPGameMode::OnResponseReceived);
	Request->SetURL("https://jsonplaceholder.typicode.com/posts/1");
	Request->SetVerb("GET");
	Request->ProcessRequest();	
	// * /
}

void AUMGClientCPPGameMode::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Display, TEXT("Response %s"), *Response->GetContentAsString());
}
