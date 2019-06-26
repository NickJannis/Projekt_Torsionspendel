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
	stw[0] = pStw;
}
Pendel::Pendel(const double& pStw, const double& pFehler){
	stw[0] = pStw;
	stw[1] = pFehler;
}

void Pendel::erstelleDraht(const double& rad, const double& laen, const double& tors, const double& dRad, const double& dLaen, const double& dTors){
	draht.setRad(rad, dRad);
	draht.setLaen(laen, dLaen);
	draht.setTorsm(tors, dTors);
}
void Pendel::erstelleZylinder(const double& masse, const double& abst, const double& rai, const double& raa, const double& laen, const double& dMasse, const double& dAbst, const double& dRai, const double& dRaa, const double& dLaen){
	 zylinder.setMasse(masse, dMasse);
	 zylinder.setAbst(abst, dAbst);
	 zylinder.setRai(rai, dRai);
	 zylinder.setRaa(raa, dRaa);
	 zylinder.setLaen(laen, dLaen);
}
void Pendel::erstelleStange(const double& masse, const double& rai, const double& raa, const double& laen, const double& dMasse, const double& dRai, const double& dRaa, const double& dLaen){
	stange.setMasse(masse, dMasse);
	stange.setRai(rai, dRai);
	stange.setRaa(raa, dRaa);
	stange.setLaen(laen, dLaen);
}

void Pendel::setStw(const double& pStw, const double& pFehler){
	stw[0] = pStw;
	stw[1] = pFehler;
}

array<double,2> Pendel::getStw(){
	return stw;
}
void Pendel::berechneOmega(const double& pRichtm, const double& pTraeghmg){
	omega[0] = sqrt (richtm[0]/traegheitsmg[0]);
	omega[1] = sqrt (pow(((0.5*(1/sqrt(traegheitsmg[0]*richtm[0])))*richtm[1]),2)+pow((0.5*(sqrt(richtm[0]/pow(traegheitsmg[0],3)))*traegheitsmg[1]),2));
}
void Pendel::berechneTraeghmg(){
	traegheitsmg[0] = (stange.getTraeghm())[0]+ 2* ((zylinder.getMasse())[0]* pow((zylinder.getAbst())[0],2)+ (zylinder.getTraeghm())[0]);
	traegheitsmg[1] = sqrt(pow((stange.getTraeghm())[0],2)+ pow((2*pow((zylinder.getAbst())[0],2)*(zylinder.getMasse())[1]),2)+ pow((4*(zylinder.getMasse())[0]*(zylinder.getAbst())[0]*(zylinder.getAbst())[1]),2)+ pow((2*(zylinder.getTraeghm())[1]),2));
}

Pendel::~Pendel() {
	// TODO Auto-generated destructor stub
}

int main(){
	Pendel a;
	a.setStw(20,0.1);
	cout << a.getStw()[0] << "/" << a.getStw()[1] << endl;
	return 0;
}
