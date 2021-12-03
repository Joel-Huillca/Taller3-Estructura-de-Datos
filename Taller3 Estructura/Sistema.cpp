#include "Sistema.h"

Sistema::Sistema()
{
}

Sistema::~Sistema()
{
}

void Sistema::menuPrincipal()
{
	cout << "____.:Bienvenido al CineRitsa3D:.____" << endl;
	bool salir = false;
	string opcionString;
	char op1;
	while (salir == false)
	{
		cout << "\n>>Menu Principal\n  a) Fila de espera\n  b) Sala de cine\n  c) Estadistica\n  d) Salir\n  Elija una opcion: ";
		cin >> opcionString;

		while (!opcionString._Equal("a") && !opcionString._Equal("b") && !opcionString._Equal("c") && !opcionString._Equal("d"))
		{
			system("cls");
			cout << "Ingrese una opcion correcta\n1.Menu Principal\na.Fila de espera\nb.Sala de cine\nc.Estadistica\nd.Salir\nElija una opcion: ";
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
			cout << "\n\n ------------------------------------- \n|Hasta luego y GRACIAS por preferirnos|\n|	    Cine Ritsa 3D	      |\n ------------------------------------- \n";// _____________________________________ 
		default:
			break;
		}
	}
	
}

void Sistema::menuFilaEspera()
{
	string op2String;
	char op2;
	cout << "2.Menu fila de espera\na.Atender la fila\nb.Agregar personas a la fila\nc.Vaciar la fila\nd.Volver\nElija una opcion para el menu fila de espera: ";
	cin >> op2String;

	while (!op2String._Equal("a") && !op2String._Equal("b") && !op2String._Equal("c") && !op2String._Equal("d"))
	{
		system("cls");
		cout << "Ingrese una opcion correcta\n2.Menu fila de espera\na.Atender la fila\nb.Agregar personas a la fila\nc.Vaciar la fila\nd.Volver\nElija una opcion para el menu fila de espera: ";
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
		cout << "atendiendo fila";
	}
	break;
	case 'b':
	{
		cout << "agregando personas";
	}
	break;
	case 'c':
	{
		cout << "vaciando fila";
	}
	break;
	case 'd':
	{
		cout << "Saliendo del menu fila de espera..."<<endl;
	}
	break;
	
	default:
		break;
	}
}

void Sistema::menuSalaCine()
{
	string op2String;
	char op2;
	cout << "2.Menu Sala de Cine\na.Sala 1\nb.Sala 2\nc.Sala 3\nd.Volver\nElija una opcion para el menu sala de cine: ";
	cin >> op2String;

	while (!op2String._Equal("a") && !op2String._Equal("b") && !op2String._Equal("c") && !op2String._Equal("d"))
	{
		system("cls");
		cout << "Ingrese una opcion correcta\n2.Menu fila de espera\na.Atender la fila\nb.Agregar personas a la fila\nc.Vaciar la fila\nd.Volver\nElija una opcion para el menu fila de espera: ";
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
			cout << "sala 1";
		}
		break;
		case 'b':
		{
			cout << "sala 2";
		}
		break;
		case 'c':
		{
			cout << "sala 3";
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
	cout << "2.Menu Estadisticas\n  a) Porcentaje de espectadores por pelicula \n  b) Cantidad de personas en cola\n  c) Cantidad de personas por sala\n  d) Persona más longeva y personas más joven\n  e) Volver\n  Elija una opcion para el menu sala de cine: ";
	cin >> opcion;

	while (!opcion._Equal("a") && !opcion._Equal("b") && !opcion._Equal("c") && !opcion._Equal("d") && !opcion._Equal("e"))
	{
		system("cls");
		cout << "2.Menu Estadisticas\n  a) Porcentaje de espectadores por pelicula \n  b) Cantidad de personas en cola\n  c) Cantidad de personas por sala\n  d) Persona más longeva y personas más joven\n  e) Volver\n  Elija una opcion para el menu sala de cine: ";
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
		string fila;
		string columna;
		string cola;

		stringstream s(linea);

		getline(s, nombre, ';');
		getline(s, apellido, ';');
		getline(s, rut, ';');
		getline(s, pelicula, ';');
		getline(s, fila, ';');
		getline(s, columna, ';');
		getline(s, cola, ';');

		transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper);

	}
}

void Sistema::lecturaPeliculas()
{
	ifstream archivoPeliculas("Peliculas.txt");
	string linea = "";

	while (getline(archivoPeliculas, linea))
	{
		string nombrePelicula;
		string duracionHoras;
		string duracionMinutos;
		string generoPelicula;
		string puntajePelicula;
		string clasificacion;

		stringstream s(linea);

		getline(s, nombrePelicula, '/');
		getline(s, duracionHoras, '/');
		getline(s, duracionMinutos, '/');
		getline(s, generoPelicula, '/');
		getline(s, puntajePelicula, '/');
		getline(s, clasificacion, '/');

		transform(nombrePelicula.begin(), nombrePelicula.end(), nombrePelicula.begin(), ::toupper);
	}
}
