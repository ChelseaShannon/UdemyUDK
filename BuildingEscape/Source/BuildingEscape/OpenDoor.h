// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"


#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
public:
	// Sets default values for this component's properties
	UOpenDoor();

	void OpenDoor();
	void CloseDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 75.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay=1.f;

	float LastDoorOpenTime;

	const AActor* ActorThatOpens; // Remember pawn inherits from actor
	AActor* Owner = GetOwner(); // Owning door

};
