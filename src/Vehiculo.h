/*
 * Vehiculo.h
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#ifndef VEHICULO_H_
#define VEHICULO_H_
#include "string.h"
#include "Estancia.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
enum estadoVehiculo{
	fuera,
	dentro
};
class Vehiculo {
protected:
 char* matricula;
 float precio;
 Estancia estanciaActual;
public:
 	Vehiculo(char* mat=(char*)"0\0",float pre=0.0);
	void entrar();
	Vehiculo(const Vehiculo &other);
	virtual void salir()=0;
	friend ifstream& operator>> (ifstream& ifs, Vehiculo* a);
	friend ofstream& operator<< (ofstream& ofs, Vehiculo* a);
	char* getMatricula() const {
		return matricula;
	}

	void setMatricula(char *matri) {
		matricula= new char[strlen(matri)+1];
		for(int i=0;i<=(int)strlen(matri);i++){
			matricula[i] = matri[i];
		}

	}
	virtual ~Vehiculo();

	const Estancia& getEstanciaActual() const {
		return estanciaActual;
	}

	void setEstanciaActual(const Estancia &estanciaActual) {
		this->estanciaActual = estanciaActual;
	}

	float getPrecio() const {
		return precio;
	}

	void setPrecio(float precio) {
		this->precio = precio;
	}
};

#endif /* VEHICULO_H_ */
