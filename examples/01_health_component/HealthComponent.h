#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnHealthChangedSignature, class UHealthComponent*, HealthComp, float, Health, float, HealthDelta);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeathSignature, AActor*, DeadActor);

UCLASS(ClassGroup=(Combat), meta=(BlueprintSpawnableComponent))
class YOURGAME_API UHealthComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UHealthComponent();
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnHealthChangedSignature OnHealthChanged;
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnDeathSignature OnDeath;
    UFUNCTION(BlueprintCallable, Category = "Health")
    void Heal(float HealAmount);
protected:
    virtual void BeginPlay() override;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (ClampMin = 1.0f))
    float MaxHealth = 100.0f;
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Health")
    float CurrentHealth;
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Health")
    bool bIsDead = false;
    UFUNCTION()
    void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};