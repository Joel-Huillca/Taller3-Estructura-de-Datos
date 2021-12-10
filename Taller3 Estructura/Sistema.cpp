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
			//mpp->agregaMpp(cliente, fila, columna);
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
		
		//Coloca el dato en Mayuscula:
		//transform(nombrePelicula.begin(), nombrePelicula.end(), nombrePelicula.begin(), ::toupper);

		Pelicula* pelicula = new Pelicula(nombrePelicula, duracionHoras, duracionMinutos, generoPelicula, puntajePelicula, clasificacion);
				
	}

	archivoPeliculas.close();
}


/*void Sistema::agregaMpp(Cliente* cliente, int fila, int columna)
{
	if (columna < 5 && fila % 4 != 0 && (fila + columna) % 2 == 0 || columna > 26 && fila % 4 != 0 && (fila + columna) % 2 == 0 || columna > 7 && columna < 24 && fila % 4 != 0 && (fila + columna) % 2 != 0)
	{
		NodoMpp* nodoMpp = new NodoMpp(cliente, fila, columna);

		NodoMpp* aux = &mpp->getAROW()[fila];
		while (aux->getLeft()->getColumna() > 0 && aux->getLeft()->getColumna() > columna)
		{
			if (aux->getLeft()->getColumna() == columna) {  // ya esta ocupado
				return;
			}
			aux = aux->getLeft();
		}
		nodoMpp->setLeft(aux->getLeft());
		aux->setLeft(nodoMpp);

		NodoMpp* aux2 = &mpp->getACOL()[columna];
		while (aux2->getUp()->getFila() > 0 && aux2->getUp()->getFila() > fila)
		{
			aux2 = aux2->getUp();
		}
		nodoMpp->setLeft(aux2->getUp());
		aux2->setUp(nodoMpp);
	}
	else
	{
		cout << "no es valido";
	}
}*/

void Sistema::menuPrincipal()
{
	lecturaClientes();
	lecturaPeliculas();

	cout << "____.:Bienvenido al CineRitsa3D:.____" << endl;
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
			cout << "atendiendo fila...";
			//mpp->imprimirMpp();
		}
		break;
		case 'b':
		{
			cout << "Ingrese nombre del cliente ha agregar: ";
			string nombre;
			cin >> nombre;
			cout << "Ingrese apellido del cliente ha agregar: ";
			string apellido;
			cin >> apellido;
			cout << "Ingrese rut del cliente ha agregar: ";
			string rut;
			cin >> rut;
			cout << "Ingrese pelicula que desea ver el cliente: ";
			string pelicula;
			cin >> pelicula;
			//cout << nombre << apellido << rut << pelicula;

			
			Cliente* cliente = new Cliente(nombre, apellido, rut, pelicula);
			cola.push(*cliente);
		
			menuFilaEspera();
			
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
			cout << "\n  ****|Sub-Menu|****\n �Sala 1 �"<<endl;
			char opSubMenu = subMenu();
			int cantActualSala1 = sala1->recorrerSala();
			if (opSubMenu == 'a')
			{
				if (peliculaSala1->getNombrePelicula() == "")
					cout << "La sala 1 no tiene pelicula asignada" << endl;
				else
					cout << "La pelicula asignada a la sala 1 es " << peliculaSala1->getNombrePelicula() << " y el porcentaje de la sala ocupada es " << (cantActualSala1/180)*100 << " % " <<endl; //(cant actual/180)*100
			}
			if (opSubMenu == 'b')
			{
				string nuevaPelicula;		
				cout << "Asigne el nombre de una nueva pelicula: ";
				cin >> nuevaPelicula;
				peliculaSala1->setNombrePelicula(nuevaPelicula);
				
			}
			if (opSubMenu == 'c')
			{
				cout << "iniciando pelicula sala 1";
			}			
		}
		break;
		case 'b':
		{
			cout << "\n  ****|Sub-Menu|****\n �Sala 2 �" << endl;
			char opSubMenu = subMenu();
			int cantActualSala2 = sala2->recorrerSala();
			if (opSubMenu == 'a')
			{
				if (peliculaSala2->getNombrePelicula() == "")
					cout << "La  sala 2 no tiene pelicula asignada" << endl;
				else
					cout << "La pelicula asignada a la sala 2 es " << peliculaSala2->getNombrePelicula() << " y el porcentaje de la sala ocupada es " << (cantActualSala2/180)*100 << " % " << endl;
			}
			if (opSubMenu == 'b')
			{
				string nuevaPelicula;
				cout << "Asigne el nombre de una nueva pelicula: ";
				cin >> nuevaPelicula;
				peliculaSala2->setNombrePelicula(nuevaPelicula);	
			}
			if (opSubMenu == 'c')
			{
				cout << "iniciando pelicula sala 2";
			}
		}
		break;
		case 'c':
		{
			cout << "\n  ****|Sub-Menu|****\n �Sala 3 �" << endl;
			char opSubMenu = subMenu();
			int cantActualSala3 = sala3->recorrerSala();
			if (opSubMenu == 'a')
			{
				if (peliculaSala3->getNombrePelicula() == "")
					cout << "La sala 3 no tiene pelicula asignada" << endl;
				else
					cout << "La pelicula asignada a la sala 3 es " << peliculaSala3->getNombrePelicula() << " y el porcentaje de la sala ocupada es " << (cantActualSala3/180)*100 << " % "<< endl;
			}
			if (opSubMenu == 'b')
			{
				string nuevaPelicula;
				cout << "Asigne el nombre de una nueva pelicula: ";
				cin >> nuevaPelicula;
				peliculaSala3->setNombrePelicula(nuevaPelicula);
			}
			if (opSubMenu == 'c')
			{
				cout << "iniciando pelicula sala 3";
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
	cout << "\n>>Menu Estadisticas\n  a) Porcentaje de espectadores por pelicula \n  b) Cantidad de personas en cola\n  c) Cantidad de personas por sala\n  d) Persona m�s longeva y personas m�s joven\n  e) Volver\n  Elija una opcion para el menu estadisticas: ";
	cin >> opcion;

	while (!opcion._Equal("a") && !opcion._Equal("b") && !opcion._Equal("c") && !opcion._Equal("d") && !opcion._Equal("e"))
	{
		system("cls");
		cout << "Ingrese una opcion correcta\n>>Menu Estadisticas\n  a) Porcentaje de espectadores por pelicula \n  b) Cantidad de personas en cola\n  c) Cantidad de personas por sala\n  d) Persona m�s longeva y personas m�s joven\n  e) Volver\n  Elija una opcion para el menu estadisticas: ";
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
		cout << "aaaaaaaaaa";
	}
	break;
	case 'b':
	{
		cout << "bbbbbbbbbbbb";
	}
	break;
	case 'c':
	{
		cout << "ccccccccc";
	}
	break;
	case 'd':
	{
		cout << "dddddddddd" << endl;
	}
	break;

	case 'e':
	{
		cout << "eeeeeeeeeeeee" << endl;
	}
	break;

	}
}

bool  Sistema::salir_Menu()
{
	string opcionString;
	cout << "\nEsta seguro de salir del sistema?\n>>    [1] Si | [2] No : ";
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


