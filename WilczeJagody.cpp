#include "WilczeJagody.h"

#define SILA_JAGOD 99
#define SYMBOL_JAGOD 'j'
#define GATUNEK_JAGOD "jagody"

WilczeJagody::WilczeJagody(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Roslina(polozenie_x, polozenie_y, inicjatywa, SILA_JAGOD, szansa_rozpylenia, SYMBOL_JAGOD, GATUNEK_JAGOD, swiat)
{

}

void WilczeJagody::Kolizja(Organizm* inny_organizm)
{
	if (inny_organizm->GetInicjatywa() != 0)
	{
		cout << this->GetGatunek() << " wygrywa walke z " << inny_organizm->GetGatunek() << endl;
		inny_organizm->SetZywy(0);
		swiat.Usmierc(inny_organizm);
	}

}

Organizm* WilczeJagody::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new WilczeJagody(x, y, this->swiat);
	return nowy_organizm;
}

WilczeJagody::~WilczeJagody()
{

}