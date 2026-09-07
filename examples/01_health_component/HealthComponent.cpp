#include "HealthComponent.h"
#include "GameFramework/Actor.h"

UHealthComponent::UHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    MaxHealth = 100.0f;
    CurrentHealth = MaxHealth;
    bIsDead = false;
}

void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    CurrentHealth = MaxHealth;
    bIsDead = false;
    AActor* Owner = GetOwner();
    if (Owner)
    {
        Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
    }
}

void UHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.0f || bIsDead) return;
    CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
    OnHealthChanged.Broadcast(this, CurrentHealth, -Damage);
    if (CurrentHealth <= 0.0f && !bIsDead)
    {
        bIsDead = true;
        OnDeath.Broadcast(DamagedActor);
    }
}

void UHealthComponent::Heal(float HealAmount)
{
    if (HealAmount <= 0.0f || bIsDead) return;
    float OldHealth = CurrentHealth;
    CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, 0.0f, MaxHealth);
    float Delta = CurrentHealth - OldHealth;
    if (Delta > 0.0f)
    {
        OnHealthChanged.Broadcast(this, CurrentHealth, Delta);
    }
}