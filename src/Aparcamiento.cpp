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
	listaVehiculosOficiales=new Oficial[1];
	listaVehiculosResidentes=new Residente[1];
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
	listaVehiculosOficiales= new Oficial[numVehiculosOficiales+1];
	for(int i=0;i<numVehiculosOficiales;i++){
		listaVehiculosOficiales[i]=other.listaVehiculosOficiales[i];
	}
	listaVehiculosResidentes= new Residente[numVehiculosResidentes+1];
		for(int i=0;i<(numVehiculosResidentes);i++){
			listaVehiculosResidentes[i]=other.listaVehiculosResidentes[i];
		}

}

Aparcamiento& Aparcamiento::operator =(Aparcamiento& other){
	plazasOcupadas=other.plazasOcupadas;
	plazasTotales=other.plazasTotales;
	delete parking;
	parking=new Vehiculo*[plazasTotales];
	for(int i=0;i<plazasTotales;i++){
			parking[i]=other.parking[i];
		}
	estadoActualParking = other.estadoActualParking;
	numVehiculosResidentes=other.numVehiculosOficiales;
	numVehiculosOficiales=other.numVehiculosResidentes;
	delete listaVehiculosOficiales;
	listaVehiculosOficiales= new Oficial[numVehiculosOficiales+1];
	for(int i=0;i<numVehiculosOficiales;i++){
		listaVehiculosOficiales[i]=other.listaVehiculosOficiales[i];
	}
	delete listaVehiculosResidentes;
	listaVehiculosResidentes= new Residente[numVehiculosResidentes+1];
		for(int i=0;i<(numVehiculosResidentes);i++){
			listaVehiculosResidentes[i]=other.listaVehiculosResidentes[i];
		}

	return *this;
}

void Aparcamiento::introducirDocumentos(){
	int auxNum;
	char aux[100];
	char* matri;
	try{

		ifstream fer("Residente.txt");
		if(fer.good()){
			fer>>numVehiculosResidentes;
			delete listaVehiculosResidentes;
			listaVehiculosResidentes = new Residente[numVehiculosResidentes+1];
			for(int i=0;i<numVehiculosResidentes;i++){
				fer>>listaVehiculosResidentes[i];
			}
		}
		else{
			throw ExcepcionNoExisteFichero();
		}
		fer.close();
	}catch(ExcepcionNoExisteFichero& ed){
			cout<< ed.what();
	}

	try{
		ifstream feo("Oficial.txt");
		if(feo.good()){
			feo>>numVehiculosOficiales;
			delete listaVehiculosOficiales;
			listaVehiculosOficiales = new Oficial[numVehiculosOficiales+1];
			for(int i=0;i<numVehiculosOficiales;i++){
				feo>>listaVehiculosOficiales[i];
			}
		}
		else{
			throw ExcepcionNoExisteFichero();
		}
		feo.close();

	}catch(ExcepcionNoExisteFichero& ed){
			cout<< ed.what();
	}

	try{
		int posicion;
		ifstream fep("Parking.txt");
		if(fep.good()){
			fep>>plazasTotales;
			delete parking;
			parking= new Vehiculo*[plazasTotales];
			for(int i=0;i<plazasTotales;i++){
					parking[i]=NULL;
			}

			fep>>plazasOcupadas;
			for(int i=0;i<plazasOcupadas;i++){
				fep>>auxNum;
				fep>> aux;
				matri= new char[strlen(aux)+1];
				for(int j=0; j<=(int)strlen(aux);j++){
					matri[j]=aux[j];
				}
				if((posicion=comprobarListaResidente(matri))>-1){
					parking[auxNum]=&listaVehiculosResidentes[posicion];
				}
				else if((posicion=comprobarListaOficial(matri))>-1){
					parking[auxNum]=&listaVehiculosOficiales[posicion];
				}
				else{
					NoResidente *auxNo= new NoResidente(matri);
					parking[auxNum]= auxNo;
				}
				fep>>parking[auxNum];
			}
		}
		else{
			seleccionarPlazasParking();
			throw ExcepcionNoExisteFichero();
		}
		fep.close();
	}catch(ExcepcionNoExisteFichero& ed){
			cout<< ed.what();
		}
}

