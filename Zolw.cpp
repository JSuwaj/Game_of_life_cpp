#include "Zolw.h"

#define INICJATYWA_ZOLWIA 1
#define SILA_ZOLWIA 2
#define ZASIEG_ZOLWIA 1
#define SYMBOL_ZOLWIA 'z'
#define GATUNEK_ZOLWIA "zolw"


Zolw::Zolw(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Zwierze(polozenie_x, polozenie_y, INICJATYWA_ZOLWIA, SILA_ZOLWIA, ZASIEG_ZOLWIA, SYMBOL_ZOLWIA, GATUNEK_ZOLWIA, swiat)
{

}

void Zolw::Akcja()
{
	int czy_ruszy= rand() % 4;
	if (czy_ruszy == 0)
	{
		int kierunek = rand() % 4;
		switch (kierunek % 4)
		{
		case 0:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), zasieg_ruchu, 0) == 0)
				this->Akcja();
			else
				swiat.PoruszZwierza(this, zasieg_ruchu, 0);
			break;
		case 1:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, zasieg_ruchu) == 0)
				this->Akcja();
			else
				swiat.PoruszZwierza(this, 0, zasieg_ruchu);
			break;
		case 2:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), (-1) * zasieg_ruchu, 0) == 0)
				this->Akcja();
			else
				swiat.PoruszZwierza(this, (-1) * zasieg_ruchu, 0);
			break;
		case 3:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, (-1) * zasieg_ruchu) == 0)
				this->Akcja();
			else
				swiat.PoruszZwierza(this, 0, (-1) * zasieg_ruchu);
			break;
		}
	}

}

Organizm* Zolw::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new Zolw(x, y, this->swiat);
	return nowy_organizm;
}

bool Zolw::Unik(Organizm* atakujacy)
{
	if (atakujacy->GetSila() < 5)
	{
		cout << this->GetGatunek() << " wykonuje unik" << endl;
		return true;
	}
	else
		return false;
}

Zolw::~Zolw()
{

}