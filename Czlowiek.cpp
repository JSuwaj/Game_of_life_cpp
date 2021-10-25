#include "Czlowiek.h"

#define INICJATYWA_CZLOWIEKA 4
#define SILA_CZLOWIEKA 5
#define ZASIEG_CZLOWIEKA 1
#define SYMBOL_CZLOWIEKA 'c'
#define GATUNEK_CZLOWIEKA "czlowiek"
#define STARTOWY_CZAS_OD_UMIEJETNOSCI 10

#define GORA 72
#define DOL 80
#define LEWO 75
#define PRAWO 77

Czlowiek::Czlowiek(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Zwierze(polozenie_x, polozenie_y, INICJATYWA_CZLOWIEKA, SILA_CZLOWIEKA, ZASIEG_CZLOWIEKA, SYMBOL_CZLOWIEKA, GATUNEK_CZLOWIEKA, swiat),czas_od_aktywowania_umiejetnosci(STARTOWY_CZAS_OD_UMIEJETNOSCI),kierunek(NULL)
{

}

void Czlowiek::Akcja()
{
	//na podstawie czasu od uzycia umiejetnosci funkcja zmienia zasieg czlowieka
	int temp_czas_umiejetnosci = swiat.GetUmiejetnosc();
	if (temp_czas_umiejetnosci == 1 || temp_czas_umiejetnosci == 2 || temp_czas_umiejetnosci == 3)
		this->SetZasieg(2);
	if (temp_czas_umiejetnosci == 4 || temp_czas_umiejetnosci == 5)
	{
		int temp = rand() % 2;
		if(temp==1)
			this->SetZasieg(2);
		else
			this->SetZasieg(1);
	}
	if (temp_czas_umiejetnosci >= 6)
		this->SetZasieg(1);
	switch (this->GetKierunek())
	{
	case DOL:
		if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), zasieg_ruchu, 0) != 0)
			swiat.PoruszZwierza(this, zasieg_ruchu, 0);
		break;
	case PRAWO:
		if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, zasieg_ruchu) != 0)
			swiat.PoruszZwierza(this, 0, zasieg_ruchu);
		break;
	case GORA:
		if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), (-1) * zasieg_ruchu, 0) != 0)
			swiat.PoruszZwierza(this, (-1) * zasieg_ruchu, 0);
		break;
	case LEWO:
		if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, (-1) * zasieg_ruchu) != 0)
			swiat.PoruszZwierza(this, 0, (-1) * zasieg_ruchu);
		break;
	case 'e':
		this->UmiejetnoscSpecjalna();
		break;
	}
}

void Czlowiek::SetKierunekCzlowieka(char kierunek)
{
	this->kierunek = kierunek;
}

char Czlowiek::GetKierunek()
{
	return kierunek;
}

void Czlowiek::SetCzasUmiejetnosci(int czas_umiejetnosci)
{
	this->czas_od_aktywowania_umiejetnosci = czas_umiejetnosci;
}

int Czlowiek::GetCzasUmiejetnosci()
{
	return czas_od_aktywowania_umiejetnosci;
}

void Czlowiek::UmiejetnoscSpecjalna()
{
	if (swiat.GetUmiejetnosc() > 10)
	{
		swiat.SetUmiejetnosc(0);
		cout << "uzyto umiejetnosc specjalna czlowieka" << endl;
	}
}

Organizm* Czlowiek::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new Czlowiek(x, y, this->swiat);
	return nowy_organizm;
}

Czlowiek::~Czlowiek()
{

}