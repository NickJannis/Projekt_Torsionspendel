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


int begruessung(){
	cout<<"Dieses Programm simuliert ein Torsionspendel. Was möchten Sie berechnen lassen?"<<endl;
	cout<<"1 - Pendel berechnen (Torsionsmodul, Trägheitsmoment, Auslenkung zum Zeitpunkt t)"<<endl;
	cout<<"2 - Zeit-Auslenkung-Graph plotten/simulieren"<<endl;
	cout<<"3 - Ende (beendet das Programm)"<<endl;
	cout<<"Bitte geben Sie die entsprechende Zahl ein: "<<endl;
	cin>>int var1;
	cout<<"\n";
	switch(var1){
	case 1:{
		this->berechnen();
		return 1;
	}
	case 2:{
		this->berePlot();
		return 1;
	}
	case 3:{
		return 0;
	}
	default:{
		cout<<"Ihre Ausgabe enthält einen Fehler. Das Programm wird beendet."<<endl;
		return 0;
	}
	}
}

void berechnen(){
	this->erstellePendel();
}

void berePlot(){
	this->erstellePendel();
}

void erstellePendel(){
	cout<<"Erstellen Sie zunächst ein Pendel. Bitte geben Sie das Material des Drahtes an:"<<endl;
	cout<<"1 - Stahl"<<endl;
	cout<<"2 - Kupfer"<<endl;
	cout<<"3 - Aluminium"<<endl;
	cout<<"4 - beliebiges Material"<<endl;
	cin>>int var2;
	cout<<"\n";
	string pFehler = "Fehler: (Wenn ohne Fehler gerechnet werden soll, bitte 0 angeben)(in m)";
	array<double, 5> pDraht;
	while(this->setzeTM(var2)==1){
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
	cout<<"Ihr Pendel wurde nun erstellt."<<endl;


}

int setzeTM(const int& pZahl){
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

void erstellePlot(){

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

int main(){
	while(this->begruessung()==1){};
}
