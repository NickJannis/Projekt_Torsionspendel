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
	Draht();
	Draht(const double& pRad, pLaen, pTors);
	Draht(const double& pRad, pLaen, pTors, dRad, dLaen, dTors);

	void berechneRichtm();
	void setRad(const double& pRad,const double& pFehler);
	void setLaen(const double& pLaen, const double& pFehler);
	array<double, 2> getRad();
	array<double, 2> getLaen();
	array<double, 2> getTors();
	array<double, 2> getRichtm();

	virtual ~Draht();
};

#endif /* DRAHT_H_ */
