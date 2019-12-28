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

	const Estancia* getEstanciasTotales() const {
		return estanciasTotales;
	}

	void setEstanciasTotales(Estancia *estanciasTotal) {
		this->estanciasTotales = estanciasTotal;
	}

	int getNumEstaciones() const {
		return numEstaciones;
	}

	void setNumEstaciones(int numEstaciones) {
		this->numEstaciones = numEstaciones;
	}
};

#endif /* OFICIAL_H_ */