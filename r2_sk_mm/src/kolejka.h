#ifndef KOLEJKA_H
#define KOLEJKA_H
class Port;
/********************************************//**
* \file kolejka.h
* \brief Definicja kolejki
* \author Maciej Maciejewski
* \date   2015-04-23
***********************************************/
/////////////////////////////////////////////////
/*! \brief Kolejka.
*
*	Implementacja kolejki.
*
*/
class Kolejka{


private:
	Statek *pierwszy;

public:
	void statekZajmujeMiejsce(Statek *StatekWplywajacy); //!< Zajecie miejsca
	void statekZwalniaMiejsce(Statek *StatekZwalniajacy); //!< Zwolnienie miejsca przez statek
	//Statek ktoryStatekZwalniaMiejsce(Kolejka KolejkaStatkow, Kanal &pierwszy, Kanal &drugi, Kanal &trzeci, Kanal &czwarty);
	void wyswietl();//!< Wyswietlenie listy
	Statek* wyborStatkuDoZwolnienia(Kanal &pierwszyK, Kanal &drugiK, Kanal &trzeciK, Kanal &czwartyK, Port &MojPort);	//<! Wybranie statku ktory moze zwolnic kolejke 
	Statek* wyborStatkuDoZwolnieniaZportu(Kanal &pierwszyK, Kanal &drugiK, Kanal &trzeciK, Kanal &czwartyK, Port &MojPort);
	bool czyPusta();//<! Sprawdzenie czy w kolejce istnieje statek
	void sprIlewKolejce();
	//Statek* szukaj(int numer2);
	void reset();
	void statekZwalniaMiejsceNaZwasze(Statek *StatekZwalniajacy);

	//! Konstruktor
	Kolejka();

	//! Destruktor
	~Kolejka(){
		//Statek *ostatni;
		///Statek *temp;
	//	if (pierwszy == NULL) { return; }
	//	for (ostatni = pierwszy->nastepny; ostatni != pierwszy; ostatni = temp)
	//	{
	//		temp = ostatni->nastepny;
	//		delete ostatni;

	//	}
		//cout << "destruktor";
	//	delete pierwszy;
	}



};

/////////////////////////////////////////////////
//***********************************************
#endif /*KOLEJKA_H*/ 