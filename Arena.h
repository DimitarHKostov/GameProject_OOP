class Arena
{
private:
	Tournament* tournamentParticipants;
	int numofparticipants;
	Boss* boss;
public:
	Arena();
	Arena(Tournament*, int);
	~Arena();

	void setPlayers(Tournament*);
	void setNumofplayers(int);
	const Tournament* getPlayers() const;
	const int getNumofplayers() const;
	void printStats(const Tournament&) const;

	void directEliminations(const Tournament&);
	void allVsAll(const Tournament&);

	void printWinnerOfDirectEliminations(const Tournament&) const;
	void printWholeTable(const Tournament&) const;
	void printWinnerOfTheAllVsALl(const Tournament&) const;

	void printCurrentRoundParticipants() const;
	void printWinnerOfCurrentRound() const;
	void printWinnerOfTheTournament() const;
};