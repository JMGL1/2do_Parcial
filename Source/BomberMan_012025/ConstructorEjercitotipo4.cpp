// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorEjercitotipo4.h"
#include "Ejercito.h"
#include "Engine/World.h"

AConstructorEjercitotipo4::AConstructorEjercitotipo4()
{
    PrimaryActorTick.bCanEverTick = false; // No requiere Tick
}

void AConstructorEjercitotipo4::BeginPlay()
{
    Super::BeginPlay();
    UWorld* Mundo = GetWorld();
    if (Mundo)
    {
        Ejercito = Mundo->SpawnActor<AEjercito>(AEjercito::StaticClass());
        if (Ejercito)
        {
            Ejercito->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("No se pudo crear AEjercito en ConstructorEjercitoMiselaneo."));
        }
    }
}

void AConstructorEjercitotipo4::ConstruirComandante1()
{
    if (Ejercito)
    {
        Ejercito->Setbatallon4(3);
    }
}

void AConstructorEjercitotipo4::ConstruirPrimerEnemigo1()
{
    if (Ejercito)
    {
        Ejercito->Setbatallon4(1);
    }
}

void AConstructorEjercitotipo4::ConstruirSegundoEnemigo1()
{
    if (Ejercito)
    {
        Ejercito->Setbatallon4(2);
    }
}

AEjercito* AConstructorEjercitotipo4::GetEjercito1()
{
    return Ejercito;
}

void AConstructorEjercitotipo4::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

