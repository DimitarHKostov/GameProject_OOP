#include "Potions.h"
#include <cstring>

Potion::Potion()
{
    this->name = nullptr;
    this->bonusHealth = 0;
    this->setDurability(0);
}

Potion::Potion(const char* name, int bonusHealth)
{
    this->name=nullptr;
    this->setName(name);
    this->setBonusHealth(bonusHealth);
    this->setDurability(0);
}

Potion::Potion(const Potion& other)
{
    this->setName(other.getName());
    this->setBonusHealth(other.getBonusHealth());
    this->setDurability(other.getDurability());
}

Potion& Potion::operator=(const Potion& other)
{
    if (this!=&other)
    {
        this->setName(other.getName());
        this->setBonusHealth(other.getBonusHealth());
        this->setDurability(other.getDurability());
    }
    return *this;
}

void Potion::setBonusHealth(int bonus)
{
    this->bonusHealth=bonus;
}

const int Potion::getBonusHealth() const
{
    return this->bonusHealth;
}

Potion::~Potion()
{

}