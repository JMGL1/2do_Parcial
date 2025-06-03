// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ConstructorEjercito2.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstructorEjercitotipo3.generated.h"
class AEnemigoTerrestre; class AEnemigoAereo; class AEnemigoGigante;
UCLASS()
class BOMBERMAN_012025_API AConstructorEjercitotipo3 : public AActor, public IConstructorEjercito2
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstructorEjercitotipo3();

protected:

    UPROPERTY() // El producto que se está construyendo
        class AEjercito* Ejercito;


public:
    // Implementación de IConstructorMapa

    virtual void ConstruirComandante1() override;
    virtual void ConstruirPrimerEnemigo1() override;
    virtual void ConstruirSegundoEnemigo1() override;
    virtual class AEjercito* GetEjercito1() override;


    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override; // Podría llamar a IniciarNuevoMapa aquí si el builder se usa solo una vez.
};