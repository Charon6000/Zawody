#pragma once
#include "Common.h"
#include "Uczestnik.h"
#include "Trasa.h"

//pula imion i nazwisk
string tab[2][5] = { {"Jan","Dzban","Adam","Mariusz", "Dariusz"},{"Pancel","Adamowicz","Pawlak","Geleciak","Globus"} };



class Zawody
{

	Trasa* _trasa; //obiekt trasy
	int _iloscKom = 0; //ilosc linijek tekstu komentatora

public:
	vector<Uczestnik*> _uczestnicy; //lista zawodników
	int nrTrasy = 1;
	 vector<Uczestnik*> wygrani;
	 bool wygrana = false;

	Zawody(int dlugosc, int ilosc, int trudnosc)
	{
		srand(time(NULL));
		if (ilosc < 1)
			ilosc = 1;
		for (int i = 0; i < ilosc; i++)
		{
			string temp = "";
			temp += tab[0][rand() % 5];
			temp += " ";
			temp += tab[1][rand() % 5];
			_uczestnicy.push_back(new Uczestnik(temp, rand() % 20 + 10, rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1));
			gotoxy(1, i * 2 + 3);
		}

		gotoxy(2, ilosc + 7);
		_trasa = new Trasa(dlugosc, trudnosc, nrTrasy);
		for (int i = 0; i < _uczestnicy.size(); i++)
		{
			for (int j = 0; j < _trasa->getLen(); j++)
			{
				if (_trasa->getEl(j).getsila() <= _uczestnicy[i]->getSila() && _trasa->getEl(j).getdlugosc() <= _uczestnicy[i]->getZrecznosc() && _trasa->getEl(j).getwiedza() <= _uczestnicy[i]->getWiedza())
				{
					_uczestnicy[i]->addZal();
				}
			}
			_uczestnicy[i]->addProgres();
		}
		gotoxy(32, 25);
		cout << "Kliknij cokolwiek, aby przejsc dalej . . . ";
		_getch();

		system("CLS");
		gotoxy(1, 1);
		for (int i = 0; i < _uczestnicy.size(); i++)
		{
			PokazUczestnikow();
		}
		_getch();
		gotoxy(32, 25);
		cout << "Kliknij cokolwiek, aby przejsc dalej . . . ";
		_getch();

		//generowanie trasy
		//---------------------DEBUG LINE----------------//
		//_uczestnicy[0]->addProgres(36);
		//_uczestnicy[0]->addZal();

	}

	//dodaje komentarz do komentatora
	void dodajKomentarz(string what)
	{
		_iloscKom += 1;
		gotoxy(1, 9 + _iloscKom);
		cout << what;
		if (_iloscKom > 25)
			_iloscKom = 0;
	}

	//nastepna runda 
	void NastepnaRunda(int dlugosc, int trudnosc)
	{
		for(int i = 0; i < _uczestnicy.size(); i++)
		{
			for (int j = 0; j < _trasa->getLen(); j++)
			{
				if(_trasa->getEl(j).getsila() <= _uczestnicy[i]->getSila() && _trasa->getEl(j).getdlugosc() <= _uczestnicy[i]->getZrecznosc() && _trasa->getEl(j).getwiedza() <= _uczestnicy[i]->getWiedza())
				{
					_uczestnicy[i]->addZal();
				}
			}
			_uczestnicy[i]->addProgres();
		}
		system("CLS");
		_trasa = new Trasa(dlugosc, trudnosc, nrTrasy);
		nrTrasy++;
		gotoxy(32, 25);
		cout << "Kliknij cokolwiek, aby przejsc dalej . . . ";
		_getch();
		system("CLS");
		gotoxy(1, 1);
		for (int i = 0; i < _uczestnicy.size(); i++)
		{
			PokazUczestnikow();
		}
		_getch();
	}

	//wyswietla wszystkich uczestnikow
	void PokazUczestnikow()
	{
		for (int i = 0; i < _uczestnicy.size(); i++)
		{
			gotoxy((i + 1) * 20, 2);
			cout << _uczestnicy[i]->getName();
			gotoxy((i + 1) * 20, 3);
			cout << "Wiedza: ";
			for (int j = 0; j < 10; j++)
			{
				if (j < _uczestnicy[i]->getWiedza())
					cout << char(178);
				else
					cout << char(176);
			}
			gotoxy((i + 1) * 20, 4);
			cout << "Zrecznosc: ";
			for (int j = 0; j < 10; j++)
			{
				if (j < _uczestnicy[i]->getZrecznosc())
					cout << char(178);
				else
					cout << char(176);
			}
			gotoxy((i + 1) * 20, 5);
			cout << "Sila: ";
			for (int j = 0; j < 10; j++)
			{
				if (j < _uczestnicy[i]->getSila())
					cout << char(178);
				else
					cout << char(176);
			}
			gotoxy((i + 1) * 20, 6);
			cout << "Etap: ";
			for (int j = 0; j < 5; j++)
			{
				if (j < _uczestnicy[i]->getProgr())
					cout << char(178);
				else
					cout << char(176);
			}
			gotoxy((i + 1) * 20, 7);
			cout << "Punkty: ";
			for (int j = 0; j < 10; j++)
			{
				if (j < _uczestnicy[i]->getZal())
					cout << char(178);
				else
					cout << char(176);
			}

		}
		gotoxy(1, 8);
		cout << "_____________________________________________________________________________________________";
	}

	void SprawdzZwyciezce()
	{
			for (int i = 0; i < _uczestnicy.size(); i++)
			{
				if (_uczestnicy[i]->getZal() >= 10)
				{
						wygrana = true;
						wygrani.push_back(_uczestnicy[i]);
				}

				if (_uczestnicy[i]->getProgr() == 5)
				{
					wygrana = true;
				}
			}
	}

	void WypiszZwyciezcow()
	{
		if (wygrani.size() != 0)
		{
			cout << "\nZwyciezcy:";
			for (int i = 0; i < wygrani.size(); i++)
			{
				cout << wygrani[i]->getName() + "\n";
			}
			cout << "Gratulujemy!";
			_getch();
		}
		else cout << "\n Brak wygranych!\n";
	}


};