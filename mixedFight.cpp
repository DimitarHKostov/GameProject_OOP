#include "mixedFight.h"
#include <iostream>

using namespace std;

mixedFight::mixedFight()
{
    this->index=0;
    this->current_index=0;
}

bool mixedFight::mixedFight_checker() const
{
    return this->scheme_fighters.size()%2==0;
}

void mixedFight::serialize_helper_one()
{
    this->round.serialize_MIX();
}

void mixedFight::serialize_helper_two()
{
    ofstream write_to_file;
    write_to_file.open("serialize_mixed_2.txt");
    write_to_file << "Now the fighters fight for points!" << endl;
    for (int i = 0; i < 4; i++)
    {
        write_to_file << this->round.getMonster(i)->getName() << " has "  
        << this->round.getMonster(i)->getPoints().getPoint() << " points." << endl;
    }
    
    write_to_file.close();
}

void mixedFight::serialize()
{
    ifstream file1_opener("serialize_mixed_1.txt");
    ifstream file2_opener("serialize_mixed_2.txt");
    ofstream combined("mixed_serialized.txt");
    combined << file1_opener.rdbuf() << file2_opener.rdbuf();
    combined.close();
}

void mixedFight::MixedFight_definition() 
{

    // for (i:=0 - 4)
    // {
    //     a[i] new allvsall()

    // }
    if (this->mixedFight_checker())
    {
        Monster** winners = new Monster*[this->scheme_fighters.size()];
        Monster** winners2 = new Monster*[this->scheme_fighters.size()/2];

        for (int i = 0; i < this->scheme_fighters.size(); i++)
        {
            winners[i]=this->scheme_fighters[i];
            winners[i]->setMaxHealth(this->scheme_fighters[i]->getHealth());
        }

        for (int i = 0; i < this->scheme_fighters.size()/2; i++)
        {
            winners[current_index] =  &(this->monster_picker(winners)->fight(*this->monster_picker(winners)));
            winners[current_index]->resetHealth();
            this->round.addFighter(*winners[current_index]);
            current_index++;
            round.addFighter(*winners[current_index]);

            for (int i = 0; i < this->scheme_fighters.size(); i++)
            {
                if (strcmp(winners[current_index]->getName(), winners[i]->getName())==0)
                {
                    round.popFighter();
                }
            }
            round.addToSerializator(*winners[current_index]);
            winners2[i]=winners[current_index];
            winners2[i]->setMaxHealth(winners[i]->getHealth());
            
        }
        this->serialize_helper_one();
        
        for (int i = 0; i < this->scheme_fighters.size()/2; i++)
        {
            for (int j = i+1; j < this->scheme_fighters.size()/2; j++)
            {
                while(winners2[i]->isAlive() && winners2[j]->isAlive())
                {
                    Monster* toGetPoint = &(winners2[i]->fight(*winners2[j]));
                    toGetPoint->givePoint();
                }
                winners2[i]->resetHealth();
                winners2[j]->resetHealth();
            }    
        }
        this->round.clear();

        for (int i = 0; i < scheme_fighters.size()/2; i++)
        {
            this->round.addFighter(*winners2[i]);
        }
        
        this->round.print();
        this->serialize_helper_two();
        
        this->serialize();
        delete [] winners2;
        delete [] winners;
    }
    else
    {
        cout << "not enough fighters for this mode" << endl;
    }
}

void mixedFight::addFighter(Monster &other)
{
    this->scheme_fighters.push_back(&other);
}

const int mixedFight::getNumOfFighters() const
{
    return this->scheme_fighters.size();
}

Monster* mixedFight::monster_picker(Monster** fighter)
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