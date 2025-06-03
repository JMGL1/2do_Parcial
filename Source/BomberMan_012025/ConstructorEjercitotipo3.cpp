// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorEjercitotipo3.h"
#include "Ejercito.h"
#include "Engine/World.h"

AConstructorEjercitotipo3::AConstructorEjercitotipo3()
{
    PrimaryActorTick.bCanEverTick = false; // No requiere Tick
}

void AConstructorEjercitotipo3::BeginPlay()
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

void AConstructorEjercitotipo3::ConstruirComandante1()
{
    if (Ejercito)
    {
        Ejercito->Setbatallon3(1);
    }
}

void AConstructorEjercitotipo3::ConstruirPrimerEnemigo1()
{
    if (Ejercito)
    {
        Ejercito->Setbatallon3(2);
    }
}

void AConstructorEjercitotipo3::ConstruirSegundoEnemigo1()
{
    if (Ejercito)
    {
        Ejercito->Setbatallon3(3);
    }
}

AEjercito* AConstructorEjercitotipo3::GetEjercito1()
{
    return Ejercito;
}

void AConstructorEjercitotipo3::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

