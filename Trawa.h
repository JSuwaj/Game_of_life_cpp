#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
public:
	Trawa(int polozenie_x, int polozenie_y, Swiat& swiat);
	Organizm* KopiujOrganizm(int x, int y) override;
	~Trawa() override;
};

