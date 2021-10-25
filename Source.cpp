#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio.h>
#include "Swiat.h"
#include "Organizm.h"
using namespace std;


int main() {
	srand(time(NULL));
	cout << "Jakub Suwaj 179927" << endl << endl;
	cout << "z-zapisz  w-wczytaj  e-uzyj umiejetnosci  q-zakoncz dzialanie programu  strzalki-poruszanie" << endl;
	int wysokosc, szerokosc;
	cout << "podaj wysokosc" << endl;
	cin >> wysokosc;
	cout << "podaj szerokosc" << endl;
	cin >> szerokosc;
	Swiat swiat(wysokosc,szerokosc);
	int temp = 1;
	while (temp)
	{
		temp = swiat.WykonajRuch();

		swiat.RysujSwiat();
	}
	return 0;
}

