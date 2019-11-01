class Weapon: public Items
{
private:
    int strength;
public:
    Weapon();
    Weapon(const char*, int, int);
    Weapon(const Weapon&);
    ~Weapon();
    Weapon& operator=(const Weapon&);

    void setStrength(int);
    const int getStrength() const;
    void durabilityLower();
};
