// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h" // Para GetWorld()
#include "Ejercito.h"
#include "Enemigo.h"
#include "EnemigoAereo.h"
#include "EnemigoTerrestre.h"
#include "EnemigoGigante.h"

// Sets default values
AEjercito::AEjercito()
{
    PrimaryActorTick.bCanEverTick = false; // No requiere Tick
}

// Método auxiliar: spawnea en función del tipo
void SpawnSegunTipo(int32 Tipo, UWorld* Mundo, const FVector& Posicion, TArray<AActor*>& Miembros)
{
    if (!Mundo) return;
    AActor* Nuevo = nullptr;
    switch (Tipo)
    {
    case 1:
        Nuevo = Mundo->SpawnActor<AEnemigoAereo>(AEnemigoAereo::StaticClass(), Posicion, FRotator::ZeroRotator);
        break;
    case 2:
        Nuevo = Mundo->SpawnActor<AEnemigoTerrestre>(AEnemigoTerrestre::StaticClass(), Posicion, FRotator::ZeroRotator);
        break;
    case 3:
        Nuevo = Mundo->SpawnActor<AEnemigoGigante>(AEnemigoGigante::StaticClass(), Posicion, FRotator::ZeroRotator);
        break;
    default:
        break;
    }
    if (Nuevo)
    {
        Miembros.Add(Nuevo);
    }
}

void AEjercito::BeginPlay()
{
    Super::BeginPlay();
}

void AEjercito::SetBatallon1(int32 tipo)
{
    if (!(tipo == 1 || tipo == 2 || tipo == 3))
    {
        UE_LOG(LogTemp, Error, TEXT("SetComandante: Tipo inválido %d"), tipo);
        return;
    }
    UWorld* Mundo = GetWorld();
    for (int32 i = 0; i < aBatallon1.Num(); i++)
    {
        for (int32 j = 0; j < aBatallon1[i].Num(); j++)
        {
                FVector Pos = FVector(XInicial + i * 10, YInicial + j * 10, ZInicial);
                SpawnSegunTipo(tipo, Mundo, Pos, MiembrosDelEjercito);
        }
    }
}

void AEjercito::Setbatallon2(int32 tipo)
{
    if (!(tipo == 1 || tipo == 2 || tipo == 3))
    {
        UE_LOG(LogTemp, Error, TEXT("SetPrimerEnemigo: Tipo inválido %d"), tipo);
        return;
    }
    UWorld* Mundo = GetWorld();
    for (int32 i = 0; i < aBatallon2.Num(); i++)
    {
        for (int32 j = 0; j < aBatallon2[i].Num(); j++)
        {
                FVector Pos = FVector(XInicial + i * 10, YInicial + j * 10, ZInicial);
                SpawnSegunTipo(tipo, Mundo, Pos, MiembrosDelEjercito);
        }
    }
}

void AEjercito::Setbatallon3(int32 tipo)
{
    if (!(tipo == 1 || tipo == 2 || tipo == 3))
    {
        UE_LOG(LogTemp, Error, TEXT("SetSegundoEnemigo: Tipo inválido %d"), tipo);
        return;
    }
    UWorld* Mundo = GetWorld();
    for (int32 i = 0; i < aBatallon3.Num(); i++)
    {
        for (int32 j = 0; j < aBatallon3[i].Num(); j++)
        {
                FVector Pos = FVector(XInicial + i * 10, YInicial + j * 10, ZInicial);
                SpawnSegunTipo(tipo, Mundo, Pos, MiembrosDelEjercito);
        }
    }
}

void AEjercito::Setbatallon4(int32 tipo)
{
    if (!(tipo == 1 || tipo == 2 || tipo == 3))
    {
        UE_LOG(LogTemp, Error, TEXT("SetSegundoEnemigo: Tipo inválido %d"), tipo);
        return;
    }
    UWorld* Mundo = GetWorld();
    for (int32 i = 0; i < aBatallon4.Num(); i++)
    {
        for (int32 j = 0; j < aBatallon4[i].Num(); j++)
        {
                FVector Pos = FVector(XInicial + i * 10, YInicial + j * 10, ZInicial);
                SpawnSegunTipo(tipo, Mundo, Pos, MiembrosDelEjercito);
        }
    }
}
// Called every frame
void AEjercito::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}







/*
void AConstructorMapaNivelUno::IniciarNuevoMapa()
{
	if (MapaEnConstruccion) {
		for (int32 i = 0; i < MapaEnConstruccion->aMapaBloques.Num(); i++)
		{
			for (int32 j = 0; j < MapaEnConstruccion->aMapaBloques[i].Num(); j++)
			{
				int32 BlockType = MapaEnConstruccion->aMapaBloques[i][j];
				if (BlockType != 0) {
					MapaEnConstruccion->aMapaBloques[i][j] = 0;
				}
			}
		}
	}
}
*/