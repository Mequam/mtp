#include <iostream>
#include <string>
#include "Race.h"
using namespace std;
//The life class
class Life
{
public:
	Life() {};
	Life(Rng*,int,int,int);
	void ToString();
private:
	int Flora = 0;
	int Fauna = 0;
	int Civilization = 0;
	int Aliens = 0;
	Race* LifeRace;
	Race Natives;
};

Life::Life(Rng* rand,int x,int y,int w)
{
	this->Flora = rand->Range(0,100,x,y,w);
	this->Fauna = rand->Range(0,100,x,y,w);
	if(rand->Percent(40,x,y,w) == true) 
	{
		//Generate a random number of alien races
		this->Aliens=rand->Range(1,10); 
		this->LifeRace = new Race[this->Aliens]; 
		for(int i = 0; i < this->Aliens; i++)
		{
			this->LifeRace[i]=Race(90,"name",rand,x,y,w);
		}
	}
	if(rand->Percent(10,x,y,w) == true) { this->Civilization = rand->Range(0,100,x,y,w); }
	if(this->Civilization > 0) {Natives = Race(90,"name",rand,x,y,w);}
}

void Life::ToString()
{
	cout << "Flora:" << this-> Flora << endl;
	cout << "Fauna:" << this-> Fauna << endl;

	cout << "Civilization:" << this-> Civilization << endl;
	if (this->Aliens != 0)
	{
		cout << this->Aliens << " Alien lifeforms:" << endl;
		cout << "- - - - - - - - - - - - - - - - " << endl;
		for (int i = 0; i < this->Aliens;i++) 
		{
			cout << "	";
			this->LifeRace[i].ToString();
		}
	}
	if (this->Civilization > 0) 
	{
		cout << "Native Race:" << endl << "- - - - - - - - - - - - - - - - " << endl << "	";
		this->Natives.ToString();
	}
}

//The planet class
class Planet
{
public:
	Planet(int,int,int);
	Planet() {};
	void ReSpawn(Rng&,int,int,int);
	void ToString();
private:
	int Temp[2];
	int Tox[2];
	int Size = 0;
	int Moons = 0;
	int Water = 0;
	int Metals = 0;
	int Eatheriam = 0;
	int CrudeFuel = 0;
	int Power = 0;
	bool alive = false;
	bool Controled = false;
	Life Biosphere;
};
//Initilizer for the planet
Planet::Planet(int x,int y,int w)
{
	Rng rand;
	this->Temp[0] = rand.Range(-300,300,x,y,w);
	this->Temp[1] = rand.Range(-300,300,x,y,w);
	this->Tox[0] = rand.Range(0,100,x,y,w);
	this->Tox[1] = rand.Range(0,100,x,y,w);
	this->Moons = rand.Range(1,20,x,y,w);
	this->Size = rand.Range(1,20,x,y,w);
	this->Biosphere = Life(&rand,x,y,w);
	if (rand.Percent(45,x,y,w))
	{
		this->Metals=rand.Range(1,60);
	}
	 if (rand.Percent(45,x,y,w)) 
        {
                this->Power=rand.Range(1,60);
        }
	if (rand.Percent(45,x,y,w)) 
        {
                this->CrudeFuel=rand.Range(1,60);
        }
	if (rand.Percent(15,x,y,w)) 
        {
                this->Eatheriam=rand.Range(1,10);
        }
	if (rand.Percent(1,x,y,w))
	{
		this->Eatheriam=100;
	}
	if (rand.Percent(25,x,y,w) == true)
	{this->Water=rand.Range(0,100,x,y,w);}
	if (rand.Percent(50,x,y,w) == true)
	{this->alive=true;}
	if (rand.Percent(25,x,y,w) == true)
	{this->Controled = true;}
}

void Planet::ReSpawn(Rng& rand,int x, int y, int w)
{
	//this function exists so we take up less memory and just re-change an existing planet
	this->Temp[0] = rand.Range(-300,300,x,y,w);
        this->Temp[1] = rand.Range(-300,300,x,y,w);
        this->Tox[0] = rand.Range(0,100,x,y,w);
        this->Tox[1] = rand.Range(0,100,x,y,w);
        this->Moons = rand.Range(1,20,x,y,w);
        this->Size = rand.Range(1,20,x,y,w);
	this->Biosphere = Life(&rand,x,y,w);
        if (rand.Percent(25,x,y,w) == true) {this->Water=rand.Range(0,100,x,y,w);}
	if (rand.Percent(45,x,y,w))
	{
        	this->alive=true;
	}
	if (rand.Percent(45,x,y,w)) 
        {
                this->Metals=rand.Range(1,60);
        }
         if (rand.Percent(45,x,y,w)) 
        {
                this->Power=rand.Range(1,60);
        }
        if (rand.Percent(45,x,y,w)) 
        {
                this->CrudeFuel=rand.Range(1,60);
        }
        if (rand.Percent(15,x,y,w)) 
        {
                this->Eatheriam=rand.Range(1,10);
        }
        if (rand.Percent(1,x,y,w))
        {
                this->Eatheriam=100;
        }
	if (rand.Percent(25,x,y,w) == true)
        {this->Controled = true;}

}

