#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
private:
	char kierunek;
	int czas_od_aktywowania_umiejetnosci;
public:
	Czlowiek(int polozenie_x, int polozenie_y, Swiat& swiat);
	void Akcja() override;
	void SetKierunekCzlowieka(char kierunek) override;
	char GetKierunek();
	void SetCzasUmiejetnosci(int czas_umiejetnosci);
	int GetCzasUmiejetnosci();
	void UmiejetnoscSpecjalna();
	Organizm* KopiujOrganizm(int x, int y) override;
	~Czlowiek() override;
};


