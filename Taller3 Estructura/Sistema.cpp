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
		cout << "1.Menu Principal\na.Fila de espera\nb.Sala de cine\nc.Estadistica\nd.Salir\nElija una opcion: ";
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
			cout << "opcion cc"<<endl;
		}
		break;
		case 'd':
			salir = true;
			cout << "saliendo";
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

	default:
		break;
	}
}


void Sistema::lecturaArchivo()
{
}
