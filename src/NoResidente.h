/*
 * NoResidente.h
 *
 *  Created on: 22 dic. 2019
 *      Author: User
 */

#ifndef NORESIDENTE_H_
#define NORESIDENTE_H_
#include "Vehiculo.h"

class NoResidente: public Vehiculo {
int tiempo;
public:
	NoResidente(char* mat=(char*)"0");
	NoResidente(const NoResidente &other);
	NoResidente& operator=(NoResidente&);
	void salir();
	virtual ~NoResidente();
};

#endif /* NORESIDENTE_H_ */
