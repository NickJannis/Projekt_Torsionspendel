/*
 * Masse.cpp
 *
 *  Created on: 10.06.2019
 *      Author: nick
 */

#include "Masse.h"
#include<iostream>
#include<vector>
#include <cmath>
using namespace std;
typedef vector<double> v2;

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
	this->berechneTraeghm();
}

void Masse::setMasse(const double& pMasse,const double& pFehler){
	masse.clear();
	masse.push_back(pMasse);
	masse.push_back(pFehler);
}


void Masse::setAbst(const double& pAbst, const double& pFehler){
	abst.clear();
	abst.push_back(pAbst);
	abst.push_back(pFehler);
}
void
Masse::setRai(const double& pRai, const double& pFehler){
	rai.clear();
	rai.push_back(pRai);
	rai.push_back(pFehler);
}

void
Masse::setRaa(const double& pRaa, const double& pFehler){
	raa.clear();
	raa.push_back(pRaa);
	raa.push_back(pFehler);
}
void
Masse::setLaen(const double& pLaen, const double& pFehler){
	laen.clear();
	laen.push_back(pLaen);
	laen.push_back(pFehler);
}


v2
Masse::getMasse(){
	return masse;
}
v2
Masse::getAbst(){
	return abst;
}
v2
Masse::getRai(){
	return rai;
}
v2
Masse::getRaa(){
	return raa;
}
v2
Masse::getLaen(){
	return laen;
}

void
Masse::berechneTraeghm(){}
Masse::~Masse() {
	// TODO Auto-generated destructor stub
}

