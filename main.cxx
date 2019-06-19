#include "Masse.h"
#include<iostream>
#include <cmath>
using namespace std;

int main(){
	Masse bei;
	bei.setRai(8.3, 0.2);
	bei.setRaa(9.3, 0.2);
	bei.setLaen(5.0, 0.2);
	vector<double> p1 = bei.getRai();
	double pp1 = p1.front();
	double pp2= p1.back();
	cout<<pp1<<", "<<pp2<<endl;

	p1 = bei.getRaa();
	pp1 = p1.front();
	pp2= p1.back();
	cout<<pp1<<", "<<pp2<<endl;

	p1 = bei.getLaen();
	pp1 = p1.front();
	pp2= p1.back();
	cout<<pp1<<", "<<pp2<<endl;
	return 0;
}
