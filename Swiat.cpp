#include "Swiat.h"
#include "Organizm.h"
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>

#include "Wilk.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "BarszczSosnowskiego.h"
#include "WilczeJagody.h"
#include "Czlowiek.h"
#include "Punkt.h"
using namespace std;


#define L_STARTOWA_WILKOW 4
#define L_STARTOWA_OWIEC 4
#define L_STARTOWA_ANTYLOP 4
#define L_STARTOWA_ZOLWI 4
#define L_STARTOWA_LISOW 4
#define L_STARTOWA_TRAWY 3
#define L_STARTOWA_MLECZY 2
#define L_STARTOWA_GUARANY 3
#define L_STARTOWA_BARSZCZU 3
#define L_STARTOWA_JAGOD 3
#define MAX_INICJATYWA 7

Swiat::Swiat(int wysokosc, int szerokosc)
	:wysokosc(wysokosc), szerokosc(szerokosc)
{
	InicjujSwiat();
	RysujSwiat();	
	czas_umiejetnosci_czlowieka = 10;
}

void Swiat::InicjujSwiat()
{
	//funkcja rozmieszcza organizmy w losowych miejscach oraz inicjalizuje zmienne
	for (int i = 0; i < wysokosc; i++)
	{
		mapa_organizmy.push_back(vector<Organizm*>());
		for (int j = 0; j < szerokosc; j++)
		{
			mapa_organizmy[i].push_back(NULL);
			mapa_organizmy[i][j] = NULL;

		}
	}

	UtworzPoczatkowyOrganizm("czlowiek");
	for (int i = 0; i < L_STARTOWA_WILKOW; i++)
	{
		UtworzPoczatkowyOrganizm("wilk");
	}
	for (int i = 0; i < L_STARTOWA_OWIEC; i++)
	{
		UtworzPoczatkowyOrganizm("owca");
	}
	for (int i = 0; i < L_STARTOWA_ANTYLOP; i++)
	{
		UtworzPoczatkowyOrganizm("antylopa");
	}
	for (int i = 0; i < L_STARTOWA_ZOLWI; i++)
	{
		UtworzPoczatkowyOrganizm("zolw");
	}
	for (int i = 0; i < L_STARTOWA_LISOW; i++)
	{
		UtworzPoczatkowyOrganizm("lis");
	}
	for (int i = 0; i < L_STARTOWA_TRAWY; i++)
	{
		UtworzPoczatkowyOrganizm("trawa");
	}
	for (int i = 0; i < L_STARTOWA_MLECZY; i++)
	{
		UtworzPoczatkowyOrganizm("mlecz");
	}
	for(int i = 0; i < L_STARTOWA_GUARANY; i++)
	{
		UtworzPoczatkowyOrganizm("guarana");
	}
	for (int i = 0; i < L_STARTOWA_BARSZCZU; i++)
	{
		UtworzPoczatkowyOrganizm("barszcz");
	}
	for (int i = 0; i < L_STARTOWA_JAGOD; i++)
	{
		UtworzPoczatkowyOrganizm("jagody");
	}
	
}

Organizm* Swiat::UtworzPoczatkowyOrganizm(string gatunek)
{
	//funkcja tworzy organizm podczas inicjalizacji swiata
	Organizm* organizm = NULL;
	int organizm_x = rand() % wysokosc;
	int organizm_y = rand() % szerokosc;
	while (mapa_organizmy[organizm_x][organizm_y] != NULL)
	{
		organizm_x = rand() % wysokosc;
		organizm_y = rand() % szerokosc;
	}
	if (gatunek == "wilk")
	{
		organizm = new Wilk( organizm_x, organizm_y,*this);
	}
	if (gatunek == "owca")
	{
		organizm = new Owca(organizm_x, organizm_y, *this);
	}
	if (gatunek == "antylopa")
	{
		organizm = new Antylopa(organizm_x, organizm_y, *this);
	}
	if (gatunek == "zolw")
	{
		organizm = new Zolw(organizm_x, organizm_y, *this);
	}
	if (gatunek == "lis")
	{
		organizm = new Lis(organizm_x, organizm_y, *this);
	}
	if (gatunek == "trawa")
	{
		organizm = new Trawa(organizm_x, organizm_y, *this);
	}
	if (gatunek == "mlecz")
	{
		organizm = new Mlecz(organizm_x, organizm_y, *this);
	}
	if (gatunek == "guarana")
	{
		organizm = new Guarana(organizm_x, organizm_y, *this);
	}
	if (gatunek == "barszcz")
	{
		organizm = new BarszczSosnowskiego(organizm_x, organizm_y, *this);
	}
	if (gatunek == "jagody")
	{
		organizm = new WilczeJagody(organizm_x, organizm_y, *this);
	}
	if (gatunek == "czlowiek")
	{
		organizm = new Czlowiek(organizm_x, organizm_y, *this);
	}
	DodajOrganizm(organizm, organizm_x, organizm_y);
	return organizm;
}

