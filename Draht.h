/*
 * Draht.h
 *
 *  Created on: Jun 21, 2019
 *      Author: m1848568
 */
///Diese Klasse modelliert den Draht, der als Torsionspendel fungiert.
/** Die Klasse speichert den Radius, die effektive Länge, das Torsionsmodul in Abhängigkeit vom Material
 *  und das Richtmoment, was aus den übrigen Größen berechnet wird.*/
#ifndef DRAHT_H_
#define DRAHT_H_
#define _USE_MATH_DEFINES

#include<iostream>
#include<array>
#include<cmath>
using namespace std;

class Draht {
private:
///Die Klasse speichert ihren Radius, die effektive Länge, das Torsionsmodul und das Richtmoment.
	array<double, 2> rad;
	array<double, 2> laen;
	array<double, 2> torsm;
	array<double, 2> richtm;
public:
	///Objekte der Klasse können leer, mit Radius, Länge und Torsionsmodul, oder mit Radius, Länge und Torsionsmodul inklusive Fehler erstellt werden.
	Draht();
	Draht(const double& pRad,const double& pLaen,const double& pTors);
	Draht(const double& pRad,const double& pLaen,const double& pTors,const double& dRad,const double& dLaen,const double& dTors);

	///Diese Funktion berechnet das Richtmoment des Drahtes und speichert es in der entsprechenden Variable.
	/**Das Richtmoment wird mit der Formel D=pi*G*R^4/2L berechnet. Der Fehler wird nach Fehlerfortpflanzung berechnet. */
	void berechneRichtm();
	///Diese Funktion setzt den Radius des Drahtes mit Fehler.
	void setRad(const double& pRad,const double& pFehler);
	///Diese Funktion setzt die effektive Länge des Drahtes mit Fehler.
	void setLaen(const double& pLaen, const double& pFehler);
	///Diese Funktion setzt das Torsionsmodul des Drahtes mit Fehler.
	void setTorsm(const double& pTorsm, const double& pFehler);
	///Diese Funktion gibt den Radius des Drahtes aus.
	array<double, 2> getRad();
	///Diese Funktion gibt die Länge des Drahtes aus.
	array<double, 2> getLaen();
	///Diese Funktion gibt das Torsionsmodul des Drahtes aus.
	array<double, 2> getTorsm();
	///Diese Funktion gibt das Richtmoment des Drahtes aus.
	/**In dieser Funktion wird zunächst die klasseneigene Funktion zur Berechnung des Richtmoments aufgerufen und gibt daraufhin die Variable richtm aus. */
	array<double, 2> getRichtm();

	virtual ~Draht();
};

#endif /* DRAHT_H_ */
