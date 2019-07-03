#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<array>
#include<cstdio>
#include"Masse.h"
#include"Draht.h"
#include"Pendel.h"
#include"gnuplot_i.hpp"

using namespace std;

Pendel pendel;

int setzeTM(const int& pZahl,array<double, 5>& pDraht){
	switch(pZahl){
	case 1:{
		pDraht[2] = 79.3 * pow(10, 0);
		return 0;


	}
	case 2:{
		pDraht[2]=47.0 * pow(10, 9);
		return 0;
	}

	case 3:{
		pDraht[2] = 25.5 *pow(10,9);
		return 0;
	}

	case 4:{
		cout<<"Bitte geben Sie das Schub-/Torsionsmodul des verwendeten Materials ein: "<<endl;
		cin>>pDraht[2];

		return 0;
	}
	default:{
		cout<<"Ihre Ausgabe enthält einen Fehler. Das Programm wird beendet."<<endl;
		return 1;
	}
	}

}

void erstellePendel(){
	cout<<"Erstellen Sie zunächst ein Pendel. Bitte geben Sie das Material des Drahtes an:"<<endl;
	cout<<"1 - Stahl"<<endl;
	cout<<"2 - Kupfer"<<endl;
	cout<<"3 - Aluminium"<<endl;
	cout<<"4 - beliebiges Material"<<endl;
	int var2;
	cin>>var2;
	cout<<"\n";
	string pFehler = "Fehler: (Wenn ohne Fehler gerechnet werden soll, bitte 0 angeben)(in m)";
	array<double, 5> pDraht;
	while(setzeTM(var2, pDraht)==1){
		cout<<"Bitte wiederholen Sie ihre Eingabe: "<<endl;
		cin>>var2;
	}

	cout<<"Bitte geben Sie die effektive Länge des Drahtes an (in m): "<<endl;
	cin>>pDraht[1];
	cout<<pFehler<<endl;
	cin>>pDraht[4];

	array<double, 8> pStange;
	cout<<"Bitte geben Sie den Radius des verwendeten Drahtes ein(in m): "<<endl;
	cin>>pDraht[0];
	cout<<pFehler <<endl;
	cin>>pDraht[3];
	pendel.erstelleDraht(pDraht[0],pDraht[1], pDraht[2], pDraht[3], pDraht[4], 0);

	cout<<"Bitte geben Sie die Masse der verwendeten Querstange ein(in kg): "<<endl;
	cin>>pStange[0];
	cout<<"Fehler: (Wenn ohne Fehler gerechnet werden soll, bitte 0 angeben)(in kg): " <<endl;
	cin>>pStange[5];

	cout<<"Bitte geben Sie den Innenradius der verwendeten Querstange ein(in m): "<<endl;
	cin>>pStange[1];
	cout<<pFehler <<endl;
	cin>>pStange[7];

	cout<<"Bitte geben Sie den Außenradius der verwendeten Querstange ein(in m): "<<endl;
	cin>>pStange[2];
	cout<<pFehler<<endl;
	cin>>pStange[6];

	cout<<"Bitte geben Sie die Länge der verwendeten Querstange ein(in m): "<<endl;
	cin>>pStange[3];
	cout<<pFehler<<endl;
	cin>>pStange[7];

	pendel.erstelleStange(pStange[0], pStange[1], pStange[2], pStange[3], pStange[4], pStange[5], pStange[6], pStange[7]);

	array<double, 10> pZylinder;

	cout<<"Bitte geben Sie die Masse der verwendeten Massestücke ein(in kg): "<<endl;
	cin>>pZylinder[0];
	cout<<"Fehler: (Wenn ohne Fehler gerechnet werden soll, bitte 0 angeben)(in kg): " <<endl;
	cin>>pZylinder[5];

	cout<<"Bitte geben Sie den Abstand der Mittelpunkte der Massestücke zum Draht an(in m): "<<endl;
	cin>>pZylinder[8];
	cout<<pFehler<<endl;
	cin>>pZylinder[9];

	cout<<"Bitte geben Sie den Innenradius der verwendeten Massestücke ein(in m): "<<endl;
	cin>>pZylinder[1];
	cout<<pFehler <<endl;
	cin>>pZylinder[7];

	cout<<"Bitte geben Sie den Außenradius der verwendeten Massestücke ein(in m): "<<endl;
	cin>>pZylinder[2];
	cout<<pFehler<<endl;
	cin>>pZylinder[6];

	cout<<"Bitte geben Sie die Länge der verwendeten Massestücke ein(in m): "<<endl;
	cin>>pZylinder[3];
	cout<<pFehler<<endl;
	cin>>pZylinder[7];

	pendel.erstelleZylinder(pZylinder[0],pZylinder[8],pZylinder[1],pZylinder[2], pZylinder[3], pZylinder[4], pZylinder[9], pZylinder[5], pZylinder[6], pZylinder[7]);

	cout<<"Bitte geben Sie nun den Startwinkel an, mit dem das Pendel ausgelenkt wird (in rad): "<<endl;
	array<double, 2> pStw;
	cin>>pStw[0];
	cout<<"Fehler: (Wenn ohne Fehler gerechnet werden soll, bitte 0 angeben)(in rad): "<<endl;
	cin>>pStw[1];
	pendel.setStw(pStw[0], pStw[1]);

	cout<<"Ihr Pendel wurde nun erstellt."<<endl;


}

