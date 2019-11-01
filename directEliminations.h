class directEliminations:public Schema
{
private:
    int index;
    int current_index;
public:
    directEliminations();
    bool dirElChecker() const;
    void dirElDefinition();
    void addFighter(Monster&) override;
    const int getNumOfFighters() const;
    Monster* pickFighter(Monster**);
    void serialize() override;
};