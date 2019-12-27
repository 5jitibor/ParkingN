/*
 * Aparcamiento.cpp
 *
 *  Created on: 15 dic. 2019
 *      Author: User
 */

#include "Aparcamiento.h"

Aparcamiento::Aparcamiento(int tamParking) {
	// TODO Auto-generated constructor stub
	plazasOcupadas=0;
	plazasTotales=tamParking;
	listaVehiculosOficiales=new Oficial[100];
	listaVehiculosResidentes=new Residente[100];
	parking=new Vehiculo*[plazasTotales];
	for(int i=0;i<plazasTotales;i++){
		parking[i]=NULL;
	}
	estadoActualParking = libre;
	numVehiculosResidentes=0;
	numVehiculosOficiales=0;

}

Aparcamiento::Aparcamiento(const Aparcamiento &other) {
	plazasOcupadas=other.plazasOcupadas;
	plazasTotales=other.plazasTotales;
	parking=new Vehiculo*[plazasTotales];
	for(int i=0;i<plazasTotales;i++){
			parking[i]=other.parking[i];
		}
	estadoActualParking = other.estadoActualParking;
	numVehiculosResidentes=other.numVehiculosOficiales;
	numVehiculosOficiales=other.numVehiculosResidentes;
	listaVehiculosOficiales= new Oficial[100];
	for(int i=0;i<numVehiculosOficiales;i++){
		listaVehiculosOficiales[i]=other.listaVehiculosOficiales[i];
	}
	listaVehiculosResidentes= new Residente[100];
		for(int i=0;i<(numVehiculosResidentes);i++){
			listaVehiculosResidentes[i]=other.listaVehiculosResidentes[i];
		}


}

void Aparcamiento::generarDocumentos(){
	ofstream fsa("Residente.txt");
	fsa<<numVehiculosResidentes<<endl;
	for(int i=0;i<numVehiculosResidentes;i++){
		fsa<<listaVehiculosResidentes[i].getMatricula()<<endl;
		fsa<<listaVehiculosResidentes[i].getTiempoTotal()<<endl;
	}
	fsa.close();

	ofstream fs("Oficial.txt");
	fs<<numVehiculosOficiales<<endl;
	for(int i=0;i<numVehiculosOficiales;i++){
		fs<<listaVehiculosOficiales[i].getMatricula()<<endl;
		fs<<listaVehiculosOficiales[i].getNumEstaciones()<<endl;
		for(int j=0; j<listaVehiculosOficiales[i].getNumEstaciones(); j++){
			fs<<listaVehiculosOficiales[i].getEstanciasTotales()[i].getInicio().getHora()<<endl;
			fs<<listaVehiculosOficiales[i].getEstanciasTotales()[i].getInicio().getMinuto()<<endl;
			fs<<listaVehiculosOficiales[i].getEstanciasTotales()[i].getFin().getHora()<<endl;
			fs<<listaVehiculosOficiales[i].getEstanciasTotales()[i].getFin().getMinuto()<<endl;

		}
	}
	fs.close();
	ofstream fsb("Parking.txt");
	fsb<<plazasTotales<<endl;
	fsb<<plazasOcupadas<<endl;
	for(int i=0;i<plazasTotales;i++){
		if(parking[i]!=NULL){
			fsb<<(*parking[i]).getMatricula()<<endl;
			fsb<<(*parking[i]).getEstanciaActual().getInicio().getHora()<<endl;
			fsb<<(*parking[i]).getEstanciaActual().getInicio().getMinuto()<<endl;

		}
	}
	fsb.close();
}

char* Aparcamiento::pedirMatricula(){
	char* nombre;
	char nombres[200];
	cout<<"Dame el nombre de la matricula: ";
	cin>>nombres;
	nombre=new char(strlen(nombres)+1);
	for(int i=0;i<=(int)strlen(nombres);i++){
		nombre[i]=nombres[i];
	}
	return nombre;
}
void Aparcamiento::menuPrincipal(){
	bool terminar=true;
	char elecciones;
	do{
		cout<<"Que quieres hacer:\n1-Identificar Vehiculo\n2-Fin de mes\n3-Cerrar\nOpcion:";
		cin>>elecciones;
		switch(elecciones){
			case '1':
				identificarMatricula(pedirMatricula());
				break;
			case '2':
				finDeMes();
				break;
			case '3':
				terminar=false;
				break;
			default:
				cout<<"No hay accion en esa posicion"<<endl;
		}

	}while(terminar);
	generarDocumentos();

	cout<<"Adios";
}

void Aparcamiento::identificarMatricula(char* mat){
	char eleccionar=0;
	bool terminar=true;

	do{
		cout<<"Que quieres hacer con el vehiculo "<<mat<<endl<<"1-Registrar Vehiculo Oficial\n2-Registrar Vehiculo Residente\n3-Entrar\n4-Salir\n5-Generar Informe\n6-Cerrar\nOpcion: ";
		cin>>eleccionar;
		switch(eleccionar){
					case '1':
						registarVehiculoOficial(mat);
						break;
					case '2':
						registrarVehiculoResidente(mat);
						break;
					case '3':
						entrarVehiculo(mat);
						break;
					case '4':
						salirVehiculo(mat);
						break;
					case '5':
						generarInforme(mat);
						break;
					case '6':
						terminar=false;
						break;
					default:
						cout<<"No hay accion en esa posicion"<<endl;
				}
	}while(terminar);

}

