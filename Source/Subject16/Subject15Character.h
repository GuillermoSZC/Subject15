#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"

#include "GameFramework/SpringArmComponent.h"

#include "Camera/CameraComponent.h"

#include "Materials/Material.h"

#include "Subject15Character.generated.h"

UCLASS()
class SUBJECT16_API ASubject15Character : public ACharacter
{
    GENERATED_BODY()

  public:
    ASubject15Character();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    USpringArmComponent *SpringArmCompCpp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UCameraComponent *CameraCompCpp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UStaticMeshComponent *PistolCompCpp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UArrowComponent *ArrowCompCpp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UMaterial *GunMaterialCpp;

  private:
    UMaterialInstanceDynamic *GunDynMaterialCpp;

  protected:
    virtual void BeginPlay() override;

    // Axes
    virtual void MoveVertical(float Amount);
    virtual void MoveHorizontal(float Amount);
    virtual void Pitch(float Amount);
    virtual void Yaw(float Amount);

    // Actions
    virtual void JumpStart();
    virtual void JumpStop();
    virtual void SlotOne();
    virtual void SlotTwo();

  public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
};
