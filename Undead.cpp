#include "Undead.h"

Undead::Undead()
{
    this->setHealth(0);
	this->setMaxHealth(0);
	this->setAttackPower(0);
	this->setDefense(0);
	this->name=nullptr;
    this->secondLife=true;
}

Undead::Undead(int health, int attackPower, 
				 int defense, const char* name)
{
    this->name=nullptr;
	this->setHealth(health);
	this->setMaxHealth(health);
	this->setAttackPower(attackPower);
	this->setDefense(defense);
	this->setName(name);
	this->hasWeapon = false;
	this->hasShield = false;
    this->secondLife=true;
}

Undead::~Undead()
{
   //delete [] this->name;
}

void Undead::removeSecondLife()
{
    this->secondLife=false;
}

const bool Undead::getSecondLife() const
{
    return this->secondLife;
}

void Undead::specialAbility()
{
    this->setHealth(this->getMaxHealth()/2);
}

void Undead::specialAbilityEffect() const
{
    cout << this->getName() << " just activated special ability and revived with " << this->getHealth()/2 << " health." << endl;
	cout << this->getName() << " current health: " << this->getHealth() << endl;
}

void Undead::hit(Monster& other)
{
    if (isAlive()) {
		if (this->getAttackPower()>other.getDefense()) 
		{
			other.setHealth(other.getHealth()+other.getDefense()-(this->getAttackPower()));
			this->hitPrint(other);
		}

		if (this->hasW()==true)
			{
				this->weapon.durabilityLower();
			}
		
		else if (this->getAttackPower()<other.getDefense())
		{
			this->successfullBlock(other);
			other.setHealth(other.getHealth());
		}
	}

    else if(!isAlive() && this->getSecondLife()==true){
		this->removeSecondLife();
        if (this->getAttackPower()>other.getDefense()) 
		{
			other.setHealth(other.getHealth()+other.getDefense()-(this->getAttackPower()));
			this->hitPrint(other);
			this->specialAbility();
			this->specialAbilityEffect();
		}
		
		else if (this->getAttackPower()<other.getDefense())
		{
			this->successfullBlock(other);
			other.setHealth(other.getHealth());
		}
    }

	//Monster:hit(other);
}

