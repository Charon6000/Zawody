#pragma once
#include "Common.h"
#include "Element.h"
#include <string>

Element sciezka = Element("Sciezka", 8, 0, 10);
Element krzaki = Element("Krzaki", 4, 3, 5);
Element kamienie = Element("Kamienie", 8, 8, 2);
Element rzeka = Element("rzeka", 4, 7, 4);
Element orunczyk = Element("orunczyk", 10, 10, 10);
Element kaluza = Element("kaluza", 1, 1, 1);

Element tab_elementy[6] = { sciezka,krzaki,kamienie, rzeka, orunczyk, kaluza };



class Trasa
{
	int _len;
	float _diff;
	int nrTrasy;
	vector <Element*> _elementy;

public:
	//zwraca ilosc elementow trasy
	int getLen() { return _len; }

	//pobiera dany element o indeksie i
	Element getEl(int i)
	{
		return *_elementy[i];
	}

	Trasa(int len, int diff, int nrTrasy)
	{
		this->_diff = diff;
		this->_len = len;
		this->nrTrasy = nrTrasy;

		cout << "Trasa o numerze " + to_string(nrTrasy) + " sklada sie z : \n";
		for (int i = 0; i < _len; i++)
		{
			_elementy.push_back(&tab_elementy[rand() % 6]);
			_elementy[i]->sila_roll *= _diff;
			_elementy[i]->wiedza_roll *= _diff;
			_elementy[i]->dlugosc *= _diff;
			cout << i + 1 << ". " << _elementy[i]->name << endl;
		}


	}

};