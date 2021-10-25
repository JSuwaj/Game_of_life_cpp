#pragma once
#include "Zwierze.h"
class Lis:public Zwierze
{
public:
	Lis(int polozenie_x, int polozenie_y, Swiat& swiat);
	bool SprawdzMiejscaDookola();
	void Akcja() override;
	Organizm* KopiujOrganizm(int x, int y) override;
	~Lis() override;
};

