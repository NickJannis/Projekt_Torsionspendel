#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<array>
#include<cstdio>
#include"Masse.h"
#include"Draht.h"
#include"Pendel.h"

using namespace std;

Pendel pendel;

int main(){}

void erstellePlot(){}

void erstelleDaten(const double& pInterv, const double& pEnde){
	ofstream daten;
	array<double, 2> Auslenkung;
	daten.open("DatenPendel.txt");
	for(double i=0, i<pEnde, i=i+pIntervall){
		Auslenkung = pendel.berechneAuslenkung(i);
		daten<<i<<Auslenkung[0]<<Auslenkung[1]<<endl;
	}
	daten.close();
}