void Aparcamiento::generarDocumentos(){
	ofstream fsa("Residente.txt");
	fsa<<numVehiculosResidentes<<endl;
	for(int i=0;i<numVehiculosResidentes;i++){
		fsa<<listaVehiculosResidentes[i];
	}
	fsa.close();

	ofstream fs("Oficial.txt");
	fs<<numVehiculosOficiales<<endl;
	for(int i=0;i<numVehiculosOficiales;i++){
		fs<<listaVehiculosOficiales[i];
	}
	fs.close();

	ofstream fsb("Parking.txt");
	fsb<<plazasTotales<<endl;
	fsb<<plazasOcupadas<<endl;
	for(int i=0;i<plazasTotales;i++){
		if(parking[i]!=NULL){
			fsb<<i<<endl;
			fsb<<parking[i];
		}
	}
	fsb.close();
}
void Aparcamiento::mostrarAparcamiento(){
	cout<<"Plazas del parking:"<<endl;
	for(int i=0;i<plazasTotales;i++){
		cout<<"Plaza "<<i<<": ";
		if(parking[i] !=NULL){
			cout<<(*parking[i]).getMatricula()<<endl;
		}
		else{
			cout<<"Libre"<<endl;
		}
	}
	cout<<endl;
}

char* Aparcamiento::pedirMatricula(){
	char* nombre=NULL;
	char nombres[100];
	fflush(stdin);
	cout<<"Dame la matricula: ";
	cin>>nombres;
	nombre=new char[strlen(nombres)+1];
	for(int i=0;i<=(int)strlen(nombres);i++){
		nombre[i]=nombres[i];
	}
	cout<<endl;
	return nombre;
}

void Aparcamiento::menuPrincipal(){
	menuCargar();
	bool terminar=true;
	char elecciones;
	do{
		fflush(stdin);
		cout<<"Que quieres hacer:\n1-Identificar Vehiculo\n2-Fin de mes\n3-Mostrar Listas\n4-Salir\nOpcion:";
		cin>>elecciones;
		cout<<"\n";
		try{
			switch(elecciones){
				case '1':
					identificarMatricula(pedirMatricula());
					break;
				case '2':
					finDeMes();
					break;
				case '3':
					menuVer();
					break;
				case '4':
					menuGuardar();
					terminar=false;
					break;
				default:
					throw ExcepcionDatoNoValido();
					}
			}catch(ExcepcionDatoNoValido& ed){
				cout<< ed.what();
			}
	}while(terminar);
	cout<<"Adios";
}

void Aparcamiento::menuCargar(){
	bool terminated=true;
		char elecciones;
		do{
			terminated=false;
			fflush(stdin);
			cout<<"Quieres cargar desde fichero:\nSi (S) o No(N)\nOpcion:";
			cin>>elecciones;
			cout<<"\n";
			try{
				switch(elecciones){
					case 'S':
						introducirDocumentos();
						cout<<"Se ha cargado correctamente\n"<<endl;
						break;
					case 'N':
						cout<<"No se han cargado datos de fichero\n"<<endl;
						seleccionarPlazasParking();
						break;

					default:
						terminated=true;
						throw ExcepcionDatoNoValido();
						}
				}catch(ExcepcionDatoNoValido& ed){
					cout<< ed.what();
				}catch(ExcepcionListaVacia& ed){
					cout<< ed.what();
				}

	}while(terminated);
}


void Aparcamiento::menuGuardar(){
	bool terminated=true;
	char elecciones;
	do{
		terminated=false;
		fflush(stdin);
		cout<<"Quieres guardar los cambios:\nSi (S) o No(N)\nOpcion:";
		cin>>elecciones;
		cout<<"\n";
		try{
			switch(elecciones){
				case 'S':
					generarDocumentos();
					cout<<"Se ha guardado correctamente"<<endl;
					break;
				case 'N':
					cout<<"No se han guardado los cambios"<<endl;
					break;

				default:
					terminated=true;
					throw ExcepcionDatoNoValido();
					}
			}catch(ExcepcionDatoNoValido& ed){
				cout<< ed.what();
			}catch(ExcepcionListaVacia& ed){
				cout<< ed.what();
			}

	}while(terminated);
}

