/*
 * Masse.cpp
 *
 *  Created on: 10.06.2019
 *      Author: nick
 */

#include "Masse.h"
#include<iostream>

Masse::Masse() {
	// TODO Auto-generated constructor stub

}
Masse(const double& pMasse){
	masse = pMasse;
	this->berechneTraeghm();
}

Masse::~Masse() {
	// TODO Auto-generated destructor stub
}

virtual void setMasse(double& pMasse, double& pFehler){
	masse = pMasse;
	dMasse = pFehler;
}

