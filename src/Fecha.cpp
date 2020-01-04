/*
 * Fecha.cpp
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#include "Fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
Fecha::Fecha() {
	hora=0;
	minuto=0;

}

void Fecha::insertarFechaActual(){
	srand(time((NULL)));
	hora=rand()%24;
	minuto=rand()%60;
}

Fecha Fecha::operator-(const Fecha& ini){
	Fecha aux;

	aux.minuto=minuto-ini.getMinuto();

	aux.hora=hora-ini.getHora();
	if(aux.minuto<0){
		aux.minuto+=60;
		hora--;
	}
	if(aux.hora<0){
		aux.hora+=24;
	}
	return aux;
}


