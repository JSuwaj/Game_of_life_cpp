#include "Lis.h"

#define INICJATYWA_LISA 7
#define SILA_LISA 3
#define ZASIEG_LISA 1
#define SYMBOL_LISA 'l'
#define GATUNEK_LISA "lis"

Lis::Lis(int polozenie_x, int polozenie_y, Swiat& swiat)
	:Zwierze(polozenie_x, polozenie_y, INICJATYWA_LISA, SILA_LISA, ZASIEG_LISA, SYMBOL_LISA, GATUNEK_LISA, swiat)
{

}

void Lis::Akcja()
{
	//funkcja sprawdza czy miejsce istnieje i czy nie stoi na nim organizm silniejszy i wtedy porusza tam lisa
		int kierunek = rand() % 4;
		switch (kierunek % 4)
		{
		case 0:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), zasieg_ruchu, 0) == 0)
				this->Akcja();
			else
				if (swiat.CoTuStoi(this->GetPolozenieX() + zasieg_ruchu, this->GetPolozenieY()))
				{
					if (swiat.CoTuStoi(this->GetPolozenieX() + zasieg_ruchu, this->GetPolozenieY())->GetSila() > this->GetSila())
					{
						if (this->SprawdzMiejscaDookola())
							this->Akcja();
					}
					else
						swiat.PoruszZwierza(this, zasieg_ruchu, 0);
				}
				else
					swiat.PoruszZwierza(this, zasieg_ruchu, 0);
			break;
		case 1:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, zasieg_ruchu) == 0)
				this->Akcja();
			else
				if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() + zasieg_ruchu))
				{
					if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() + zasieg_ruchu)->GetSila() > this->GetSila())
					{
						if (this->SprawdzMiejscaDookola())
							this->Akcja();
					}
					else
						swiat.PoruszZwierza(this, 0, zasieg_ruchu);
				}
				else
					swiat.PoruszZwierza(this, 0, zasieg_ruchu);
			break;
		case 2:

			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), (-1) * zasieg_ruchu, 0) == 0)
				this->Akcja();
			else
				if (swiat.CoTuStoi(this->GetPolozenieX() + (-1) * zasieg_ruchu, this->GetPolozenieY()))
				{
					if (swiat.CoTuStoi(this->GetPolozenieX() + (-1) * zasieg_ruchu, this->GetPolozenieY())->GetSila() > this->GetSila())
					{
						if (this->SprawdzMiejscaDookola())
							this->Akcja();
					}
					else
						swiat.PoruszZwierza(this, (-1) * zasieg_ruchu, 0);
				}
				else
					swiat.PoruszZwierza(this, (-1) * zasieg_ruchu, 0);
			break;
		case 3:
			if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, (-1) * zasieg_ruchu) == 0)
				this->Akcja();
			else
				if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() + (-1) * zasieg_ruchu))
				{
					if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() + (-1) * zasieg_ruchu)->GetSila() > this->GetSila())
					{
						if (this->SprawdzMiejscaDookola())
							this->Akcja();
					}
					else
						swiat.PoruszZwierza(this, 0, (-1) * zasieg_ruchu);
				}
				else
					swiat.PoruszZwierza(this, 0, (-1) * zasieg_ruchu);
			break;
		}
	

}

bool Lis::SprawdzMiejscaDookola()
{
	//funkcja sprawdza czy jest miejsce dookola lisa ktore istnieje i na ktorym mie stoi organizm od niego silniejszy
	//jest ona po to aby funkcja akcja nie wchodzila w nieskonczona petle
	if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), zasieg_ruchu, 0) != NULL)
	{
		if (swiat.CoTuStoi(this->GetPolozenieX() + zasieg_ruchu, this->GetPolozenieY()) == NULL)
			return true;
		else
			if (swiat.CoTuStoi(this->GetPolozenieX() + zasieg_ruchu, this->GetPolozenieY())->GetSila()<this->GetSila())
				return true;
	}
	if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, zasieg_ruchu) != NULL)
	{
		if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() + zasieg_ruchu) == NULL)
			return true;
		else
			if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() + zasieg_ruchu)->GetSila() < this->GetSila())
				return true;
	}
	if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), (-1) * zasieg_ruchu, 0) != NULL)
	{
		if (swiat.CoTuStoi(this->GetPolozenieX() + (-1) * zasieg_ruchu, this->GetPolozenieY()) == NULL)
			return true;
		else
			if (swiat.CoTuStoi(this->GetPolozenieX() + (-1) * zasieg_ruchu, this->GetPolozenieY())->GetSila() < this->GetSila())
				return true;
	}
	if (swiat.CzyMiejsceIstnieje(this->GetPolozenieX(), this->GetPolozenieY(), 0, (-1) * zasieg_ruchu) != NULL)
	{
		if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() + (-1) * zasieg_ruchu) == NULL)
			return true;
		else
			if (swiat.CoTuStoi(this->GetPolozenieX(), this->GetPolozenieY() + (-1) * zasieg_ruchu)->GetSila() < this->GetSila())
				return true;
	}
	return false;
}

Organizm* Lis::KopiujOrganizm(int x, int y)
{
	Organizm* nowy_organizm = new Lis(x, y, this->swiat);
	return nowy_organizm;
}

Lis::~Lis()
{

}