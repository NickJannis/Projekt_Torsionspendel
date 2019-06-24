/*
 * Draht.cpp
 *
 *  Created on: Jun 21, 2019
 *      Author: m1848568
 */
#define _USE_MATH_DEFINES
#include "Draht.h"
#include<array>
#include<cmath>



using namespace std;

Draht::Draht() {
	// TODO Auto-generated constructor stub

}
Draht::Draht(const double& pRad,const double& pLaen,const double& pTors){
	rad[0]=pRad;
	laen[0]=pLaen;
	torsm[0]=pTors;
	rad[1]=0;
	laen[1]=0;
	torsm[1]=0;
}
Draht::Draht(const double& pRad,const double& pLaen,const double& pTors,const double& dRad,const double& dLaen,const double& dTors){
	rad[0]=pRad;
	rad[1]=dRad;
	laen[0]=pLaen;
	laen[1]=dLaen;
	torsm[0]=pTors;
	torsm[1]=dTors;
}
void
Draht::berechneRichtm(){
	richtm[0]=M_PI*torsm[0]*pow(rad[0],4)/(2*laen[0]);
	richtm[1]=M_PI*sqrt(pow(pow(rad[0],4)*torsm[1]/(2*laen[0]),2)+pow(torsm[0]*pow(rad[0],3)*rad[1]/(8*laen[0]),2)+pow(-torsm[0]*pow(rad[0],4)*laen[1]/(2*pow(laen[0],2)),2));
}
void
Draht::setRad(const double& pRad,const double& pFehler){
	rad[0]=pRad;
	rad[1]=pFehler;
}
void
Draht::setLaen(const double& pLaen, const double& pFehler){
	laen[0]=pLaen;
	laen[1]=pFehler;
}
void
Draht::setTorsm(const double& pTorsm, const double& pFehler){
	torsm[0]=pTorsm;
	torsm[1]=pFehler;
}

array<double, 2>
Draht::getLaen(){
	return laen;
}

array<double,2>
Draht::getRad(){
	return rad;
}
array<double,2>
Draht::getRichtm(){
	this->berechneRichtm();
	return richtm;
}

array<double,2>
Draht::getTorsm(){
	return torsm;
}
int main(){
	Draht bei(0.05, 20.0, 47, 0.01, 0.1, 1);
	array<double, 2> a = bei.getRichtm();
	cout<<a[0]<<", "<<a[1]<<endl;
}

Draht::~Draht() {
	// TODO Auto-generated destructor stub
}

