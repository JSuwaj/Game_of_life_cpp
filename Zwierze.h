#pragma once
#include "Organizm.h"
#include <string>

class Zwierze : public Organizm
{
protected:
	int zasieg_ruchu;
public:
	Zwierze(int polozenie_x, int polozenie_y, int inicjatywa, int sila,int zasieg_ruchu, char symbol, string gatunek, Swiat& swiat);
	virtual void Akcja() override;
	void Kolizja(Organizm* inny_organizm) override;
	void SetZasieg(int zasieg);
	int GetZasieg();
	void PoruszSie();
	void Rozmnazanie(int x, int y);
	virtual bool Unik(Organizm* atakujacy) override;
	~Zwierze() override;





};

