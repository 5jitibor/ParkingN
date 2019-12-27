/*
 * Residente.cpp
 *
 *  Created on: 22 dic. 2019
 *      Author: User
 */

#include "Residente.h"

Residente::Residente(char* mat):Vehiculo(mat,(float)0.002) {
	tiempoTotal=0;
}

Residente::Residente(const Residente &other):Vehiculo(other) {
	tiempoTotal=other.tiempoTotal;
}

void Residente::salir(){
	estanciaActual.pararTiempo();
	tiempoTotal+=estanciaActual.calcularTiempo();
}

Residente& Residente::operator =(Residente& other){
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
	if(tiempoTotal!=other.tiempoTotal){
		tiempoTotal=other.tiempoTotal;
	}

	return *this;
}

void Residente::generarInforme(){
	char* aux=(char *)".txt";
	char *nombrefichero= new char(strlen(matricula)+strlen(aux)+1);
	for(int i=0;i<(int)strlen(matricula);i++){
		nombrefichero[i]=matricula[i];
	}
	for(int i=0;i<=(int)strlen(aux);i++){
		nombrefichero[i+strlen(matricula)]=aux[i];
	}
	ofstream fs(nombrefichero);
	fs<<"Informe del vehiculo residente "<<endl;
	fs<<"Matricula: "<<matricula<<endl;
	fs<<"Minutos este mes: "<<tiempoTotal<<" minutos"<<endl;
	fs<<"Tiene que pagar: "<<tiempoTotal*precio<<" euros"<<endl;
	fs.close();
}

void Residente::finDeMes(){

	cout<<"El vehiculo "<<matricula<<" tiene que pagar "<<tiempoTotal*precio<<" euros"<<endl;
	system("pause");
	tiempoTotal=0;
}

Residente::~Residente(){

}



