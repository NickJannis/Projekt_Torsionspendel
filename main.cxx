/*
 * main.cxx
 *
 *  Created on: 14.06.2019
 *      Author: nick
 */
#include<iostream>
#include"Masse.h"

using namespace std;

main(){
	Beispielmasse = new Masse();
	Beispielmasse.setMasse(200.0, 0.1);
	cout<<Beispielmasse.getMasse().front()<<", "<< Beispielmasse.getMasse().back()<<endl;
}



