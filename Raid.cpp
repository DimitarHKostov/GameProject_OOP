#include "Raid.h"
#include <iostream>

using namespace std;

Raid::Raid()
{
    this->fighters=nullptr;
    this->bosses=nullptr;
    this->weapons=nullptr;
    this->shields=nullptr;
    this->setNumOfFighters(0);
    this->setNumOfBosses(0);
    this->setNumOfWeapons(0);
    this->setNumOfShields(0);
}

Raid::~Raid()
{
    delete [] this->fighters;
    delete [] this->bosses;
    delete [] this->weapons;
    delete [] this->shields;
}

void Raid::setNumOfFighters(int num)
{
    this->numoffighters = num;
}

void Raid::setNumOfBosses(int num)
{
    this->numofbosses=num;
}

void Raid::setNumOfWeapons(int num)
{
    this->numofweapons=num;
}

void Raid::setNumOfShields(int num)
{
    this->numofshields=num;
}

const int Raid::getNumOfFighters() const
{
    return this->numoffighters;
}

const int Raid::getNumOfBosses() const
{
    return this->numofbosses;
}

const int Raid::getNumOfWeapons() const
{
    return this->numofweapons;
}

const int Raid::getNumOfShields() const
{
    return this->numofshields;
}

void Raid::addFighter(Monster& other)
{
    Monster** temp = new Monster*[this->getNumOfFighters()+1];
    for (int i = 0; i < this->getNumOfFighters(); i++)
    {
        temp[i]=this->fighters[i];
    }
    delete [] this->fighters;
    temp[numoffighters] = &other;
    this->fighters = temp;
    this->setNumOfFighters(this->getNumOfFighters()+1);
}

void Raid::addBoss(Boss& other)
{
    Boss** temp = new Boss*[this->getNumOfBosses()+1];
    for (int i = 0; i < this->getNumOfBosses(); i++)
    {
        temp[i]=this->bosses[i];
    }
    delete [] this->bosses;
    temp[this->getNumOfBosses()] = &other;
    this->bosses = temp;
    this->setNumOfBosses(this->getNumOfBosses()+1);
}

void Raid::addWeapon(const Weapon& other)
{
    Weapon* temp = new Weapon[this->getNumOfWeapons()+1];
    for (int i = 0; i < this->getNumOfWeapons(); i++)
    {
        temp[i]=this->weapons[i];
    }
    delete [] this->weapons;
    temp[this->getNumOfWeapons()] = other;
    this->weapons=temp;
    this->setNumOfWeapons(this->getNumOfWeapons()+1);
}

void Raid::addShield(const Shield& other)
{
    Shield* temp = new Shield[this->getNumOfShields()+1];
    for (int i = 0; i < this->getNumOfShields(); i++)
    {
        temp[i]=this->shields[i];
    }
    delete [] this->shields;
    temp[this->getNumOfShields()] = other;
    this->shields=temp;
    this->setNumOfShields(this->getNumOfShields()+1);
}

void Raid::fbossPrint() const
{
    const char* space = "              ";
    cout << endl;
    cout << space << "---------------------------------------" << endl;
    cout << space <<  "Time has come to fight the first BOSS!!" << endl;
    cout << space << "---------------------------------------" << endl;
    cout << endl;
}

void Raid::nbossPrint() const
{
    const char* space = "              ";
    cout << endl;
    cout << space << "--------------------------------------" << endl;
    cout << space << "Time has come to fight the next BOSS!!" << endl;
    cout << space << "--------------------------------------" << endl;
    cout << endl;
}

void Raid::lbossPrint() const
{
    const char* space = "              ";
    cout << endl;
    cout << space << "--------------------------------------" << endl;
    cout << space << "Time has come to fight the last BOSS!!" << endl;
    cout << space << "--------------------------------------" << endl;
    cout << endl;
}

void Raid::bossesWin() const
{
    const char* space = "              ";
    cout << endl;
    cout << space << "--------------------------" << endl;
    cout << space << "OMG THE BOSSES JUST WON!!!" << endl;
    cout << space << "--------------------------" << endl;
    cout << endl;
}

void Raid::fightersWin() const
{
    const char* space = "              ";
    cout << endl;
    cout << space << "-----------------------------------" << endl;
    cout << space << "OMG THE FIGHTERS KILLED THEM ALL!!!" << endl;
    cout << space << "-----------------------------------" << endl;
    cout << endl;   
}

void Raid::startFight()
{
    Monster ** temp = new Monster*[this->numoffighters];
    for (int i = 0; i < this->getNumOfFighters(); i++)
    {
        temp[i]=this->fighters[i];
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (this->fighters[i]->isAlive() && this->bosses[j]->isAlive()) 
    {
        if (k==0)
        {
            fbossPrint();
            k=1;
        }
        this->bosses[j]->hit(*this->fighters[i]);
        this->fighters[i]->hit(*this->bosses[j]);
        if (!fighters[i]->isAlive())
        {
            temp[i] = this->fighters[i];
            this->fighters[i]=this->fighters[this->getNumOfFighters()-1];
            this->fighters[this->getNumOfFighters()-1]=temp[i];
            this->setNumOfFighters(this->getNumOfFighters()-1);
            
        }
        i++;
        if (!bosses[j]->isAlive())
        {
            j++;
            if (j<=this->getNumOfBosses()-2)
            {
                nbossPrint();
            }
            if (j==this->getNumOfBosses()-1)
            {
                lbossPrint();
            }
            if (j==this->getNumOfBosses())
            {
                fightersWin();
                break;
            } 
        }

        if (this->getNumOfFighters() == 0)
        {
            bossesWin();
            break;
        }
        
        if (i==this->getNumOfFighters() && this->getNumOfFighters()>0)
        {
            i=0;
        }
    }   
    delete [] temp;
}