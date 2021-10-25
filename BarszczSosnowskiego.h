#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(int polozenie_x, int polozenie_y, Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* inny_organizm) override;
	Organizm* KopiujOrganizm(int x, int y) override;
	~BarszczSosnowskiego() override;
};

