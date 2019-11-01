#include "Points.h"
#include <iostream>

Point::Point()
{
    this->value=0;
}

void Point::setPoint(int value)
{
    this->value=value;
}

const int Point::getPoint() const
{
    return this->value;
}

void Point::pointIncrease()
{
    this->value++;
}