/********************************************//**
 * \file   statek.cpp
 * \brief  Definicja statku
 * \author Maciej Maciejewski
 * \date   2015-04-23
 ***********************************************/



#include "sc.h"
int Statek::tools_seed1;
int Statek::tools_seed2;
int Statek::tools_seed3;
int Statek::tools_seed4;
int Statek::tools_seed5;
int Statek::tools_seed6;
int Statek::tools_seed7;
int Statek::tools_seed8;

int Statek::jr_seed1;
int Statek::jr_seed2;
int Statek::jr_seed3;
int Statek::jr_seed4;
int Statek::jr_seed5;


/////////////////////////////////////////////////






//! Czas przeplyniecia statku przez okreslony tor
double Statek::czasPrzeplyniecia(Kanal *wybrany){ //funkcja wykorzystujaca wzor i okreslajaca czas przeplyniecia okreslonego statku przez okreslony tor
	
	int kt=0;
	if ((symulacja::sim_clock - wybrany->czasOstatniegoUzycia) > 10)
	{ kt = 0; }
	else 
	
	{
		if (wybrany->doCzyZ && !czasPrzeplynieciaPrzezKanal) { kt = -1; }
		else { kt = 1; }
	}



	double czas=0;
	czas = (9.5 + (masa / 1000)* ((log(masa / 100)) / log(5)) + 5 * kt); //logx/logb = lox o podstawie b z x
	czasPrzeplynieciaPrzezKanal = czas;
	wybrany->czasZajetosci+=czas;
	return czas;


}



double Statek::czasRozladunku()
{
	if (typ == 1){
		//cerr << "Czas rozladunku statku:" << czasOb << " typ:" << typ; "\n";
		return czasOb;
	
	}
	double czasTemp=0;
	if (ppz){
		czasTemp = ((czasMagazynowy) * 2);
	}
	else
	{
		czasTemp = czasMagazynowy;
	}
	//cerr << "Czas rozladunku statku:" << czasTemp << " typ:" << typ; "\n";
	return czasTemp;
}

Kanal Statek::wyborKanaluiZajecie(Kanal pierwszy, Kanal drugi, Kanal trzeci, Kanal czwarty, Statek *plynie) {

	if (plynie->numerKanalu == pierwszy.numer){ pierwszy.zajecieKanaluDo(plynie); return pierwszy; }
	if (plynie->numerKanalu == drugi.numer) { drugi.zajecieKanaluDo(plynie); return drugi; }
	if (plynie->numerKanalu == trzeci.numer){ trzeci.zajecieKanaluDo(plynie); return trzeci; }
	if (plynie->numerKanalu == czwarty.numer) { czwarty.zajecieKanaluDo(plynie); return czwarty; }
	else{//do przemyslenia
		czwarty.zajecieKanaluDo(plynie); return czwarty;
		//cerr << "errror w wKtorymTorzeJestem";
	}

	


}



int Statek::wKtorymTorzeJestem(Statek *plynie){
	if (plynie == symulacja::KanalJeden1.pierwszy)return 1;
	else if (plynie == symulacja::KanalDwa2.pierwszy)return 2;
	else if (plynie == symulacja::KanalTrzy3.pierwszy)return 3;
	else if (plynie == symulacja::KanalCztery4.pierwszy)return 4;
	}


//! Funkcja losujaca statek.
int Statek::losowanieStatku(){
	double a;
	a=Uniform(tools_seed1) * 100;	
	if (a <= 20) return 1;
	else if (a > 20  && a<=30) return 2;
	else if (a > 30  && a<=50) return 3;
	else if (a > 50 && a<=65) return 4;
	else if (a > 65 && a<=90) return 5;
	else if (a > 90 && a <= 100) return 6;
}







