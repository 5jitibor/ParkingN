/*
 * ExcepcionDesbordamientoParking.h
 *
 *  Created on: 30 dic. 2019
 *      Author: User
 */

#ifndef EXCEPCIONDESBORDAMIENTOPARKING_H_
#define EXCEPCIONDESBORDAMIENTOPARKING_H_

#include <stdexcept>

using namespace std;
class ExcepcionDesbordamientoParking: public runtime_error {
public:
	ExcepcionDesbordamientoParking():runtime_error("Desbordamiento Parking\n\n"){};
};





#endif /* EXCEPCIONDESBORDAMIENTOPARKING_H_ */
