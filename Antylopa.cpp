#include "Antylopa.h"

#define INICJATYWA_ANTYLOPY 4
#define SILA_ANTYLOPY 4
#define ZASIEG_ANTYLOPY 2
#define SYMBOL_ANTYLOPY 'a'
#define GATUNEK_ANTYLOPY "antylopa"

Antylopa::Antylopa(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Zwierze(polozenie_x, polozenie_y, INICJATYWA_ANTYLOPY, SILA_ANTYLOPY, ZASIEG_ANTYLOPY, SYMBOL_ANTYLOPY, GATUNEK_ANTYLOPY, swiat)
{

}

Organizm* Antylopa::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new Antylopa(x, y, this->swiat);
	return nowy_organizm;
}

bool Antylopa::Unik(Organizm* atakujacy)
{
	//w przypadku wylosowania opcji wynokania uniku funkcja szuka wolnego miejsca obok antylopy i przemieszcza ja na nie w przypadku braku wolnego miejsca antylopa sie nie przemieszcza
	int liczba;
	liczba = rand() % 2;
	if (liczba == 1)
	{
		Punkt punkt;
		punkt = swiat.WolnePole(this->GetPolozenieX(), this->GetPolozenieY());
		if (punkt.GetX() - 1 == this->GetPolozenieX() || punkt.GetX() + 1 == this->GetPolozenieX() || punkt.GetX() == this->GetPolozenieX())
			if (punkt.GetY() - 1 == this->GetPolozenieY() || punkt.GetY() + 1 == this->GetPolozenieY() || punkt.GetY()  == this->GetPolozenieY())
				if (punkt.GetX() >= 0 && punkt.GetY() >= 0)
				{
					cout << this->GetGatunek() << " wykonuje unik" << endl;
					int temp_x = this->GetPolozenieX();
					int temp_y = this->GetPolozenieY();
					swiat.PoruszZwierza(this, punkt.GetX()-this->GetPolozenieX(), punkt.GetY() - this->GetPolozenieY());
					swiat.PoruszZwierza(atakujacy, temp_x-atakujacy->GetPolozenieX(), temp_y-atakujacy->GetPolozenieY());
					return true;
				}
	}
	return false;
}

Antylopa::~Antylopa()
{

}