bool Swiat::WykonajRuch()
{
	//funcja wykonuje pojedyncza ture symulacji
	int znak = _getch();
	znak= _getch();
	system("cls");
	cout << "Jakub Suwaj 179927" << endl << endl;
	if (znak == 'q')
		return 0;
	if (znak == 'z')
	{
		this->ZapiszStanGry();
		return 1;
	}
	if (znak == 'w')
	{
		this->WczytajStanGry();
		return 1;
	}
	if(this->ZnajdzCzlowieka()!=NULL)
		this->ZnajdzCzlowieka()->SetKierunekCzlowieka(znak);
	for (int i = MAX_INICJATYWA; i >= 0; i--)
	{
		for (Organizm* organizm : v_organizmy)
		{
			if (organizm->GetInicjatywa() == i && organizm->GetZywy() == 1)
			{
				organizm->Akcja();
			}
		}
	}
	this->SetUmiejetnosc(czas_umiejetnosci_czlowieka + 1);
	this->AktualizujOrganizmy();
	for (Organizm* organizm : nowe_organizmy)
	{
		delete[] organizm;
	}
	nowe_organizmy.clear();
	this->DodajLata();
	return 1;
}

void Swiat::DodajLata()
{
	//funkcja dodaje organizmom jeden rok zycia 
	for (Organizm* organizm : v_organizmy)
	{
		organizm->DodajRok();
	}
}

void Swiat::RysujSwiat()
{
	for (int i = 0; i < wysokosc +2; i++)
	{
		for (int j = 0; j < szerokosc +2; j++)
		{
			if (i == 0 || i == wysokosc + 1 || j == 0 || j == szerokosc + 1)
				cout << "*";
			else
				if (mapa_organizmy[i - 1][j - 1] == NULL)
					cout << ".";
				else
					cout << mapa_organizmy[i - 1][j - 1]->GetSymbol();

		}
		cout << endl;
	}

}

Punkt Swiat::WolnePole(int x, int y)
{
	//funkcja szuka najblizszego wolnego pola od podanych kordynatow
	int temp_x = x;
	int temp_y = y;
	int licznik_powtorzen = 0, granica = 0, kolo = 1;
	while (mapa_organizmy[temp_x][temp_y] != NULL)
	{
		for (int i = x-kolo; i < x+kolo;  i++)
		{
			for (int j =y-kolo; j < y + kolo; j++)
			{
				if (i >= 0 && j >= 0 && i < wysokosc && j < szerokosc)
				{
					if (mapa_organizmy[i][j] == NULL)
					{
						temp_x = i;
						temp_y = j;
						i= x + kolo;
						j = y + kolo;
					}
				}
			}
		}
		kolo++;
		if (kolo >= wysokosc && kolo >= szerokosc)
		{
			temp_x = -1;
			temp_y = -1;
			break;
		}
	}
	Punkt punkt;
	punkt.SetPunkt(temp_x, temp_y);
	return punkt;
	
}

