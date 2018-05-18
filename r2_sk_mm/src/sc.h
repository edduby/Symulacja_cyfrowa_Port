/********************************************//**
* \file sc.h
* \brief Definicja sc.
* \author Maciej Maciejewski
* \date   2015-04-23
***********************************************/
#ifndef SC_H
#define SC_H
//***********************************************
/////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <math.h>
//-----------------------------------------------
using namespace std;
//-----------------------------------------------
//-----------------------------------------------




#include "confidence_interval_estimation.h"

#include "statek.h"
#include "kanal.h"
#include "rng.h"
#include "kolejka.h"
#include "event_scheduling.h"

#include "zrodlo.h"
#include "port.h"
#include "events.h"


//-----------------------------------------------

//! Reset simulation statistics.
void resetStatystyk();




namespace symulacja{
	extern Port NowyPort;
	extern EventList agenda;
	extern Kanal KanalJeden1;
	extern Kanal KanalDwa2;
	extern Kanal KanalTrzy3;
	extern Kanal KanalCztery4;
	extern double sim_clock;
	extern double steady_start;
	extern Kolejka qPort;			
	extern Kolejka qMorze;
	extern int i;
	extern int liczbaWszystkich;
	extern int statkiWyplywajace;
	extern double czas;
	extern double wynik;
	extern int typ1;
	extern int typ2;
	extern int typ3;
	extern int typ4;
	extern int typ5;
	extern int typ6;
	extern int typ7;
	extern double typ1t;
	extern double typ2t;
	extern double typ3t;
	extern double typ4t;
	extern double typ5t;
	extern double typ6t;
	extern double tor1;
	extern double tor2;
	extern double tor3;
	extern double tor4;
	extern double maxCzasOczekiwania;
	extern double czasNarzedziMiejsceJachty;
	extern double czasNarzedziDzwigi;
	extern double czasNarzedziTasmociagi;
	extern double czasNarzedziRampy;
	extern double czasNarzedziProwadnice;
	extern int ileWygenerowalem;
	extern ofstream client_stats;
	extern ofstream statystyki_lambda;
	extern ofstream uniform;
	extern ofstream statystyki_lambda_srednia;
	extern ofstream expotential;
}

/////////////////////////////////////////////////
//***********************************************


#endif /*SC_H*/