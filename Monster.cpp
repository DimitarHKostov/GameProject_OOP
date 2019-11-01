#include "Monster.h"
#include <cstring>
#include <iostream>

using namespace std;

Monster::Monster()
{
	this->setHealth(0);
	this->setMaxHealth(0);
	this->setAttackPower(0);
	this->setDefense(0);
	this->name=nullptr;
}

Monster::Monster(int health, int attackPower, 
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

Monster::Monster(const Monster &m)
{
	this->name=nullptr;
	this->setHealth(m.getHealth());
	this->setMaxHealth(m.getHealth());
	this->setAttackPower(m.getAttackPower());
	this->setDefense(m.getDefense());
	this->setName(m.getName());
	this->setPoints(m.getPoints());
}

void Monster::setHealth(int health) 
{
	if (health<0)
	{
		health=0;
	}

	this->health=health;
}

void Monster::givePoint()
{
	this->point.pointIncrease();
}

void Monster::setMaxHealth(int health) 
{
	this->maxHealth=health;
}

const int Monster::getHealth() const
{
	return this->health;
}

const int Monster::getMaxHealth() const
{
	return this->maxHealth;
}

void Monster::resetHealth()
{
	this->health = this->maxHealth;
}

void Monster::setAttackPower(int attackPower)
{
	this->attackPower=attackPower;
}

const int Monster::getAttackPower() const
{
	return this->attackPower;
}

void Monster::setDefense(int defense)
{
	this->defense=defense;
}

const int Monster::getDefense() const
{
	return this->defense;
}

void Monster::setName(const char* name)
{
	if (this->name!=nullptr)
	{
		delete [] this->name;
	}
	this->name = new char[strlen(name)+1];

	strcpy(this->name, name);
}

const char* Monster::getName() const
{
	return this->name;	
}

Monster& Monster::operator=(const Monster& m)
{
	if (this != &m)
	{
		this->setHealth(m.getHealth());
		this->setDefense(m.getDefense());
		this->setAttackPower(m.getAttackPower());
		this->setName(m.getName());
		this->setMaxHealth(m.getMaxHealth());
		this->addWeapon(m.getWeapon());
		this->addShield(m.getShield());
		this->setPoints(m.getPoints());
		this->hasWeapon=m.hasWeapon;
		this->hasShield=m.hasShield;
	}
	return *this;
}

void Monster::hit(Monster& other)
{
	if (this->isAlive()) {
		if (this->getAttackPower()>other.getDefense()) 
		{
			other.setHealth(other.getHealth()+other.getDefense()-(this->getAttackPower()));
			hitPrint(other);
		}
		
		else if (this->getAttackPower()<other.getDefense())
		{
			successfullBlock(other);
			other.setHealth(other.getHealth());
		}
	}
}

Monster& Monster::fight(Monster& other)
{
	if (this!=&other)
	{
			while (this->getHealth()>0 && other.getHealth()>0)
			{
				this->hit(other);
				other.hit(*this);
			}
		cout << "winner ";
		if (this->getHealth()>0)
		{
			cout << this->getName() << endl;
		}
		else
		{
			cout << other.getName() << endl;
		}
		
		return this->getHealth() > 0 ? *this : other;
	}
	else{
		cout << "sorry, a monster cant fight itself" << endl;
	}
	
}

bool Monster::isAlive()
{
	return this->getHealth()>0;
}

void Monster::enrage()
{
	this->setAttackPower(this->getAttackPower()*2);
	cout << "ENRAGE" << endl;
}

void Monster::hitPrint(const Monster& other) const
{
	cout << this->getName() << " hits " << other.getName() << " with " << this->getAttackPower() << " attack power and " <<other.getName() << " has "
	<< other.getHealth() << " health left." << endl;
}

void Monster::weaponGiven()
{
	this->hasWeapon = true;
}

void Monster::shieldGiven()
{
	this->hasShield = true;
}

bool Monster::hasW() const
{
	return this->hasWeapon;
}

bool Monster::hasS() const
{
	return this->hasShield;
}

void Monster::successfullBlock(const Monster& other) const
{
	cout << other.getName() << " successfully blocked the attack of " << this->getName() << " and lost 0 health." << endl;
}

void Monster::addWeapon(const Weapon& other)
{
	this->weapon=other;
}

void Monster::addShield(const Shield& other)
{
	this->shield=other;
}

void Monster::addPotion(const Potion& other)
{
	this->potion=other;
}

const Weapon& Monster::getWeapon() const
{
	return this->weapon;
}

const Shield& Monster::getShield() const
{
	return this->shield;
}

const Potion& Monster::getPotion() const
{
	return this->potion;
}

void Monster::specialAbility()
{
	return;
}

void Monster::specialAbilityEffect() const
{
	return;
}

void Monster::setPoints(Point point)
{
	this->point=point;
}

const Point Monster::getPoints() const
{
	return this->point;
}

Monster::~Monster()
{
	delete [] this->name;
}