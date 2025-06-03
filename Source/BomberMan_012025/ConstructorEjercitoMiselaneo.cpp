// Fill out your copyright notice in the Description page of Project Settings.

#include "ConstructorEjercitoMiselaneo.h"
#include "Ejercito.h"
#include "Engine/World.h"

AConstructorEjercitoMiselaneo::AConstructorEjercitoMiselaneo()
{
    PrimaryActorTick.bCanEverTick = false; // No requiere Tick
}

void AConstructorEjercitoMiselaneo::BeginPlay()
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

void AConstructorEjercitoMiselaneo::ConstruirComandante()
{
    if (Ejercito)
    {
        Ejercito->SetBatallon1(3);
    }
}

void AConstructorEjercitoMiselaneo::ConstruirPrimerEnemigo()
{
    if (Ejercito)
    {
        Ejercito->SetBatallon1(1);
    }
}

void AConstructorEjercitoMiselaneo::ConstruirSegundoEnemigo()
{
    if (Ejercito)
    {
        Ejercito->SetBatallon1(2);
    }
}

AEjercito* AConstructorEjercitoMiselaneo::GetEjercito()
{
    return Ejercito;
}

void AConstructorEjercitoMiselaneo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}