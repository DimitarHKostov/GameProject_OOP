#include "Mutant.h"

Mutant::Mutant()
{
    this->setHealth(0);
	this->setMaxHealth(0);
	this->setAttackPower(0);
	this->setDefense(0);
	this->name=nullptr;
    this->mutantSpecial = true;
}

Mutant::Mutant(int health, int attackPower, 
				 int defense, const char* name)
{
    this->mutantSpecial = true;
    this->name=nullptr;
	this->setHealth(health);
	this->setMaxHealth(health);
	this->setAttackPower(attackPower);
	this->setDefense(defense);
	this->setName(name);
	this->hasWeapon = false;
	this->hasShield = false;
}

Mutant::~Mutant()
{
   //delete [] this->name;
}

void Mutant::specialAbility()
{
    this->setAttackPower(this->getAttackPower()*2);
    this->setDefense(this->getDefense()/2);
}

void Mutant::specialAbilityEffect() const
{
    cout << this->getName() << " just mutated and his attack power gets twice as much but his armor decreases twice." << endl;
	cout << this->getName() << " current attack power: " << this->getAttackPower() << endl;
    cout << this->getName() << " current defense: " << this->getDefense() << endl;
}

bool Mutant::removeMutantSpecial()
{
    this->mutantSpecial=false;
}	

const bool Mutant::getMutantSpecial() const
{
    return this->mutantSpecial;
}

void Mutant::hit(Monster& other)
{
    if (this->isAlive()) {
		if (this->getAttackPower()>other.getDefense()) 
		{
			other.setHealth(other.getHealth()+other.getDefense()-(this->getAttackPower()));
			this->hitPrint(other);

			if (this->hasW()==true)
			{
				this->weapon.durabilityLower();
			}

            if (this->getHealth()<=this->getMaxHealth() && this->getMutantSpecial()==true)
            {
                this->specialAbility();
			    this->specialAbilityEffect();
                this->removeMutantSpecial();
            }
		}
		
		else if (this->getAttackPower()<other.getDefense())
		{
			this->successfullBlock(other);
			other.setHealth(other.getHealth());
		}
	}
}
