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

		fila = stoi(filaAux);
		columna = stoi(columnaAux);

		transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

	}
	archivoClientes.close();
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

		transform(nombrePelicula.begin(), nombrePelicula.end(), nombrePelicula.begin(), ::toupper);

		Pelicula* pelicula = new Pelicula(nombrePelicula, duracionHoras, duracionMinutos, generoPelicula, puntajePelicula, clasificacion);
	}

	archivoPeliculas.close();
}

void Sistema::menuPrincipal()
{
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
			salir = true;
			//generar un archivo de salida
			cout << "\n\n ------------------------------------- \n|Hasta luego y GRACIAS por preferirnos|\n|	    Cine Ritsa 3D	      |\n ------------------------------------- \n";// _____________________________________ 
		}
	}
	
}

bool Sistema::subMenu()
{
	bool salir = false;
	string opcionString;
	char op1;
	while (salir == false)
	{
		cout << "\n  ****|Sub-Menu|****\n  a) Revisar pelicula\n  b) Asignar pelicula\n  c) Iniciar Pelicula\n  d) Volver\n  Elija una opcion: ";
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
				cout << "\nLa pelicula es: xxxxxxxxxxxxx"<<endl;
				return true;
			}
			case 'b':
			{
				string pelicula;
				cout << "Ingrese la pelicula:";
				cin >> pelicula;
				return true;
			}
			case 'c':
			{
				cout << "\nIniciando pelicula....\n";
				return true;
			}
			case 'd':
				return false;
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
			subMenu();
		}
		break;
		case 'b':
		{
			subMenu();
		}
		break;
		case 'c':
		{
			subMenu();
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
	cout << "\n>>Menu Estadisticas\n  a) Porcentaje de espectadores por pelicula \n  b) Cantidad de personas en cola\n  c) Cantidad de personas por sala\n  d) Persona más longeva y personas más joven\n  e) Volver\n  Elija una opcion para el menu estadisticas: ";
	cin >> opcion;

	while (!opcion._Equal("a") && !opcion._Equal("b") && !opcion._Equal("c") && !opcion._Equal("d") && !opcion._Equal("e"))
	{
		system("cls");
		cout << "Ingrese una opcion correcta\n>>Menu Estadisticas\n  a) Porcentaje de espectadores por pelicula \n  b) Cantidad de personas en cola\n  c) Cantidad de personas por sala\n  d) Persona más longeva y personas más joven\n  e) Volver\n  Elija una opcion para el menu estadisticas: ";
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




