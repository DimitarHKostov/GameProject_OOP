#include "betterTournament.h"
#include <iostream>
#include <algorithm>

using namespace std;

betterTournament::betterTournament()
{
    this->directEL=false;
    this->ava=false;
    this->mixed=false;
}

void betterTournament::addFighter(Monster& other)
{
    this->fighters.push_back(&other);
}

void betterTournament::addWeapon(const Weapon& other)
{
    weapons.push_back(other);
}

void betterTournament::addShield(const Shield& other)
{
    shields.push_back(other);
}

const int betterTournament::getNumOfWeapons() const
{
    return this->weapons.size();
}

const int betterTournament::getNumOfShields() const
{
    return this->shields.size();
}

const int betterTournament::getNumOfFighters() const
{
    return this->fighters.size();
}

bool betterTournament::directEliminations_Enabler()
{
    this->directEL=true;
}

bool betterTournament::avaEnabler()
{
    this->ava=true;
}

bool betterTournament::mixedFight_Enabler()
{
    this->mixed=true;
}

bool betterTournament::directEliminations_Disabler()
{
    this->directEL=false;
}

bool betterTournament::avaDisabler()
{
    this->ava=false;
}

bool betterTournament::mixedFight_Disabler()
{
    this->mixed=false;
}

const bool betterTournament::isDirectElEnabled() const
{
    return this->directEL;
}

const bool betterTournament::isAvaEnabled() const
{
    return this->ava;
}

const  bool betterTournament::isMixedFightEnabled() const
{
    return this->mixed;
}

void betterTournament::Random_Weapon_Alocator()
{
    if (this->getNumOfWeapons()<=this->getNumOfFighters())
    {
        random_shuffle(weapons.begin(), weapons.end());
        
        for (int i = 0; i < this->getNumOfWeapons(); i++)
        {
            this->fighters[i]->addWeapon(this->weapons[i]);
        }
    }
    else
    {
        while (this->getNumOfWeapons()>this->getNumOfFighters())
        {
            weapons.pop_back();
        }
        random_shuffle(weapons.begin(), weapons.end());
        for (int i = 0; i < this->getNumOfWeapons(); i++)
        {
            this->fighters[i]->addWeapon(this->weapons[i]);
        }
    }
}

void betterTournament::Random_Shield_Alocator()
{
    if (this->getNumOfShields()<=this->getNumOfFighters())
    {
        random_shuffle(shields.begin(), shields.end());
        for (int i = 0; i < this->getNumOfShields(); i++)
        {
            this->fighters[i]->addShield(this->shields[i]);
        }
    }
    else
    {
        while (this->getNumOfShields()>this->getNumOfFighters())
        {
            shields.pop_back();
        }
        random_shuffle(shields.begin(), shields.end());
        for (int i = 0; i < this->getNumOfShields(); i++)
        {
            this->fighters[i]->addShield(this->shields[i]);
        }
    }
}

void betterTournament::start_directEliminations()
{
    if (this->isDirectElEnabled()==true)
    {
        for (int i = 0; i < this->getNumOfFighters(); i++)
        {
            schema_directEliminations.addFighter(*this->fighters[i]);
        }

        schema_directEliminations.dirElDefinition();
    }
    else
    {
        cout << "sorry but this mode hasn`t been enabled yet" << endl;
    }
    
}

void betterTournament::start_allvsall()
{
    if (this->isAvaEnabled()==true)
    {
        for (int i = 0; i < this->getNumOfFighters(); i++)
        {
            schema_allvsall.addFighter(*this->fighters[i]);
        }
        
        schema_allvsall.allvsall_Definition();
    }
    else
    {
        cout << "sorry but this mode hasn`t been enabled yet" << endl;
    }
}

void betterTournament::start_mixedFight()
{
    if(this->isMixedFightEnabled()==true)
    {
        for (int i = 0; i < this->getNumOfFighters(); i++)
        {
            schema_mixed.addFighter(*this->fighters[i]);
        }
        schema_mixed.MixedFight_definition();
    }
    else
    {
        cout << "sorry but this mode hasn`t been enabled yet" << endl;
    }
    
}

void betterTournament::print() const
{
    for (int i = 0; i < this->getNumOfFighters(); i++)
    {
        cout << fighters[i]->getName() << " has " << fighters[i]->getWeapon().getName() << endl;
    }
    
}