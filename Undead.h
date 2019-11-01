class Undead: public Monster
{
private:
    bool secondLife;
public:
    Undead();
    Undead(int, int, int, const char*);
    void hit(Monster&) override;
    ~Undead();
    void specialAbility() override;
    void specialAbilityEffect() const override;

    void removeSecondLife();
    const bool getSecondLife() const;
};