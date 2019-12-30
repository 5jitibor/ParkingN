/*
 * ExcepcionVehiculoYaExiste.h
 *
 *  Created on: 30 dic. 2019
 *      Author: User
 */

#ifndef EXCEPCIONVEHICULOYAEXISTE_H_
#define EXCEPCIONVEHICULOYAEXISTE_H_

#include <stdexcept>

using namespace std;
class ExcepcionVehiculoYaExiste: public runtime_error {
public:
	ExcepcionVehiculoYaExiste():runtime_error("Ya existe un vehiculo con esa matricula\n\n"){};
};




#endif /* EXCEPCIONVEHICULOYAEXISTE_H_ */
