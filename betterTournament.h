#include <vector> 
#include <iostream>

class betterTournament
{
private:
    vector<Monster*> fighters;
    directEliminations schema_directEliminations;
    allvsall schema_allvsall;
    mixedFight schema_mixed;

    vector<Weapon> weapons;
    vector<Shield> shields;

    bool directEL;
    bool ava;
    bool mixed;
public:
    betterTournament();
    void addFighter(Monster&);
    const int getNumOfFighters() const;

    void addWeapon(const Weapon&);
    void addShield(const Shield&);
    const int getNumOfWeapons() const;
    const int getNumOfShields() const;
    void Random_Weapon_Alocator();
    void Random_Shield_Alocator();

    const bool isDirectElEnabled() const;
    bool directEliminations_Enabler();
    bool directEliminations_Disabler();

    const bool isAvaEnabled() const; 
    bool avaEnabler();
    bool avaDisabler();

    const bool isMixedFightEnabled() const;
    bool mixedFight_Enabler();
    bool mixedFight_Disabler();

    void start_directEliminations();
    void start_allvsall();
    void start_mixedFight();

    void print() const;
};