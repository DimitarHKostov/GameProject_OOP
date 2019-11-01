class Tank: public Monster
{
private:
    int bonusDefense;
public:
    Tank();
    Tank(int, int, int, const char*);
    void hit(Monster&) override;
    ~Tank();
    void specialAbility() override;
    void specialAbilityEffect() const override;
    void setBonusDefense(int);
    const int getBonusDefense() const;
};