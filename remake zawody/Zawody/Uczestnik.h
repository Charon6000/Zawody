#pragma once

#include "Common.h"

class Uczestnik
{
	string imie_nazwisko;
	int wiek;

	//0 - 100
	int wiedza;
	int zrecznosc;
	int sila;

	int zaliczone = 0;
	int progres = 0;
	bool wygrywa = false;
public:
	Uczestnik(string name, int wiek, int w, int z, int s)
	{
		cout << "Witamy uczestnika " << name << ", ktory ma " << wiek << " lat i pochodzi z Gdanska!\n";
		cout << "Wiedza: " << w << ", Zrecznosc: " << z << ", Sila: " << s << endl;
		this->imie_nazwisko = name;
		this->wiek = wiek;
		this->wiedza = w;
		this->zrecznosc = z;
		this->sila = s;
	}

	string getName() { return imie_nazwisko; }
	int getWiek() { return wiek; }
	int getWiedza() { return wiedza; }
	int getSila() { return sila; }
	int getZrecznosc() { return zrecznosc; }
	int getZal() { return zaliczone; }
	int getProgr() { return progres; }
	void setWygrywa(bool a) { this->wygrywa = a; }

	//zwieksza zaliczone elementy trasy o 1
	void addZal()
	{
		zaliczone++;
	}

	//zwieksza progres danego elementu trasy o a, majac na uwadze dlugosc elementu (dlugosc)
	void addProgres()
	{
		progres++;
	}

	//resetuje progres elementu
	void resetProgres()
	{
		progres = 0;
	}

};