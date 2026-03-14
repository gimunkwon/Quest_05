#include "Quest_05/Public/MyActor.h"

#include <string>


AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Actormesh = CreateDefaultSubobject<UStaticMeshComponent>("ActorMesh");
}


void AMyActor::BeginPlay()
{
	
	
	Super::BeginPlay();
	SetActorLocation(FVector(0,50,0));
	FVector StartLocation = GetActorLocation();
	
	for (int32 i = 0; i < 10; i++)
	{
		FString CurrentActorLocation = GetActorLocation().ToString();
		FString CurrentActorRotation = GetActorRotation().ToString();
		
		moveActor();
		RotateActor();
		if (GEngine)
		{
			UE_LOG(LogTemp,Warning, TEXT("디버그 실행"));
			GEngine->AddOnScreenDebugMessage(i,10.f,FColor::Red, FString::Printf(TEXT("%d번째 이동,회전"),i+1));
			GEngine->AddOnScreenDebugMessage(i+10, 10.f, FColor::Green, CurrentActorLocation);
			GEngine->AddOnScreenDebugMessage(i+20, 10.f, FColor::Green, CurrentActorRotation);
			TriggerEvent();
		}
	}
	TotalDistance(StartLocation, GetActorLocation());
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AMyActor::moveActor()
{
	int32 RandomLocation = FMath::RandRange(10,30);
	ActorLocation = GetActorLocation();
	SetActorLocation(FVector(ActorLocation.X + RandomLocation, ActorLocation.Y + RandomLocation, ActorLocation.Z + RandomLocation));
}

void AMyActor::RotateActor()
{
	int32 RandomLocation = FMath::RandRange(10,30);
	ActorRotation = GetActorRotation();
	SetActorRotation(FRotator(ActorRotation.Yaw + RandomLocation, ActorRotation.Pitch + RandomLocation, ActorRotation.Roll + RandomLocation));
}

void AMyActor::TriggerEvent()
{
	UE_LOG(LogTemp,Warning,TEXT("트리거 함수 호출"));
	int32 RandomNum = FMath::RandRange(0,1);
	int32 RandomNum64 = FMath::RandRange(1000,10000);
	
	if (RandomNum == 0)
	{
		GEngine->AddOnScreenDebugMessage(RandomNum64,10.f,FColor::Cyan, FString::Printf(TEXT("당첨")));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(RandomNum64,10.f,FColor::Red, FString::Printf(TEXT("꽝!")));
	}
}

void AMyActor::TotalDistance(const FVector& Start, const FVector& End)
{
	float TotalDistance = FVector::Dist(Start,End);
	
	FString TotalDistanceStr = FString::Printf(TEXT("TotalDistance: %f"),TotalDistance);
	
	
	GEngine->AddOnScreenDebugMessage(2000, 10.f, FColor::Emerald,TotalDistanceStr);
}





