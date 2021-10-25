#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Organizm.h"
#include "Punkt.h"


using namespace std;

class Organizm;


class Swiat
{
private:

	vector <Organizm*> v_organizmy;
	vector <Organizm*> nowe_organizmy;
	std::vector< std::vector< Organizm* > > mapa_organizmy;
	int wysokosc;
	int szerokosc;
	int czas_umiejetnosci_czlowieka;
	void InicjujSwiat();
	void DodajOrganizm(Organizm* nowy_organizm, int x, int y);
	void AktualizujOrganizmy();
	void DodajLata();
	void ZapiszStanGry();
	void WczytajStanGry();
	bool WczytajOrganizm(ifstream& plik);
	Organizm* ZnajdzCzlowieka();
	Organizm* UtworzPoczatkowyOrganizm(string gatunek);

public:
	Swiat(int wysokosc, int szerokosc);
	void RysujSwiat();
	void DodajUrodzonyOrganizm(Organizm* nowy_organizm, int x, int y);
	void PoruszZwierza(Organizm* chodzacy_organizm, int dx, int dy);
	void Usmierc(Organizm* niezywy_organizm);
	Punkt WolnePole(int x,int y);
	bool WykonajRuch();
	void SetSzerokosc(int szerokosc);
	void SetWysokosc(int wyskokosc);
	int GetSzerokosc();
	int GetWysokosc();
	void SetUmiejetnosc(int czas_umiejetnosci);
	int GetUmiejetnosc();
	bool CzyMiejsceIstnieje(int x, int y, int dx, int dy);
	Organizm* CoTuStoi(int x,int y);
	~Swiat();



};

