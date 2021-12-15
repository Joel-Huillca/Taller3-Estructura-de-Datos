#include "Sistema.h"

Sistema::Sistema()
{

}

Sistema::~Sistema()
{

}

void Sistema::lecturaClientes()
{
	ifstream archivoClientes("Clientes.txt");
	string linea = "";
	while (getline(archivoClientes, linea))
	{
		string nombre;
		string apellido;
		string rut;
		string pelicula;

		string filaAux;
		int fila;

		string columnaAux;
		int columna;
		string salaCola;

		stringstream s(linea);

		getline(s, nombre, ';');
		getline(s, apellido, ';');
		getline(s, rut, ';');
		getline(s, pelicula, ';');
		getline(s, filaAux, ';');
		getline(s, columnaAux, ';');
		getline(s, salaCola, ';');

		//Retirar los Espacios vacios del txt
		nombre.erase(remove(nombre.begin(), nombre.end(), ' '), nombre.end());
		apellido.erase(remove(apellido.begin(), apellido.end(), ' '), apellido.end());
		rut.erase(remove(rut.begin(), rut.end(), ' '), rut.end());
		pelicula.erase(remove(pelicula.begin(), pelicula.end(), ' '), pelicula.end());
		filaAux.erase(remove(filaAux.begin(), filaAux.end(), ' '), filaAux.end());
		columnaAux.erase(remove(columnaAux.begin(), columnaAux.end(), ' '), columnaAux.end());
		salaCola.erase(remove(salaCola.begin(), salaCola.end(), ' '), salaCola.end());

		//Pasar de string a int:
		fila = stoi(filaAux);
		columna = stoi(columnaAux);

		if (salaCola._Equal("C"))
		{
			//Se dirigen a la Cola de Espera:
			Cliente* cliente = new Cliente(nombre, apellido, rut, pelicula, fila, columna, salaCola);
			cola.push(*cliente);
		}
		else
		{
			//Se agregan a la matriz
			Cliente* cliente = new Cliente(nombre, apellido, rut, pelicula, fila, columna, salaCola);
			sala1->agregaMpp(cliente, fila, columna);
		}
	}
	archivoClientes.close();
	//Comprobamos -Todo correcto:
	//cout << cola.front().getNombre() <<cola.front().getRut()<< endl;
	//cout << cola_Esp.front().getNombre() <<cola_Esp.front().getRut()<< endl;
}

void Sistema::lecturaPeliculas()
{
	ifstream archivoPeliculas("Peliculas.txt");
	string linea = "";

	while (getline(archivoPeliculas, linea))
	{
		string nombrePelicula;

		string duracionHorasAux;
		int duracionHoras;

		string duracionMinutosAux;
		int duracionMinutos;

		string generoPelicula;

		string puntajePeliculaAux;
		int puntajePelicula;

		string clasificacion;

		stringstream s(linea);

		getline(s, nombrePelicula, '/');
		getline(s, duracionHorasAux, '/');
		getline(s, duracionMinutosAux, '/');
		getline(s, generoPelicula, '/');
		getline(s, puntajePeliculaAux, '/');
		getline(s, clasificacion, '/');

		duracionHoras = stoi(duracionHorasAux);
		duracionMinutos = stoi(duracionMinutosAux);
		puntajePelicula = stoi(puntajePeliculaAux);

		//Coloca el dato en Mayuscula y borra espacios:
		nombrePelicula.erase(remove(nombrePelicula.begin(), nombrePelicula.end(), ' '), nombrePelicula.end());
		transform(nombrePelicula.begin(), nombrePelicula.end(), nombrePelicula.begin(), ::toupper);

		Pelicula* peliculaTexto = new Pelicula(nombrePelicula, duracionHoras, duracionMinutos, generoPelicula, puntajePelicula, clasificacion);
		colaNombrePelicula.push(peliculaTexto->getNombrePelicula());
	}

	archivoPeliculas.close();
}

int pasarRut_StrInt(string rut)
{	//Eliminan los ' 'y'.'
	rut.erase(remove(rut.begin(), rut.end(), ' '));
	rut.erase(remove(rut.begin(), rut.end(), '.'));
	rut.erase(8); //Solo quedan los primeros 6 digitos
	int rutInt = stoi(rut);
	return rutInt;
}//Nos devuelve el rut sin el digito v. (formato int)



