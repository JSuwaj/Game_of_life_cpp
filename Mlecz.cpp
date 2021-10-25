#include "Mlecz.h"
#define SILA_MLECZA 0
#define SYMBOL_MLECZA 'm'
#define GATUNEK_MLECZA "mlecz"

Mlecz::Mlecz(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Roslina(polozenie_x, polozenie_y, inicjatywa, SILA_MLECZA, szansa_rozpylenia, SYMBOL_MLECZA, GATUNEK_MLECZA, swiat)
{

}

void Mlecz::Akcja()
{
	RozprzestrzenSie();
	RozprzestrzenSie();
	RozprzestrzenSie();
}

Organizm* Mlecz::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new Mlecz(x, y, this->swiat);
	return nowy_organizm;
}

Mlecz::~Mlecz()
{

}