//! Dodanie i wylosowanie statku
void Statek::dodanieStatku(){

	switch (losowanieStatku())
	{
	case 1:{

			   typ = 1; //<!jacht
			   masa = 200 + Uniform(tools_seed2) * 1800;//!<masa jachtu przedzial 100:2000 gl. zan. nie przekrcza 2m 
			   ppz= NULL;
			   zanurzenie = (masa / 1000.0);//!<nie wiecej niz 2m, 
			   czasOb = (24 + Uniform(tools_seed3) * 73)*60;

			//   statystyki.open("./jakDlugoJachtWPort.csv", std::ios_base::out | std::ios_base::app);
			//   statystyki << czasOb << endl;
			//   statystyki.close();

			   wymaganeDzwigi = 0;
			   wymaganeTasmociagi = 0;
			   wymaganeRampy = 0;
			   wymaganeProwadnice = 0;
			   czasMagazynowy = 0;
			//   cout << "Stworzono jacht o masie"<<masa<<endl;

			   break; }
	case 2:{

			   typ = 2;
			   masa = 750 + Uniform(tools_seed4) * 2250;
			   if ((Uniform(jr_seed1) * 100) <= 40) ppz = true;
			   zanurzenie = (masa / 1000.0);
			   czasOb = 0;
			   wymaganeDzwigi = 0;
			   wymaganeTasmociagi = 0;
			   wymaganeRampy = 1;
			   wymaganeProwadnice = 0;
			   czasMagazynowy = ((masa * 0.7) /1100)*60 ; //uwzgledna jedna dodatkowy dzwig
			   break; }
	case 3:{

			   typ = 3;
			   masa = 500 + Uniform(tools_seed5) * 2500;

			   if ((Uniform(jr_seed2) * 100) <= 75) ppz = true;
			   zanurzenie = (masa / 1000.0);
			   czasOb = 0;
			   wymaganeDzwigi = 0;
			   wymaganeTasmociagi = 0;
			   wymaganeRampy = 2;
			   wymaganeProwadnice = 0;
			   czasMagazynowy = ((masa * 0.7) / 1000) * 60;
			   break; }
	case 4:{

			   typ = 4;
			   masa = 500 + Uniform(tools_seed6) * 2500;

			   if ((Uniform(jr_seed3) * 100) <= 5) ppz = true;
			   zanurzenie = (masa / 1000.0);
			   czasOb = 0;
			   wymaganeDzwigi = 1;
			   wymaganeTasmociagi = 0;
			   wymaganeRampy = 0;
			   wymaganeProwadnice = 0;
			   czasMagazynowy = ((masa * 0.7) / 600) * 60;
			   break; }
	case 5:{

			   typ = 5;
			   masa = 3000 + Uniform(tools_seed7) * 9000;
			   if ((Uniform(jr_seed4) * 100) <= 2) ppz = true;
			   zanurzenie = (masa / 1000.0);
			   czasOb = 0;
			   wymaganeDzwigi = 0;
			   wymaganeTasmociagi = 0;
			   wymaganeRampy = 0;
			   wymaganeProwadnice = (int)ceil((0.7*masa) / 6000); //na kazde rozpoczete 6000j ladunku
			   czasMagazynowy = ((masa * 0.7) / (1000 * wymaganeProwadnice)) * 60;
			   break; }
	case 6:{

			   typ = 6;
			   masa = 1500 + Uniform(tools_seed8) * 13500;
			   if ((Uniform(jr_seed5) * 100) <= 20) ppz = true;
			   zanurzenie = (masa / 1000.0);
			   czasOb = 0;
			   wymaganeDzwigi = 0;
			   wymaganeTasmociagi = (int)ceil((0.7*masa) / 5000);
			   wymaganeRampy = 0;
			   wymaganeProwadnice = 0;
			   czasMagazynowy = ((masa * 0.7) / (800 * wymaganeTasmociagi)) * 60;
			   break; }
	}






}


bool Statek::czyMozeWplynac(Kanal &pierwszy, Kanal &drugi, Kanal &trzeci, Kanal &czwarty)//<! Okreslenie czy statek moze wplynac do portu
{
	if ((pierwszy.zajetosc == 0) && (pierwszy.glebokosc >=zanurzenie)){ return 1; }
	if ((drugi.zajetosc == 0) && (drugi.glebokosc >= zanurzenie)){ return 1; }
	if ((trzeci.zajetosc == 0) && (trzeci.glebokosc >= zanurzenie)){ return 1; }
	if ((czwarty.zajetosc == 0) && (czwarty.glebokosc >=zanurzenie)){ return 1; }
	return 0;
}


