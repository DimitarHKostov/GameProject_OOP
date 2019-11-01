#include "Mage.h"

Mage::Mage()
{
    this->setBonusDamage(0);
    this->setHealth(0);
	this->setMaxHealth(0);
	this->setAttackPower(0);
	this->setDefense(0);
	this->name=nullptr;
}

Mage::Mage(int health, int attackPower, 
				 int defense, const char* name)
{
	this->setBonusDamage(1);
    this->name=nullptr;
	this->setHealth(health);
	this->setMaxHealth(health);
	this->setAttackPower(attackPower);
	this->setDefense(defense);
	this->setName(name);
	this->hasWeapon = false;
	this->hasShield = false;
}

void Mage::specialAbility()
{
   this->setBonusDamage(this->getBonusDamage()+1);
}

void Mage::specialAbilityEffect() const
{
    cout << this->getName() << " just activated special ability and dealt bonus " << this->getBonusDamage() << " fire damage." << endl;
}

void Mage::hit(Monster& other)
{
    if (isAlive()) {
		if (this->getAttackPower()>other.getDefense()) 
		{
			other.setHealth(other.getHealth()+other.getDefense()-(this->getAttackPower()+this->getBonusDamage()));
			this->specialAbilityEffect();
			this->specialAbility();
			this->hitPrint(other);

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

void Mage::setBonusDamage(int bonus)
{
	this->bonusDamage = bonus;
}

const int Mage::getBonusDamage() const
{
	return this->bonusDamage;
}

Mage::~Mage()
{
    //delete this->name;
}