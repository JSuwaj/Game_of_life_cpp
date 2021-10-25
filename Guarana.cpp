#include "Guarana.h"
#define SILA_GUARANY 0
#define SYMBOL_GUARANY 'g'
#define GATUNEK_GUARANY "guarana"

Guarana::Guarana(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Roslina(polozenie_x, polozenie_y, inicjatywa, SILA_GUARANY, szansa_rozpylenia, SYMBOL_GUARANY, GATUNEK_GUARANY, swiat)
{

}

void Guarana::Kolizja(Organizm* inny_organizm)
{
	if (this->GetSila() < inny_organizm->GetSila())
	{
		int temp_x = this->GetPolozenieX();
		int temp_y = this->GetPolozenieY();
		inny_organizm->SetSila(inny_organizm->GetSila() + 3);
		this->SetZywy(0);
		swiat.Usmierc(this);
		inny_organizm->SetPolozenie(temp_x, temp_y);
	}
	else
	{
		inny_organizm->SetZywy(0);
		swiat.Usmierc(inny_organizm);
	}
}

Organizm* Guarana::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new Guarana(x, y, this->swiat);
	return nowy_organizm;
}

Guarana::~Guarana()
{

}