#include <iostream>
#include <string>
#include "Organizm.h"
#include "Punkt.h"
using namespace std;


Organizm::Organizm(int polozenie_x,int polozenie_y,int inicjatywa,int sila,char symbol, string gatunek, Swiat& swiat)
	: polozenie_x(polozenie_x), polozenie_y(polozenie_y), sila(sila), inicjatywa(inicjatywa),symbol(symbol), swiat(swiat), gatunek(gatunek)
{

	zywy = 1;
}

Organizm::~Organizm()
{

}


int Organizm::GetPolozenieX()
{
	return polozenie_x;
}

int Organizm::GetPolozenieY()
{
	return polozenie_y;
}

int Organizm::GetInicjatywa()
{
	return inicjatywa;
}

int Organizm::GetSila()
{
	return sila;
}

void Organizm::SetPolozenie(int x,int y)
{
	this->polozenie_x = x;
	this->polozenie_y = y;
}

char Organizm::GetSymbol()
{
	return symbol;
}

string Organizm::GetGatunek()
{
	return gatunek;
}

bool Organizm::GetZywy()
{
	return zywy;
}

void Organizm::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}

void Organizm::SetSila(int sila)
{
	this->sila = sila;
}

void Organizm::SetZywy(bool zywy)
{
	this->zywy = zywy;
}

void Organizm::SetIleZyje(int ile_zyje)
{
	this->ile_zyje = ile_zyje;
}

void Organizm::Rysowanie()
{
	cout << symbol;
}

int Organizm::GetIleZyje()
{
	return ile_zyje;
}

void Organizm::DodajRok()
{
	ile_zyje++;
}

void Organizm::SetKierunekCzlowieka(char kierunek)
{
	cout << "blad, to nie jest czlowiek" << endl;
}

string Organizm::ZapiszOrganizm()
{
	string zapis;
	zapis+= this->GetSymbol();
	zapis += '_';
	zapis += to_string(this->GetPolozenieX());
	zapis += '_';
	zapis += to_string(this->GetPolozenieY());
	zapis += '_';
	zapis += to_string(this->GetSila());
	zapis += '_';
	zapis += to_string(this->GetIleZyje());
	zapis += '\n';
	return zapis;
}
