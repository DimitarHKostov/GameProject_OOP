class mixedFight:public Schema
{
private:
    int index;
    int current_index;
public:
    mixedFight();
    bool mixedFight_checker() const;
    void MixedFight_definition();
    void addFighter(Monster&) override;
    const int getNumOfFighters() const;
    void serialize() override;
    void serialize_helper_one();
    void serialize_helper_two();
    Monster* monster_picker(Monster**);
};