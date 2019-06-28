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


void begruessung(){
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
	break;
	}
	case 2:{
		this->berePlot();
		break;
	}
	case 3:{
		break;
	}
	default:{
		cout<<"Ihre Ausgabe enthält einen Fehler. Das Programm wird beendet."<<endl;
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
	this->setzeTM(var2);
}

void setzeTM(const int& pZahl){
	double pTM;
	switch(pZahl){
	case 1:{
		pTM = 79.3 * pow(10, 0);
		break;
	}
	case 2:{
		pTM=47.0 * pow(10, 9);
		break;
	}

	case 3:{
		pTM = 25.5 *pow(10,9);
		break;
	}

	case 4:{

		break;
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
	this->begruessung();
}
