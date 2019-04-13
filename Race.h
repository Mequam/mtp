//A class used to symulate Race data for RPG like aplications
//Uses basic DND rules
#include <string>
#include "XYRng.h"
using namespace std;
class Race
{
private:
	//Data
	string Name = "Human";
	int Age = 90;
	int* Tox = new int[2];

	//Contains six ints to represent race modifiers for each stat
	//int* Mod = new int[6];
	string Culture = "curious";
	string family = "sapian";
	string PhyTraits = "Hairless";

public:

	//effectivly tables to roll into
	string GenFamily(int Roll,bool Plural=false);
	string GenTrait(int);
	string GenPhyTrait(int);

	//ReturnFunction
	int GetAge() {return this->Age;}
	string GetName() {return this->Name;}

	Race();
	Race(int,string,Rng*,int, int, int);

	void ToString();
};

Race::Race()
{
}

Race::Race(int age,string name,Rng* dice, int x, int y, int w)
{
	int Roll;
	this -> Age = age;
	this -> Name = name;
	this -> Culture = "";

	for (int i = 0; i < (dice->Range(1,2,x,y,w) + dice->Range(1,2,x,y,w)); i++) 
        {
                this -> Culture +=  this->GenTrait(dice->Range(1,100,x,y,w)) + ' ';
        }
	Roll = dice->Range(1,2,x,y,w);
	if(Roll == 2)
	{
		this -> family = this->GenFamily(dice->Range(1,20,x,y,w)) + '-' + this->GenFamily(dice->Range(1,20,x,y,w),true);
	}
	else 
	{
		this -> family = this->GenFamily(dice->Range(1,20,x,y,w),true);
	}
	this->PhyTraits = "";

	for(int i = 0; i < dice->Range(1,4,x,y,w); i++)
	{
		this -> PhyTraits += this->GenPhyTrait(dice->Range(1,41,x,y,w)) + " ";
	}
}
void Race::ToString()
{
	cout << "a " << this -> Culture << "race of " << this->PhyTraits << this->family << endl;
}
string Race::GenFamily(int Roll,bool Plural)
{
	if (Plural == false)
	{
		switch (Roll)
		{
			case 1:
			return "Rodent";
			case 2:
			return "Canine";
			case 3:
			return "Feline";
			case 4:
			return "Bear";
			case 5:
			return "Fish";
			case 6:
			return "Primate";
			case 7:
			return "Bird";
			case 8:
			return "Slug";
			case 9:
			return "Insect";
			case 10:
			return "Arachnid";
			case 11:
			return "Crustation";
			case 12:
			return "Reptile";
			case 13:
			return "Bacteria";
			case 14:
			return "Machine";
			case 15:
			return "Horse";
			case 16:
			return "Amphibian";
			case 17:
			return "Plant";
			case 18:
			return "Fungi";
			case 19:
			return "cow";
			case 20:
			return "octopus";
			default:
			return "meta";
		}
	}
	else 
	{
		 switch (Roll)
                {
                        case 1:
                        return "Rodents";
                        case 2:
                        return "Canines";
                        case 3:
                        return "Felines";
                        case 4:
                        return "Bears";
                        case 5:
                        return "Fish";
                        case 6:
                        return "Primates";
                        case 7:
                        return "Birds";
                        case 8:
                        return "Slugs";
                        case 9:
                        return "Insects";
                        case 10:
                        return "Arachnids";
                        case 11:
                        return "Crustations";
                        case 12:
                        return "Reptiles";
                        case 13:
                        return "Bacteria";
                        case 14:
                        return "Machines";
                        case 15:
			 return "Horses";
                        case 16:
                        return "Amphibians";
                        case 17:
                        return "Plants";
                        case 18:
                        return "Fungi";
                        case 19:
                        return "cows";
                        case 20:
                        return "octopi";
                        default:
                        return "metaz";

	}
	return "glitch";
	}
}


