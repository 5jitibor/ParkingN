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
	char *nombrefichero= new char[strlen(matricula)+strlen(aux)+1];
	for(int i=0;i<(int)strlen(matricula);i++){
		nombrefichero[i]=matricula[i];
	}
	for(int i=0;i<=(int)strlen(aux);i++){
		nombrefichero[i+strlen(matricula)]=aux[i];
	}
	ofstream fsr(nombrefichero);
	fsr<<"Informe del vehiculo residente"<<endl;
	fsr<<"Matricula: "<<matricula<<endl;
	fsr<<"Minutos este mes: "<<tiempoTotal<<" minutos"<<endl;
	fsr<<"Tiene que pagar: "<<tiempoTotal*precio<<" euros"<<endl;
	fsr.close();
	cout<<"Se ha generado correctamente el documento\n"<<endl;
}

ostream& operator<< (ostream& os, Residente& a){
	os<<a.matricula<<endl;
	os<<"Tiempo: "<<a.tiempoTotal<<endl;
	os<<"Pago Total: "<<(a.tiempoTotal*a.precio)<<endl;
	return os;
}

void Residente::finDeMes(){
	cout<<"El vehiculo "<<matricula<<" tiene que pagar "<<tiempoTotal*precio<<" euros"<<endl;
	system("pause");
	tiempoTotal=0;
}

Residente::~Residente(){

}



