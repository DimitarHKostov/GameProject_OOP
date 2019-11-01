#include <vector>

class Round
{
private:
    vector <Monster*> round_fighters;
    vector<Monster*> toBeSerialized;
    int index;
    int number_of_alive_fighters;
public:
    Round();
    void addFighter(Monster&);
    void popFighter();
    const int getNumOfFighters() const;
    const int getNumOfAliveFighters() const;
    void kill_another_one();
    void print() const;
    void serialize_DE();
    void serialize_MIX();
    void addToSerializator(Monster&);
    const int getnumofserializedones() const;
    void clear();
    Monster* getMonster(int) const;

    Monster*& round_direct_eliminations_picker(); 
};