string Sistema::recibirPelicula(string peliculaCliente)
{
	getline(cin, peliculaCliente);
	// se borran los espacios y se pone todo en mayuscula para poder comparar
	peliculaCliente.erase(remove(peliculaCliente.begin(), peliculaCliente.end(), ' '), peliculaCliente.end());
	transform(peliculaCliente.begin(), peliculaCliente.end(), peliculaCliente.begin(), ::toupper);
	return peliculaCliente;
}

void Sistema::menuPrincipal(){
	Cliente* cliente1 = new Cliente("Juan", "Sanchez", "21.934.925-2", "The Butterfly Effect", 9, 29, "S");
	Cliente* cliente2 = new Cliente("Paola", "Correa", "18.434.333-1", "Kung Fury", 3, 22, "C");
	Cliente* cliente3 = new Cliente("Diana", "Lopez", "8.439.245-9", "Spiderman: No Way Home", 20, 33, "S");

	//arbolAVL->insertNewNode(cliente1);
	//arbolAVL->insertNewNode(cliente2);
	//arbolAVL->insertNewNode(cliente3);
	//arbolAVL->printTree();

	cout << "____.:Bienvenido a CineRitsa3D:.____" << endl;
	bool salir = false;
	string opcionString;
	char op1;
	while (salir == false)
	{
		cout << "\n    MENU PRINCIPAL\n  [a] Fila de espera\n  [b] Sala de cine\n  [c] Estadistica\n  [d] Salir\n  Elija una opcion: ";
		cin >> opcionString;

		while (!opcionString._Equal("a") && !opcionString._Equal("b") && !opcionString._Equal("c") && !opcionString._Equal("d"))
		{
			system("cls");
			cout << "\nIngrese una opcion correcta\n\n    MENU PRINCIPAL\n  [a] Fila de espera\n  [b] Sala de cine\n  [c] Estadistica\n  [d] Salir\n  Elija una opcion: ";
			cin >> opcionString;
		}
		
		if (opcionString._Equal("a")) op1 = 'a';
		if (opcionString._Equal("b")) op1 = 'b';
		if (opcionString._Equal("c")) op1 = 'c';
		if (opcionString._Equal("d")) op1 = 'd';
		
		switch (op1)
		{
		case 'a':
		{
			system("cls");
			menuFilaEspera();
		}
		break;
		case 'b':
		{
			system("cls");
			menuSalaCine();
		}
		break;
		case 'c':
		{
			system("cls");
			
			menuEstadisticas();
		}
		break;
		case 'd':
			bool salirM = salir_Menu();
			if (salirM) salir = true;
			else salir = false;
		}
	}
	
}


char Sistema::subMenu()
{
	bool salir = false;
	string opcionString;
	char op1;
	while (salir == false)
	{
		cout << "\n  a) Revisar pelicula\n  b) Asignar pelicula\n  c) Iniciar Pelicula\n  d) Volver\n  Elija una opcion: ";
		cin >> opcionString;

		while (!opcionString._Equal("a") && !opcionString._Equal("b") && !opcionString._Equal("c") && !opcionString._Equal("d"))
		{
			system("cls");
			cout << "\nIngrese una opcion correcta\n\n  ****|Sub-Menu|****\n  a) Revisar pelicula\n  b) Asignar pelicula\n  c) Iniciar Pelicula\n  d) Volver\n  Elija una opcion: ";
			cin >> opcionString;
		}

		if (opcionString._Equal("a")) op1 = 'a';
		if (opcionString._Equal("b")) op1 = 'b';
		if (opcionString._Equal("c")) op1 = 'c';
		if (opcionString._Equal("d")) op1 = 'd';

		switch (op1)
		{
			case 'a':
			{
				return 'a';
			}
			case 'b':
			{
				return 'b';
			}
			case 'c':
			{
				return 'c';
			}
			case 'd':
				return 'd';
		}
	}
}

