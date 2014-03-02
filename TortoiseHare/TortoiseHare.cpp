// TortoiseHare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void Draw();
void updatePositions();
bool isAWinner();

int tortoisePos;
int harePos;
int harePercent;
int tortoisePercent;
char* hare = "H";
char* tortoise = "T";

int _tmain(int argc, _TCHAR* argv[])
{
    harePos = 0;
    tortoisePos = 0;
	srand(time(0));

//    while(1)
//    {
//        harePercent = rand() % 10 + 1;
//        tortoisePercent = rand() % 10 + 1;
//
//
//    }

	double firstFrame = time(0);

	while(!isAWinner())
	{
		if(time(0) - firstFrame >= 1)
		{
			updatePositions();
			Draw();

			firstFrame = time(0);
		}
		else{continue;}
	}

    return 0; 
}

bool isAWinner()
{
	if(tortoisePos >= 69){return 1;}
	else if(harePos >= 69){return 1;}

	return 0;
}

void updatePositions()
{
    harePercent = rand() % 10 + 1;
    tortoisePercent = rand() % 10 + 1;
	
	if(1 <= tortoisePercent && tortoisePercent <= 5){tortoisePos+=3;}
	else if(6 <= tortoisePercent && tortoisePercent <= 7){tortoisePos-=6;}
	else if(8 <= tortoisePercent && tortoisePercent <= 10){tortoisePos++;}

	if(1 <= harePercent && harePercent <= 2){}
	else if(3 <= harePercent && harePercent <= 4){harePos+=9;}
	else if(5 == harePercent){harePos-=12;}
	else if(6 <= harePercent && harePercent <= 8){harePos++;}
	else if(9 <= harePercent && harePercent <= 10){harePos-=2;}

	if(tortoisePos < 0){tortoisePos = 0;}
	if(tortoisePos > 69){tortoisePos = 69;}
	if(harePos < 0){harePos = 0;}
	if(harePos > 69){harePos = 69;}
	
}

void Draw()
{
	for(int i = 0; i < 70; i++)
	{
		if(tortoisePos == harePos && harePos == i){cout << tortoise << hare; i++;}
		else if(tortoisePos == i)
			cout << tortoise;
		else if(harePos == i)
			cout << hare;
		else{cout << "_";}
	}

	cout << endl;
}

