#pragma once
#include "Zwierze.h"
class Antylopa:public Zwierze
{
public:
	Antylopa(int polozenie_x, int polozenie_y, Swiat& swiat);
	bool Unik(Organizm* atakujacy) override;
	Organizm* KopiujOrganizm(int x, int y) override;
	~Antylopa() override;
};

