// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoGigante.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoGigante : public AEnemigo
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemigoGigante();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
