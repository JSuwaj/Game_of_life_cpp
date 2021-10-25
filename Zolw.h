#pragma once
#include "Zwierze.h"
class Zolw: public Zwierze
{
public:
	Zolw(int polozenie_x, int polozenie_y, Swiat& swiat);
	bool Unik(Organizm* atakujacy) override;
	void Akcja() override;
	Organizm* KopiujOrganizm(int x, int y) override;
	~Zolw() override;
};

