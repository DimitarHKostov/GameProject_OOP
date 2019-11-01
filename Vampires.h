class Vampire: public Monster
{
private:
public:
    Vampire();
    Vampire(int, int, int, const char*);
    void hit(Monster&) override;
    ~Vampire();
    void specialAbility() override;
    void specialAbilityEffect() const override;
};