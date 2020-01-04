/*
 * NoResidente.cpp
 *
 *  Created on: 22 dic. 2019
 *      Author: User
 */

#include "NoResidente.h"

NoResidente::NoResidente(char* mat):Vehiculo(mat,(float)0.02) {
	tiempo=0;
}

NoResidente::NoResidente(const NoResidente &other):Vehiculo(other) {
	tiempo=other.tiempo;
}

NoResidente& NoResidente::operator =(NoResidente& other){
	if(strlen(matricula)!=strlen(other.matricula)){
		delete matricula;
		matricula = new char(strlen(other.matricula)+1);
	}


	for(int i=0;i<=(int)strlen(other.matricula);i++){
				matricula[i]=other.matricula[i];
	}
	if(precio!=other.precio){
		precio=other.precio;
	}
	estanciaActual= other.estanciaActual;
	if(tiempo!=other.tiempo){
		tiempo=other.tiempo;
	}

	return *this;
}

void NoResidente::salir(){

	estanciaActual.pararTiempo();
	float cantidad= estanciaActual.calcularTiempo();
	cantidad*=precio;
	cout<<"Tienes que pagar "<<cantidad<<endl;
	system("pause");
}

NoResidente::~NoResidente() {

}
