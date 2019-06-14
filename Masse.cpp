/*
 * Masse.cpp
 *
 *  Created on: 10.06.2019
 *      Author: nick
 */

#include "Masse.h"
#include<iostream>
#include<vector>
using namespace std;

Masse::Masse() {
	// TODO Auto-generated constructor stub

}
Masse::Masse(const double& pMasse){
	masse.push_back(pMasse);
	this->berechneTraeghm();
}

Masse::Masse(const double& pMasse, const double& pFehler){
	masse.push_back(pMasse);
	masse.push_back(pFehler);
}

Masse::~Masse() {
	// TODO Auto-generated destructor stub
}

void setMasse(double& pMasse, double& pFehler){
	masse.clear();
	masse.push_back(pMasse);
	masse.push_back(pFehler);
}

void setAbst(const double& pAbst, const double& pFehler){
	abst.clear();
	abst.push_back(pAbst);
	abst.push_back(pFehler);
}

vector<double> getMasse(){
	return masse;
}

vector<double> getAbst(){
	return abst;
}

virtual void berechneTraeghm(){}

