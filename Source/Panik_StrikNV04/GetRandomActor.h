

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GetRandomActor.generated.h"

/**
 * 
 */
UCLASS()
class PANIK_STRIKNV04_API UGetRandomActor : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Random")
	static TSubclassOf<AActor> GetRandomActor(const TMap<TSubclassOf<AActor>, float>& ActorMap)
	{
		const float RandomValue = FMath::FRandRange(0.f, 100.f);
		float CumulativePercent = 0.f;
#if WITH_EDITOR
		TSubclassOf<AActor> SelectedActor = nullptr;
		for (const auto& Element : ActorMap)
		{
			checkf(Element.Value >= 0, TEXT("Percentages must be positive when using Get Random Actor node!"));
			CumulativePercent += Element.Value;
			if (RandomValue <= CumulativePercent
				&& SelectedActor == nullptr)
			{
				SelectedActor = Element.Key;
			}
		}
		checkf(FMath::IsNearlyEqual(CumulativePercent, 100.f, UE_KINDA_SMALL_NUMBER), TEXT("Sum of the percentages must be 100 when using Get Random Actor node!"));
		return SelectedActor;
#else
		for (const auto& Element : ActorMap)
		{
			CumulativePercent += Element.Value;
			if (RandomValue <= CumulativePercent)
			{
				return Element.Key;
			}
		}
		return ActorMap.Array().Last().Key;
#endif
	}
};