void Swiat::DodajOrganizm(Organizm* nowy_organizm, int x, int y)
{
	//funkcja tworzy organizmy przy tworzeniu swiata oraz wczytywaniu go z pliku
	Punkt punkt;
	punkt =this->WolnePole(x, y);
	if (punkt.GetX() != -1 && punkt.GetY() != -1)
	{
		nowy_organizm->SetPolozenie(punkt.GetX(), punkt.GetY());
		mapa_organizmy[punkt.GetX()][punkt.GetY()] = nowy_organizm;
		v_organizmy.push_back(nowy_organizm);
	}

}

void Swiat::DodajUrodzonyOrganizm(Organizm* nowy_organizm, int x, int y)
{
	//funkcja dodaje organizmy do vectora nowo urodzonych organizmow
	Punkt punkt;
	punkt = this->WolnePole(x, y);
	if (punkt.GetX() != -1 && punkt.GetY() != -1)
	{
		nowy_organizm->SetPolozenie(punkt.GetX(), punkt.GetY());
		nowe_organizmy.push_back(nowy_organizm);
	}
}

void Swiat::SetSzerokosc(int szerokosc)
{
	this->szerokosc = szerokosc;
}

void Swiat::SetWysokosc(int wyskokosc)
{
	this->wysokosc = wyskokosc;
}

int Swiat::GetSzerokosc()
{
	return szerokosc;
}

int Swiat::GetWysokosc()
{
	return wysokosc;
}

void Swiat::AktualizujOrganizmy()
{
	//funkcja dodaje nowo urodzone organizmy do swiata gry
	//w przypadku gdy jeden nowo urodzony organizm zajal pole kolejnego ten kolejny nie zostaje dodany
	int i = 0;
	for (Organizm* organizm : nowe_organizmy)
	{
		if (mapa_organizmy[organizm->GetPolozenieX()][organizm->GetPolozenieY()] == NULL)
		{
			mapa_organizmy[organizm->GetPolozenieX()][organizm->GetPolozenieY()] = organizm;
			v_organizmy.push_back(organizm);
			nowe_organizmy[i] = NULL;
		}
		i++;
	}
}

void Swiat::PoruszZwierza(Organizm* chodzacy_organizm, int dx, int dy)
{
	//funkcja wykonuje ruch poszczegolnego zwierzecia
	int docelowe_x, docelowe_y;
	docelowe_x = chodzacy_organizm->GetPolozenieX() + dx;
	docelowe_y = chodzacy_organizm->GetPolozenieY() + dy;
	if (mapa_organizmy[docelowe_x][docelowe_y] != NULL)
	{
		if (CoTuStoi(docelowe_x, docelowe_y)->Unik(chodzacy_organizm) == false)
		{
			CoTuStoi(docelowe_x, docelowe_y)->Kolizja(chodzacy_organizm);
			if (chodzacy_organizm->GetPolozenieX() == docelowe_x && chodzacy_organizm->GetPolozenieY() == docelowe_y)
			{
				mapa_organizmy[docelowe_x][docelowe_y] = chodzacy_organizm;
				mapa_organizmy[docelowe_x - dx][docelowe_y - dy] = NULL;
			}
		}
	}
	else
	{
		mapa_organizmy[chodzacy_organizm->GetPolozenieX()][chodzacy_organizm->GetPolozenieY()] = NULL;
		chodzacy_organizm->SetPolozenie(docelowe_x, docelowe_y);
		mapa_organizmy[docelowe_x][docelowe_y] = chodzacy_organizm;
	}
}

bool Swiat::CzyMiejsceIstnieje(int x, int y, int dx, int dy)
{
	//funkcja sprawdza czy punkt lezy w obrebie mapy
	if (x + dx < wysokosc && y + dy < szerokosc && x + dx>=0 && y + dy>=0)
		return 1;
	else
		return 0;
}


Organizm* Swiat::ZnajdzCzlowieka()
{
	for (Organizm* organizm : v_organizmy)
	{
		if (organizm->GetGatunek() == "czlowiek")
			return organizm;
	}
	return NULL;
}

