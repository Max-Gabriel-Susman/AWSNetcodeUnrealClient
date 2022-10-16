// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Http.h"
#include "UMGClientCPPGameMode.generated.h"

UCLASS(minimalapi)
class AUMGClientCPPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUMGClientCPPGameMode();

	virtual void StartPlay() override;

private:
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
};



