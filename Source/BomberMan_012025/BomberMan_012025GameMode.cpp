// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "ConstructorEjercitoTipo1.h"
#include "ConstructorEjercitoTipo2.h"
#include "ConstructorEjercitoTipo3.h"
#include "ConstructorEjercitoTipo4.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "IngenieroDeEjercitos.h"
#include "EnemigoAereo.h"


ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABomberMan_012025GameMode::BeginPlay()
{
    Super::BeginPlay();


    //Crerar el constructor del ejercito
    ConstructorEjercito = GetWorld()->SpawnActor<AConstructorEjercitoMiselaneo>(AConstructorEjercitoMiselaneo::StaticClass());
    ConstructorEjercito = GetWorld()->SpawnActor<AConstructorEjercitotipo2>(AConstructorEjercitotipo2::StaticClass());
    ConstructorEjercito = GetWorld()->SpawnActor<AConstructorEjercitotipo3>(AConstructorEjercitotipo3::StaticClass());
    ConstructorEjercito = GetWorld()->SpawnActor<AConstructorEjercitotipo4>(AConstructorEjercitotipo4::StaticClass());
    // Crear el ingeniero de ejercitos
    IngenieroEjercitos = GetWorld()->SpawnActor<AIngenieroDeEjercitos>(AIngenieroDeEjercitos::StaticClass());



    // Set the Builder for the Engineer and create the Army 
    IngenieroEjercitos->SetConstructorEjercito(ConstructorEjercito);
    IngenieroEjercitos->ConstruirEjercito();
    AEjercito* Ejercito = IngenieroEjercitos->GetEjercito();

}

void ABomberMan_012025GameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
