#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

const char *CANCIONES = "Canciones.dat";
const char *INTERPRETES = "Interpretes.dat";
const char *GENEROS = "Generos.dat";
const char *RESPALDOCANCIONES = "Canciones.bkp";
const char *RESPALDOINTERPRETES = "Interpretes.bkp";
const char *RESPALDOGENEROS = "Generos.bkp";

#include "Cadena.h"
#include "Clase_Fecha.h"
#include "Clase_Cancion.h"
#include "Clase_Interprete.h"
#include "Clase_Genero.h"
#include "Funciones_Clase_Cancion.h"
#include "Funciones_Clase_Interprete.h"
#include "Funciones_Clase_Genero.h"
#include "Funciones_Globales_Configuracion.h"
#include "Menues.h"

int main(){
    int opc;
    while(true){
        Menu_Principal();
        cin >> opc;
        switch(opc){
            case 1:
                Menu_Canciones();
                break;
            case 2:
                Menu_Interpretes();
                break;
            case 3:
                Menu_Generos();
                break;
            case 4:
                Menu_Reportes();
                break;
            case 5:
                Menu_Configuracion();
                break;
            case 0:
                return 0;
                break;
            default:
                system("cls");
                cout << "\nOPCION INCORRECTA" << endl;
        }
        cout << endl;
    }

    return 0;
}
