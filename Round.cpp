#include "Round.h"
#include "cassert"
#include <cstring>

Round::Round()
{
    this->index=0;
    this->number_of_alive_fighters=0;
}

void Round::addFighter(Monster& other)
{
    this->round_fighters.push_back(&other);
}

Monster* Round::getMonster(int index) const
{
    return round_fighters[index];
}

void Round::addToSerializator(Monster& other)
{
    this->toBeSerialized.push_back(&other);
}

const int Round::getnumofserializedones() const
{
    return this->toBeSerialized.size();
}

void Round::serialize_MIX()
{
    ofstream write_to_file;
    write_to_file.open("serialize_mixed_1.txt");
    write_to_file << "Tournament type: DIRECT ELIMINATIONS" << endl;
    for (int i = 0; i < this->getnumofserializedones(); i++)
    {
        write_to_file << "Winner after Round " << i+1 << " is " <<  this->toBeSerialized[i]->getName() << endl;
    } 
    write_to_file.close();
}

void Round::serialize_DE()
{
    ofstream write_to_file;
    write_to_file.open("directEliminations_Serializator.txt");
    write_to_file << "Tournament type: DIRECT ELIMINATIONS" << endl;
    for (int i = 0; i < this->getnumofserializedones(); i++)
    {
        write_to_file << "Winner after Round " << i+1 << " is " <<  this->toBeSerialized[i]->getName() << endl;
    }
    write_to_file << "Winner of the tournament is: " << 
    this->toBeSerialized[this->getnumofserializedones()-1]->getName(); 
    write_to_file.close();
}

void Round::popFighter()
{
    if(this->getNumOfFighters()>0)
    {
        this->round_fighters.pop_back();
    }
}

const int Round::getNumOfFighters() const
{
    return this->round_fighters.size();
}

const int Round::getNumOfAliveFighters() const
{
    return this->number_of_alive_fighters;
}

void Round::clear()
{
    while (this->getNumOfFighters()>0)
    {
        this->popFighter();
    }
}

void Round::print() const
{
    for (int i = 0; i < 4; i++)
    {
        cout << this->round_fighters[i]->getName() << endl;
    }
}

void Round::kill_another_one()
{
    if (this->getNumOfAliveFighters()>1)
    {
        this->number_of_alive_fighters--;
    }
}

Monster*& Round::round_direct_eliminations_picker()
{   
    this->index++;
    
    if (round_fighters[this->index-1]->isAlive())
    { 
        return round_fighters[this->index-1];
    }
}