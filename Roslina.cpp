#include "Roslina.h"
#include "Swiat.h"
#include <iostream>

#define PRAWDOPODOBIENSWO_ROZPYLENIA 0.1
#define INICJATYWA_ROSLINY 0


Roslina::Roslina(int polozenie_x, int polozenie_y, int inicjatywa, int sila, double szansa_rozpylenia, char symbol, string gatunek, Swiat& swiat)
	:Organizm(polozenie_x, polozenie_y, INICJATYWA_ROSLINY, sila, symbol, gatunek, swiat), szansa_rozpylenia(PRAWDOPODOBIENSWO_ROZPYLENIA)
{
	ile_zyje = 0;
}

Roslina::~Roslina()
{

}

void Roslina::Akcja()
{
	RozprzestrzenSie();
}

bool Roslina::Unik(Organizm* atakujacy)
{
	return false;
}

void Roslina::Kolizja(Organizm* inny_organizm)
{
	if (this->GetSila() < inny_organizm->GetSila())
	{
		cout << inny_organizm->GetGatunek() << " wygrywa walke z " << this->GetGatunek() << endl;
		int temp_x = this->GetPolozenieX();
		int temp_y = this->GetPolozenieY();
		this->SetZywy(0);
		swiat.Usmierc(this);
		inny_organizm->SetPolozenie(temp_x, temp_y);
	}
	else
	{
		cout << this->GetGatunek() << " wygrywa walke z " << inny_organizm->GetGatunek() << endl;
		inny_organizm->SetZywy(0);
		swiat.Usmierc(inny_organizm);
	}
}

void Roslina::RozprzestrzenSie()
{
	//funkcja rozprzestrzenia rosline z pewnym prawdopodobienstwem po sprawdzeniu czy nie stoi na wylosowanym polu inny organizm
	if (rand() % 100 < 100 * PRAWDOPODOBIENSWO_ROZPYLENIA)
	{
		int kierunek =rand() % 4;
		switch (kierunek % 4)
		{
		case 0:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 1, 0) == 0)
				this->Akcja();
			else
				if(swiat.CoTuStoi(this->GetPolozenieX()+1, this->GetPolozenieY())==NULL)
				{
					cout << this->GetGatunek() << " rozprzestrzenia sie" << endl;
					Organizm* nowa_roslina;
					nowa_roslina = this->KopiujOrganizm(this->GetPolozenieX() + 1, this->GetPolozenieY());
					swiat.DodajUrodzonyOrganizm(nowa_roslina, this->GetPolozenieX() + 1, this->GetPolozenieY());
				}
			break;
		case 1:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, 1) == 0)
				this->Akcja();
			else
				if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY()+1) == NULL)
				{
					cout << this->GetGatunek() << " rozprzestrzenia sie" << endl;
					Organizm* nowa_roslina;
					nowa_roslina = this->KopiujOrganizm(this->GetPolozenieX(), this->GetPolozenieY() + 1);
					swiat.DodajUrodzonyOrganizm(nowa_roslina, this->GetPolozenieX(), this->GetPolozenieY() + 1);
				}
			break;
		case 2:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), (-1), 0) == 0)
				this->Akcja();
			else
				if (swiat.CoTuStoi(this->GetPolozenieX() - 1, this->GetPolozenieY()) == NULL)
				{
					cout << this->GetGatunek() << " rozprzestrzenia sie" << endl;
					Organizm* nowa_roslina;
					nowa_roslina = this->KopiujOrganizm(this->GetPolozenieX() - 1, this->GetPolozenieY());
					swiat.DodajUrodzonyOrganizm(nowa_roslina, this->GetPolozenieX() - 1, this->GetPolozenieY());
				}
			break;
		case 3:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, (-1) ) == 0)
				this->Akcja();
			else
				if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() - 1) == NULL)
				{
					cout << this->GetGatunek() << " rozprzestrzenia sie" << endl;
					Organizm* nowa_roslina;
					nowa_roslina = this->KopiujOrganizm(this->GetPolozenieX(), this->GetPolozenieY() - 1);
					swiat.DodajUrodzonyOrganizm(nowa_roslina, this->GetPolozenieX(), this->GetPolozenieY() - 1);
				}
			break;
		}
	}
	
}