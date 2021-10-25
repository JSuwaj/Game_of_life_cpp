#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina
{
public:
	WilczeJagody(int polozenie_x, int polozenie_y, Swiat& swiat);
	void Kolizja(Organizm* inny_organizm) override;
	Organizm* KopiujOrganizm(int x, int y) override;
	~WilczeJagody() override;
};

