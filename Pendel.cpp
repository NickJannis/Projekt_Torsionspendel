/*
 * Pendel.cpp
 *
 *  Created on: 20.06.2019
 *      Author: rene
 */
#define _USE_MATH_DEFINES
#include "Pendel.h"
#include "Masse.h"
#include "Draht.h"
#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>

using namespace std;


Pendel::Pendel() {
	// TODO Auto-generated constructor stub

}
Pendel::Pendel(const double& pStw){
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
void Pendel::berechneOmega(){
	this->berechneTraeghmg();
	array<double,2> richtm= draht.getRichtm();
	omega[0] = sqrt (richtm[0]/traegheitsmg[0]);
	omega[1] = sqrt (pow(((0.5*(1/sqrt(traegheitsmg[0]*richtm[0])))*richtm[1]),2)+pow((0.5*(sqrt(richtm[0]/pow(traegheitsmg[0],3)))*traegheitsmg[1]),2));
}
void Pendel::berechneTraeghmg(){
	stange.berechneTraeghm();
	zylinder.berechneTraeghm();
	traegheitsmg[0] = (stange.getTraeghm())[0]+ 2* ((zylinder.getMasse())[0]* pow((zylinder.getAbst())[0],2)+ (zylinder.getTraeghm())[0]);
	traegheitsmg[1] = sqrt(pow((stange.getTraeghm())[0],2)+ pow((2*pow((zylinder.getAbst())[0],2)*(zylinder.getMasse())[1]),2)+ pow((4*(zylinder.getMasse())[0]*(zylinder.getAbst())[0]*(zylinder.getAbst())[1]),2)+ pow((2*(zylinder.getTraeghm())[1]),2));
}

array<double,2> Pendel::berechneAuslenkung(const double& zeit){
	array<double,2> ausl;
	ausl[0] = stw[0]* sin(omega[0]* zeit + (M_PI/2));
	ausl[1] = sqrt(pow(sin(omega[0]*zeit+(M_PI/2))*stw[1],2)+pow(stw[0]*zeit*cos(omega[0]*zeit+(M_PI/2))*omega[1],2));
	return ausl;
}

Pendel::~Pendel() {
	// TODO Auto-generated destructor stub
}

int main{
	erstelleDraht(0.005, 0.2, 74, 0.001, 0.01, 0.01);
	erstelleZylinder(0.5, 0.2, 0.01, 0.015, 0.03, 0.01, 0.01, 0.01, 0.01, 0.01);
	erstelleStange(0.05, 0.001, 0.0015, 0.2, 0.01, 0.001, 0.001, 0.001);
	setStw(1,0.01);
	berechneOmega();
	array<double,2> ausl = this->berechneAuslenkung(3.0);
	cout << ausl[0] << ausl [1] << endl;



}
