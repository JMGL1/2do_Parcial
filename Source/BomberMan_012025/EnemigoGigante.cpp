// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoGigante.h"
#include "UObject/ConstructorHelpers.h" // Para FObjectFinder, usado para localizar assets en el constructor.
#include "Engine/StaticMesh.h"          // Para UStaticMesh.
#include "Materials/Material.h"         // Para UMaterial.

// Sets default values
AEnemigoGigante::AEnemigoGigante()
{
	// Habilita Tick() para este actor. Si no se va a usar Tick() espec�ficamente en AEnemigoTerrestre
	// (y AEnemigo ya lo habilita), esta l�nea podr�a ser redundante, pero no es perjudicial.
	PrimaryActorTick.bCanEverTick = true;

	// MallaEnemigo es heredado de AEnemigo. AEnemigo ya lo crea en su constructor.
	// Aqu�, AEnemigoTerrestre est� personalizando los assets para esa malla.

	// Intenta cargar y asignar un material espec�fico para EnemigoTerrestre.
	// Nota: MallaEnemigo ya deber�a haber sido creado por el constructor de AEnemigo antes de que este c�digo se ejecute.
	if (MallaEnemigo) // Buena pr�ctica verificar que el puntero heredado es v�lido.
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBaseAsset(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_CobbleStone_Smooth.M_CobbleStone_Smooth'")); // Ruta al material.
		// Sugerencia: El nombre de la variable FObjectFinder (MaterialBaseAsset) es diferente al que usaste en AEnemigo (MaterialEnemigoAsset), lo cual est� bien.
		// Usar nombres consistentes o m�s descriptivos como 'MaterialTerrestreAsset' podr�a mejorar la legibilidad si tienes muchos.

		if (MaterialBaseAsset.Succeeded())
		{
			MallaEnemigo->SetMaterial(0, MaterialBaseAsset.Object); // Asigna el material de cromo al slot 0 de la malla.
			// Esto sobrescribir� el material establecido en el constructor de AEnemigo.
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AEnemigoTerrestre: No se pudo cargar MaterialBaseAsset (M_Metal_Chrome)."));
		}

		// Intenta cargar y asignar una malla est�tica espec�fica para EnemigoTerrestre.
		// Esto tambi�n sobrescribir� la malla establecida en el constructor de AEnemigo.
		// Es un poco inusual cambiar la malla est�tica de esta manera si la clase base ya asign� una,
		// pero es t�cnicamente posible. A menudo, se usar�an diferentes clases de enemigos para diferentes mallas
		// o se configurar�a a trav�s de propiedades TSubclassOf para mayor flexibilidad.
		static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaTerrestreAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")); // Ruta a la malla.
		// Nota: Esta es la misma malla que en AEnemigo. Si la intenci�n es usar la misma malla, esta secci�n es redundante
		// a menos que AEnemigo no siempre la asigne o quieras asegurarte.
		if (MallaTerrestreAsset.Succeeded())
		{
			MallaEnemigo->SetStaticMesh(MallaTerrestreAsset.Object); // Asigna el modelo a MallaEnemigo.
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AEnemigoTerrestre: No se pudo cargar MallaTerrestreAsset (Shape_QuadPyramid)."));
		}
	}
	else
	{
		// Esto no deber�a ocurrir si AEnemigo siempre crea MallaEnemigo.
		UE_LOG(LogTemp, Error, TEXT("AEnemigoTerrestre Constructor: MallaEnemigo es NULL. No fue creado en la clase base AEnemigo."));
	}
}

// Called when the game starts or when spawned
void AEnemigoGigante::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AEnemigoGigante::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

