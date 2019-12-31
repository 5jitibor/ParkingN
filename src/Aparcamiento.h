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
#include "ExcepcionDatoNoValido.h"
#include "ExcepcionDesbordamientoParking.h"
#include "ExcepcionVehiculoNoExiste.h"
#include "ExcepcionNoExisteFichero.h"
#include "ExcepcionVehiculoNoValido.h"
#include "ExcepcionVehiculoYaExiste.h"
#include "ExcepcionListaVacia.h"
#include <stdlib.h>
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
	Aparcamiento& operator=(Aparcamiento &other);
	void introducirDocumentos();
	void menuPrincipal();
	void menuVer();
	void verResidentes();
	void verOficiales();
	void menuTipoVehiculo();
	void menuParking();
	void menuGuardar();
	void menuCargar();
	void seleccionarPlazasParking();
	void identificarMatricula(char*);
	void generarInforme(char*);
	void generarDocumentos();
	void mostrarAparcamiento();
	void finDeMes();
	void registarVehiculoOficial(char*);
	void registrarVehiculoResidente(char*);
	void entrarVehiculo(char*);
	void salirVehiculo(char *);
	int comprobarListaResidente(char*);
	int comprobarListaOficial(char*);
	int comprobarListaParking(char*);
	int buscarSitio();

	char* pedirMatricula();
};

#endif /* APARCAMIENTO_H_ */
