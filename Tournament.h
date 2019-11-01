class Tournament
{
private:

	Monster** monsters;
	int numofmonsters;

	Weapon* weapons;
	Shield* shields;

	int numofweapons;
	int numofshields;
public:
	Tournament();
	Tournament(Monster*, int);
	~Tournament();
	Tournament(const Tournament&);
	void setNumofmonsters(int);
	
	const Monster** getMonsters() const;
	const int getNumofmonsters() const;
	
	void addFighter(Monster&);
	void addWeapon(const Weapon&);
	void addShield(const Shield&);
	int getNumOfWeapons() const;
	int getNumOfShields() const;
	void setNumofweapons(int);
	void setNumofshields(int);

	void enableWeapons();
	void enableShields();

	void print() const;

	friend class Arena;
};