//Turns the planet into a string (wow.)
//Seperates each data point with whitespace
void Planet::ToString()
{

	if (this-> Controled == true) {cout << "CONTROLED BY THE GLYGRUT" << endl;}
	if(this->Temp[0] < this->Temp[1]) {cout << "Temp:" << this->Temp[0] << "-" << this->Temp[1] << endl;}
	else {cout << "Temp:" << this->Temp[1] << "-" << this->Temp[0] << endl;}
	cout << "WaterRating:" << this->Water << endl;
	if(this->alive==true) {this->Biosphere.ToString();}
	cout << "Toxicity Rating:" << this->Tox[0] << "," << this->Tox[1] << endl;
	cout << "Size:" << this->Size << endl;
	cout << "Moons:" << this->Moons << endl;
	cout << "Resources:[" << "Metal:" << this->Metals << " Power:" << this->Power << " Crude Oil:" << this->CrudeFuel << " Eatheriam:" << this->Eatheriam << "]" << endl;
}

string GenBlack(Rng rand,bool star);

string Center(Rng rand,int x,int y,int w) {
int roll = rand.Range(1,6,x,y,w);
	if (roll == 1)
	{
		return GenBlack(rand,false) + " BlackHole";
	}
	else if (roll== 2 || roll == 3 || roll == 4)
 	{
		return GenBlack(rand,true) + " Star";
	}
	else
	{
		return "LargePlanet";
	}
}

string Obj(Rng& rand,int x,int y,int w) {
//The program jumps here if it fails to spawn one of the rarer objects
start:
int roll = rand.Range(1,8,x,y,w);
switch(roll)
{
	case 1:
	return "P";
	case 2:
	return "P";
	case 3:
	return "Asteroid Belt";
	case 4:
	return "Nebula";
	case 5:
	return GenBlack(rand,true) + " Star";
	case 6:
	if (rand.Percent(66,x,y,w) == true)
	{
		return "SpaceStation";
	}
	else {goto start;}
	case 7:
	if (rand.Percent(50,x,y,w) == true) 
	{
		return "WormHole";
	}
	else {goto start;}
	case 8:
	if (rand.Range(1,8,x,y,w) == 8) 
	{
		return GenBlack(rand,false) + " BlackHole";
	}
	else {goto start;}
}
}

string GenBlack(Rng rand,bool star)
{
	int roll = rand.Range(1,4);
	//change the swich to black holes if star is false
	if(star!=true) {roll+=4;}
	switch(roll)
	{
		case 1:
		return "Yellow";
		case 2:
		return "Red";
		case 3:
		return "Blue";
		case 4:
		return "Orange";
		case 5:
		return "Small";
		case 6:
		return "Medium";
		case 7:
		return "Large";
		case 8:
		return "SuperMassive";
		default:
		return "Error";
	}
}

int main(int argc,char* argv[])
{
	string Sepa = "________________________";
	string Sepb = "----------";
	Planet rock;
	int x = 1;
	int y = 0;
	int w = 100;
if(argc > 2)
{
	x = stoi(argv[1]);
	y = stoi(argv[2]);
}
if (argc > 3) 
{
	w = stoi(argv[3]);
}
else if (argc == 1 || argc == 2)
{
	string s;
	cout << "What Sector would you like to see" << endl;
        cout << "x - >" << endl;
        getline(cin,s);
        x = stoi(s);
        cout << "y - >" << endl;
        getline(cin,s);
        y = stoi(s);
	cout << "w - >" << endl;
        getline(cin,s);
        w = stoi(s);

}

Rng rand = Rng(x,y,w);
int Max = 1;
for(int i=0; i < Max; i++)
{
	cout << "Center of Sector:" << Center(rand,x,y,w) << endl << Sepb << endl;
	int Roll = rand.Range(1,8,x,y,w);
		for(int i = 0; i < Roll; i++) 
		{
			string obj = Obj(rand,x,y,w);
			if (obj == "P")
			{
				rock.ReSpawn(rand,x,y,w); 
				cout << "Planet:" << endl << "- - - - - - - - - -" << endl;
				rock.ToString();
			}
			else if(obj != "SpaceStation")
			{
				cout << obj << endl;
			}
			else
			{
				cout << obj << endl << "- - - - - - - - - - -" << endl;
				for(int g = 0; g < rand.Range(0,4); g++)
				{
					cout << "	";
					Race(90,"name",&rand,x,y,w).ToString();
				}
			}
			cout << Sepb << endl;
		}

	cout << Sepa << endl;
}
return 1;
}
