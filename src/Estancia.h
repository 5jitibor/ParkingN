/*
 * Estancia.h
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#ifndef ESTANCIA_H_
#define ESTANCIA_H_
#include "Fecha.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
class Estancia {
Fecha inicio;
Fecha fin;

public:
	Estancia();
	void iniciarTiempo();
	void pararTiempo();
	int calcularTiempo();
	friend ifstream& operator>> (ifstream& ifs, Estancia& a);
	friend ofstream& operator<< (ofstream& ofs, Estancia& a);

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
