/*
 * Pendel.cpp
 *
 *  Created on: 20.06.2019
 *      Author: rene
 */

#include "Pendel.h"
#include<iostream>
#include<vector>
#include<array>

using namespace std;


Pendel::Pendel() {
	// TODO Auto-generated constructor stub

}
Pendel::Pendel(const double& pPhi){
	phi[1] = pPhi;
}
Pendel::Pendel(const double& pPhi, const double& pFehler){
	phi[1] = pPhi;
	phi[2] = pFehler;
}
Pendel::void erstelleZylinder(const double& masse, const double& abst, const double& rai, const double& raa, const double& laen, const double& dMasse, const double& dAbst, const double& dRai, const double& dRaa, const double& dLaen){
	zylinder = new Masse(masse, abst, rai, raa, laen, dMasse, dAbst, dRai, dRaa, dLaen);
}
Pendel::void erstelle Stange(const double& masse, const double& rai, const double& raa, const double& laen, const double& dMasse, const double& dRai, const double& dRaa, const double& dLaen){
	stange = new Masse(masse,0, rai, raa, laen, dMasse, 0, dRai, dRaa, dLaen)
}

void Pendel::setPhi(const double& pPhi, const double& pFehler){
	phi[1] = pPhi;
	phi[2] = pFehler;
}

array<double,2> Pendel::getPhi(){
	return phi;
}
array<double,2> Pendel::berechneOmega(const double& pRichtm, const double& pTraeghmg){
	omega[1] = sqrt (richtm[1]/traegheitsmg[1]);
	omega[2] = sqrt (pow((0.5*(1/sqrt(traegheitsmg[1]*richtm[1])))*richtm[2]),2)+pow((0.5*(sqrt(richtm[1]/pow(traegheitsmg[1],3)))*traegheitsmg[2]),2))
	return omega;
}
void Pendel::berechneTraeghmg(){
	traegheitsmg[1] = (stange.getTraeghm())[1]+ 2* ((zylinder.getMasse())[1]* pow((zylinder.getAbst())[1],2)+ (zylinder.getTraeghm()[1])
	traegheitsmg[2] = sqrt(pow((stange.getTraeghm())[2],2)+ pow((2*pow((zylinder.getAbst())[1],2)*(zylinder.getMasse())[2]),2)+ pow((4*(zylinder.getMasse())[1]*(zylinder.getAbst())[1]*(zylinder.getAbst())[2]),2)+ pow((2*(zylinder.getTraeghm())[2]),2))
}

Pendel::~Pendel() {
	// TODO Auto-generated destructor stub
}

