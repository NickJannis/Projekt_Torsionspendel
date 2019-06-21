/*
 * Masse.cpp
 *
 *  Created on: 10.06.2019
 *      Author: nick
 */

#include "Masse.h"
#include<iostream>
#include <cmath>
#include<array>
using namespace std;


Masse::Masse() {
	// TODO Auto-generated constructor stub

}
Masse::Masse(const double& pMasse, const double& pAbst, const double& pRai, const double& pRaa, const double& pLaen){
	masse[0]= pMasse;
	masse[1]=0;
	abst[0]=pAbst;
	abst[1]=0;
	rai[0]=pRai;
	rai[1]=0;
	raa[0]=pRaa;
	raa[1]=0;
	laen[0]=pLaen;
	laen[1]= 0;
	this->berechneTraeghm();
}

Masse::Masse(const double& pMasse, const double& pAbst, const double& pRai, const double& pRaa, const double& pLaen, const double& dMasse, const double& dAbst, const double& dTraeghm, const double& dRai, const double& dRaa, const double& dLaen){
	masse[0]= pMasse;
		masse[1]=dMasse;
		abst[0]=pAbst;
		abst[1]=dAbst;
		rai[0]=pRai;
		rai[1]=dRai;
		raa[0]=pRaa;
		raa[1]=dRaa;
		laen[0]=pLaen;
		laen[1]= dLaen;
		this->berechneTraeghm();
}

void Masse::setMasse(const double& pMasse,const double& pFehler){
	masse[0]=pMasse;
	masse[1]=pFehler;
}


void Masse::setAbst(const double& pAbst, const double& pFehler){
	abst[0]=pAbst;
	abst[1]=pFehler;
}
void
Masse::setRai(const double& pRai, const double& pFehler){
	rai[0]=pRai;
	rai[1]=pFehler;
}

void
Masse::setRaa(const double& pRaa, const double& pFehler){
	raa[0]=pRaa;
	raa[1]=pFehler;
}
void
Masse::setLaen(const double& pLaen, const double& pFehler){
	laen[0]=pLaen;
	laen[1]=pFehler;
}


array<double, 2>
Masse::getMasse(){
	return masse;
}
array<double, 2>
Masse::getAbst(){
	return abst;
}
array<double, 2>
Masse::getRai(){
	return rai;
}
array<double, 2>
Masse::getRaa(){
	return raa;
}
array<double, 2>
Masse::getLaen(){
	return laen;
}

array<double, 2>
Masse::getTraeghm(){
	this->berechneTraeghm();
	return traegheitsm;
}

void
Masse::berechneTraeghm(){
	if(!(masse.empty())&&!(rai.empty())&&!(raa.empty())&&!(laen.empty())){
		traegheitsm[0]=(pow(raa[0],2)+pow(rai[0],2)+pow(laen[0],2)/3)*0.25*masse[0];
		traegheitsm[1]=sqrt(pow((pow(raa[0],2)+pow(rai[0],2)+pow(laen[0],2)/3)*0.25*masse[1],2)+pow(0.5*masse[0]*raa[0]*raa[1],2)+pow(0.5*masse[0]*rai[0]*rai[1],2)+pow(0.5*masse[0]*laen[0]*laen[1]/3,2));
	}else{
		cout<<"Fehler beim Berechnen des Traegheitsmoment."<<endl;
	}
}
Masse::~Masse() {
	// TODO Auto-generated destructor stub
}