void Sistema::menuFilaEspera()
{
	string op2String;
	char op2;
	cout << "\n>>Menu fila de espera\n a) Atender la fila\n b) Agregar personas a la fila\n c) Vaciar la fila\n d) Volver\n Elija una opcion: ";
	cin >> op2String;

	while (!op2String._Equal("a") && !op2String._Equal("b") && !op2String._Equal("c") && !op2String._Equal("d"))
	{
		system("cls");
		cout << "Ingrese una opcion correcta\n>>Menu fila de espera\n a) Atender la fila\n b) Agregar personas a la fila\n c) Vaciar la fila\n d) Volver\n Elija una opcion: ";
		cin >> op2String;
	}

	if (op2String._Equal("a")) op2 = 'a';
	if (op2String._Equal("b")) op2 = 'b';
	if (op2String._Equal("c")) op2 = 'c';
	if (op2String._Equal("d")) op2 = 'd';

	switch (op2)
	{
		case 'a':
		{
			sala1->imprimirSala();
		}
		break;
		case 'b':
		{
			string nombre;
			string apellido;
			string rut;
			string peliculaCliente;
			cout << "Ingrese nombre del cliente ha agregar: " ;
			cin >> nombre;
			cout << "Ingrese apellido del cliente ha agregar: " ;
			cin >> apellido;
			cout << "Ingrese rut del cliente ha agregar: " ;
			cin >> rut;
			cout << "Ingrese pelicula que desea ver el cliente: ";
			getline(cin, peliculaCliente);
			string peliculaClienteCheck = recibirPelicula(peliculaCliente);
			//cout << "Los datos son " << nombre << apellido << rut << peliculaClienteCheck <<endl;
			while (!colaNombrePelicula.empty()) {
				if (peliculaClienteCheck._Equal(colaNombrePelicula.front())) {
					Cliente* cliente = new Cliente(nombre,apellido,rut,peliculaClienteCheck);
					cola.push(*cliente);
					cout << "El cliente ha sido agregado a la fila de espera" << endl;
					return;
				}
				else
					colaNombrePelicula.pop();
			}
			cout << "La pelicula que desea ver no la maneja el cine,lo sentimos" << endl;
		}
		break;
		case 'c':
		{
			cout << "Vaciando fila...";
			while (!cola.empty())
			{
				cola.pop();
			}
			menuFilaEspera();
		}
		break;
		case 'd':
		{
			cout << "Saliendo del menu fila de espera..."<<endl;
		}
		break;
	}
}

