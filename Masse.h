/*
 * Masse.h
 *
 *  Created on: 10.06.2019
 *      Author: nick
 */

///Diese Klasse bildet die Basisklasse der am Pendel zu befestigenden Massestücke.
/** Das hier modellierte Massestück besitzt eine Masse, einen bestimmten Abstand zum Pendel und ein eigenes Trägheitsmoment.
 * Dieses wird benötigt, um die Schwingung des Pendels zu simulieren. */

#ifndef MASSE_H_
#define MASSE_H_
#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

class Masse {
private:
	///Die Klasse speichert ihre Masse, ihr Traegheitsmoment und den Abstand zum Torsionsdraht mit möglichem einzugebenden Fehler (Bezeichnet mit d).
	vector<double> masse;
	vector<double> abst;
	vector<double> traegheitsm;
public:
	///Ein Massestück kann ohne Parameter und mit angegebener Masse erstellt werden.
	Masse();
	Masse(const double& pMasse);
	///Ein Massestück kann auch mit angegebener Masse mit Fehler angegeben werden.
	Masse(const double& pMasse, const double& pFehler);
	virtual ~Masse();

	///Mit dieser Methode wird die Masse festgelegt.
	/**Die Methode erhält als Vector die Masse, wobei die Masse als 1. Eintrag und der Fehler als 2. Eintrag gespeichert wird. */
	void setMasse(const double& pMasse,const double& pFehler);

	///Diese Methode setzt den Abstand des Massestücks zum Draht.
	/** Der Funktione werden als Parameter der Abstand und der Fehler übergeben.*/
	void setAbst(const double& pAbst, const double& pFehler);
	///Diese Methode gibt die Masse des Objekts aus.
	vector<double> getMasse();
	///Diese Methode gibt den Abstand des Pendels zum Draht aus.
	vector<double> getAbst();
	///Diese Methode berechnet das Traegheitsmoment des Massestücks und speichert es in der entsprechenden Variable.
	/** Diese Methode ist in der Klasse Masse vorgeschrieben, damit jede erbende Klasse diese Methode implementiert haben muss. */
	void berechneTraeghm();

	int main(){
		Masse beispielmasse;
		beispielmasse.setMasse(200.0, 0.1);
		cout<<beispielmasse.getMasse().front()<<", "<< beispielmasse.getMasse().back()<<endl;
		return 1;
	}

};

#endif /* MASSE_H_ */
