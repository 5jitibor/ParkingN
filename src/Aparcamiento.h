/*
 * Aparcamiento.h
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#ifndef APARCAMIENTO_H_
#define APARCAMIENTO_H_
#include <iostream>
#include "Oficial.h"
#include "Residente.h"
#include "NoResidente.h"
#include "string.h"
#include <fstream>
using namespace std;
enum estadoParking{
	libre,
	completo
};

class Aparcamiento {
	int plazasOcupadas;
	int plazasTotales;
	int numVehiculosOficiales;
	int numVehiculosResidentes;
	Oficial* listaVehiculosOficiales;
	Residente* listaVehiculosResidentes;
	Vehiculo** parking;
	estadoParking estadoActualParking;
public:
	Aparcamiento(int tamParking=30);
	virtual ~Aparcamiento();
	Aparcamiento(const Aparcamiento &other);
	void introducirDocumentos();
	void registarVehiculoOficial(char*);
	void registrarVehiculoResidente(char*);
	void identificarMatricula(char*);
	void generarInforme(char*);
	void entrarVehiculo(char*);
	void salirVehiculo(char *);
	void generarDocumentos();
	void finDeMes();
	int comprobarListaResidente(char*);
	int comprobarListaOficial(char*);
	int comprobarListaParking(char*);
	int buscarSitio();
	void menuPrincipal();
	char* pedirMatricula();
};

#endif /* APARCAMIENTO_H_ */
