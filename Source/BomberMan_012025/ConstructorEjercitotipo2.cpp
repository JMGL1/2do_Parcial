// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorEjercitotipo2.h"
#include "Ejercito.h"
#include "Engine/World.h"

AConstructorEjercitotipo2::AConstructorEjercitotipo2()
{
    PrimaryActorTick.bCanEverTick = false; // No requiere Tick
}

void AConstructorEjercitotipo2::BeginPlay()
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

void AConstructorEjercitotipo2::ConstruirComandante()
{
    if (Ejercito)
    {
        Ejercito->Setbatallon2(1);
    }
}

void AConstructorEjercitotipo2::ConstruirPrimerEnemigo()
{
    if (Ejercito)
    {
        Ejercito->Setbatallon2(2);
    }
}

void AConstructorEjercitotipo2::ConstruirSegundoEnemigo()
{
    if (Ejercito)
    {
        Ejercito->Setbatallon2(3);
    }
}

AEjercito* AConstructorEjercitotipo2::GetEjercito()
{
    return Ejercito;
}

void AConstructorEjercitotipo2::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
