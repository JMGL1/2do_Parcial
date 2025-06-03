// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ejercito.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEjercito : public AActor
{
	GENERATED_BODY()

public:
	/** Constructor por defecto de la clase AEjercito. */
	AEjercito();

	void SetBatallon1(int32 TipoBatallon1);

	void Setbatallon2(int32 TipoBatallon2);

	void Setbatallon3(int32 TipoBatallon3);

	void Setbatallon4(int32 TipoBatallon4);

	UPROPERTY(VisibleAnywhere, Category = "Ejercito ??") // "Estado del Ejército";
		TArray<AActor*> MiembrosDelEjercito; // Cambié el nombre de la variable para mayor claridad en este contexto. Mantenemos el nombre original 'ElementosDelMapa' en el código si es un requisito estricto.

	TArray<TArray<int32>> aBatallon1 = {
{0, 0, 0, 0, 0, 0, 0, 3, 2, 1},
{0, 0, 0, 0, 0, 0, 0, 3, 2, 0},
{0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	TArray<TArray<int32>> aBatallon2 = {
{1, 2, 3, 0, 0, 0, 0, 0, 0, 0},
{1, 2, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	TArray<TArray<int32>> aBatallon3 = {
{2, 1, 3, 0, 0, 0, 0, 0, 0, 0},
{2, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};




	TArray<TArray<int32>> aBatallon4 = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 5, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
{0, 0, 0, 0, 0, 0, 0, 3, 2, 1}
	};

	// --- Coordenadas base para el despliegue del ejército ---
	// Estas definirán el origen o punto de anclaje del ejército en el mundo.
	// Las posiciones en 'aEjercito' se calcularán relativas a estas.
	UPROPERTY(EditAnywhere, Category = "Despliegue Ejercito")
	float XInicial = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Despliegue Ejercito")
	float YInicial = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Despliegue Ejercito")
	float ZInicial =0.0f;

	// Podrías añadir funciones para limpiar el mapa, etc.
	//void AnadirElemento(AActor* Elemento);
	//void MostrarResumenDelMapa(); // Similar a CaracteristicasDelAlojamiento

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};