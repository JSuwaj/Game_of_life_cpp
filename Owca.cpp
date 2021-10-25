#include "Owca.h"

#define INICJATYWA_OWCY 4
#define SILA_OWCY 4
#define ZASIEG_OWCY 1
#define SYMBOL_OWCY 'o'
#define GATUNEK_OWCY "owaca"

Owca::Owca(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Zwierze(polozenie_x, polozenie_y, INICJATYWA_OWCY, SILA_OWCY, ZASIEG_OWCY, SYMBOL_OWCY, GATUNEK_OWCY, swiat)
{

}

Organizm* Owca::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new Owca(x, y, this->swiat);
	return nowy_organizm;
}

Owca::~Owca()
{

}