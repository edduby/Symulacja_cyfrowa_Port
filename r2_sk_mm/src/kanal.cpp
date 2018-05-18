
/********************************************//**
 * \file kanal.cpp
 * \brief Definicja kanalu.
 * \author Maciej Maciejewski
 * \date 2015-04-23
 ***********************************************/
#include "sc.h"
											  /////////////////////////////////////////////////
bool Kanal::zajmujeKanalJesli(Statek *wybrany) {//!< Zajecie kanalu pod warunkiem wolnego kanalu i wystaczajacego zanurzenia
		if (glebokosc >= wybrany->zanurzenie && zajetosc == 0) { zajetosc = 1; return 1; }
		else { return 0; }
}
void Kanal::zajecieKanaluDo(Statek* nowy) {//!< Zajecie kanalu
										   //cout << "zajecie z kanalu:" << numer << " numerksnalu:" << nowy->numerKanalu <<
	"\n";
	pierwszy = nowy;
	zajetosc = 1;
	doCzyZ = 1;
}
void Kanal::zajecieKanaluZ(Statek* nowy) {//!< Zajecie kanalu
										  //cout << "zajecie z kanalu:"<<numer<<" numerksnalu:"<<nowy->numerKanalu<<"\n";
	pierwszy = nowy;
	zajetosc = 1;
	doCzyZ = 0;
	nowy->numerKanalu = numer;
}
void Kanal::zwolnienieKanalu(Statek* &nowy) {//!< Zwolnienie kanalu
	czasOstatniegoUzycia = symulacja::sim_clock;
	pierwszy = NULL;
	zajetosc = 0;
	nowy->numerKanalu = 0;
}
void Kanal::reset() {
	zajetosc = 0;
	czasZajetosci = 0;
	czasOstatniegoUzycia = 0;
	if (pierwszy != NULL) {
		delete pierwszy;
	}
	pierwszy = NULL;
}