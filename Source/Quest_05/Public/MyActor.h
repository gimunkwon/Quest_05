#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class QUEST_05_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	AMyActor();
protected:
	virtual void BeginPlay() override;
protected:
	UPROPERTY(EditAnywhere,Category="Mesh")
	TObjectPtr<UStaticMeshComponent> Actormesh;
	
	void moveActor();
	void RotateActor();
	void TriggerEvent();
	void TotalDistance(const FVector& Start, const FVector& End);
public:
	virtual void Tick(float DeltaTime) override;
	
private:
	FVector ActorLocation;
	FRotator ActorRotation;
};