void Aparcamiento::menuVer(){
	bool terminar=true;
	char elecciones;
	do{
		terminar=false;
		fflush(stdin);
		cout<<"Que quieres mostrar:\n1-Oficiales\n2-Residente\n3-Parking\n4-Volver\nOpcion:";
		cin>>elecciones;
		cout<<"\n";
		try{
			switch(elecciones){
				case '1':
					if(numVehiculosOficiales>0){
						cout<<"Vehiculos oficiales:"<<endl;
						for(int i=0;i<numVehiculosOficiales;i++){
							cout<<"Vehiculo "<<i<<": ";
							cout<<listaVehiculosOficiales[i];
						}
						cout<<endl;
					}
					else{
						throw ExcepcionListaVacia();
					}
					break;
				case '2':

					if(numVehiculosResidentes>0){
					cout<<"Vehiculos residentes:"<<endl;
					for(int i=0;i<numVehiculosResidentes;i++){
						cout<<"Vehiculo "<<i<<": ";
						cout<<listaVehiculosResidentes[i];
					}
					cout<<endl;
					}
					else{
						throw ExcepcionListaVacia();
					}
					break;
				case '3':
					mostrarAparcamiento();
					break;
				case '4':
					terminar=false;
					break;
				default:
					terminar=true;
					throw ExcepcionDatoNoValido();
					}
			}catch(ExcepcionDatoNoValido& ed){
				cout<< ed.what();
			}catch(ExcepcionListaVacia& ed){
				cout<< ed.what();
			}

	}while(terminar);
}

void Aparcamiento::menuTipoVehiculo(char* mat){
	bool terminar=true;
	char elecciones;
	int aux=0;
	do{
		aux=0;
		terminar=false;
		fflush(stdin);
		cout<<"Que quieres hacer:\n1-Gestion oficial\n2-Gestion residente\n3-Volver\nOpcion:";
		cin>>elecciones;
		cout<<"\n";
		try{
			switch(elecciones){
				case '1':
					aux=menuOficial(mat);
					break;
				case '2':
					aux=menuResidente(mat);
					break;
				case '3':
					break;
				default:
					terminar=true;
					throw ExcepcionDatoNoValido();
					}
				if(aux){
					terminar=true;
					}
			}catch(ExcepcionDatoNoValido& ed){
				cout<< ed.what();
			}catch(ExcepcionListaVacia& ed){
				cout<< ed.what();
			}

		}while(terminar);
}

int Aparcamiento::menuOficial(char* mat){
	bool terminar=true;
		char elecciones;
		do{
			terminar=false;
			fflush(stdin);
			cout<<"Que quieres hacer como vehiculo oficial:\n1-Registrar\n2-Eliminar\n3-Volver\nOpcion:";
			cin>>elecciones;
			cout<<"\n";
			try{
				switch(elecciones){
					case '1':
						registrarVehiculoOficial(mat);
						break;
					case '2':
						eliminarVehiculoOficial(mat);
						break;
					case '3':
						return 1;
						break;
					default:
						terminar=true;
						throw ExcepcionDatoNoValido();
						}
				}catch(ExcepcionDatoNoValido& ed){
					cout<< ed.what();
				}catch(ExcepcionListaVacia& ed){
					cout<< ed.what();
				}

		}while(terminar);
		return 0;
}

