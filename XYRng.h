#include <cstdlib>
#include <ctime>
#include <iostream>
//an Rng class for c++ that allows the roling of arbitrary dice
using namespace std;
class Rng
{
public:
Rng();
int StartTime = 0;
int NumLine(int x, int y, int w) 
{
	return ((y * w + x) + 20) * ((y * w + x) + 20);
}

Rng(int x, int y, int w) {this->StartTime=NumLine(x,y,w);}


//returns a random number between str and end, INCLUDING str and end
int Range(int str=1, int end=6,int x=0, int y=0,int w=2)
{
	if((end-str) >= 1)
	{
		srand(this->StartTime);
		this->StartTime += 1;
		return ((rand() % ((end-str) + 1)) + str);
	}
	else
	{
		return -1;
	}
}

//returns true Perc percent of the times it is called
bool Percent(int Perc,int x, int y, int w)
{
	if (Perc >= 100)
	{
		return true;
	}
	else if (Perc <= 0)
	{
		return false;
	}
	else if (Range(0,100,x,y,w) <= Perc)
	{
		return true;
	}

	else
	{
	//if you manage to get down here, you rolled an i :P
	return false;
	}
}
};
Rng::Rng() {}
