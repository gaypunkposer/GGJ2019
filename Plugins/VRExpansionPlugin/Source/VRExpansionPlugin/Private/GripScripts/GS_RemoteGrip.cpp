// Fill out your copyright notice in the Description page of Project Settings.

#include "GripScripts/GS_RemoteGrip.h"
#include "VRGripInterface.h"
#include "GripMotionControllerComponent.h"

UGS_RemoteGrip::UGS_RemoteGrip(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
}

bool UGS_RemoteGrip::GetWorldTransform_Implementation
(
	UGripMotionControllerComponent* GrippingController, 
	float DeltaTime, FTransform & WorldTransform, 
	const FTransform &ParentTransform, 
	FBPActorGripInformation &Grip, 
	AActor * actor, 
	UPrimitiveComponent * root, 
	bool bRootHasInterface, 
	bool bActorHasInterface, 
	bool bIsForTeleport
) 
{
	if (CustomPivotComponent.IsValid())
	{
		return Super::GetWorldTransform_Implementation(GrippingController, DeltaTime, WorldTransform, CustomPivotComponent->GetComponentTransform(), Grip, actor, root, bRootHasInterface, bActorHasInterface, bIsForTeleport);
	}
	else
	{
		return Super::GetWorldTransform_Implementation(GrippingController, DeltaTime, WorldTransform, ParentTransform, Grip, actor, root, bRootHasInterface, bActorHasInterface, bIsForTeleport);
	}
}