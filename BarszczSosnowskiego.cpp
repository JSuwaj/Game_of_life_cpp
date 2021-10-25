#include "BarszczSosnowskiego.h"
#define SILA_BARSZCZU 10
#define SYMBOL_BARSZCZU 'b'
#define GATUNEK_BARSZCZU "barszcz"

BarszczSosnowskiego::BarszczSosnowskiego(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Roslina(polozenie_x, polozenie_y, inicjatywa, SILA_BARSZCZU, szansa_rozpylenia, SYMBOL_BARSZCZU, GATUNEK_BARSZCZU, swiat)
{

}

void BarszczSosnowskiego::Akcja()
{
	//funkcja sprawdza czy w jego sasiedztwie stoi jakies zwierze i jezeli stoi to je zabija
	Organizm* temp = swiat.CoTuStoi(this->GetPolozenieX() + 1, this->GetPolozenieY());
	if (temp!=NULL)
	{
		if (temp->GetInicjatywa() != 0)
		{
			cout << this->GetGatunek() << " zabija " << temp->GetGatunek() << endl;
			temp->SetZywy(0);
			swiat.Usmierc(temp);
		}
	}
	temp = swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() + 1);
	if (temp != NULL)
	{
		if (temp->GetInicjatywa() != 0)
		{
			cout << this->GetGatunek() << " zabija " << temp->GetGatunek() << endl;
			temp->SetZywy(0);
			swiat.Usmierc(temp);
		}
	}
	temp = swiat.CoTuStoi(this->GetPolozenieX() - 1, this->GetPolozenieY());
	if (temp != NULL)
	{
		if (temp->GetInicjatywa() != 0)
		{
			cout << this->GetGatunek() << " zabija " << temp->GetGatunek() << endl;
			temp->SetZywy(0);
			swiat.Usmierc(temp);
		}
	}
	temp = swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() - 1);
	if (temp != NULL)
	{
		if (temp->GetInicjatywa() != 0)
		{
			cout << this->GetGatunek() << " zabija " << temp->GetGatunek() << endl;
			temp->SetZywy(0);
			swiat.Usmierc(temp);
		}
	}
	RozprzestrzenSie();
}

void BarszczSosnowskiego::Kolizja(Organizm* inny_organizm)
{

	if (inny_organizm->GetInicjatywa()!=0)
	{
		inny_organizm->SetZywy(0);
		swiat.Usmierc(inny_organizm);
	}

}

Organizm* BarszczSosnowskiego::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new BarszczSosnowskiego(x, y, this->swiat);
	return nowy_organizm;
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{

}