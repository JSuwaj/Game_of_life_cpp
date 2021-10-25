#pragma once
#include "Zwierze.h"
class Wilk:public Zwierze
{
public:
	Wilk(int polozenie_x, int polozenie_y, Swiat& swiat);

	Organizm* KopiujOrganizm(int x, int y) override;
	~Wilk() override;
};

