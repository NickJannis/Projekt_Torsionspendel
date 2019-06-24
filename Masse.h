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

class Masse {
private:
	///Die Klasse speichert ihre Masse, ihr Traegheitsmoment und den Abstand zum Torsionsdraht mit möglichem einzugebenden Fehler (Bezeichnet mit d).
	array<double, 2> masse;
	array<double, 2> abst;
	array<double, 2> traegheitsm;
	array<double, 2> rai;
	array<double, 2> raa;
	array<double, 2> laen;
public:
	///Ein Massestück kann ohne Parameter und mit angegebener Masse erstellt werden.
	Masse();
	//Dieser Konstruktor erstellt einen Hohlzylinder mit angegebenen Parametern.
	/**Als Parameter werden der Methode die Masse, der Abstand, der Innenradius, der Außenradius und die Länge übergeben. */
	Masse(const double& pMasse, const double& pAbst, const double& pRai, const double& pRaa, const double& pLaen);
	//Dieser Konstruktor erstellt einen Hohlzylinder mit angegebenen Parametern und Fehlern.
	/**Als Parameter werden der Methode die Masse, der Abstand, der Innenradius, der Außenradius, die Länge, den Massefehler, den Abstandsfehler, den Fehler des Innen- und Außenradius und den Fehler der Länge übergeben. */
	Masse(const double& pMasse, const double& pAbst, const double& pRai, const double& pRaa, const double& pLaen, const double& dMasse, const double& dAbst, const double& dRai, const double& dRaa, const double& dLaen);
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
	array<double, 2> getMasse();
	///Diese Methode gibt den Abstand des Pendels zum Draht aus.
	array<double, 2> getAbst();
	///Diese Methode gibt den Innenradius des Zylinders aus.
	array<double, 2> getRai();
	///Diese Methode gibt den Außenradius des Zylinders aus.
	array<double, 2> getRaa();
	///Diese Methode gibt die Länge des Zylinders aus.
	array<double, 2> getLaen();
	///Diese Methode gibt das Trägheitsmoment aus.
	array<double, 2> getTraeghm();

	///Diese Methode berechnet das Traegheitsmoment des Massestücks und speichert es in der entsprechenden Variable.
	/** Diese Methode geht von einem Hohlzylinder als Objekt aus und berechnet das entsprechende Trägheitsmoment. */
	void berechneTraeghm();

};

#endif /* MASSE_H_ */
