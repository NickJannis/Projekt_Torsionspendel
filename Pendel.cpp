/*
 * Pendel.cpp
 *
 *  Created on: 20.06.2019
 *      Author: rene
 */

#include "Pendel.h"
#include "Masse.h"
#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>

using namespace std;


Pendel::Pendel() {
	// TODO Auto-generated constructor stub

}
Pendel::Pendel(const double& pPhi){
	phi[0] = pPhi;
}
Pendel::Pendel(const double& pPhi, const double& pFehler){
	phi[0] = pPhi;
	phi[1] = pFehler;
}
Pendel::void erstelleZylinder(const double& masse, const double& abst, const double& rai, const double& raa, const double& laen, const double& dMasse, const double& dAbst, const double& dRai, const double& dRaa, const double& dLaen){
	zylinder = new Masse(masse, abst, rai, raa, laen, dMasse, dAbst, dRai, dRaa, dLaen);
}
Pendel::void erstelle Stange(const double& masse, const double& rai, const double& raa, const double& laen, const double& dMasse, const double& dRai, const double& dRaa, const double& dLaen){
	stange = new Masse(masse,0, rai, raa, laen, dMasse, 0, dRai, dRaa, dLaen)
}

void Pendel::setPhi(const double& pPhi, const double& pFehler){
	phi[0] = pPhi;
	phi[1] = pFehler;
}

array<double,2> Pendel::getPhi(){
	return phi;
}
double Pendel::berechneOmega(const double& pRichtm, const double& pTraeghmg){
	omega[0] = sqrt (richtm[0]/traegheitsmg[0]);
	omega[1] = sqrt (pow((0.5*(1/sqrt(traegheitsmg[0]*richtm[0])))*richtm[1]),2)+pow((0.5*(sqrt(richtm[0]/pow(traegheitsmg[0],3)))*traegheitsmg[1]),2))
	return omega;
}
void Pendel::berechneTraeghmg(){
	traegheitsmg[0] = (stange.getTraeghm())[0]+ 2* ((zylinder.getMasse())[0]* pow((zylinder.getAbst())[0],2)+ (zylinder.getTraeghm()[0])
	traegheitsmg[1] = sqrt(pow((stange.getTraeghm())[0],2)+ pow((2*pow((zylinder.getAbst())[0],2)*(zylinder.getMasse())[1]),2)+ pow((4*(zylinder.getMasse())[0]*(zylinder.getAbst())[0]*(zylinder.getAbst())[1]),2)+ pow((2*(zylinder.getTraeghm())[1]),2))
}

Pendel::~Pendel() {
	// TODO Auto-generated destructor stub
}

int main(){
	Pendel a;
	a.setPhi(20,0.1);
	cout << a.getPhi()[0] << "/" << a.getPhi()[1] << endl;
	return 0;
}
