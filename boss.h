class Boss: public Monster
{
private:
public:
	~Boss();
	Boss(int , int , int , const char*);
	Boss(const Monster &);
    Boss();
    void hit(Monster&) override;
    void enrage() override;
};