void Swiat::Usmierc(Organizm* niezywy_organizm)
{
	cout << "umiera " << niezywy_organizm->GetGatunek() << endl;
	for (vector<int>::size_type i = 0; i != v_organizmy.size(); i++)
	{
		if (v_organizmy[i]->GetPolozenieX() == niezywy_organizm->GetPolozenieX() && v_organizmy[i]->GetPolozenieY() == niezywy_organizm->GetPolozenieY())
		{
			mapa_organizmy[niezywy_organizm->GetPolozenieX()][niezywy_organizm->GetPolozenieY()] = NULL;
			v_organizmy.erase(v_organizmy.begin() + i);
			break;
		}
	}
}

Organizm* Swiat::CoTuStoi(int x, int y)
{
	//funkcja sprawdza jaki organizm stoi na podanym miejscu i go zwraca
	if (this->CzyMiejsceIstnieje(x, y, 0, 0))
	{
		for (vector<int>::size_type i = 0; i != v_organizmy.size(); i++)
		{
			if (v_organizmy[i]->GetPolozenieX() == x && v_organizmy[i]->GetPolozenieY() == y)
				return v_organizmy[i];
		}
	}
	return NULL;
}

void Swiat::SetUmiejetnosc(int czas_umiejetnosci)
{
	this->czas_umiejetnosci_czlowieka = czas_umiejetnosci;
}

int Swiat::GetUmiejetnosc()
{
	return czas_umiejetnosci_czlowieka;
}

void Swiat::ZapiszStanGry()
{
	ofstream plik;
	plik.open("zapis.txt");
	plik << wysokosc <<'_'<< szerokosc << '_' << czas_umiejetnosci_czlowieka << '\n';
	for (Organizm* organizm : v_organizmy)
		plik << organizm->ZapiszOrganizm();
	plik << '!';
	plik.close();
	cout << "zapisano swiat do pliku" << endl;

}

void Swiat::WczytajStanGry()
{
	v_organizmy.clear();
	mapa_organizmy.clear();
	nowe_organizmy.clear();
	ifstream plik("zapis.txt");
	string linia;
	int temp_wysokosc, temp_szerokosc,temp_umiejetnosc;
	char c;
	plik >> temp_wysokosc >> c >> temp_szerokosc >> c >>temp_umiejetnosc;
	this->SetSzerokosc(temp_szerokosc);
	this->SetWysokosc(temp_wysokosc);
	this->SetUmiejetnosc(temp_umiejetnosc);
	for (int i = 0; i < temp_wysokosc; i++)
	{
		mapa_organizmy.push_back(vector<Organizm*>());
		for (int j = 0; j < temp_szerokosc; j++)
		{
			mapa_organizmy[i].push_back(NULL);
			mapa_organizmy[i][j] = NULL;

		}
	}
	bool temp = true;
	while (temp)
	{
		temp = WczytajOrganizm(plik);
	}
	plik.close();
	cout << "wczytano swiat z pliku" << endl;
}

bool Swiat::WczytajOrganizm(ifstream& plik)
{
	char symbol, c;
	int sila, polozenie_x, polozenie_y,ile_zyje;
	plik >> symbol;
	if (symbol == '!')
		return false;
	plik >> c >> polozenie_x >> c >> polozenie_y >> c >> sila >> c >> ile_zyje;
	Organizm* organizm=NULL;
	if (symbol == 'w')
	{
		organizm = new Wilk(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 'o')
	{
		organizm = new Owca(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 'a')
	{
		organizm = new Antylopa(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 'z')
	{
		organizm = new Zolw(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 'l')
	{
		organizm = new Lis(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 't')
	{
		organizm = new Trawa(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 'm')
	{
		organizm = new Mlecz(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 'g')
	{
		organizm = new Guarana(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 'b')
	{
		organizm = new BarszczSosnowskiego(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 'j')
	{
		organizm = new WilczeJagody(polozenie_x, polozenie_y, *this);
	}
	if (symbol == 'c')
	{
		organizm = new Czlowiek(polozenie_x, polozenie_y, *this);
	}
	DodajOrganizm(organizm, polozenie_x, polozenie_y);
	organizm->SetSila(sila);
	organizm->SetIleZyje(ile_zyje);
	return true;
}

Swiat::~Swiat()
{
	
	for (Organizm* organizm : v_organizmy)
	{
		delete[] organizm;
	}

}
