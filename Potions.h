class Potion: public Items
{
private:
    int bonusHealth;
public:
    Potion();
    ~Potion();
    Potion(const char*, int);
    Potion(const Potion&);
    Potion& operator=(const Potion&);

    void setBonusHealth(int);
    const int getBonusHealth() const;
};