int Aparcamiento::menuResidente(char* mat){
	bool terminar=true;
		char elecciones;
		do{
			terminar=false;
			fflush(stdin);
			cout<<"Que quieres hacer como vehiculo residente:\n1-Registrar\n2-Eliminar\n3-Volver\nOpcion:";
			cin>>elecciones;
			cout<<"\n";
			try{
				switch(elecciones){
					case '1':
						registrarVehiculoResidente(mat);
						break;
					case '2':
						eliminarVehiculoResidente(mat);
						break;
					case '3':
						return 1;
						break;
					default:
						terminar=true;
						throw ExcepcionDatoNoValido();
						}
				}catch(ExcepcionDatoNoValido& ed){
					cout<< ed.what();
				}catch(ExcepcionListaVacia& ed){
					cout<< ed.what();
				}

		}while(terminar);
		return 0;
}

void Aparcamiento::registrarVehiculoOficial(char *matri){
	try{
		if(comprobarListaOficial(matri)>-1){
			throw ExcepcionVehiculoYaExiste();
		}
		else if(comprobarListaResidente(matri)>-1 || comprobarListaParking(matri)>-1){
			throw ExcepcionVehiculoNoValido();
		}
		else{
			listaVehiculosOficiales[numVehiculosOficiales].setMatricula(matri);

			cout<<"Se ha registrado "<<listaVehiculosOficiales[numVehiculosOficiales].getMatricula()<<" como oficial\n"<<endl;
			numVehiculosOficiales++;

			Oficial* auxiliar= new Oficial[numVehiculosOficiales+1];
			for(int i=0; i<numVehiculosOficiales;i++){
				auxiliar[i]=listaVehiculosOficiales[i];
			}
			listaVehiculosOficiales=auxiliar;
		}
		}catch(ExcepcionVehiculoNoValido& ed){
				cout<< ed.what();
		}catch(ExcepcionVehiculoYaExiste& ed){
				cout<< ed.what();
			}





}

void Aparcamiento::registrarVehiculoResidente(char *matri){
	try{
		if(comprobarListaResidente(matri)>-1){
				throw ExcepcionVehiculoYaExiste();
			}
		else if(comprobarListaOficial(matri)>-1 || comprobarListaParking(matri)>-1){
				throw ExcepcionVehiculoNoValido();
		}
		else{
			listaVehiculosResidentes[numVehiculosResidentes].setMatricula(matri);
			cout<<"Se ha registrado "<<listaVehiculosResidentes[numVehiculosResidentes].getMatricula()<<" como Residente\n"<<endl;
			numVehiculosResidentes++;

			Residente* auxiliar= new Residente[numVehiculosResidentes+1];
			for(int i=0; i<numVehiculosResidentes;i++){
				auxiliar[i]=listaVehiculosResidentes[i];
			}
			listaVehiculosResidentes=auxiliar;
		}
	}catch(ExcepcionVehiculoNoValido& ed){
			cout<< ed.what();
	}catch(ExcepcionVehiculoYaExiste& ed){
			cout<< ed.what();
		}

}

void Aparcamiento::eliminarVehiculoResidente(char *matri){
	try{
		int pos;
		if(comprobarListaParking(matri)==-1){
			if((pos=comprobarListaResidente(matri))>-1){
				Residente* aux = new Residente[numVehiculosResidentes];
				int auxnum=0;
				for(int i=0;i<numVehiculosResidentes;i++){
					if(pos!=i){
						aux[auxnum]=listaVehiculosResidentes[i];
						auxnum++;
					}
				}
				listaVehiculosResidentes=aux;
				numVehiculosResidentes--;
				for(int i=0;i<numVehiculosResidentes;i++){
					auxnum=comprobarListaParking(listaVehiculosResidentes[i].getMatricula());
					if(auxnum>-1){
						parking[auxnum]=NULL;
						parking[auxnum]=&listaVehiculosResidentes[i];
					}
				}
				cout<<"Se ha eliminado de la lista residente el vehiculo "<<matri<<endl<<endl;
			}
			else{
				throw ExcepcionVehiculoNoExiste();
			}
		}
		else{
			throw ExcepcionVehiculoNoValido();
		}
	}catch(ExcepcionVehiculoNoValido& ed){
			cout<< ed.what();
	}catch(ExcepcionVehiculoNoExiste& ed){
			cout<< ed.what();
		}
}

