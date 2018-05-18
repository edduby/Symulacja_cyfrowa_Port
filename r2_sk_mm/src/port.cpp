/********************************************//**
* \file port.cpp
* \brief Definicja potru
* \author Maciej Maciejewski
* \date   2015-04-23
***********************************************/

#include "sc.h"
/////////////////////////////////////////////////



Port::Port(){
	miejsceJachty = 55;
	dzwigi = 6;
	tasmociagi = 4;
	rampy = 10;
	prowadnice = 8;
}


void Port::reset(){

	miejsceJachty = 55;
	dzwigi = 6;
	tasmociagi = 4;
	rampy = 10;
	prowadnice = 8;


}



//! Czy sa dostepne narzedzia by moc wplynac do portu
bool Port::czyMogeWplynac(Statek *wybrany){

	if (wybrany->typ == 1 && miejsceJachty > 0) { return 1; }
	if (wybrany->typ == 1 && miejsceJachty == 0) { return 0; }
	if ((rampy - wybrany->wymaganeRampy >= 0) &&
		(dzwigi - wybrany->wymaganeDzwigi >= 0) &&
		(tasmociagi - wybrany->wymaganeTasmociagi >= 0) &&
		(prowadnice - wybrany->wymaganeProwadnice >= 0))
												{ return 1; }
	
	return 0;

}





//! Zajecie narzedzi w porcie.
void Port::zajecieNarzedzi(Statek *wybrany){  
	wybrany->czasZajeciaNarzedzi = symulacja::sim_clock;
	if (wybrany->typ == 1) { miejsceJachty--; } //Dla jachtu zajmuje odzielnie
	else
	{
		rampy = rampy - wybrany->wymaganeRampy;
		dzwigi = dzwigi - wybrany->wymaganeDzwigi;
		tasmociagi = tasmociagi - wybrany->wymaganeTasmociagi;
		prowadnice = prowadnice - wybrany->wymaganeProwadnice;
		 
	}
}

void Port::wykorzystanieNarzedzi(Statek *wybrany){
	switch (wybrany->typ)
	{
	case 1: {
				symulacja::czasNarzedziMiejsceJachty += (symulacja::sim_clock - wybrany->czasZajeciaNarzedzi);
				break; }
	case 2: {
				symulacja::czasNarzedziRampy += (symulacja::sim_clock - wybrany->czasZajeciaNarzedzi)*wybrany->wymaganeRampy;
				break; }
	case 3: {
				symulacja::czasNarzedziRampy += (symulacja::sim_clock - wybrany->czasZajeciaNarzedzi)*wybrany->wymaganeRampy;
				break; }
	case 4: {
				symulacja::czasNarzedziDzwigi += (symulacja::sim_clock - wybrany->czasZajeciaNarzedzi)*wybrany->wymaganeDzwigi;
				break; }
	case 5: {
				symulacja::czasNarzedziProwadnice += (symulacja::sim_clock - wybrany->czasZajeciaNarzedzi)*wybrany->wymaganeProwadnice;
			break; }
	case 6: {
				symulacja::czasNarzedziTasmociagi+= (symulacja::sim_clock - wybrany->czasZajeciaNarzedzi)*wybrany->wymaganeTasmociagi;
				break; }
	}

	
	
	
	
	

}


void Port::zwolnienieNarzedzi(Statek *wybrany){
	wykorzystanieNarzedzi(wybrany);
	if (wybrany->typ == 1) { miejsceJachty++; }
	else
	{
		rampy = rampy + wybrany->wymaganeRampy;
		dzwigi = dzwigi + wybrany->wymaganeDzwigi;
		tasmociagi = tasmociagi + wybrany->wymaganeTasmociagi;
		prowadnice = prowadnice + wybrany->wymaganeProwadnice;
	}
}

void Port::czyJestPonownieZaladowany(Statek *wybrany){
	if (wybrany->typ == 1){
		return;
	}

	if (wybrany->ppz)
	{
		//podwajam czas	ladowania
	//	cout << "statek zostanie ponownie zaladowany" << endl;
	} 
	
	else{
		//brak ponownego zaladowania statku po zwolnieniu narzedzi czyli po tym trzeba policzyc czas jaki bedzie w kanale
		wybrany->masa = wybrany->masa * 0.30;
		wybrany->zanurzenie = wybrany->masa / 1000.0;
	}
}
