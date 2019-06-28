#include "Pendel.h"
#include "Masse.h"
#include "Draht.h"
#include<iostream>
#include<vector>
#include<array>
#include<cmath>
#include<string>

using namespace std;


int main(){
	Pendel bei;
	bei.erstelleDraht(0.005, 0.2, 74, 0.001, 0.01, 0.01);
	bei.erstelleZylinder(0.5, 0.2, 0.01, 0.015, 0.03, 0.01, 0.01, 0.01, 0.01, 0.01);
	bei.erstelleStange(0.05, 0.001, 0.0015, 0.2, 0.01, 0.001, 0.001, 0.001);
	bei.setStw(1,0.01);
	bei.berechneOmega();
	array<double,2> ausl = bei.berechneAuslenkung(3.0);
	cout << ausl[0] << " "<<ausl [1] << endl;

	return 0;

}
;
