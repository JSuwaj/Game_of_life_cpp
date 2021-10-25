#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
public:
	Guarana(int polozenie_x, int polozenie_y, Swiat& swiat);
	void Kolizja(Organizm* inny_organizm) override;
	Organizm* KopiujOrganizm(int x, int y) override;
	~Guarana() override;
};

