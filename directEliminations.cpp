#include "directEliminations.h"
#include <cassert>

directEliminations::directEliminations()
{
    this->index=0;
    this->current_index=0;
}

Monster* directEliminations::pickFighter(Monster** fighter)
{
    int count = this->getNumOfFighters();
    this->index++;

    if (index>count)
    {
        count/=2;
        index=0;
        index++;
    }
    
    if (fighter[this->index-1]->isAlive())
    { 
        this->round.addFighter(*fighter[index-1]);
        return fighter[this->index-1];
    }
}

void directEliminations::serialize()
{
    ofstream write_to_file;
    write_to_file.open("directEliminations_serialized.txt");
    for (int i = 0; i < this->getNumOfFighters(); i++)
    {
       write_to_file << this->scheme_fighters[i]->getName() << endl;
    }
    write_to_file.close();
}

void directEliminations::dirElDefinition()
{   
    if (this->dirElChecker())
    {

        Monster** winners = new Monster*[this->scheme_fighters.size()];

        for (int i = 0; i < this->scheme_fighters.size(); i++)
        {
            winners[i]=this->scheme_fighters[i];
            winners[i]->setMaxHealth(this->scheme_fighters[i]->getHealth());
        }
    
        while (current_index<this->scheme_fighters.size()-1)
        {
            
            winners[current_index] =  &(this->pickFighter(winners)->fight(*this->pickFighter(winners)));
            winners[current_index]->resetHealth();
            round.addFighter(*winners[current_index]);

            for (int i = 0; i < this->scheme_fighters.size(); i++)
            {
                if (strcmp(winners[current_index]->getName(), winners[i]->getName())==0)
                {
                    round.popFighter();
                }
            }

            round.addToSerializator(*winners[current_index]);
            current_index++;
        }
        this->round.serialize_DE();
        delete [] winners;
    }
    else
    {
        cout << "not enough fighters for this mode" << endl;
    }
}

bool directEliminations::dirElChecker() const
{
    return (this->getNumOfFighters() & this->getNumOfFighters()-1)==0;
}

void directEliminations::addFighter(Monster& other)
{
    this->scheme_fighters.push_back(&other);
}

const int directEliminations::getNumOfFighters() const
{
    return this->scheme_fighters.size();
}