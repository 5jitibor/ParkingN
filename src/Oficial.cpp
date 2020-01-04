/*
 * Oficial.cpp
 *
 *  Created on: 22 dic. 2019
 *      Author: User
 */

#include "Oficial.h"

Oficial::Oficial(char* mat):Vehiculo(mat,(float)0.0){
	numEstaciones=0;
	estanciasTotales= new Estancia[numEstaciones+1];
}

Oficial::Oficial(const Oficial &other):Vehiculo(other) {
	numEstaciones=other.numEstaciones;
	estanciasTotales= new Estancia[numEstaciones+1];
	for(int i=0;i<other.numEstaciones;i++){
		estanciasTotales[i]=other.estanciasTotales[i];
	}
}

void Oficial::salir(){
	estanciaActual.pararTiempo();
	estanciasTotales[numEstaciones]=estanciaActual;
	numEstaciones++;
	Estancia* auxiliar= new Estancia[numEstaciones+1];

	for(int i=0; i<numEstaciones;i++){
		auxiliar[i]=estanciasTotales[i];
	}
	estanciasTotales=auxiliar;
}

void Oficial::finDeMes(){
	if(numEstaciones >0){
		cout<<"El vehiculo "<<matricula<<":"<<endl;
		for(int i=0;i<numEstaciones;i++){
			cout<<"Estacionamiento "<<i<<":"<<endl;
			cout<<"\tEntrada:\n\t\tHora: "<<estanciasTotales[i].getInicio().getHora()<<"\n\t\tMinuto: "<<estanciasTotales[i].getInicio().getMinuto()<<endl;
			cout<<"\tSalida:\n\t\tHora: "<<estanciasTotales[i].getFin().getHora()<<"\n\t\tMinuto: "<<estanciasTotales[i].getFin().getMinuto()<<endl;
		}
		delete estanciasTotales;
		estanciasTotales= new Estancia[1];
		numEstaciones=0;
		cout<<"Se ha eliminado correctamente todos las estancias"<<endl;
		system("pause");
	}
	else{
		cout<<"El vehiculo oficial "<<matricula<<" no tiene ninguna estancia este mes registrada"<<endl;
	}
}

ostream& operator<< (ostream& os, Oficial& a){
	os<<"Matricula: "<<a.matricula<<endl;
	os<<"Numero de estacionamientos: "<<a.numEstaciones<<endl;
	for(int i=0;i<a.numEstaciones;i++){
		os<<"Estacionamiento "<<i<<":"<<endl;
		os<<"\tEntrada:\n\t\tHora: "<<a.estanciasTotales[i].getInicio().getHora()<<"\n\t\tMinuto: "<<a.estanciasTotales[i].getInicio().getMinuto()<<endl;
		os<<"\tSalida:\n\t\tHora: "<<a.estanciasTotales[i].getFin().getHora()<<"\n\t\tMinuto: "<<a.estanciasTotales[i].getFin().getMinuto()<<endl;
	}
	return os;
}

Oficial& Oficial::operator =(Oficial& other){
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
	if(numEstaciones!=other.numEstaciones){
		numEstaciones=other.numEstaciones;
		delete estanciasTotales;
		estanciasTotales= new Estancia[numEstaciones+1];
	}

	for(int i=0;i<other.numEstaciones;i++){
		estanciasTotales[i]=other.estanciasTotales[i];
	}
	return *this;
}

Oficial::~Oficial() {
	if(estanciasTotales!=NULL){
		delete estanciasTotales;
	}
}



