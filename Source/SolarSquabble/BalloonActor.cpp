// Fill out your copyright notice in the Description page of Project Settings.


#include "BalloonActor.h"

// Sets default values
ABalloonActor::ABalloonActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create the Static Mesh Component
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;  // Set the Static Mesh Component as the Root Component
}

// Called when the game starts or when spawned
void ABalloonActor::BeginPlay()
{
	Super::BeginPlay();
	InitialPosition = GetActorLocation();
}

// Called every frame
void ABalloonActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewPosition = InitialPosition;
	NewPosition.Z += (FMath::Sin(GetWorld()->GetTimeSeconds() * HoverSpeed) * HoverHeight);
	SetActorLocation(NewPosition);
}

