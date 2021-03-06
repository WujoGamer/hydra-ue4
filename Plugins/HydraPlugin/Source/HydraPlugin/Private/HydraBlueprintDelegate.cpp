#include "HydraPluginPrivatePCH.h"
#include "HydraBlueprintDelegate.h"

//Event forwarding to interface
void HydraBlueprintDelegate::HydraPluggedIn()
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraPluggedIn(_interfaceDelegate);
}
void HydraBlueprintDelegate::HydraUnplugged()
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraUnplugged(_interfaceDelegate);
}
void HydraBlueprintDelegate::HydraControllerEnabled(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraControllerEnabled(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraControllerDisabled(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraControllerDisabled(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraDocked(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraDocked(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraUndocked(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraUndocked(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraButtonPressed(int32 controller, HydraControllerButton button)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraButtonPressed(_interfaceDelegate, controllerForId(controller), button);
}
void HydraBlueprintDelegate::HydraButtonReleased(int32 controller, HydraControllerButton button)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraButtonReleased(_interfaceDelegate, controllerForId(controller), button);
}
void HydraBlueprintDelegate::HydraB1Pressed(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraB1Pressed(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraB1Released(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraB1Released(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraB2Pressed(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraB2Pressed(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraB2Released(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraB2Released(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraB3Pressed(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraB3Pressed(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraB3Released(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraB3Released(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraB4Pressed(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraB4Pressed(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraB4Released(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraB4Released(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraTriggerPressed(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraTriggerPressed(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraTriggerReleased(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraTriggerReleased(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraTriggerChanged(int32 controller, float value)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraTriggerChanged(_interfaceDelegate, controllerForId(controller), value);
}
void HydraBlueprintDelegate::HydraBumperPressed(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraBumperPressed(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraBumperReleased(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraBumperReleased(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraJoystickPressed(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraJoystickPressed(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraJoystickReleased(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraJoystickReleased(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraStartPressed(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraStartPressed(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraStartReleased(int32 controller)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraStartReleased(_interfaceDelegate, controllerForId(controller));
}
void HydraBlueprintDelegate::HydraJoystickMoved(int32 controller, FVector2D movement)
{
	if (implementsInterface())
		IHydraInterface::Execute_HydraJoystickMoved(_interfaceDelegate, controllerForId(controller), movement);
}
void HydraBlueprintDelegate::HydraControllerMoved(int32 controller,
	FVector position, FVector velocity, FVector acceleration,
	FRotator rotation, FRotator angularVelocity)
{
	if (implementsInterface()){
		IHydraInterface::Execute_HydraControllerMoved(_interfaceDelegate, controllerForId(controller), position, velocity, acceleration, rotation, angularVelocity);
	}
}

//Blueprint exposing the HydraDelegate Methods
//Override Callable Functions - Required to forward their implementations in order to compile, cannot skip implementation as we can for events.
bool HydraBlueprintDelegate::HydraIsAvailable()
{
	return HydraDelegate::HydraIsAvailable();
}

UHydraSingleController* HydraBlueprintDelegate::HydraGetHistoricalFrames(int32 controllerId, int32 historyIndex)
{
	sixenseControllerDataUE* dataUE = HydraDelegate::HydraGetHistoricalData(controllerId, historyIndex);

	UHydraSingleController* controller;
	controller = NewObject<UHydraSingleController>(UHydraSingleController::StaticClass());
	controller->setFromSixenseDataUE(dataUE);
	return controller;
}

UHydraSingleController* HydraBlueprintDelegate::HydraGetLatestFrame(int32 controllerId)
{
	return HydraGetHistoricalFrames(controllerId, 0);
}

bool HydraBlueprintDelegate::implementsInterface()
{
	return (_interfaceDelegate != NULL && _interfaceDelegate->GetClass()->ImplementsInterface(UHydraInterface::StaticClass()));
}

//Setting
void HydraBlueprintDelegate::SetInterfaceDelegate(UObject* newDelegate)
{
	UE_LOG(LogClass, Log, TEXT("InterfaceDelegate passed: %s"), *newDelegate->GetName());

	//Use this format to support both blueprint and C++ form
	if (newDelegate->GetClass()->ImplementsInterface(UHydraInterface::StaticClass()))
	{
		_interfaceDelegate = newDelegate;
	}
	else
	{
		//Try casting as self
		if (ValidSelfPointer->GetClass()->ImplementsInterface(UHydraInterface::StaticClass()))
		{
			_interfaceDelegate = (UObject*)this;
		}
		else
		{
			//If you're crashing its probably because of this setting causing an assert failure
			_interfaceDelegate = NULL;
			UE_LOG(LogClass, Log, TEXT("HydraBlueprintDelegate Warning: HydraInterface delegate is NULL, did your class implement HydraInterface? Events are disabled."));
		}

		//Either way post a warning, this will be a common error
		UE_LOG(LogClass, Log, TEXT("HydraBlueprintDelegate Warning: HydraInterface Delegate is NOT set, did your class implement HydraInterface? Events are disabled."));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("HydraBlueprintDelegate Warning: Delegate is NOT set, did your class implement HydraInterface? Events are disabled."));
	}
}

//Startup
void HydraBlueprintDelegate::HydraStartup()
{
	HydraDelegate::HydraStartup();

	UObject* validUObject = NULL;
	validUObject = Cast<UObject>(ValidSelfPointer);

	//Setup our Controller BP array
	for (int i = 0; i < MAX_CONTROLLERS_SUPPORTED; i++)
	{
		UHydraSingleController* controller;
		if (validUObject)
			controller = NewObject<UHydraSingleController>(validUObject, UHydraSingleController::StaticClass());
		else{
			UE_LOG(LogClass, Log, TEXT("This shouldn't be happening!"));
			controller = NULL;//NewObject<UHydraSingleController>(UHydraSingleController::StaticClass());	//no ownership
		}
		_latestFrame[i] = controller;
	}

	//Set self as interface delegate by default
	if (!_interfaceDelegate && validUObject)
		SetInterfaceDelegate(validUObject);
}

UHydraSingleController* HydraBlueprintDelegate::controllerForId(int controllerId)
{
	UHydraSingleController* controller = _latestFrame[controllerId];
	if (controller == NULL || !controller->IsValidLowLevel())
	{
		controller = NewObject<UHydraSingleController>(ValidSelfPointer, UHydraSingleController::StaticClass());
		_latestFrame[controllerId] = controller;
	}
	return controller;
}

void HydraBlueprintDelegate::HydraTick(float DeltaTime)
{
	HydraDelegate::HydraTick(DeltaTime);
}

void HydraBlueprintDelegate::UpdateControllerReference(sixenseControllerDataUE* controllerData, int index)
{
	UHydraSingleController* controller = _latestFrame[index];
	controller->setFromSixenseDataUE(controllerData);
	controller->controllerId = index;
}