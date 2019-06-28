#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<array>
#include<cstdio>
#include"Masse.h"
#include"Draht.h"
#include"Pendel.h"
#include"gnuplot-iostream.h"

using namespace std;

Pendel pendel;

int main(){}

void erstellePlot(const double& pInterv, const double& pEnde){

	this->erstelleDaten(pInterv, pEnde);
	Gnuplot gp;
	gp.setxlabel'Zeit in s';
	gp.setylabel'Auslenkung in rad';
	gp.settitle'Auslenkung eines Torsionspendels in Abhaengigkeit von der Zeit';
	gp.plot"DatenPendel.txt" using 1:2:3 w xerrorbars;


}

void erstelleDaten(const double& pInterv, const double& pEnde){
	ofstream daten;
	array<double, 2> Auslenkung;
	daten.open("DatenPendel.txt");
	for(double i=0, i<pEnde, i=i+pInterv){
		Auslenkung = pendel.berechneAuslenkung(i);
		daten<<i<<Auslenkung[0]<<Auslenkung[1]<<endl;
	}
	daten.close();
}
