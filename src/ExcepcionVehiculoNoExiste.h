/*
 * ExcepcionVehiculoNoExiste.h
 *
 *  Created on: 30 dic. 2019
 *      Author: User
 */

#ifndef EXCEPCIONVEHICULONOEXISTE_H_
#define EXCEPCIONVEHICULONOEXISTE_H_

#include <stdexcept>

using namespace std;
class ExcepcionVehiculoNoExiste: public runtime_error {
public:
	ExcepcionVehiculoNoExiste():runtime_error("No existe ese vehiculo con esa matricula\n\n"){};
};




#endif /* EXCEPCIONVEHICULOYAEXISTE_H_ */
