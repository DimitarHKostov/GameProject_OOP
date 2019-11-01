#include "Items.h"
#include <iostream>
#include <cstring>

Items::Items()
{
    this->name = nullptr;
    this->durability=durability;
}

Items::Items(const char* name, int durability)
{
    this->name=nullptr;
    this->setName(name);
    this->setDurability(durability);
}

Items& Items::operator=(const Items& other)
{
    if (this!=&other) {
        this->setName(other.getName());
        this->setDurability(other.getDurability());
    }
    return *this;
}

Items::Items(const Items& other)
{
    this->setName(other.getName());
    this->setDurability(other.getDurability());
}

Items::~Items()
{
    delete [] this->name;
}

bool Items::isBroken() const
{
    return this->getDurability() > 0;
}

void Items::decreaseDurability()
{
    this->setDurability(this->getDurability()-1);
}

void Items::setName(const char* name)
{
    if (this->name != nullptr) 
    {
        delete [] this->name;
    }
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

const char* Items::getName() const
{
    return this->name;
}

void Items::setDurability(int durability)
{
    if (durability<0) {
        durability=0;
    }
    
    this->durability=durability;
}

int Items::getDurability() const
{
    return this->durability;
}