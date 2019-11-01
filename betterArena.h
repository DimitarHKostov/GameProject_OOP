#include <vector>

class betterArena
{
private:
    int num_of_active_tournaments;
public:
    betterArena();
    void startFight(betterTournament&);
    const int getNumOfActiveTournaments() const;
};