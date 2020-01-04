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

ifstream& operator>> (ifstream& ifs, Estancia& a){
	int auxNum;
	ifs>>auxNum;
	a.inicio.setHora(auxNum);
	ifs>>auxNum;
	a.inicio.setMinuto(auxNum);
	ifs>>auxNum;
	a.fin.setHora(auxNum);
	ifs>>auxNum;
	a.fin.setMinuto(auxNum);


	return ifs;
}
ofstream& operator<< (ofstream& ofs, Estancia& a){
	ofs<<a.inicio.getHora()<<endl;
	ofs<<a.inicio.getMinuto()<<endl;
	ofs<<a.fin.getHora()<<endl;
	ofs<<a.fin.getMinuto()<<endl;
	return ofs;
}
