/*
 * Fecha.h
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class Fecha {
int hora;
int minuto;
public:
	Fecha();
	void insertarFechaActual();
	Fecha operator-(const Fecha&);
	int getHora() const {
		return hora;
	}

	void setHora(int hora) {
		this->hora = hora;
	}

	int getMinuto() const {
		return minuto;
	}

	void setMinuto(int minuto) {
		this->minuto = minuto;
	}
};

#endif /* FECHA_H_ */
