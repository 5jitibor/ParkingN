/*
 * ExcepcionDatoNoValido.h
 *
 *  Created on: 30 dic. 2019
 *      Author: User
 */

#ifndef EXCEPCIONDATONOVALIDO_H_
#define EXCEPCIONDATONOVALIDO_H_


#include <stdexcept>

using namespace std;
class ExcepcionDatoNoValido: public runtime_error {
public:
	ExcepcionDatoNoValido():runtime_error("Dato no valido\n\n"){};
};




#endif /* EXCEPCIONDATONOVALIDO_H_ */
