class allvsall: public Schema
{
private:
    int this_monster_index;
    int next_monster_index;
public:
    allvsall();
    void allvsall_Definition();
    void addFighter(Monster&) override;
    const int getNumOfFighters() const;

    const int getThisMonsterIndex() const;
    const int getNextMonsterIndex() const;
    void increment_this_monster_index();
    void increment_next_monster_index();
    void serialize() override;

    void print();
};