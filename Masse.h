/*
 * Masse.h
 *
 *  Created on: 10.06.2019
 *      Author: nick
 */

///Diese Klasse bildet die Basisklasse der am Pendel zu befestigenden Massestücke.
/** Das hier modellierte Massestück besitzt eine Masse, einen bestimmten Abstand zum Pendel und ein eigenes Trägheitsmoment.
 * Dieses wird benötigt, um die Schwingung des Pendels zu simulieren.
 * Bei dem Massestück handelt es sich um einen Zylinder, dessen zentrale Achse in Richtung des Pendels zeigt.
 * Der Zylinder ist dabei ein Hohlzylinder mit Innenradius RaI und Außenradius RaA, sowie der Länge Laen.*/

#ifndef MASSE_H_
#define MASSE_H_
#include<iostream>
#include <cmath>
#include<array>

using namespace std;
typedef array<double, 2> v2;

class Masse {
private:
	///Die Klasse speichert ihre Masse, ihr Traegheitsmoment und den Abstand zum Torsionsdraht mit möglichem einzugebenden Fehler (Bezeichnet mit d).
	v2 masse;
	v2 abst;
	v2 traegheitsm;
	v2 rai;
	v2 raa;
	v2 laen;
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
	///Diese Methode setzt den Innenradius des Zylinders.
	/**Der Methode werden dabei als Parameter der Innenradius mit Fehler angegeben.*/
	void setRai(const double& pRai, const double& pFehler);
	///Diese Methode setzt den Außenradius des Zylinders.
	/**Der Methode werden dabei als Parameter der Außenradius mit Fehler angegeben.*/
	void setRaa(const double& pRaa, const double& pFehler);
	///Diese Methode setzt die Länge des Zylinders.
	/**Der Methode werden dabei die Länge des Zylinders, sowie der zugehörige Fehler übergeben.*/
	void setLaen(const double& pLaen, const double& pFehler);

	///Diese Methode gibt die Masse des Objekts aus.
	v2 getMasse();
	///Diese Methode gibt den Abstand des Pendels zum Draht aus.
	v2 getAbst();
	///Diese Methode gibt den Innenradius des Zylinders aus.
	v2 getRai();
	///Diese Methode gibt den Außenradius des Zylinders aus.
	v2 getRaa();
	///Diese Methode gibt die Länge des Zylinders aus.
	v2 getLaen();

	///Diese Methode berechnet das Traegheitsmoment des Massestücks und speichert es in der entsprechenden Variable.
	/** Diese Methode ist in der Klasse Masse vorgeschrieben, damit jede erbende Klasse diese Methode implementiert haben muss. */
	void berechneTraeghm();

};

#endif /* MASSE_H_ */
