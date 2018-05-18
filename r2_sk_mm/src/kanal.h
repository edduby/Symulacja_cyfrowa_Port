/********************************************//**
* \file kanal.h
* \brief Definicja obiektu kanalu
* \author Maciej Maciejewski
* \date   2015-04-23
***********************************************/
#ifndef KANAL_H
#define KANAL_H
/////////////////////////////////////////////////
/*! \brief kanal.
*
*	Implementacja kanalu.
*
*/


class Kanal{
	//! Parametry kanalu.
public:
	bool zajetosc;
	int glebokosc;
	double czasZajetosci;
	bool doCzyZ; //<! Do =1 z= 0 
	int kt;
	int numer;
	double czasOstatniegoUzycia;
	Statek *pierwszy;
	

	Kanal(){}//!<Konstruktor domyslny
	~Kanal(){}//!<destruktor domyslny
	Kanal(int glebokosc2, int numer2){ glebokosc = glebokosc2; zajetosc = 0, numer = numer2; czasZajetosci = 0; }//!<Konsturktor
	void reset();
	bool zajmujeKanalJesli(Statek *wybrany);//!< Czy ma wymagana glebokosc jezeli tak to zajmuje kanal
	void zajecieKanaluDo(Statek* nowy);//!< Zajecie kanalu Do
	void zajecieKanaluZ(Statek* nowy);//!< Zajecie kanalu Z
	void zwolnienieKanalu(Statek* &nowy);//!< Zwolnienie kanalu
	void doKolejki();//<!Dodanie kanalu
	
private:




};

/////////////////////////////////////////////////
//***********************************************
#endif /*KANAL_H*/ 