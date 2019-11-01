#include "Weapon.h"
#include <iostream>
#include <cstring>

using namespace std;

Weapon::Weapon()
{
    this->name=nullptr;
    this->setStrength(0);
    this->setDurability(0);
}

Weapon::Weapon(const char* name, int strength, int durability)
{
    this->name = nullptr;
    this->setName(name);
    this->setStrength(strength);
    this->setDurability(durability);
}

Weapon::Weapon(const Weapon& other)
{
    this->setName(other.getName());
    this->setDurability(other.getDurability());
    this->setStrength(other.getStrength());
}

Weapon& Weapon::operator=(const Weapon& other)
{
    if (this!=&other) {
        this->setName(other.getName());
        this->setStrength(other.getStrength());
        this->setDurability(other.getDurability());
    }
    return *this;
}

Weapon::~Weapon()
{
    //delete [] this->name;
}

void Weapon::setStrength(int strength)
{
    this->strength=strength;
}

const int Weapon::getStrength() const
{
    return this->strength;
}

void Weapon::durabilityLower()
{
    if (this->getDurability()>=1)
    {
        this->setDurability(this->getDurability()-1);
    }
    
}