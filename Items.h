class Items
{
protected:
    char* name;
    int durability;
public:
    Items();
    Items(const char*, int);
    Items(const Items&);
    virtual ~Items();
    Items& operator=(const Items&);

    virtual void setName(const char*);
    virtual void setDurability(int);
    virtual void decreaseDurability();
    virtual bool isBroken() const;
    
    virtual const char* getName() const;
    virtual int getDurability() const;
};