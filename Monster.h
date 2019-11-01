class Monster
{
protected:
	int maxHealth;
	int health;
	int attackPower;
	int defense;
	char* name;
	bool hasWeapon;
	bool hasShield;

	Point point;

	Weapon weapon;
	Shield shield;
	Potion potion;
public:
	Monster& operator=(const Monster&);
	Monster();
	virtual ~Monster();
	Monster(int , int , int , const char*);
	Monster(const Monster &);

	virtual void setPoints(Point);
	virtual const Point getPoints() const;

	virtual void givePoint();

	virtual void setHealth(int);
	virtual void setMaxHealth(int);
	virtual void setAttackPower(int);
	virtual void setDefense(int);
	virtual void setName(const char*);
	virtual void resetHealth();
	
	virtual void addWeapon(const Weapon&);
	virtual void addShield(const Shield&);
	virtual void addPotion(const Potion&);
	
	virtual const int getHealth() const;
	virtual const int getAttackPower() const;
	virtual const int getDefense() const;
	virtual const char* getName() const;
	virtual const int getMaxHealth() const;
	
	virtual void weaponGiven();
	virtual void shieldGiven();
	virtual void hit(Monster&);
	virtual Monster& fight(Monster&);
	virtual void specialAbility();
	virtual void specialAbilityEffect() const;

	virtual const Weapon& getWeapon() const;
	virtual const Shield& getShield() const;
	virtual const Potion& getPotion() const;

	virtual bool hasW() const;
	virtual bool hasS() const;
	virtual void enrage();
	virtual bool isAlive();
	virtual void hitPrint(const Monster&) const;
	virtual void successfullBlock(const Monster&) const;

};