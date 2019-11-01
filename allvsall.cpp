#include "allvsall.h"

allvsall::allvsall()
{
    this->this_monster_index=0;
    this->next_monster_index=0;
}

void allvsall::allvsall_Definition()
{
    Monster** winners = new Monster*[this->scheme_fighters.size()];

    for(int i = 0; i < this->scheme_fighters.size(); i++)
	{
		winners[i]=this->scheme_fighters[i];
        winners[i]->setMaxHealth(this->scheme_fighters[i]->getHealth());
	}
    
    for (int i = 0; i < this->scheme_fighters.size(); i++)
    {
        for (int j = i+1; j < this->scheme_fighters.size(); j++)
        {
         while(winners[i]->isAlive() && winners[j]->isAlive())
			{
				Monster* toGetPoint = &(winners[i]->fight(*winners[j]));
                toGetPoint->givePoint(); 
			}
            winners[i]->resetHealth();
            winners[j]->resetHealth();
        }    
    }
    
    this->serialize();
    
    delete [] winners;
}

void allvsall::serialize()
{
    ofstream write_to_file;
    write_to_file.open("allvsall_serialized.txt");
    write_to_file << "Tournament type: ALL VS ALL" << endl;
    for (int i = 0; i < this->getNumOfFighters(); i++)
    {
       write_to_file << this->scheme_fighters[i]->getName() << " has " 
       << this->scheme_fighters[i]->getPoints().getPoint()  << " points." << endl;
    }
    write_to_file.close();
}

void allvsall::print()
{
    for(int i = 0; i < this->getNumOfFighters();++i)
    {
        cout << this->scheme_fighters[i]->getName() << " has " << this->scheme_fighters[i]->getPoints().getPoint() << endl;
    }
}

const int allvsall::getNextMonsterIndex() const
{
    return next_monster_index;
}

const int allvsall::getThisMonsterIndex() const
{
    return this_monster_index;
}

void allvsall::addFighter(Monster& other)
{
    this->scheme_fighters.push_back(&other);
}

const int allvsall::getNumOfFighters() const
{
    return this->scheme_fighters.size();
}

void allvsall::increment_this_monster_index()
{
    this->this_monster_index++;
}

void allvsall::increment_next_monster_index()
{
    this->next_monster_index++;
}