void Aparcamiento::eliminarVehiculoOficial(char *matri){
	try{
		int pos;
		if(comprobarListaParking(matri)==-1){
			if((pos=comprobarListaOficial(matri))>-1){
				Oficial* aux = new Oficial[numVehiculosOficiales];
				int auxnum=0;
				for(int i=0;i<numVehiculosOficiales;i++){
					if(pos!=i){
						aux[auxnum]=listaVehiculosOficiales[i];
						auxnum++;
					}
				}
				listaVehiculosOficiales=aux;
				numVehiculosOficiales--;
				for(int i=0;i<numVehiculosOficiales;i++){
					if((auxnum=comprobarListaParking(listaVehiculosOficiales[i].getMatricula()))>-1){
						parking[auxnum]=NULL;
						parking[auxnum]=&listaVehiculosOficiales[i];
					}
				}
				cout<<"Se ha eliminado de la lista oficial el vehiculo "<<matri<<endl<<endl;
			}
			else{
				throw ExcepcionVehiculoNoExiste();
			}
		}
		else{
			throw ExcepcionVehiculoNoValido();
		}
	}catch(ExcepcionVehiculoNoValido& ed){
			cout<< ed.what();
	}catch(ExcepcionVehiculoNoExiste& ed){
			cout<< ed.what();
		}


}



void Aparcamiento::menuParking(char* mat){
	bool terminar=true;
		char elecciones;
		do{
			terminar=false;
			fflush(stdin);
			cout<<"Que quieres hacer:\n1-Entrar al Parking\n2-Salir del Parking\n3-Volver\nOpcion:";
			cin>>elecciones;
			cout<<"\n";
			try{
				switch(elecciones){
					case '1':
						entrarVehiculo(mat);
						break;
					case '2':
						salirVehiculo(mat);
						break;
					case '3':
						terminar=false;
						break;
					default:
						terminar=true;
						throw ExcepcionDatoNoValido();
						}
				}catch(ExcepcionDatoNoValido& ed){
					cout<< ed.what();
				}catch(ExcepcionListaVacia& ed){
					cout<< ed.what();
				}

		}while(terminar);
}
void Aparcamiento::identificarMatricula(char* mat){
	char eleccionar=0;
	bool terminar=true;

	do{
		fflush(stdin);
		cout<<"Que quieres hacer con el vehiculo "<<mat<<endl<<"1-Gestion tipo de vehiculo\n2-Gestion Parking\n3-Generar Informe\n4-Volver\nOpcion: ";
		cin>>eleccionar;
		cout<<endl;
		try{
			switch(eleccionar){
						case '1':
							menuTipoVehiculo(mat);
							break;
						case '2':
							menuParking(mat);
							break;
						case '3':
							generarInforme(mat);
							break;
						case '4':
							terminar=false;
							break;
						default:
							throw ExcepcionDatoNoValido();
					}
		}catch(ExcepcionDatoNoValido& ed){
					cout<< ed.what();
				}
	}while(terminar);

}

void Aparcamiento::entrarVehiculo(char* mat){
	try{
		int numAux;
		if(estadoActualParking==libre){
			if(comprobarListaParking(mat)==-1){
				if((numAux=comprobarListaResidente(mat))>-1){
					parking[buscarSitio()]=&listaVehiculosResidentes[numAux];
					cout<<"Ha entrado el vehiculo Residente";
				}
				else if((numAux=comprobarListaOficial(mat))>-1){
					parking[buscarSitio()]=&listaVehiculosOficiales[numAux];
					cout<<"Ha entrado el vehiculo Oficial ";
				}
				else{
					NoResidente *aux= new NoResidente(mat);
					parking[buscarSitio()]= aux;
					cout<<"Ha entrado el vehiculo No residente";
				}
				numAux=comprobarListaParking(mat);
				cout<<" con la matricula "<<mat<<" en la plaza "<<numAux<<endl<<endl;
				parking[numAux]->entrar();
				plazasOcupadas++;
				if(plazasOcupadas == plazasTotales){
					estadoActualParking= completo;
				}
			}
			else{
				throw ExcepcionVehiculoYaExiste();
			}
		}

		else{
			throw ExcepcionDesbordamientoParking();
		}
	}catch(ExcepcionDesbordamientoParking& ed){
			cout<< ed.what();
	}catch(ExcepcionVehiculoYaExiste& ed){
			cout<< ed.what();
		}
}

