#include "boss.h"

Boss::~Boss()
{
  	//delete[] this->name;
}

Boss::Boss(int health, int attackPower, 
				 int defense, const char* name)
{
	this->name=nullptr;
	this->setHealth(health);
	this->setMaxHealth(health);
	this->setAttackPower(attackPower);
	this->setDefense(defense);
	this->setName(name);
}
Boss::Boss()
{
	this->setHealth(0);
	this->setMaxHealth(0);
	this->setAttackPower(0);
	this->setDefense(0);
	this->name=nullptr;
}

void Boss::hit(Monster& other) 
{
	if (this->isAlive()) {
		if (this->getAttackPower()>other.getDefense()) 
		{
			other.setHealth(other.getHealth()+other.getDefense()-(this->getAttackPower()));
			hitPrint(other);
			if (other.isAlive()) {
				other.setHealth(other.getHealth()+other.getDefense()-(this->getAttackPower()));
				hitPrint(other);
			}
		}
		
		else
		{
			successfullBlock(other);
			other.setHealth(other.getHealth());
		}
	}
}

void Boss::enrage() 
{
    this->setAttackPower(this->getAttackPower()*4);
	cout << "ENRAGE" << endl;
}