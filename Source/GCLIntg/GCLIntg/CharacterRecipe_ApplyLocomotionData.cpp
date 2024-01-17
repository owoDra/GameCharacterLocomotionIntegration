// Copyright (C) 2024 owoDra

#include "CharacterRecipe_ApplyLocomotionData.h"

#include "GCLIntgLogs.h"

#include "LocomotionComponent.h"
#include "LocomotionData.h"

#include "CharacterInitStateComponent.h"

#include "GameFramework/Character.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CharacterRecipe_ApplyLocomotionData)


UCharacterRecipe_ApplyLocomotionData::UCharacterRecipe_ApplyLocomotionData()
{
	InstancingPolicy = ECharacterRecipeInstancingPolicy::NonInstanced;
	NetExecutionPolicy = ECharacterRecipeNetExecutionPolicy::Both;
}

void UCharacterRecipe_ApplyLocomotionData::StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const
{
	if (auto* Character{ Cast<ACharacter>(Info.Pawn.Get()) })
	{
		if (auto* LC{ ULocomotionComponent::FindLocomotionComponent(Character) })
		{
			auto* LoadedLocomotionData
			{
				LocomotionData.IsNull() ? nullptr :
				LocomotionData.IsValid() ? LocomotionData.Get() : LocomotionData.LoadSynchronous()
			};

			UE_LOG(LogGCLI, Log, TEXT("++LocomotionData (Name: %s)"), *GetNameSafe(LoadedLocomotionData));

			LC->SetLocomotionData(LoadedLocomotionData);
		}
	}
}
