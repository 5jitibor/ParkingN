/*
 * Fecha.cpp
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#include "Fecha.h"

Fecha::Fecha() {
	hora=0;
	minuto=0;

}

void Fecha::insertarFechaActual(){
	srand(time((NULL)));
	hora=rand()%24;
	minuto=rand()%60;
}




