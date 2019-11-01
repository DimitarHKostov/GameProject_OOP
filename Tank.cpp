#include "Tank.h"

Tank::Tank()
{
    this->setHealth(0);
	this->setMaxHealth(0);
	this->setAttackPower(0);
	this->setDefense(0);
	this->name=nullptr;
    this->setBonusDefense(0);
}

Tank::Tank(int health, int attackPower, 
				 int defense, const char* name)
{
    this->name=nullptr;
	this->setHealth(health);
	this->setMaxHealth(health);
	this->setAttackPower(attackPower);
	this->setDefense(defense);
	this->setName(name);
	hasWeapon = false;
	hasShield = false;
    this->setBonusDefense(1);
}

Tank::~Tank()
{
   //delete [] this->name;
}

void Tank::specialAbility()
{	
	this->setDefense(this->getDefense()+this->getBonusDefense());
}

void Tank::specialAbilityEffect() const
{
    cout << this->getName() << " just activated special ability and gained " << this->getBonusDefense() << " bonus defense." << endl;
    cout << this->getName() << " current defense: " << this->getDefense() << endl;
}

void Tank::hit(Monster& other)
{
    if (isAlive()) {
		if (this->getAttackPower()>other.getDefense()) 
		{
			other.setHealth(other.getHealth()+other.getDefense()-(this->getAttackPower()));
			this->hitPrint(other);

			if (this->hasW()==true)
			{
				this->weapon.durabilityLower();
			}

			if(this->getDefense()<13)
			{
				this->specialAbility();
				this->specialAbilityEffect();
			}
		}
		
		else if (this->getAttackPower()<other.getDefense())
		{
			this->successfullBlock(other);
			other.setHealth(other.getHealth());
		}
	}
}

void Tank::setBonusDefense(int bonus)
{
    this->bonusDefense = bonus;
}

const int Tank::getBonusDefense() const
{
    return this->bonusDefense;
}