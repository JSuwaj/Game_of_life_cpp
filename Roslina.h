#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
protected:
	double szansa_rozpylenia;
public:
	Roslina(int polozenie_x, int polozenie_y, int inicjatywa, int sila, double szansa_rozpylenia, char symbol, string gatunek, Swiat& swiat);
	virtual void Akcja() override;
	void Kolizja(Organizm* inny_organizm) override;
	virtual bool Unik(Organizm* atakujacy) override;
	void RozprzestrzenSie();
	~Roslina();
};

