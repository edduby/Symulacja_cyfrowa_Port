#include "sc.h"


using namespace std;
/********************************************//**
* \file sc.cpp
* \brief Definicja klasy sc
* \author Maciej Maciejewski
* \date   2015-04-23
***********************************************/
namespace symulacja{
	double sim_clock = 0.0;
	double steady_start = 0.0;
	EventList agenda;
	Port NowyPort;
	Kanal KanalJeden1(8,1);
	Kanal KanalDwa2(12,2);
	Kanal KanalTrzy3(20,3);
	Kanal KanalCztery4(25,4);
	Kolejka qPort;
	Kolejka qMorze;
	int i=0; 
	int statkiWyplywajace=0;
	double czas=0.;
	double wynik=0.;
	int typ1 = 0;
	int typ2 = 0;
	int typ3 = 0;
	int typ4 = 0;
	int typ5 = 0;
	int typ6 = 0;
	int typ7 = 0;
	double typ1t=0;
	double typ2t = 0;
	double typ3t = 0;
	double typ4t = 0;
	 double typ5t = 0;
	 double typ6t = 0;
	 double tor1 = 0;
	 double tor2 = 0;
	 double tor3 = 0;
	 double tor4 = 0;
	 double maxCzasOczekiwania = 0;
	 double czasNarzedzi=0;
	 double czasNarzedziMiejsceJachty = 0;
	 double czasNarzedziDzwigi = 0;
	 double czasNarzedziTasmociagi = 0;
	 double czasNarzedziRampy = 0;
	 double czasNarzedziProwadnice = 0;
	 int liczbaWszystkich = 0;
	 int ileWygenerowalem = 0;
	
	 ofstream client_stats;
	 ofstream statystyki_lambda;
	  ofstream uniform;
	  ofstream statystyki_lambda_srednia;
	  ofstream expotential;
}



int main()
{
	Symulacja();
}