/*
 * ExcepcionListaVacia.h
 *
 *  Created on: 31 dic. 2019
 *      Author: User
 */

#ifndef EXCEPCIONLISTAVACIA_H_
#define EXCEPCIONLISTAVACIA_H_
#include <stdexcept>

using namespace std;
class ExcepcionListaVacia: public runtime_error {
public:
	ExcepcionListaVacia():runtime_error("No hay vehiculos\n\n"){};
};


#endif /* EXCEPCIONLISTAVACIA_H_ */
