/*
 * Estancia.cpp
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#include "Estancia.h"

Estancia::Estancia() {
	// TODO Auto-generated constructor stub

}

void Estancia::iniciarTiempo(){
	inicio.insertarFechaActual();
}

void Estancia::pararTiempo(){
	fin.insertarFechaActual();
}

int  Estancia::calcularTiempo(){
	int minutos=fin.getMinuto()-inicio.getMinuto();

	int hora=fin.getMinuto()-inicio.getHora();
	if(minutos<0){
		minutos+=60;
		hora--;
	}
	if(hora<0){
		hora+=24;
	}
	return (hora*24)+minutos;
}

