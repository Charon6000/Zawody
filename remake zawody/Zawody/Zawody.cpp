#include "zawody.h"
#include "Element.h"
#include "Uczestnik.h"
#include "Common.h"
#include "Trasa.h"


int main()
{
	Zawody game(5, 3, 1.0);
	while (game.wygrana == false)
	{
		game.NastepnaRunda(rand()%9+1, rand() & 7 + 1);
		game.SprawdzZwyciezce();
	}
	game.WypiszZwyciezcow();
	return 0;
}