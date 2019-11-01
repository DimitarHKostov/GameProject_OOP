#include "betterArena.h"

betterArena::betterArena()
{
    this->num_of_active_tournaments = 0;
}

const int betterArena::getNumOfActiveTournaments() const
{
    return this->num_of_active_tournaments;
}

void betterArena::startFight(betterTournament& other)
{
    if (other.isDirectElEnabled())
    {
        other.start_directEliminations();
    }
    else if (other.isAvaEnabled())
    {
        other.start_allvsall();
    }
    else if (other.isMixedFightEnabled())
    {
        other.start_mixedFight();
    } 
    
    else
    {
        cout << "sorry, no active tournaments!" << endl; 
    }
}