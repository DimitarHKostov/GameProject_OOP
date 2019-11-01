class Mutant: public Monster
{
private:
    bool mutantSpecial;
public:
    Mutant();
    Mutant(int, int, int, const char*);
    void hit(Monster&) override;
    ~Mutant();
    void specialAbility() override;
    void specialAbilityEffect() const override;

    bool removeMutantSpecial();
    const bool getMutantSpecial() const;
};