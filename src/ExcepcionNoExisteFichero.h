/*
 * ExcepcionNoExisteFichero.h
 *
 *  Created on: 30 dic. 2019
 *      Author: User
 */

#ifndef EXCEPCIONNOEXISTEFICHERO_H_
#define EXCEPCIONNOEXISTEFICHERO_H_

#include <stdexcept>

using namespace std;
class ExcepcionNoExisteFichero: public runtime_error {
public:
	ExcepcionNoExisteFichero():runtime_error("No existe el fichero\n\n"){};
};





#endif /* EXCEPCIONNOEXISTEFICHERO_H_ */
