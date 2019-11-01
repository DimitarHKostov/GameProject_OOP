class Shield: public Items
{
private:
    int block;
public:
    Shield();
    Shield(const char*, int, int);
    Shield(const Shield&);
    ~Shield();
    Shield& operator=(const Shield&);

    void setBlock(int);
    const int getBlock() const;
};