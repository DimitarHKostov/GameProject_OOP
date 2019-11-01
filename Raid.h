class Raid
{
private:
    Monster** fighters;
    Boss** bosses;
    Weapon* weapons;
    Shield* shields;

    int numoffighters;
    int numofbosses;
    int numofweapons;
    int numofshields;

public:
    Raid();
    ~Raid();

    void addFighter(Monster&);
    void addBoss(Boss&);
    void addWeapon(const Weapon&);
    void addShield(const Shield&);

    const Monster& getFighter() const;
    const Monster& getBoss() const;
    const Weapon& getWeapon() const;
    const Shield& getShield() const;

    void setNumOfFighters(int);
    void setNumOfBosses(int);
    void setNumOfWeapons(int);
    void setNumOfShields(int);

    const int getNumOfFighters() const;
    const int getNumOfBosses() const;
    const int getNumOfWeapons() const;
    const int getNumOfShields() const;

    void startFight();
    void fbossPrint() const;
    void nbossPrint() const;
    void lbossPrint() const;

    void bossesWin() const;
    void fightersWin() const;
};