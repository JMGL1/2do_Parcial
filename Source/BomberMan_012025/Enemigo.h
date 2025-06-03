// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemigo.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEnemigo : public ACharacter
{
	GENERATED_BODY()


public:
	/** Constructor por defecto de la clase AEnemigo. */
	AEnemigo();

	/** Componente de malla estática para la representación visual del enemigo. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MallaEnemigo")
	// VisibleAnywhere: Permite ver esta propiedad en el editor de Unreal, pero no modificarla directamente desde el panel de detalles.
	// BlueprintReadOnly: Permite que los Blueprints lean el valor de esta propiedad.
	// Category = "MallaEnemigo": Agrupa esta propiedad en la categoría "MallaEnemigo" en el editor para una mejor organización.
	UStaticMeshComponent* MallaEnemigo; // Puntero al componente de malla estática. Se inicializará en el constructor.
	// Sugerencia: Si este enemigo siempre usa una malla estática y no el SkeletalMeshComponent de ACharacter, considera heredar de APawn y añadir UFloatingPawnMovement si necesitas movimiento simple, o gestionar el movimiento manualmente. Si usas ACharacter, normalmente se usa su SkeletalMeshComponent (this->GetMesh()).

protected:
	/** Se llama cuando el juego comienza o cuando el actor es instanciado en el mundo. Ideal para lógica de inicialización. */
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

public: // Esta sección 'public' es redundante ya que la anterior también lo era. Se pueden agrupar.
	/** Almacena la dirección y magnitud del movimiento actual del enemigo. */
	FVector MovimientoActual;
	/** Acumula la distancia recorrida en la dirección de MovimientoActual. */
	float DistanciaRecorrida;
	/** Distancia máxima que el enemigo recorrerá en una dirección antes de intentar cambiarla. */
	const float DistanciaMaxima = 100.0f;

private:
	/** Calcula y establece una nueva dirección aleatoria para MovimientoActual. */
	void CambiarDireccion();

	bool DetectarObstaculo(FVector Direccion, float Distancia); // Modifiqué ligeramente la firma para que sea más clara (dirección y distancia en lugar de un destino absoluto).
	// Podrías también considerar usar el sistema de navegación de UE (NavMesh) para un movimiento más robusto si planeas niveles complejos.
};