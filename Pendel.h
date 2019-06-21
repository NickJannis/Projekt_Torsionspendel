/*
 * Pendel.h
 *
 *  Created on: 20.06.2019
 *      Author: Ronja van Luijt
 */

///Diese Klasse bildet sozusagen die Hauptklasse.
/**In ihr werden das Gesamtträgheitsmoment traegheitsmg des Torsionspendels berechnet und gespeichert sowie
 * die weiteren Größen die man für die Schwingungsgleichung benötigt.
 * Diese sind das Richtmoment richtm, die Kreisfrequenz omega und der Phasenwinkel phi.
 */
#ifndef PENDEL_H_
#define PENDEL_H_
#include <iostream>
#include <vector>
#include<array>
#include<cmath>
#include<string>
#include "Masse.h"

using namespace std;

class Pendel {
private:
	///In der Klasse werden das Gesamtträgheitsmoment, die Kreisfrequenz, der Phasenwinkel, sowie das Richtmoment gespeichert.
	///Zusätzlich werden die Zylindergewichte und die Stange auf welcher diese befestigt sind, mit ihren Eigenschaften gespeichert, welche in der Klasse "Masse" festgelegt wurden.
	array<double,2> traegheitsmg;
	array<double,2> omega;
	array<double,2> phi;
	array<double,2> richtm;
	Masse zylinder;
	Masse stange;
public:
	///Das Pendel kann ohne Parameter erstellt werden oder mit einem Startwinkel phi.
	Pendel();
	Pendel(const double& pPhi);
	///Das Pendel kann auch mit dem Startwinkel phi sowie seinen Fehler erstellt werden.
	Pendel(const double& pPhi, const double& pFehler);
	virtual ~Pendel();
	///Die Funktionen erstelleStange und erstelleZylinder erzeugen eine Stange sowie eine Zylindermassse, dessen Eigenschaften in der Klasse "Masse" festgelegt wurden.
	void erstelleStange(const double& masse, const double& abst, const double& rai, const double& raa, const double& laen, const double& dMasse, const double& dAbst, const double& dRai, const double& dRaa, const double& dLaen);
	void erstelleZylinder(const double& masse, const double& rai, const double& raa, const double& laen, const double& dMasse, const double& dRai, const double& dRaa, const double& dLaen);
	///Mit dieser Methode wird der Startwinkel festgelegt. Dieser ist ein Array, der zwei Einträge des Types double hat. Der erste Eintrag ist sein Wert, der Zweite der dazugehörige Fehler.
	void setPhi(const double& pPhi, const double& pFehler);
	///Mit dieser Methode wird der Startwinkel phi ausgegeben.
	array<double,2> getPhi();
	/**Diese Methode berechnet das Gesamtträgheitsmoment mit Fehler mit Hilfe der in der Klasse "Masse" berechneten Einzelträgheitsmomente von Stange und Zylinder, sowie deren festgelegte Masse und Abstand zum Drehpunkt.*/
	void berechneTraeghmg();
	///Diese Methode berechnet die Kreisfrequenz mit Hilfe des Gesamtträgheitsmomentes und dem in der Klasse "Draht" berechnetem Richtmoment.
	double berechneOmega(const double& pRichtm, const double& pTraeghmg);


};

#endif /* PENDEL_H_ */
