/*
 * Estancia.h
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#ifndef ESTANCIA_H_
#define ESTANCIA_H_
#include "Fecha.h"
class Estancia {
Fecha inicio;
Fecha fin;

public:
	Estancia();
	void iniciarTiempo();
	void pararTiempo();
	int calcularTiempo();

	const Fecha& getFin() const {
		return fin;
	}

	void setFin(const Fecha &fin) {
		this->fin = fin;
	}

	const Fecha& getInicio() const {
		return inicio;
	}

	void setInicio(const Fecha &inicio) {
		this->inicio = inicio;
	}
};

#endif /* ESTANCIA_H_ */