Kanal *Statek::wyborKanalu(Kanal &pierwszy, Kanal &drugi, Kanal &trzeci, Kanal &czwarty)//<! Wybor najlepszego kanalu dla statku pod wzgledem dobrego wykorzystania
{

	double min = 100;
	Kanal *temp;
	if ((pierwszy.zajetosc == 0) && (pierwszy.glebokosc >= zanurzenie)){ if (pierwszy.glebokosc - zanurzenie < min){ min = pierwszy.glebokosc - zanurzenie; temp = &pierwszy; numerKanalu = 1; } }
	if ((drugi.zajetosc == 0) && (drugi.glebokosc >= zanurzenie)){ if (drugi.glebokosc - zanurzenie < min){ min = drugi.glebokosc - zanurzenie; temp = &drugi; numerKanalu = 2; } }
	if ((trzeci.zajetosc == 0) && (trzeci.glebokosc >= zanurzenie)){ if (trzeci.glebokosc - zanurzenie < min){ min = trzeci.glebokosc - zanurzenie; temp = &trzeci; numerKanalu = 3; } }
	if ((czwarty.zajetosc == 0) && (czwarty.glebokosc >= zanurzenie)){ if (czwarty.glebokosc - zanurzenie < min){ min = czwarty.glebokosc - zanurzenie; temp = &czwarty; numerKanalu = 4; } }

	//cout << "zajety kanal:"<<temp.numer<< endl;

	return temp;

}

void Statek::czazOczekiwania(double czas){

	symulacja::czas = symulacja::czas + (symulacja::sim_clock - czasPrzybycia);
	symulacja::statystyki_lambda_srednia << symulacja::czas / symulacja::i << endl;
	
	switch (typ)
	{
	case 1:{symulacja::typ1++; symulacja::typ1t = symulacja::typ1t + czas; break; }
	case 2:{symulacja::typ2++; symulacja::typ2t = symulacja::typ2t + czas; break; }
	case 3:{symulacja::typ3++; symulacja::typ3t = symulacja::typ3t + czas; break; }
	case 4:{symulacja::typ4++; symulacja::typ4t = symulacja::typ4t + czas; break; }
	case 5:{symulacja::typ5++; symulacja::typ5t = symulacja::typ5t + czas; break; }
	case 6:{symulacja::typ6++; symulacja::typ6t = symulacja::typ6t + czas; break; }
	}
	if (czas > symulacja::maxCzasOczekiwania)symulacja::maxCzasOczekiwania = czas;


}



void Statek::resetStatystyk()
{
	symulacja::wynik = 0;
	symulacja::czas = 0;
	symulacja::i = 0;
	symulacja::liczbaWszystkich = 0;
	symulacja::typ1t = 0;
	symulacja::typ2t = 0;
	symulacja::typ3t = 0;
	symulacja::typ4t = 0;
	symulacja::typ5t = 0;
	symulacja::typ6t = 0;
	symulacja::typ1 = 0;
	symulacja::typ2 = 0;
	symulacja::typ3 = 0;
	symulacja::typ4 = 0;
	symulacja::typ5 = 0;
	symulacja::typ6 = 0;
	symulacja::statkiWyplywajace = 0;
	symulacja::KanalJeden1.czasZajetosci = 0;
	symulacja::KanalDwa2.czasZajetosci = 0;
	symulacja::KanalTrzy3.czasZajetosci = 0;
	symulacja::KanalCztery4.czasZajetosci = 0;
	symulacja::maxCzasOczekiwania = 0;
	symulacja::czasNarzedziDzwigi = 0;
	symulacja::czasNarzedziMiejsceJachty = 0;
	symulacja::czasNarzedziProwadnice = 0;
	symulacja::czasNarzedziRampy = 0;
	symulacja::czasNarzedziTasmociagi = 0;

}