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

class Masse {
private:
	///Die Klasse speichert ihre Masse, ihr Traegheitsmoment und den Abstand zum Torsionsdraht mit möglichem einzugebenden Fehler (Bezeichnet mit d).
	double masse;
	double dMasse;
	double abst;
	double dAbst;
	double traegheitsm;
	double dTraegheitsm;
public:
	///Ein Massestück kann ohne Parameter und mit angegebener Masse erstellt werden.
	Masse();
	Masse(const double& pMasse);
	virtual ~Masse();

	///Mit dieser Methode wird die Masse festgelegt.
	/**Die Methode erhält als Parameter die zu speichernde Masse und den zugehörigen Fehler. */
	void setMasse(const double& pMasse,const double& pFehler);

	///Diese Methode setzt den Abstand des Massestücks zum Draht.
	/** Der Funktione werden als Parameter der Abstand und der Fehler übergeben.*/
	void setAbst(const double& pAbst, const double& pFehler);
	///Diese Methode gibt die Masse des Objekts aus.
	double getMasse();
	///Diese Methode gibt den Abstand des Pendels zum Draht aus.
	double getAbst();
	///Diese Methode berechnet das Traegheitsmoment des Massestücks und speichert es in der entsprechenden Variable.
	virtual void berechneTraeghm();

};

#endif /* MASSE_H_ */
