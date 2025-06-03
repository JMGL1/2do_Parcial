// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "IngenieroDeEjercitos.h"
#include "ConstructorEjercitoMiselaneo.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberMan_012025GameMode.generated.h"

UCLASS(minimalapi)
class ABomberMan_012025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABomberMan_012025GameMode();
private:
	//The Builder Actor
	class AConstructorEjercitoMiselaneo* ConstructorEjercito;
	//The Engineer Actor
	class AIngenieroDeEjercitos* IngenieroEjercitos;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};



