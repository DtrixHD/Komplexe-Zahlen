// komplexeZahlen.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include "timer.hpp"
using namespace std;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ Struct +++++++++++++++++++++++++++++++++++++++++++

struct komplexeZahl
{
	float re;
	float im;
};


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ Funktionen ++++++++++++++++++++++++++++++++++++++
void Ausgabe(komplexeZahl zahl[], int anzahl)
{
	for (int i=0; i<anzahl; i++)
	{
		komplexeZahl z = zahl[i];

		cout<< z.re; 
		if(z.im <0)
		{
			cout<<z.im <<"i" <<endl;
		}
		else
		{
			cout<< " + " <<z.im <<"i" <<endl;
		}
	}
}

void Ausgabe(komplexeZahl z)
{
	cout<< z.re; 
	if(z.im <0)
	{
		cout<<z.im <<"i" <<endl;
	}
	else
	{
		cout<< " + " <<z.im <<"i" <<endl;
	}
}

float Re(komplexeZahl z)
{
	return z.re;
}

float Im(komplexeZahl z)
{
	return z.im;
}

komplexeZahl Addition(komplexeZahl z1, komplexeZahl z2)
{
	komplexeZahl z3;

	z3.re = z1.re + z2.re;
	z3.im = z1.im + z2.im;

	return z3;
}

komplexeZahl Subtraktion(komplexeZahl z1, komplexeZahl z2)
{
	komplexeZahl z3;

	z3.re = z1.re - z2.re;
	z3.im = z1.im - z2.im;

	return z3;
}

komplexeZahl Multiplikation(komplexeZahl z1, komplexeZahl z2)
{
	komplexeZahl z3;
	z3.re = (z1.re * z2.re - z1.im * z2.im);
	z3.im =	(z1.re * z2.im + z2.re * z1.im);

	return z3;
}

komplexeZahl Division(komplexeZahl z1, komplexeZahl z2)
{
	komplexeZahl z3;

	float a = z1.re;
	float b = z1.im;
	float c = z2.re;
	float d = z2.im;

	z3.re = (a * c + b * d) / (c * c + d * d);
	z3.im = (b * c - a * d) / (c * c + d * d);

	return z3;
}

komplexeZahl KonjugiertKomplex(komplexeZahl z)
{
	komplexeZahl z2 = z;
	z2.im *= -1;
	return z2;
}

float Betrag(komplexeZahl z)
{
	return abs(sqrt(z.re*z.re + z.im*z.im));
}

void randomZahlen(komplexeZahl zahl[], int anzahl)
{
	int i;
	
	
	for (i=0; i<anzahl; i++)
	{
		 zahl[i].re = (rand() %101)-50;
		 zahl[i].im = (rand() %101)-50;
	}
}

//Sortieren einens Feld (interativ)
void iSort(komplexeZahl Werte[],int Anzahl)
{
	int tausch;
	komplexeZahl dummy;
	do
	{
		tausch = 0;	//Abbruch = Ja
		for(int i = 0; i < Anzahl - 1; i++)
		{
			if(Betrag(Werte[i]) > Betrag(Werte[i + 1]))//Überprüfung von Werten
			{
				tausch = 1;	//Abbruch = Nein
				dummy = Werte[i];
				Werte[i] = Werte[i + 1];
				Werte[i + 1] = dummy;
			}
		}
	}while (tausch == 1);//Wiederholen bis Abbruch = ja
}


//** Funktion: teile - Teil-Funktion von QuickSort
int teile(komplexeZahl* arr, int links, int rechts)
{
	int i = links;
	int j = rechts - 1;

	float pivot = Betrag(arr[rechts]);

	do
	{
		while(Betrag(arr[i]) < pivot && i < rechts - 1)
		{
			i++;
		}

		while(Betrag(arr[j]) >= pivot && j > links)
		{
			j--;
		}

		if(i < j)
		{
			komplexeZahl dummy = arr[i];
			arr[i] = arr[j];
			arr[j] = dummy;
		}
	} while(i < j);

	if(Betrag(arr[i]) > pivot)
	{
		komplexeZahl dummy = arr[i];
		arr[i] = arr[rechts];
		arr[rechts] = dummy;
	}

	return i;
}
//** Funktion: quickSort - QuickSort Haupt-Funktion
void quickSort(komplexeZahl* arr, int links, int rechts)
{
	if(links < rechts)
	{
		int teiler = teile(arr, links, rechts);

		quickSort(arr, links, teiler);
		quickSort(arr, teiler + 1, rechts);
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ Variablen +++++++++++++++++++++++++++++++++++
	komplexeZahl z1, z2, z3;
	float f;
	int anzahl;

	z1.re = 6;
	z1.im = 4;

	z2.re = 4;
	z2.im = 2;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ Anzahl festlegen ++++++++++++++++++++++++++++

cout<< "Geb Sie die Anzahl an Komplexen Zahlen ein die generiert werden sollen: ";
cin>>anzahl;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ Dyn. Array +++++++++++++++++++++++++++++++
	
	komplexeZahl *zahl = 0;     
	zahl = new komplexeZahl [anzahl]; 

	komplexeZahl *kopie = 0;     
	kopie = new komplexeZahl [anzahl]; 

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++ Hauptprogramm ++++++++++++++++++++++++++++

	//Beweis für die Funktion der Funktionen

	cout<<"Komplexe Zahlen:" <<endl <<endl;
	Ausgabe(z1);
	Ausgabe(z2);

	cout<<endl;
	cout<<"Addition von Z1 u. Z2" <<endl;
	z3 = Addition(z1, z2);
	
	Ausgabe(z3);

	cout<<endl;
	cout<<"Suptraktion von Z1 u. Z2" <<endl;
	z3 = Subtraktion(z1, z2);

	Ausgabe(z3);
	
	cout<<endl;
	cout<<"Multiplikation von Z1 u. Z2" <<endl;
	z3 = Multiplikation(z1, z2);

	Ausgabe(z3);

	cout<<endl;
	cout<<"Division von Z1 u. Z2" <<endl;
	z3 = Division(z1, z2);

	Ausgabe(z3);

	cout<<endl;
	cout<<"Z1 und KonjugiertKomplex von Z1" <<endl;
	Ausgabe(z1);
	z3 = KonjugiertKomplex(z1);
	Ausgabe(z3);

	cout<<endl;
	cout<<"Betrag von Z1" <<endl;
	f = Betrag(z1);
	cout<<f <<endl;

	cout<<endl;
	//Zufällige Zahlen + Sortieren
	randomZahlen(zahl, anzahl);

	for (int i = 0; i < anzahl;i++)
	{
		kopie[i] = zahl[i];
	}

	//zeitmessung während bubblesort
	timer_t time;
	iSort(zahl, anzahl);
	time.stop();

	cout << "Fuer BublleSort benoetigte Sekunden: " << time.get_seconds() <<endl;

	randomZahlen(zahl, anzahl);

	//zeitmessung während quicksort
	timer_t time2;
	quickSort(kopie, 0, anzahl-1);
	time2.stop();

	cout << "Fuer QuickSort benoetigte Sekunden: " << time2.get_seconds() <<endl;
	
	cout<<endl;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++  Freigabe +++++++++++++++++++++++++++++++++
	delete[] zahl;
	zahl = 0;

	delete[] kopie;
	kopie = 0;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	return 0;
}