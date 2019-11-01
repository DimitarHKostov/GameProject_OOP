#include <vector>

class Schema
{
protected:
    vector<Monster*> scheme_fighters;
    Round round;
public:
    virtual void addFighter(Monster&)=0;
    virtual void serialize()=0;
    const int getNumOfFighters() const;
};