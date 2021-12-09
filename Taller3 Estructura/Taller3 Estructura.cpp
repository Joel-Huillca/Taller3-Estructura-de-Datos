// Taller3 Estructura.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Sistema.h"

int main()
{   
    Sistema* sistema = new Sistema;
    sistema->lecturaClientes();
    sistema->lecturaPeliculas();
    sistema->menuPrincipal();
    
}


//Estado cero

