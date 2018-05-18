
/********************************************//**
* \file kolejka.cpp
* \brief Definicja kolejki
* \author Maciej Maciejewski
* \date   2015-04-23
***********************************************/
#include "sc.h"
///////////////////////////////////////////////// 
#include "kolejka.h"
#include "statek.h"






//! Implementacja listy dwukierunkowej do kolejki.  
void Kolejka::statekZajmujeMiejsce(Statek *StatekWplywajacy){
	//cout << "zajmuje miesjce w kolejce \n";
	int i = 1;
	if (pierwszy == NULL)
	{
		pierwszy = StatekWplywajacy;
		pierwszy->nastepny = NULL;
		pierwszy->poprzedni = NULL;

	}
	else
	{
		Statek *temp = pierwszy;

		if (StatekWplywajacy->typ == 6) // jezeli ten typ to wpuszczamy go na poczatek kolejki bo ma najmniej narzedzi
		{
			if (pierwszy->typ == 6)
			{
				
					while (temp->nastepny != NULL)
					{
						if (temp->nastepny->typ != 6) break;
						temp = temp->nastepny;
						
					}
				
				if (temp->nastepny == NULL)
				{
					temp->nastepny = StatekWplywajacy;
					StatekWplywajacy->nastepny = NULL;
					StatekWplywajacy->poprzedni = temp;
					return;
				}
				else
				{
					temp->nastepny->poprzedni = StatekWplywajacy;
					StatekWplywajacy->nastepny = temp->nastepny;
					temp->nastepny = StatekWplywajacy;
					StatekWplywajacy->poprzedni = temp;
					return;
				
				}


			}


			else{
				pierwszy->poprzedni = StatekWplywajacy;
				StatekWplywajacy->nastepny = pierwszy;
				pierwszy = StatekWplywajacy;
				}
		}
		else{


			while (temp->nastepny != NULL)
			{
				temp = temp->nastepny;
				i++;
			}
			//	cerr << "Jestem kolejnym statkiem w kolejce typ:"<<StatekWplywajacy->typ<<" Jest nas:"<<i<<"\n\n";
			temp->nastepny = StatekWplywajacy;
			StatekWplywajacy->nastepny = NULL;
			StatekWplywajacy->poprzedni = temp;
		}
		{

		}
	}

}

void Kolejka::statekZwalniaMiejsceNaZwasze(Statek *StatekZwalniajacy)
{
	if (pierwszy == NULL){// cerr << "kolejka pusta jest";
		return;
	}
	Statek *temp;
	temp = pierwszy;

	if (temp == StatekZwalniajacy)
	{
		if (temp->nastepny == NULL)
		{
			temp = NULL;
			delete pierwszy;
			pierwszy = NULL;
			//cout << "usuwam jeden element";
		}
		else
		{
			//cout << "usuwam pierwszy";



			temp = temp->nastepny;
			temp->poprzedni = NULL;
			delete pierwszy;
			pierwszy = temp;
		}
	}
	else
	{
		while (temp->nastepny != NULL)
		{
			temp = temp->nastepny;
			if (temp->nastepny != NULL)
			{
				if (temp == StatekZwalniajacy)
				{
					//	cout << "usuwam ze srodka";
					temp->poprzedni->nastepny = temp->nastepny;
					temp->nastepny->poprzedni = temp->poprzedni;
					temp->nastepny = NULL;
					temp->poprzedni = NULL;
					delete StatekZwalniajacy;
				}
			}
			else
			{
				if (temp == StatekZwalniajacy)
				{
					//	cout << "usuwam z konca";
					temp->poprzedni->nastepny = NULL;
					delete StatekZwalniajacy;
				}
			}


		}





	}

}








void Kolejka::statekZwalniaMiejsce(Statek *StatekZwalniajacy){

	if (pierwszy == NULL){// cerr << "kolejka pusta jest";
	return; }
	Statek *temp;
	temp = pierwszy;

	if (temp == StatekZwalniajacy)
	{
		if (temp->nastepny == NULL)
		{
			temp = NULL;
			pierwszy = NULL;
		}
		else
		{
			temp = temp->nastepny;
			temp->poprzedni = NULL;
			pierwszy = temp;
		}
	}
	else
	{
		while (temp->nastepny != NULL)
		{
			temp = temp->nastepny;
			if (temp->nastepny != NULL)
			{
				if (temp == StatekZwalniajacy)
				{
					temp->poprzedni->nastepny = temp->nastepny;
					temp->nastepny->poprzedni = temp->poprzedni;
					temp->nastepny = NULL;
					temp->poprzedni = NULL;			
				}
			}
			else
			{
				if (temp == StatekZwalniajacy)
				{
					temp->poprzedni->nastepny = NULL;
				}
			}


		}





}


	


}

Statek* Kolejka::wyborStatkuDoZwolnienia(Kanal &pierwszyK, Kanal &drugiK, Kanal &trzeciK, Kanal &czwartyK, Port &MojPort)
{
	
	
	if (pierwszy == NULL){ 
	return NULL; }
	Statek *temp;
	
	temp = pierwszy;
	

	if (temp->czyMozeWplynac(pierwszyK, drugiK, trzeciK, czwartyK) && MojPort.czyMogeWplynac(temp)){
		return temp;
	}
		if (((pierwszyK.zajetosc && drugiK.zajetosc && trzeciK.zajetosc && czwartyK.zajetosc) == 0))//ograniczenie ilosci petli
		{
			while (temp->nastepny != NULL){
				if (temp->czyMozeWplynac(pierwszyK, drugiK, trzeciK, czwartyK) && MojPort.czyMogeWplynac(temp)){
					//cerr << "Wybrany statek do zwolnienia:"<<temp->typ<<"\n";

					return temp;

				}
			
		
				temp = temp->nastepny;

			
		}
	}
	return NULL;
}



Statek* Kolejka::wyborStatkuDoZwolnieniaZportu(Kanal &pierwszyK, Kanal &drugiK, Kanal &trzeciK, Kanal &czwartyK, Port &MojPort)
{
	if (pierwszy == NULL)
	{ 
	return NULL;
	}
	Statek *temp;
	temp = pierwszy;
	if (((pierwszyK.zajetosc && drugiK.zajetosc && trzeciK.zajetosc && czwartyK.zajetosc) == 0))//< optymalizacja
	{
		while (temp->nastepny != NULL){
			if (temp->czyMozeWplynac(pierwszyK, drugiK, trzeciK, czwartyK)){

				return temp;
			}
			temp = temp->nastepny;
		}
	}
	return NULL;
}





void Kolejka::reset()
{
	while (pierwszy != NULL)

	{
		statekZwalniaMiejsceNaZwasze(pierwszy);
		
	}


}









void Kolejka::sprIlewKolejce(){//<pomocnicza
	Statek *temp;
	temp = pierwszy;
	int i=0;
	if (pierwszy == NULL){ return; }
	while (temp->nastepny != NULL){
		i++;
		cout << temp->masa << endl;
		temp = temp->nastepny;
		}
	cout << temp->masa << endl;

}


Kolejka::Kolejka(){ pierwszy = NULL; }

bool Kolejka::czyPusta(){

	if (pierwszy == NULL)
{
		return 1;
	
	};
	return 0;
}

