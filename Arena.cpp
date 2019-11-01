#include "Arena.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cassert>

using namespace std;

Arena::Arena()
{
	this->tournamentParticipants=nullptr;
	this->setNumofplayers(0);
}

Arena::Arena(Tournament* players, int numofparticipants)
{
	this->tournamentParticipants=nullptr;
	this->setPlayers(players);
	this->setNumofplayers(numofparticipants);
}

void Arena::setPlayers(Tournament* players)
{
	if (this->tournamentParticipants!=nullptr)
	{
		delete [] this->tournamentParticipants;
	}
	this->tournamentParticipants = new Tournament[numofparticipants];
	this->tournamentParticipants=players;
}

void Arena::setNumofplayers(int numofplayers)
{
	this->numofparticipants=numofplayers;
}

const Tournament* Arena::getPlayers() const
{
	return this->tournamentParticipants;
}

const int Arena::getNumofplayers() const
{
	return this->numofparticipants;
}

void Arena::printCurrentRoundParticipants() const
{

}

void Arena::printWinnerOfCurrentRound() const
{
	
}

void Arena::printWinnerOfTheTournament() const
{
	
}

void Arena::directEliminations(const Tournament& other)
{
	printStats(other);
	int temp = other.getNumofmonsters();
	Monster** winners = new Monster*[temp];	
	
	for(int i = 0; i < temp; i++)
	{
		winners[i]=other.monsters[i];
	}
	
	int* starthealth = new int[temp];

	for(int i = 0; i < temp; i++)
	{
		starthealth[i] = winners[i]->getHealth();
	}

	for(int i = 0; i < temp; i++)
	{
		winners[i]->setMaxHealth(starthealth[i]);
	}
	
	int pos = 0;
	
	// тук идеята е, че за да има турнир, то участниците в него трябва да са 
	//степен на 2
	if ((other.getNumofmonsters() & (other.getNumofmonsters()-1)) == 0) {
		while(temp>1){
			pos=0;
			temp/=2;

			for(int i = 0; i < temp; i++)
			{
				int firstMonster = i*2;
				int secondMonster=i*2+1;

				while(winners[firstMonster]->isAlive() && winners[secondMonster]->isAlive()) {
					winners[firstMonster]->fight(*winners[secondMonster]); 
				}
				
				cout << endl;
				
				if (winners[firstMonster]->isAlive() || winners[secondMonster]->isAlive()) {

					if (winners[firstMonster]->isAlive()) {
						winners[firstMonster]->resetHealth();
		
						winners[pos]=winners[firstMonster];
						pos++;
					}
					else
					{
						winners[secondMonster]->resetHealth();		
						winners[pos]=winners[secondMonster];
						pos++;
					}
					printWinnerOfDirectEliminations(other);
				}
			}
		}
	}

	delete [] winners;
	delete [] starthealth;
}

void Arena::allVsAll(const Tournament& other)
{
	//тук няма ограничения за броя учстници в турнира
	printStats(other);
	int temp = other.getNumofmonsters();
	Monster** winners = new Monster*[temp];	
	
	for(int i = 0; i < temp; i++)
	{
		winners[i]=other.monsters[i];
	}
	
	int* starthealth = new int[temp];

	for(int i = 0; i < temp; i++)
	{
		starthealth[i] = winners[i]->getHealth();
	}

	for(int i = 0; i < temp; i++)
	{
		winners[i]->setMaxHealth(starthealth[i]);
	}

	for (int i = 0; i < other.getNumofmonsters(); i++)
	{
		for (int j = i+1; j < other.getNumofmonsters(); j++)
		{
			while(winners[i]->isAlive() && winners[j]->isAlive())
			{
				winners[i]->fight(*winners[j]);
			}

			cout << endl;
			
			if (winners[i]->isAlive())
			{
				winners[i]->givePoint();
			}
			else
			{
				winners[j]->givePoint();
			}
			
			winners[i]->resetHealth();
			winners[j]->resetHealth();
		}
	}

	printWholeTable(other);
	printWinnerOfTheAllVsALl(other);
	
	cout << endl;
				
	delete [] winners;
	delete [] starthealth;
}

void Arena::printWinnerOfDirectEliminations(const Tournament& other) const
{
	int temp = other.getNumofmonsters();
	Monster** winners = new Monster*[temp];

	for (int i = 0; i < other.getNumofmonsters(); i++)
	{
		if (other.monsters[i]->isAlive())
		{
			cout << "The winner of the tournament is: " << other.monsters[i]->getName() << "." << endl;
		}
	}

	delete [] winners;
}

void Arena::printWholeTable(const Tournament& other) const
{
	int temp = other.getNumofmonsters();
	Monster** winners = new Monster*[temp];	
	
	for(int i = 0; i < temp; i++)
	{
		winners[i]=other.monsters[i];
	}

	for (int i = 0; i < other.getNumofmonsters(); i++)
	{
		cout << winners[i]->getName() << " has " << winners[i]->getPoints().getPoint() << " point." << endl;
	}

	delete [] winners;
}

void Arena::printWinnerOfTheAllVsALl(const Tournament& other) const
{
	int temp = other.getNumofmonsters();
	Monster** winners = new Monster*[temp];	
	
	for(int i = 0; i < temp; i++)
	{
		winners[i]=other.monsters[i];
	}

	Monster** best = new Monster*[1];	
	
	best[0]=other.monsters[0];

	for (int i = 0; i < other.getNumofmonsters(); i++)
	{
		if (best[0]->getPoints().getPoint()<winners[i]->getPoints().getPoint())
		{
			best[0]=winners[i];
		}
	}
	
	cout << endl << "The winner of the tournament is: " << best[0]->getName() << ", " << best[0]->getPoints().getPoint() << " points." << endl << endl;

	delete [] winners;
	delete [] best;
}

void Arena::printStats(const Tournament& other) const
{
	// cout << endl << endl;
	// for(int i = 0; i < other.getNumofmonsters(); i++)
	// {
	// 	cout << other.monsters[i].getName() << " has " << other.monsters[i].getHealth() << " health, " << other.monsters[i].getAttackPower()
	// 	<< " attack power and " << other.monsters[i].getDefense() << " defense." << endl;
	// }
	// cout << endl << endl;
}

Arena::~Arena()
{
	delete [] this->tournamentParticipants;
}