void Aparcamiento::salirVehiculo(char* mat){
	try{
		int numAux;
		if((numAux=comprobarListaParking(mat))>-1){
			parking[numAux]->salir();
			parking[numAux]=NULL;
			cout<<"Ha salido el vehiculo "<<mat<<"\n"<<endl;
			if(plazasOcupadas == plazasTotales){
				estadoActualParking= libre;
			}
			plazasOcupadas--;

		}
		else{
			throw ExcepcionVehiculoNoExiste();
		}
	}catch(ExcepcionVehiculoNoExiste& ed){
					cout<< ed.what();
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

int Aparcamiento::comprobarListaResidente(char* mat){

	for(int i=0;i<numVehiculosResidentes;i++){
		if(igualesMatriculas(mat,listaVehiculosResidentes[i].getMatricula())){
			return i;
		}
	}
	return -1;
}


int Aparcamiento::comprobarListaParking(char* mat){
	for(int i=0;i<plazasTotales;i++){
		if(parking[i]!=NULL){
			if(igualesMatriculas(mat,parking[i]->getMatricula())){
				return i;
			}
		}

	}
	return -1;
}

int Aparcamiento::comprobarListaOficial(char* mat){
	for(int i=0;i<numVehiculosOficiales;i++){
		if(igualesMatriculas(mat,listaVehiculosOficiales[i].getMatricula())){
			return i;
		}

	}
	return -1;
}

bool Aparcamiento::igualesMatriculas(char* mata, char* matb){
	if(strlen(mata)==strlen(matb)){
		for(int j=0;j<(int)strlen(mata);j++){
			if(mata[j]!=matb[j]){
				return false;
			}
		}
	}
	else{
		return false;
	}
	return true;
}

void Aparcamiento::finDeMes(){
	try{
		if(numVehiculosOficiales>0){

			for(int i=0;i<numVehiculosOficiales;i++){
				listaVehiculosOficiales[i].finDeMes();
				cout<<endl;
			}
		}
		else{
			throw ExcepcionListaVacia();
		}
	}catch(ExcepcionListaVacia& ed){
		cout<< ed.what();
	}
	try{
		if(numVehiculosResidentes>0){
			for(int i=0;i<numVehiculosResidentes;i++){
				listaVehiculosResidentes[i].finDeMes();
				cout<<endl;
			}
		}
		else{
			throw ExcepcionListaVacia();
		}
	}catch(ExcepcionListaVacia& ed){
			cout<< ed.what();
		}
}

void Aparcamiento::generarInforme(char* mat){
	try{
		int numAux;
		if((numAux=comprobarListaResidente(mat))>-1){
			listaVehiculosResidentes[numAux].generarInforme();
		}
		else{
			throw ExcepcionVehiculoNoValido();
		}
	}catch(ExcepcionVehiculoNoValido& ed){
			cout<< ed.what();
		}
}

void Aparcamiento::seleccionarPlazasParking(){

	char aux[100];
	do{
		try{
			 fflush(stdin);
			 cout<<"Dame el numero de plazas: ";
			 cin>>aux;
			 plazasTotales=atoi(aux);
			 cout<<endl;

			 if(plazasTotales<1){
				 throw ExcepcionDatoNoValido();
			 }
		 }catch(ExcepcionDatoNoValido& ed){
					cout<< ed.what();
		 }
	}while(plazasTotales<1);
	delete parking;
	parking= new Vehiculo*[plazasTotales];
	for(int i=0;i<plazasTotales;i++){
			parking[i]=NULL;
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



