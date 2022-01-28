// Fill out your copyright notice in the Description page of Project Settings.

#include "../Subject15Character.h"
#include "PowerBaseComponent.h"

// Sets default values for this component's properties
UPowerBaseComponent::UPowerBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	//Get the owner
	//M_Owner = Cast<ASubject15Character>(GetOwner());
	
}


// Called when the game starts
void UPowerBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//PullTrigger();
}


void UPowerBaseComponent::PullTrigger()
{
	if (FireMode == EFireMode::Automatic)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("AutomaticFire Power!\n"));
		GetWorld()->GetTimerManager().SetTimer(*FireTimerHandle, this, &UPowerBaseComponent::FirePower, 1/FireRate, true, 0 );
	}

	else if (FireMode == EFireMode::Semiautomatic)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Semi Fire Power!\n"));
		FirePower();
	}

	else if (FireMode == EFireMode::Laser)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("LaserMode Power!\n"));
	}
	else if (FireMode == EFireMode::None)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("INVALID Fire Power!\n"));
	}
	else if (FireMode == EFireMode::Default)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Default Fire Power! SELECT A FIREMODE TYPE PLS\n"));
	}
}

void UPowerBaseComponent::ReleaseTrigger()
{
	GetWorld()->GetTimerManager().ClearTimer(*FireTimerHandle);
}

void UPowerBaseComponent::ActivatePower()
{
	
}

void UPowerBaseComponent::DeactivatePower() //Metodo que se llama cuando se cambia de poder, Setear parametros que se quieren desactivar
{
	ReleaseTrigger(); //Dejar de disparar
}

void UPowerBaseComponent::OnPowerChange()
{
	if (Cast<ASubject15Character>(GetOwner()))
	{
		Cast<ASubject15Character>(GetOwner())->SetGunDynMaterialCpp(PowerColor);
	}
}

void UPowerBaseComponent::FirePower()
{
	////SetUp the FirePoint and the Direction
	////FirePointTransform = M_Owner->ArrowCompCpp->GetRelativeTransform();
	//FirePointTransform = Cast<ASubject15Character>(GetOwner())->ArrowCompCpp->GetComponentTransform(); //Para coger la posicion en el mundo del CMP Arrow
	//*CameraPitchRotator = Cast<ASubject15Character>(GetOwner())->CameraCompCpp->GetComponentRotation();  //Rotacion en el mundo del CMP Camera
	//
	////FQuat auxQuaternion(FirePointTransform.GetRotation().X, CameraPitchRotator->Quaternion().Y, FirePointTransform.GetRotation().Z);
	//FQuat auxQuaternion = FirePointTransform.GetRotation(); //AuxQuat Para mirar forward de la camara
	//auxQuaternion.Y = CameraPitchRotator->Vector().Y;
	//	//CameraPitchRotator->Quaternion().Y;
	//	
	//FirePointTransform.SetRotation(auxQuaternion);


	////GetWorld()->SpawnActor<AProjectileClass>(ProjectilePowerType, FirePointTransform.GetLocation(), auxQuaternion.Rotator());

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Black, TEXT("LLEGO Fire Power!\n"));
	}

}

