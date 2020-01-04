/*
 * Residente.h
 *
 *  Created on: 22 dic. 2019
 *      Author: User
 */

#ifndef RESIDENTE_H_
#define RESIDENTE_H_

#include "Vehiculo.h"
#include <fstream>
class Residente: public Vehiculo {
int tiempoTotal;
public:
	Residente(char* mat=(char*)"0");
	virtual ~Residente();
	void salir();
	void finDeMes();
	void generarInforme();
	Residente& operator =(Residente&);
	friend ostream& operator<< (ostream& os, Residente& a);
	friend ofstream& operator<< (ofstream& ofs, Residente& a);
	friend ifstream& operator>> (ifstream& ifs, Residente& a);
	Residente(const Residente &other);

	int getTiempoTotal() const {
		return tiempoTotal;
	}

	void setTiempoTotal(int tiempoTotal) {
		this->tiempoTotal = tiempoTotal;
	}
};

#endif /* RESIDENTE_H_ */
