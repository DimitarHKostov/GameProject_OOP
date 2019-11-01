#include "Vampires.h"

Vampire::Vampire()
{
    this->setHealth(0);
	this->setMaxHealth(0);
	this->setAttackPower(0);
	this->setDefense(0);
	this->name=nullptr;
}

Vampire::Vampire(int health, int attackPower, 
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
}

Vampire::~Vampire()
{
   //delete [] this->name;
}

void Vampire::specialAbility()
{
	if(this->getHealth()<this->getMaxHealth())
	{
    	this->setHealth(this->getHealth()+this->getAttackPower()/2);
	}
}

void Vampire::specialAbilityEffect() const
{
    cout << this->getName() << " just activated special ability and restored " << this->getAttackPower()/2 << " health." << endl;
	cout << this->getName() << " current health: " << this->getHealth() << endl;
}

void Vampire::hit(Monster& other)
{
    if (isAlive()) {
		if (this->getAttackPower()>other.getDefense()) 
		{
			other.setHealth(other.getHealth()+other.getDefense()-(this->getAttackPower()));
			this->hitPrint(other);
			this->specialAbility();
			this->specialAbilityEffect();

			if (this->hasW()==true)
			{
				this->weapon.durabilityLower();
			}
		}
		
		else if (this->getAttackPower()<other.getDefense())
		{
			this->successfullBlock(other);
			other.setHealth(other.getHealth());
		}
	}
}