string Race::GenPhyTrait(int Roll)
{
	switch(Roll)
	{
		case 1:
		return "wiskerd";
		case 2:
		return "mutated";
		case 3:
		return "Demonic";
		case 4:
		return "Ghostly";
		case 5:
		return "armored";
		case 6:
		return "long";
		case 7:
		return "skinny";
		case 8:
		return "fat";
		case 9:
		return "stared";
		case 10:
		return "rock";
		case 11:
		return "longnecked";
		case 12:
		return "blind";
		case 13:
		return "poisinous";
		case 14:
		return "venemus";
		case 15:
		return "colorful";
		case 16:
		return "undead";
		case 17:
		return "hypnotic";
		case 18:
		return "hairess";
		case 19:
		return "pale";
		case 20:
		return "gem";
		case 21:
		return "metalic";
		case 22:
		return "air";
		case 23:
		return "fire";
		case 24:
		return "water";
		case 25:
		return "long nosed";
		case 26:
		return "gloomy";
		case 27:
		return "wingless";
		case 28:
		return "winged";
		case 29:
		return "mindless";
		case 30:
		return "ghastly";
		case 31:
		return "clawed";
		case 32:
		return "toothed";
		case 33:
		return "shiny";
		case 34:
		return "many headed";
		case 35:
		return "invisible";
		case 36:
		return "stalker";
		case 37:
		return "horned";
		case 38:
		return "gaseous";
		case 39:
		return "liquidious";
		case 40:
		return "square";
		case 41:
		return "circular";
		default:
		return "cute";
	}
	return "glich";
}

string Race::GenTrait(int Roll)
{

	switch(Roll)
	{
		case 1:
		return "selfless";
		case 2:
		return "selfish";
		case 3:
		return "araggant";
		case 4:
		return "empathetic";
		case 5:
		return "mature";
		case 6:
		return "funny";
		case 7:
		return "wise";
		case 8:
		return "reclusive";
		case 9:
		return "social";
		case 10:
		return "defensive";
		case 11:
		return "scared";
		case 12:
		return "hungry";
		case 13:
		return "tired";
		case 14:
		return "emotionless";
		case 15:
		return "emotional";
		case 16:
		return "sparatic";
		case 17:
		return "logistical";
		case 18:
		return "nocternal";
		case 19:
		return "lathargic";
		case 20:
		return "nomadic";
		case 21:
		return "lost";
		case 22:
		return "exestential";
		case 23:
		return "secure";
		case 24:
		return "fast";
		case 25:
		return "musical";
		case 26:
		return "arrogant";
		case 27:
		return "curious";
		case 28:
		return "hopefull";
		case 29:
		return "pathetic";
		case 30:
		return "heroic";
		case 31:
		return "chosen";
		case 32:
		return "creative";
		case 33:
		return "manipulative";
		case 34:
		return "inovative";
		case 35:
		return "resoursefull";
		case 36:
		return "clever";
		case 37:
		return "parasitic";
		case 38:
		return "mockery";
		case 39:
		return "sympathetic";
		case 40:
		return "energetic";
		case 41:
		return "morronic";
		case 42:
		return "petrified";
		case 43:
		return "uninteligable";
		case 44:
		return "solitary";
		case 45:
		return "chill";
		case 46:
		return "sickly";
		case 47:
		return "sly";
		case 48:
		return "infected";
		case 49:
		return "impatient";
		case 50:
		return "patient";
		case 51:
		return "peacefull";
		case 52:
		return "brickwall";
		case 53:
		return "seductive";
		case 54:
		return "cool";
		case 55:
		return "nieve";
		case 56:
		return "musical";
		case 57:
		return "computational";
		case 58:
		return "forgetful";
		case 59:
		return "misanthropic";
		case 60:
		return "sadist";
		case 61:
		return "blunt";
		case 62:
		return "literal";
		case 63:
		return "sarcastic";
		case 64:
		return "condencending";
		case 65:
		return "terrifying";
		case 66:
		return "safe";
		case 67:
		return "imoral";
		case 68:
		return "moral";
		case 69:
		return "nice";
		case 70:
		return "mean";
		case 71:
		return "enslaving";
		case 72:
		return "lazy";
		case 73:
		return "grounded";
		case 74:
		return "primative";
		case 75:
		return "political";
		case 76:
		return "passionet";
		case 77:
		return "distant";
		case 78:
		return "forgoten";
		case 79:
		return "famous";
		case 80:
		return "humble";
		case 81:
		return "fearliss";
		case 82:
		return "foolish";
		case 83:
		return "apathetic";
		case 84:
		return "entitled";
		case 85:
		return "sensative";
		case 86:
		return "insensative";
		case 87:
		return "humane";
		case 88:
		return "inhumane";
		case 89:
		return "industrive";
		case 90:
		return "closeMinded";
		case 91:
		return "simpleMinded";
		case 92:
		return "bold";
		case 93:
		return "meticulus";
		case 94:
		return "sloppy";
		case 95:
		return "clean";
		case 96:
		return "obsesive";
		case 97:
		return "lawful";
		case 98:
		return "chaotic";
		case 99:
		return "meh";
		case 100:
		return "victorious";
		default:
		return "?";
	}
return "mysterious";
}
