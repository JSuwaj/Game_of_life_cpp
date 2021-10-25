#include "Trawa.h"

#define SILA_TRAWY 0
#define SYMBOL_TRAWY 't'
#define GATUNEK_TRAWY "trawa"

Trawa::Trawa(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Roslina(polozenie_x, polozenie_y, inicjatywa, SILA_TRAWY, szansa_rozpylenia, SYMBOL_TRAWY, GATUNEK_TRAWY, swiat)
{

}

Organizm* Trawa::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new Trawa(x, y, this->swiat);
	return nowy_organizm;
}

Trawa::~Trawa()
{

}