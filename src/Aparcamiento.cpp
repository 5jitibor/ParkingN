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
	Estancia auxEst;
	Estancia* auxListaEst;
	Fecha auxFecha;
	try{

		ifstream fer("Residente.txt");
		if(fer.good()){

			fer>>numVehiculosResidentes;
			delete listaVehiculosResidentes;
			listaVehiculosResidentes = new Residente[numVehiculosResidentes+1];
			for(int i=0;i<numVehiculosResidentes;i++){
				fer>> aux;
				matri= new char[strlen(aux)+1];
				for(int j=0; j<=(int)strlen(aux);j++){
					matri[j]=aux[j];
				}
				listaVehiculosResidentes[i].setMatricula(matri);
				fer>> auxNum;
				listaVehiculosResidentes[i].setTiempoTotal(auxNum);
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
						feo>> aux;
						matri= new char[strlen(aux)+1];
						for(int j=0; j<=(int)strlen(aux);j++){
							matri[j]=aux[j];
						}
						listaVehiculosOficiales[i].setMatricula(matri);
						feo>> auxNum;
						listaVehiculosOficiales[i].setNumEstaciones(auxNum);
						delete auxListaEst;
						auxListaEst= new Estancia[listaVehiculosOficiales[i].getNumEstaciones()];
						for(int j=0;j<listaVehiculosOficiales[i].getNumEstaciones();j++){
							feo>>auxNum;
							auxFecha.setHora(auxNum);
							feo>>auxNum;
							auxFecha.setMinuto(auxNum);
							auxListaEst[j].setInicio(auxFecha);
							feo>>auxNum;
							auxFecha.setHora(auxNum);
							feo>>auxNum;
							auxFecha.setMinuto(auxNum);
							auxListaEst[j].setFin(auxFecha);
						}
						listaVehiculosOficiales[i].setEstanciasTotales(auxListaEst);
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
				fep>> aux;
				matri= new char[strlen(aux)+1];
				for(int j=0; j<=(int)strlen(aux);j++){
					matri[j]=aux[j];
				}
				fep>>auxNum;
				if(comprobarListaResidente(matri)>-1){
					parking[auxNum]=&listaVehiculosResidentes[comprobarListaResidente(matri)];
				}
				else if(comprobarListaOficial(matri)>-1){
					parking[auxNum]=&listaVehiculosOficiales[comprobarListaOficial(matri)];
				}
				else{
					NoResidente *auxNo= new NoResidente(matri);
					parking[auxNum]= auxNo;
				}
				fep>>auxNum;
				auxFecha.setHora(auxNum);
				fep>>auxNum;
				auxFecha.setHora(auxNum);
				auxEst.setInicio(auxFecha);
				(*parking[comprobarListaParking(matri)]).setEstanciaActual(auxEst);
			}
		}
		else{
			seleccionarPlazasParking();
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
			fsb<<i<<endl;
			fsb<<(*parking[i]).getEstanciaActual().getInicio().getHora()<<endl;
			fsb<<(*parking[i]).getEstanciaActual().getInicio().getMinuto()<<endl;

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
	char nombres[10];
	fflush(stdin);
	cout<<"Dame el nombre de la matricula: ";
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
		cout<<"Que quieres hacer:\n1-Identificar Vehiculo\n2-Fin de mes\n3-Mostrar Listas\n4-Cerrar\nOpcion:";
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
			cout<<"Que quieres cargar desde fichero:\nSi (S) o No(N)\nOpcion:";
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
		cout<<"Que quieres guardar los cambios:\nSi (S) o No(N)\nOpcion:";
		cin>>elecciones;
		cout<<"\n";
		try{
			switch(elecciones){
				case 'S':
					generarDocumentos();
					cout<<"Se ha guardado correctamente"<<endl;
					break;
				case 'N':
					cout<<"No se guardaran los cambios"<<endl;
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
						cout<<"Vehiculo"<<i<<": ";
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
		do{
			terminar=false;
			fflush(stdin);
			cout<<"Que quieres hacer:\n1-Registrar oficial\n2-Registrar residente\n3-Volver\nOpcion:";
			cin>>elecciones;
			cout<<"\n";
			try{
				switch(elecciones){
					case '1':
						registarVehiculoOficial(mat);
						break;
					case '2':
						registrarVehiculoResidente(mat);
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
		cout<<"Que quieres hacer con el vehiculo "<<mat<<endl<<"1-Gestion tipo de vehiculo\n2-Gestion Parking\n3-Generar Informe\n4-Cerrar\nOpcion: ";
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
		if(estadoActualParking==libre){
			if(comprobarListaParking(mat)==-1){
				if(comprobarListaResidente(mat)>-1){
					parking[buscarSitio()]=&listaVehiculosResidentes[comprobarListaResidente(mat)];
					cout<<"Ha entrado el vehiculo Residente";
				}
				else if(comprobarListaOficial(mat)>-1){
					parking[buscarSitio()]=&listaVehiculosOficiales[comprobarListaOficial(mat)];
					cout<<"Ha entrado el vehiculo Oficial ";
				}
				else{
					NoResidente *aux= new NoResidente(mat);
					parking[buscarSitio()]= aux;
					cout<<"Ha entrado el vehiculo No residente";
				}
				cout<<" con la matricula "<<mat<<" en la plaza "<<comprobarListaParking(mat)<<endl<<endl;
				parking[comprobarListaParking(mat)]->entrar();
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
		if(comprobarListaParking(mat)>-1){
			parking[comprobarListaParking(mat)]->salir();
			parking[comprobarListaParking(mat)]=NULL;
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


void Aparcamiento::registarVehiculoOficial(char *matri){
	try{
		if(comprobarListaOficial(matri)>-1){
			throw ExcepcionVehiculoYaExiste();
		}
		else if(comprobarListaResidente(matri)>-1){
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
		else if(comprobarListaOficial(matri)>-1){
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

int Aparcamiento::comprobarListaResidente(char* mat){
	bool iguales=false;
	char * mataux;
	for(int i=0;i<numVehiculosResidentes;i++){
		mataux=listaVehiculosResidentes[i].getMatricula();
		if(strlen(mataux)==strlen(mat)){
				iguales=true;

				for(int j=0;j<(int)strlen(mat);j++){
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

					for(int j=0;j<(int)strlen(mat);j++){
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
			for(int j=0;j<(int)strlen(mat);j++){
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
	try{
		if(numVehiculosOficiales>0){

			for(int i=0;i<numVehiculosOficiales;i++){
				cout<<endl;
				listaVehiculosOficiales[i].finDeMes();
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
				cout<<endl;
				cout<<listaVehiculosResidentes[i];
					listaVehiculosResidentes[i].finDeMes();
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
		if(comprobarListaResidente(mat)>-1){
			listaVehiculosResidentes[comprobarListaResidente(mat)].generarInforme();
		}
		else{
			throw ExcepcionVehiculoNoValido();
		}
	}catch(ExcepcionVehiculoNoValido& ed){
			cout<< ed.what();
		}
}

void Aparcamiento::seleccionarPlazasParking(){

	int num=0;
	char aux[100];
	do{
		try{
			 fflush(stdin);
			 cout<<"Dame el numero de plazas: ";
			 cin>>aux;
			 num=atoi(aux);
			 cout<<endl;

			 if(num<1){
				 throw ExcepcionDatoNoValido();
			 }
		 }catch(ExcepcionDatoNoValido& ed){
					cout<< ed.what();
		 }
	}while(num<1);
	plazasTotales=num;
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



