#pragma once
#include "Zwierze.h"
class Owca :public Zwierze
{
public:
	Owca(int polozenie_x, int polozenie_y, Swiat& swiat);

	Organizm* KopiujOrganizm(int x, int y) override;
	~Owca() override;
};

