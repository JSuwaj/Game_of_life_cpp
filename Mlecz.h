#pragma once
#include "Roslina.h"
class Mlecz : public Roslina
{
public:
	Mlecz(int polozenie_x, int polozenie_y, Swiat& swiat);
	void Akcja() override;
	Organizm* KopiujOrganizm(int x, int y) override;
	~Mlecz() override;
};
