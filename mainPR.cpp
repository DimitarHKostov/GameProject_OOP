#include <fstream>
#include "Points.cpp"
#include "Items.cpp"
#include "Weapon.cpp"
#include "Shield.cpp"
#include "Potions.cpp"
#include "Monster.cpp"
#include "Mage.cpp"
#include "Vampires.cpp"
#include "Tank.cpp"
#include "Mutant.cpp"
#include "Undead.cpp"
#include "boss.cpp"
#include "Round.cpp"
#include "schema.cpp"
#include "directEliminations.cpp"
#include "allvsall.cpp"
#include "mixedFight.cpp"
#include "Tournament.cpp"
#include "betterTournament.cpp"
#include "betterArena.cpp"
#include "Arena.cpp"
#include "Raid.cpp"


int main()
{
	Undead zombie(120, 15, 4, "Zombie");
	Mage dragon(160, 13, 7, "Dragon");
	Vampire vampire(110, 14, 5, "Vampire");
	Mage warlock(140, 11, 6, "Warlock");
	Vampire rekcus(160, 14, 11, "Rekcus"); //Knight
	Undead mummy(110, 12, 5, "Mummy");
	Tank golem(210, 14, 5, "Golem");
	Mutant werewolf(170, 10, 14, "Werewolf");

	Weapon dagger("dagger", 2, 7);
	Weapon sword("sword", 4, 10);
	Weapon mace("mace", 5, 12);

	Shield soul("soul", 2, 7);
	Shield vision("vision", 4, 10);
	Shield omega("omega", 5, 12);

	Boss Ilidan(900, 12, 10, "Ilidan");
	Boss Supremus(900, 11, 19, "Supremus");
	Boss Hydra(1100, 10, 7, "Hydra");

	//potion-ите ще влязат по-късно в играта, 
	//сега просто съм ги оставил като идея, която трябва да реализирам
	Potion red("Rot", 30);
	Potion blue("Blau", 45);

	Tournament Dalaran;
	Dalaran.addFighter(zombie); 
	Dalaran.addFighter(dragon);
	Dalaran.addFighter(vampire);
	Dalaran.addFighter(warlock);
	Dalaran.addFighter(rekcus); 
	Dalaran.addFighter(mummy);
	Dalaran.addFighter(golem);
	Dalaran.addFighter(werewolf);

	//Dalaran.addWeapon(dagger);
	//Dalaran.addWeapon(sword);
	//Dalaran.addWeapon(mace);
	//Dalaran.addShield(soul);
	//Dalaran.addShield(vision);
	//Dalaran.addShield(omega);

	//Dalaran.enableWeapons();
	//Dalaran.enableShields();
	
	Arena big;

	//big.directEliminations(Dalaran);

	//big.allVsAll(Dalaran);
	
	// тук това го направих, защото ми беше интересно
	Raid Black_Temple;
	Black_Temple.addFighter(zombie);
	Black_Temple.addFighter(dragon);
	Black_Temple.addFighter(vampire);
	Black_Temple.addFighter(warlock);
	Black_Temple.addFighter(rekcus);
	Black_Temple.addFighter(mummy);
	Black_Temple.addFighter(golem);
	Black_Temple.addFighter(werewolf);

	Black_Temple.addBoss(Ilidan);
	Black_Temple.addBoss(Supremus);
	Black_Temple.addBoss(Hydra);

	//Black_Temple.startFight();

	betterTournament thisOne;
	thisOne.addFighter(zombie);
	thisOne.addFighter(dragon);
	thisOne.addFighter(vampire);
	thisOne.addFighter(warlock);
	thisOne.addFighter(rekcus);
	thisOne.addFighter(mummy);
	thisOne.addFighter(golem);
	thisOne.addFighter(werewolf);

	thisOne.directEliminations_Enabler();
	//thisOne.avaEnabler();
	//thisOne.mixedFight_Enabler();

	thisOne.addWeapon(dagger);
	thisOne.addWeapon(sword);
	thisOne.addWeapon(mace);
	thisOne.addShield(soul);
	thisOne.addShield(vision);
	thisOne.addShield(omega);
	thisOne.Random_Weapon_Alocator();
	thisOne.Random_Shield_Alocator();

	betterArena thatOne;
	thatOne.startFight(thisOne);
}