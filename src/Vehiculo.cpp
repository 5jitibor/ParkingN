/*
 * Vehiculo.cpp
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo(char* mat,float pre) {
	matricula= new char[strlen(mat)+1];
	for(int i=0;i<=(int)strlen(mat);i++){
		matricula[i]=mat[i];
	}
	precio=pre;
	}

Vehiculo::Vehiculo(const Vehiculo &other) {
	matricula = new char[strlen(other.matricula)+1];
	for(int i=0;i<=(int)strlen(other.matricula);i++){
				matricula[i]=other.matricula[i];
	}
	precio=other.precio;
	estanciaActual= other.estanciaActual;
}

ifstream& operator>> (ifstream& ifs, Vehiculo* a){
	Fecha aux;
	int auxNum;
	ifs>>auxNum;
	aux.setHora(auxNum);
	ifs>>auxNum;
	aux.setMinuto(auxNum);
	a->estanciaActual.setInicio(aux);
	return ifs;
}

ofstream& operator<< (ofstream& ofs, Vehiculo* a){
	ofs<<a->matricula<<endl;
	ofs<<a->estanciaActual.getInicio().getHora()<<endl;
	ofs<<a->estanciaActual.getInicio().getMinuto()<<endl;
	return ofs;
}

void Vehiculo::entrar(){
	estanciaActual.iniciarTiempo();
}

Vehiculo::~Vehiculo() {
	if(matricula!=NULL){
		delete matricula;
	}
}
