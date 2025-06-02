// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ConstructorEjercito2.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConstructorEjercito2 : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN_012025_API IConstructorEjercito2
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    virtual void ConstruirComandante1() = 0;
    virtual void ConstruirPrimerEnemigo1() = 0;
    virtual void ConstruirSegundoEnemigo1() = 0;
    virtual class AEjercito* GetEjercito1() = 0;
};