void Sistema::menuSalaCine()
{
	string op2String;
	char op2;
	cout << "\n>>Menu Sala de Cine\n a) Sala 1\n b) Sala 2\n c) Sala 3\n d) Volver\n Elija una opcion para el menu sala de cine: ";
	cin >> op2String;

	while (!op2String._Equal("a") && !op2String._Equal("b") && !op2String._Equal("c") && !op2String._Equal("d"))
	{
		system("cls");
		cout << "Ingrese una opcion correcta\n>>Menu Sala de Cine\n a) Sala 1\n b) Sala 2\n c) Sala 3\n d) Volver\n Elija una opcion para el menu sala de cine: ";
		cin >> op2String;
	}

	if (op2String._Equal("a")) op2 = 'a';
	if (op2String._Equal("b")) op2 = 'b';
	if (op2String._Equal("c")) op2 = 'c';
	if (op2String._Equal("d")) op2 = 'd';


	switch (op2)
	{
		case 'a':
		{
			cout << "\n  ****|Sub-Menu|****\n °Sala 1 °"<<endl;
			char opSubMenu = subMenu();
			int cantActualSala1 = sala1->recorrerSala();
			float porcSala1 = (cantActualSala1 / 180.0) * 100.0;
			bool salaVacia1 = sala1->estaVacia();
			if (opSubMenu == 'a')
			{
				if (peliculaSala1->getNombrePelicula() == "")
					cout << "La sala 1 no tiene pelicula asignada" << endl;
				else
					cout << "La pelicula asignada a la sala 1 es " << peliculaSala1->getNombrePelicula() << " y el porcentaje de la sala ocupada es " << porcSala1 << " % " <<endl; //(cant actual/180)*100
			}
			if (opSubMenu == 'b')
			{
				if (peliculaSala1->getNombrePelicula() != "") { // si existe una pelicula se podra asignar solo si esta vacia
					if (salaVacia1 == true) {
						string nuevaPelicula;
						cout << "Asigne el nombre de una nueva pelicula: ";
						cin >> nuevaPelicula;
						peliculaSala1->setNombrePelicula(nuevaPelicula);
					}
					else
						cout << "La sala 1 no esta vacia,no puede reasignar una pelicula" << endl;
				}
				else
				{
					string nuevaPelicula;
					cout << "Asigne el nombre de una nueva pelicula: ";
					cin >> nuevaPelicula;
					peliculaSala1->setNombrePelicula(nuevaPelicula);
				}
			}
			if (opSubMenu == 'c')
			{
				cout << "Iniciando la pelicula " << peliculaSala1->getNombrePelicula();
				peliculaSala1->setNombrePelicula("");
				sala1->vaciarSala();
				sala1->~MatrizPP();
			}			
		}
		break;
		case 'b':
		{
			cout << "\n  ****|Sub-Menu|****\n °Sala 2 °" << endl;
			char opSubMenu = subMenu();
			int cantActualSala2 = sala2->recorrerSala();
			float porcSala2 = (cantActualSala2 / 180.0) * 100.0;
			bool salaVacia2 = sala2->estaVacia();
			if (opSubMenu == 'a')
			{
				if (peliculaSala2->getNombrePelicula() == "")
					cout << "La  sala 2 no tiene pelicula asignada" << endl;
				else
					cout << "La pelicula asignada a la sala 2 es " << peliculaSala2->getNombrePelicula() << " y el porcentaje de la sala ocupada es " << porcSala2 << " % " << endl;
			}
			if (opSubMenu == 'b')
			{
				if (peliculaSala2->getNombrePelicula() != "") { 
					if (salaVacia2 == true) {
						string nuevaPelicula;
						cout << "Asigne el nombre de una nueva pelicula: ";
						cin >> nuevaPelicula;
						peliculaSala2->setNombrePelicula(nuevaPelicula);
					}
					else
						cout << "La sala 2 no esta vacia,no puede reasignar una pelicula" << endl;
				}
				else
				{
					string nuevaPelicula;
					cout << "Asigne el nombre de una nueva pelicula: ";
					cin >> nuevaPelicula;
					peliculaSala2->setNombrePelicula(nuevaPelicula);
				}
			}
			if (opSubMenu == 'c')
			{
				cout << "Iniciando la pelicula " << peliculaSala2->getNombrePelicula();
				peliculaSala2->setNombrePelicula("");
				sala2->vaciarSala();
				sala2->~MatrizPP();
			}
		}
		break;
		case 'c':
		{
			cout << "\n  ****|Sub-Menu|****\n °Sala 3 °" << endl;
			char opSubMenu = subMenu();
			int cantActualSala3 = sala3->recorrerSala();
			float porcSala3 = (cantActualSala3 / 180.0) * 100.0;
			bool salaVacia3 = sala3->estaVacia();
			if (opSubMenu == 'a')
			{
				if (peliculaSala3->getNombrePelicula() == "")
					cout << "La sala 3 no tiene pelicula asignada" << endl;
				else
					cout << "La pelicula asignada a la sala 3 es " << peliculaSala3->getNombrePelicula() << " y el porcentaje de la sala ocupada es " << porcSala3 << " % "<< endl;
			}
			if (opSubMenu == 'b')
			{
				if (peliculaSala3->getNombrePelicula() != "") {
					if (salaVacia3 == true) {
						string nuevaPelicula;
						cout << "Asigne el nombre de una nueva pelicula: ";
						cin >> nuevaPelicula;
						peliculaSala3->setNombrePelicula(nuevaPelicula);
					}
					else
						cout << "La sala 3 no esta vacia,no puede reasignar una pelicula" << endl;
				}
				else
				{
					string nuevaPelicula;
					cout << "Asigne el nombre de una nueva pelicula: ";
					cin >> nuevaPelicula;
					peliculaSala3->setNombrePelicula(nuevaPelicula);
				}
			}
			if (opSubMenu == 'c')
			{
				cout << "Iniciando  la pelicula " << peliculaSala3->getNombrePelicula();
				peliculaSala3->setNombrePelicula("");
				sala3->vaciarSala();
				sala3->~MatrizPP();
			}
		}
		break;
		case 'd':
		{
			cout << "Saliendo del menu sala de cine..." << endl;
		}
		break;
	}
}

