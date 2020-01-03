/*
 * Oficial.h
 *
 *  Created on: 22 dic. 2019
 *      Author: User
 */

#ifndef OFICIAL_H_
#define OFICIAL_H_

#include "Vehiculo.h"

class Oficial: public Vehiculo {
int numEstaciones;
Estancia* estanciasTotales;
public:

	Oficial(char* mat=(char*)"0");
	void salir();
	void finDeMes();
	Oficial(const Oficial &other);
	virtual ~Oficial();
	Oficial& operator =(Oficial&);
	friend ostream& operator<< (ostream& os, Oficial& a);
	const Estancia* getEstanciasTotales() const {
		return estanciasTotales;
	}

	void setEstanciasTotales(Estancia *estanciasTotal) {
		estanciasTotales = new Estancia[numEstaciones+1];
		for(int i=0;i<numEstaciones;i++){
			estanciasTotales[i]=estanciasTotal[i];
		}
	}

	int getNumEstaciones() const {
		return numEstaciones;
	}

	void setNumEstaciones(int numEstaciones) {
		this->numEstaciones = numEstaciones;
	}
};

#endif /* OFICIAL_H_ */
