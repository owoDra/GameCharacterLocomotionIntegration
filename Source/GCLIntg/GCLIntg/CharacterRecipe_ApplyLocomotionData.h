// Copyright (C) 2024 owoDra

#pragma once

#include "Recipe/CharacterRecipe.h"

#include "CharacterRecipe_ApplyLocomotionData.generated.h"

class ULocomotionData;


/**
 * Modifier class to apply locomotion data to Character
 */
UCLASS()
class UCharacterRecipe_ApplyLocomotionData final : public UCharacterRecipe
{
	GENERATED_BODY()
public:
	UCharacterRecipe_ApplyLocomotionData();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "ApplyLocomotionData")
	TSoftObjectPtr<ULocomotionData> LocomotionData{ nullptr };

protected:
	virtual void StartSetupNonInstanced_Implementation(FCharacterRecipePawnInfo Info) const override;

};
