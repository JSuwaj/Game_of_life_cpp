#include "Wilk.h"

#define INICJATYWA_WILKA 5
#define SILA_WILKA 9
#define ZASIEG_WILKA 1
#define SYMBOL_WILKA 'w'
#define GATUNEK_WILKA "wilk"

Wilk::Wilk(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Zwierze( polozenie_x,  polozenie_y, INICJATYWA_WILKA, SILA_WILKA, ZASIEG_WILKA, SYMBOL_WILKA, GATUNEK_WILKA, swiat)
{
	
}

Organizm* Wilk::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm=new Wilk(x,y, this->swiat);
	return nowy_organizm;
}

Wilk::~Wilk()
{

}