int abfrageBerechnen(){
	cout<<"Was möchten Sie berechnen lassen?"<<endl;
	cout<<"1 - neuen Startwinkel setzen"<<endl;
	cout<<"2 - Trägheitsmoment ausgeben"<<endl;
	cout<<"3 - Auslenkung zum Zeitpunkt t nach Start"<<endl;
	cout<<"4 - Winkelgeschwindigkeit omega ausgeben"<<endl;
	cout<<"5 - Zurück"<<endl;
	int pAbfr;
	cin>>pAbfr;
	switch(pAbfr){
	case 1:{
		cout<<"Geben Sie den neuen Startwinkel ein (in rad): "<<endl;
		array<double, 2> pStw;
		cin>>pStw[0];
		cout<<"Fehler: (Wenn ohne Fehler gerechnet werden soll, bitte 0 angeben)(in rad): "<<endl;
		cin>>pStw[1];
		pendel.setStw(pStw[0], pStw[1]);
		cout<<"Ihr neuer Startwert wurde gesetzt."<<endl;
		return 1;
	}
	case 2:{
		array<double, 2> pTraeghm = pendel.getTraeghm();
		cout<<"Trägheitsmoment: "<<endl;
		cout<<pTraeghm[0]<<"±"<<pTraeghm[1]<<"kg*m^2"<<endl;
		return 1;
	}
	case 3:{
		cout<<"Geben Sie den Zeitpunkt t an (in s): "<<endl;
		double pT;
		cin>>pT;
		array<double,2> pAusl = pendel.berechneAuslenkung(pT);
		cout<<"Auslenkung: "<<pAusl[0]<<"±"<<pAusl[1]<<"rad"<<endl;
		return 1;
	}
	case 4:{
		array<double,2> pOmega = pendel.getOmega();
		cout<<"Omega: "<<pOmega[0]<<"±"<<pOmega[1]<<"Hz"<<endl;
		return 1;
	}
	case 5:{
		return 0;
	}
	default:{
		return 1;
	}
	}
}

void berechnen(){
	while(abfrageBerechnen()==1){}
}

void erstelleDaten(const double& pInterv, const double& pEnde){
	ofstream daten;
	array<double, 2> Auslenkung;
	daten.open("DatenPendel.txt");

	for(double i=0; i<pEnde; i=i+pInterv){

	for(double i=0; i<pEnde; i=i+pInterv){

		Auslenkung = pendel.berechneAuslenkung(i);
		daten<<i<<Auslenkung[0]<<Auslenkung[1]<<endl;
	}
	daten.close();
}


void erstellePlot(){
	cout << "Geben Sie bitte an, in welchen Zeitintervallen die Auslenkung berechnet werden soll:" << endl;
	double pI;
	cin >> pI;
	cout << "Geben Sie nun noch die Zeit an, bis zu welcher der Graph angezeigt werden soll:" << endl;
	double pE;
	cin >> pE;
	erstelleDaten(pI, pE);
	Gnuplot gp("lines");
	gp << "set xlabel 'Zeit in s'";
	gp << "set ylabel 'Auslenkung in rad'";
	gp << "set key left top";
	gp << "set terminal png \n";
	gp << "set output 'a.png' \n";
	gp.set_xrange(0.0, pE);
	gp.set_yrange(-10.0, 10.0);
	gp << "g(x) = a*sin(b*x+pi/2)";
	gp << "fit g(x) 'DatenPendel.txt' using 1:2:3 via a,b";
	gp << "plot 'DatenPendel.txt' using 1:2:3 w yerrorbars title 'Messdaten mit Fehler', g(x) title 'Fit' ";
}

void berePlot(){
}

int begruessung(){
	cout<<"Dieses Programm simuliert ein Torsionspendel. Was möchten Sie berechnen lassen?"<<endl;
	cout<<"1 - Pendel erstellen"<<endl;
	cout<<"2 - Pendel berechnen (Torsionsmodul, Trägheitsmoment, Auslenkung zum Zeitpunkt t)"<<endl;
	cout<<"3 - Zeit-Auslenkung-Graph plotten/simulieren"<<endl;
	cout<<"4 - Ende (beendet das Programm)"<<endl;
	cout<<"Bitte geben Sie die entsprechende Zahl ein: "<<endl;
	int var1;
	cin>>var1;
	cout<<"\n";
	switch(var1){
	case 1:{
		erstellePendel();
		pendel.berechneOmega();
		return 1;
	}
	case 2:{
		berechnen();
		return 1;
	}
	case 3:{
		berePlot();
		return 1;
	}
	case 4:{
		return 0;
	}
	default:{
		cout<<"Ihre Ausgabe enthält einen Fehler. Das Programm wird beendet."<<endl;
		return 0;
	}
	}
}








int main(){
	while(begruessung()==1){};
	return 0;
}
