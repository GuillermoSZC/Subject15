#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnumFireMode.h"
#include "ProjectileClass.h"
#include "PowerBaseComponent.generated.h"

class ASubject15Character;

UCLASS()
class SUBJECT16_API UPowerBaseComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    UPowerBaseComponent();

    UFUNCTION()
    virtual void FirePressed();

    UFUNCTION()
    virtual void FireReleased();

    UFUNCTION()
    virtual void ActivatePower();

    UFUNCTION()
    virtual void DeactivatePower();

    UFUNCTION()
    virtual void ExecutePower();

  protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EFireMode FireMode = EFireMode::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FireRate = 1.f;

    UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
    TSubclassOf<AProjectileClass> ProjectilePowerType;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FColor PowerColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    AActor *PowerVFX;

  private:
    FTimerHandle *FireTimerHandle = new FTimerHandle();

    ASubject15Character *Character;

    FTransform FirePointTransform;
    FRotator CameraPitchRotator;
};