void Aparcamiento::entrarVehiculo(char* mat){
	if(estadoActualParking==libre){
		if(comprobarListaParking(mat)==-1){
			cout<<"encuentra"<<endl;
			if(comprobarListaResidente(mat)>-1){
				parking[buscarSitio()]=&listaVehiculosResidentes[comprobarListaResidente(mat)];
				cout<<"Ha entrado el vehiculo Residente con la matricula "<<mat<<endl;
			}
			else if(comprobarListaOficial(mat)>-1){
				parking[buscarSitio()]=&listaVehiculosOficiales[comprobarListaOficial(mat)];
				cout<<"Ha entrado el vehiculo Oficial con la matricula "<<mat<<endl;
			}
			else{
				NoResidente *aux= new NoResidente(mat);
				parking[buscarSitio()]= aux;
				cout<<"Ha entrado el vehiculo No residente con la matricula "<<mat<<endl;
			}
			parking[comprobarListaParking(mat)]->entrar();
			plazasOcupadas++;
			if(plazasOcupadas+1 == plazasTotales){
				estadoActualParking= completo;
			}
		}
		else{
			cout<<"El vehiculo ya esta dentro"<<endl;
		}
	}

	else{
		cout<<"No caben mas vehiculos"<<endl;
	}

}

void Aparcamiento::salirVehiculo(char* mat){
	if(comprobarListaParking(mat)>-1){
		parking[comprobarListaParking(mat)]->salir();
		parking[comprobarListaParking(mat)]=NULL;
		cout<<"Ha salido el vehiculo "<<mat<<endl;
		if(plazasOcupadas+1 == plazasTotales){
			estadoActualParking= libre;
		}
		plazasOcupadas--;

	}
	else{
		cout<<"Este vehiculo no esta dentro"<<endl;
	}
}

int Aparcamiento::buscarSitio(){
	for(int i=0;i<plazasTotales;i++){
		if(parking[i]==NULL){
			return i;
		}
	}
	return -1;
}


void Aparcamiento::registarVehiculoOficial(char *matri){
	if(comprobarListaOficial(matri)>-1){
		cout<<"Ya es un vehiculo Oficial"<<endl;
	}
	else if(comprobarListaResidente(matri)>-1){
		cout<<"Es un vehiculo Residente y no puede ser Oficial"<<endl;
	}
	else{
		listaVehiculosOficiales[numVehiculosOficiales].setMatricula(matri);
		cout<<"Se ha registrado "<<listaVehiculosOficiales[numVehiculosOficiales].getMatricula()<<" como oficial"<<endl;
		numVehiculosOficiales++;
	}



}

void Aparcamiento::registrarVehiculoResidente(char *matri){

	if(comprobarListaResidente(matri)>-1){
			cout<<"Ya es un vehiculo Residente"<<endl;
		}
	else if(comprobarListaOficial(matri)>-1){
		cout<<"Es un vehiculo Oficial y no puede ser Residente"<<endl;
	}
	else{
		listaVehiculosResidentes[numVehiculosResidentes].setMatricula(matri);
		cout<<"Se ha registrado "<<listaVehiculosResidentes[numVehiculosResidentes].getMatricula()<<" como Residente"<<endl;
		numVehiculosResidentes++;
	}

}

int Aparcamiento::comprobarListaResidente(char* mat){
	bool iguales=false;
	char * mataux;
	for(int i=0;i<numVehiculosResidentes;i++){
		mataux=listaVehiculosResidentes[i].getMatricula();
		if(strlen(mataux)==strlen(mat)){
				iguales=true;

				for(int j=0;j<(int)sizeof(mat);j++){
					if(mat[j]!=mataux[j]){
						iguales=false;
						break;
						}
					}
				if(iguales){
					return i;
				}
			}

	}
	return -1;
}


int Aparcamiento::comprobarListaParking(char* mat){
	bool iguales=false;
	char * mataux;
	for(int i=0;i<plazasTotales;i++){
		if(parking[i]!=NULL){
			mataux=parking[i]->getMatricula();
			if(strlen(mataux)==strlen(mat)){
					iguales=true;

					for(int j=0;j<(int)sizeof(mat);j++){
						if(mat[j]!=mataux[j]){
							iguales=false;
							break;
							}
						}
					if(iguales){
						return i;
					}

			}
		}

	}
	return -1;
}

int Aparcamiento::comprobarListaOficial(char* mat){
	bool iguales=false;

	for(int i=0;i<numVehiculosOficiales;i++){
		char* mataux=listaVehiculosOficiales[i].getMatricula();
		if(strlen(mataux)==strlen(mat)){
			iguales=true;
			for(int j=0;j<(int)sizeof(mat);j++){
				if(mat[j]!=mataux[j]){
					iguales=false;
				}
			}
			if(iguales){
				return i;
			}
		}
	}
	return -1;
}

void Aparcamiento::finDeMes(){
	for(int i=0;i<numVehiculosOficiales;i++){
		listaVehiculosOficiales[i].finDeMes();
	}
	for(int i=0;i<numVehiculosResidentes;i++){
			listaVehiculosResidentes[i].finDeMes();
	}
}

void Aparcamiento::generarInforme(char* mat){
	if(comprobarListaResidente(mat)>-1){
		listaVehiculosResidentes[comprobarListaResidente(mat)].generarInforme();
	}
	else{
		cout<<"Este vehiculo no es residente"<<endl;
	}

}
Aparcamiento::~Aparcamiento() {
	if(listaVehiculosOficiales!=NULL){
		delete listaVehiculosOficiales;
	}
	if(listaVehiculosResidentes!=NULL){
			delete listaVehiculosResidentes;
		}
}



