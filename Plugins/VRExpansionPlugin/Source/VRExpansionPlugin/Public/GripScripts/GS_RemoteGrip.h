#pragma once

#include "CoreMinimal.h"
#include "VRGripScriptBase.h"
#include "GameFramework/WorldSettings.h"
#include "GS_RemoteGrip.generated.h"


/**
* The default grip transform logic for the motion controllers
*/
UCLASS(NotBlueprintable, ClassGroup = (VRExpansionPlugin))
class VREXPANSIONPLUGIN_API UGS_RemoteGrip : public UVRGripScriptBase
{
	GENERATED_BODY()
public:

	UGS_RemoteGrip(const FObjectInitializer& ObjectInitializer);

	//virtual void BeginPlay_Implementation() override;
	virtual bool GetWorldTransform_Implementation(UGripMotionControllerComponent * GrippingController, float DeltaTime, FTransform & WorldTransform, const FTransform &ParentTransform, FBPActorGripInformation &Grip, AActor * actor, UPrimitiveComponent * root, bool bRootHasInterface, bool bActorHasInterface, bool bIsForTeleport) override;

	// The component to use for basing the grip off of instead of the motion controller
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GunSettings")
		TWeakObjectPtr<USceneComponent> CustomPivotComponent;

};
