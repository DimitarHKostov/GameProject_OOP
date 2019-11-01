class Mage: public Monster
{
private:
    int bonusDamage;
public:
    Mage();
    Mage(int, int, int, const char*);
    void hit(Monster&) override;
    ~Mage();
    void specialAbility() override;
    void specialAbilityEffect() const override;

    void setBonusDamage(int);
    const int getBonusDamage() const;
};
