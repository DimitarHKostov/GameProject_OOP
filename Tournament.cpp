#include "Tournament.h"

Tournament::Tournament()
{
	this->monsters=nullptr;
	this->weapons = nullptr;
	this->shields = nullptr;
	this->setNumofmonsters(0);
	this->setNumofweapons(0);
	this->setNumofshields(0);
}

void Tournament::addFighter(Monster& other)
{
	//тук ще оправя добавянето така, че да нямам толкова копиране,
	//като заделям всеки път масив с n+n/2-дължина, 
	//което ще доведе до заделяне на повече памет за сметка на бързина
	Monster** temp2 = new Monster*[this->numofmonsters+1];
	for(int i = 0; i < getNumofmonsters(); i++)
	{
		temp2[i] = this->monsters[i];
	}
	delete [] this->monsters;
	temp2[this->numofmonsters] = &other;
	this->monsters = temp2;
	this->numofmonsters++;
	//n+n/2
}

void Tournament::addWeapon(const Weapon& other)
{
	//както добавянето на войни ще бъде и това
	Weapon* temp = new Weapon[this->numofweapons+1];
	for (int i = 0; i < numofweapons; ++i)
	{
		temp[i] = this->weapons[i];
	}
	delete [] this->weapons;
	temp[this->numofweapons] = other;
	this->weapons = temp;
	this->numofweapons++;
}

void Tournament::addShield(const Shield& other)
{
	//аналогично на горните 2 функции
	Shield* temp = new Shield[this->numofshields+1];
	for (int i = 0; i < numofshields; ++i)
	{
		temp[i] = this->shields[i];
	}
	delete [] this->shields;
	temp[this->numofshields] = other;
	this->shields = temp;
	this->numofshields++;
}

void Tournament::setNumofmonsters(int numofmonsters)
{
	this->numofmonsters=numofmonsters;
}

void Tournament::setNumofweapons(int numofweapons)
{
	this->numofweapons=numofweapons;
}

void Tournament::setNumofshields(int numofshields)
{
	this->numofshields=numofshields;
}

const Monster** Tournament::getMonsters() const
{
	//return this->monsters;
}

const int Tournament::getNumofmonsters() const
{
	return this->numofmonsters;
}

int Tournament::getNumOfWeapons() const
{
	return this->numofweapons;
}

int Tournament::getNumOfShields() const
{
	return this->numofshields;
}

void Tournament::enableWeapons()
{
	// Все още не се раздават произволно, ще го оправя
	for(int i = 0; i < this->getNumOfWeapons(); i++)
	{
		this->monsters[i]->addWeapon(this->weapons[i]);
		this->monsters[i]->weaponGiven();
		this->monsters[i]->setAttackPower(this->monsters[i]->getAttackPower()+this->monsters[i]->getWeapon().getStrength());
	}

	for(int i = 0; i < getNumOfWeapons(); i++)
	{
		//cout << weapons[i].getDurability() << endl;
	}
}

void Tournament::enableShields()
{
	// щитовете също не се раздават произволно за сега
	for(int i = 0; i < this->getNumOfShields(); i++)
	{
		this->monsters[i]->addShield(shields[i]);
		this->monsters[i]->shieldGiven();
		this->monsters[i]->setDefense(this->monsters[i]->getDefense()+this->monsters[i]->getShield().getBlock());
	}
}

void Tournament::print() const
{
	// for (int i = 0; i < numofmonsters; ++i)
	// {
	// 	cout << i+1 <<"Fighters: " << this->monsters[i].getName() << endl;
	// }

	// for (int i = 0; i < numofweapons; ++i)
	// {
	// 	cout << i+1 <<"Weapons: " << this->weapons[i].getName() << endl;
	// }
}

Tournament::~Tournament()
{
	delete [] this->monsters;
	delete [] this->weapons;
	delete [] this->shields;
}