void Sistema::menuEstadisticas()
{
	string opcion;
	char opcion1;
	int contCola=0;
	cout << "\n>>Menu Estadisticas\n  a) Porcentaje de espectadores por pelicula \n  b) Cantidad de personas en cola\n  c) Cantidad de personas por sala\n  d) Persona mas longeva y personas mas joven\n  e) Volver\n  Elija una opcion para el menu estadisticas: ";
	cin >> opcion;

	while (!opcion._Equal("a") && !opcion._Equal("b") && !opcion._Equal("c") && !opcion._Equal("d") && !opcion._Equal("e"))
	{
		system("cls");
		cout << "Ingrese una opcion correcta\n>>Menu Estadisticas\n  a) Porcentaje de espectadores por pelicula \n  b) Cantidad de personas en cola\n  c) Cantidad de personas por sala\n  d) Persona mas longeva y personas mas joven\n  e) Volver\n  Elija una opcion para el menu estadisticas: ";
		cin >> opcion;
	}

	if (opcion._Equal("a")) opcion1 = 'a';
	if (opcion._Equal("b")) opcion1 = 'b';
	if (opcion._Equal("c")) opcion1 = 'c';
	if (opcion._Equal("d")) opcion1 = 'd';
	if (opcion._Equal("e")) opcion1 = 'e';


	switch (opcion1)
	{
	case 'a':
	{
		cout << "porcentaje de espectadores que vieron cada pelicula(recorrer arbol avl)" << endl;
	}
	break;
	case 'b':
	{
		while (!cola.empty())
		{
			cola.pop();
			contCola++;
		}
		cout << "El numero de personas en la fila de espera es " << contCola;
	}
	break;
	case 'c':
	{

		cout << "La sala 1 tiene " << sala1->recorrerSala() << " personas en la sala de cine" << endl;
		cout << "La sala 2 tiene " << sala2->recorrerSala() << " personas en la sala de cine" << endl;
		cout << "La sala 3 tiene " << sala3->recorrerSala() << " personas en la sala de cine" << endl;
	}
	break;
	case 'd':
	{
		cout << "La persona mas longeva es " << endl;
		cout << "La persona mas joven es " << endl;
	}
	break;

	case 'e':
	{
		cout << "Saliendo del menu estadisticas..." << endl;
	}
	break;
	}
}

bool  Sistema::salir_Menu()
{
	string opcionString;
	cout << "Esta seguro de salir del sistema?\n>>    [1] Si | [2] No : ";
	cin >> opcionString;
	while (!opcionString._Equal("1") && !opcionString._Equal("2")){
		cout << "\nEsta seguro de salir del sistema?\n>>    [1] Si | [2] No : ";
		cin >> opcionString;
	}
	if (opcionString._Equal("1"))
	{
		ofstream archivo("HistoricoClientes.txt");

		
		archivo <<"Cliente 1" << "," <<"Apellido 1" << "," << "Rut" << "," << "Pelicula" ;
		//archivo <<"Cliente 1" << "," <<"Apellido 1" << "," << (listaNaves->getCantElem() - FcantNavDest) << "," << FmayorGalax << "," << FcantNavesLlenas;



		cout << "\n\n ------------------------------------- \n|Hasta luego y GRACIAS por preferirnos|\n|	    Cine Ritsa 3D	      |\n ------------------------------------- \n";
		return true;
	}else
	{
		system("cls");
		return false;
	}
}

/*
bool  Sistema::salir_Menu()
{
	string opcionString;
	char op1;
	cout << "\nEsta seguro de salir del sistema?" << endl;
	cout << "[1] Si | [2] No : ";
	cin >> opcionString;
	if (opcionString._Equal("1") || opcionString._Equal("2"))
	{
		if (opcionString._Equal("1")) op1 = '1';
		if (opcionString._Equal("2")) op1 = '2';
		switch (op1)
		{
		case '1':

			cout << "\n\n ------------------------------------- \n|Hasta luego y GRACIAS por preferirnos|\n|	    Cine Ritsa 3D	      |\n ------------------------------------- \n";
			return true;
		case '2':
			system("cls");
			return false;
		}
	}
	else salir_Menu();
	
}*/


