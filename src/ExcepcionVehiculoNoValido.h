/*
 * VehiculoNoValido.h
 *
 *  Created on: 30 dic. 2019
 *      Author: User
 */

#ifndef EXCEPCIONVEHICULONOVALIDO_H_
#define EXCEPCIONVEHICULONOVALIDO_H_

#include <stdexcept>

using namespace std;
class ExcepcionVehiculoNoValido: public runtime_error {
public:
	ExcepcionVehiculoNoValido():runtime_error("Vehiculo no valido\n\n"){};
};



#endif /* EXCEPCIONVEHICULONOVALIDO_H_ */
