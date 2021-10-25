#include "Zwierze.h"
#include "Swiat.h"
#include <iostream>
#include <string>

using namespace std;

Zwierze::Zwierze(int polozenie_x, int polozenie_y, int inicjatywa, int sila,  int zasieg_ruchu, char symbol, string gatunek, Swiat& swiat)
	:Organizm( polozenie_x, polozenie_y, inicjatywa, sila, symbol,  gatunek,swiat ), zasieg_ruchu(zasieg_ruchu)
{
	ile_zyje = 0;
}

Zwierze::~Zwierze() 
{

}

void Zwierze::Akcja() 
{
	int kierunek=rand()%4;
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
			swiat.PoruszZwierza(this, 0,  zasieg_ruchu);
		break;
	case 2:
		if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), (-1) * zasieg_ruchu, 0) == 0)
			this->Akcja();
		else
			swiat.PoruszZwierza(this, (-1)*zasieg_ruchu, 0);
		break;
	case 3:
		if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, (-1) * zasieg_ruchu) == 0)
			this->Akcja();
		else
			swiat.PoruszZwierza(this, 0 , (-1) * zasieg_ruchu);
		break;
	}

}

void Zwierze::Kolizja(Organizm* inny_organizm)
{
	if (inny_organizm->GetGatunek() == this->GetGatunek())
	{
		Rozmnazanie(inny_organizm->GetPolozenieX(), inny_organizm->GetPolozenieY());
	}
	else
	{
		if (this->GetSila() < inny_organizm->GetSila())
		{
			cout << inny_organizm->GetGatunek() << " wygrywa walke z " << this->GetGatunek()<< endl;
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
}

void Zwierze::SetZasieg(int zasieg)
{
	this->zasieg_ruchu = zasieg;
}

int Zwierze::GetZasieg()
{
	return zasieg_ruchu;
}

bool Zwierze::Unik(Organizm* atakujacy)
{
	return false;
}

void Zwierze::PoruszSie()
{

}

void Zwierze::Rozmnazanie(int x, int y)
{
	cout << this->GetGatunek() << " rozmnaza sie" << endl;
	Organizm* nowy_zwierzak;
	nowy_zwierzak=this->KopiujOrganizm(x, y);
	swiat.DodajUrodzonyOrganizm(nowy_zwierzak, x, y);
}
