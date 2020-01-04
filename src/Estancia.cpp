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
	Fecha aux;
	aux=fin-inicio;
	return(aux.getHora()*60)+aux.getMinuto();
}

