#include "Shield.h"
#include <iostream>

using namespace std;

Shield::Shield()
{
    this->name = nullptr;
    this->block=block;
    this->durability=durability;
}

Shield::Shield(const char* name, int block, int durability)
{
    this->name=nullptr;
    this->setName(name);
    this->setBlock(block);
    this->setDurability(durability);
}

Shield& Shield::operator=(const Shield& other)
{
    if (this!=&other) {
        this->setName(other.getName());
        this->setBlock(other.getBlock());
        this->setDurability(other.getDurability());
    }
    return *this;
}

Shield::Shield(const Shield& other)
{
    this->setName(other.getName());
    this->setDurability(other.getDurability());
    this->setBlock(other.getBlock());
}

Shield::~Shield()
{
    //delete [] this->name;
}

void Shield::setBlock(int block)
{
    this->block=block;
}

const int Shield::getBlock() const
{
    return this->block;
}