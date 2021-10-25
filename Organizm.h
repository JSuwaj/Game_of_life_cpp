#pragma once
#include "Swiat.h"
#include "Punkt.h"
#include <string>
using namespace std;
class Swiat;

class Organizm
{
protected:
	int polozenie_x;
	int polozenie_y;
	int inicjatywa;
	int sila;
	char symbol;
	string gatunek;
	int ile_zyje;
	bool zywy;
	Swiat  &swiat;
public:
	Organizm(int polozenie_x, int polozenie_y, int inicjatywa, int sila,char symbol,string gatunek, Swiat &swiat);
	int GetPolozenieX();
	int GetPolozenieY();
	int GetInicjatywa();
	int GetSila();
	char GetSymbol();
	string GetGatunek();
	bool GetZywy();
	int GetIleZyje();
	void DodajRok();
	void SetPolozenie(int x, int y);
	void SetInicjatywa(int inicjatywa);
	void SetSila(int sila);
	void SetZywy(bool zywy);
	void SetIleZyje(int ile_zyje);
	string ZapiszOrganizm();
	virtual void Akcja()=0;
	virtual void Kolizja(Organizm *inny_organizm)=0;
	virtual bool Unik(Organizm* atakujacy)=0;
	virtual void SetKierunekCzlowieka(char kierunek);
	virtual void Rysowanie();
	virtual Organizm* KopiujOrganizm(int x, int y) = 0;
	virtual ~Organizm();
};

