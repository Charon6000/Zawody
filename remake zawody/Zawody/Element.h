#pragma once
#include "Common.h"

struct Element
{
	string name; //nazwa elementu
	int wiedza_roll;
	int sila_roll;
	int dlugosc; //dlugosc elementu

	Element(string n, int w, int s, int z)
	{
		this->name = n;
		this->wiedza_roll = w;
		this->sila_roll = s;
		this->dlugosc = z;
	}

public:
	int getwiedza() { return wiedza_roll; }
	int getsila() { return sila_roll; }
	int getdlugosc() { return dlugosc; }
};