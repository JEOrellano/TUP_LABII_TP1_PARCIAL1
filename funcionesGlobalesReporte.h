#ifndef FUNCIONESGLOBALESREPORTE_H_INCLUDED
#define FUNCIONESGLOBALESREPORTE_H_INCLUDED

void mostrarCantidadCacionesPorInterprete();

void mostrarCancionesPorGeneroIngresado();

void mostrarCantidadCacionesPorInterprete(){
    Interprete cantor;
    Cancion tema;
    int posI = 0;
    int posC = 0;
    int var;
    int cont;

    cout << "INTERPRETE" << "\tCANTIDAD DE CANCIONES" << endl;
    while(cantor.LeerDeDisco(posI++)){
        var = cantor.getIdInterprete();
        cont = 0;
        posC = 0;
        while(tema.LeerDeDisco(posC++)){
            if(var==tema.getIdInterprete()){
                cont++;
            }
        }
        cout << "\t" << var << "\t\t" << cont << endl;
    }
}

void mostrarCancionesPorGeneroIngresado(){
    Cancion tema;
    int num;
    int pos = 0;

    cout << "INGRESE UN NUMERO DE GENERO: ";
    cin >> num;
    while(tema.LeerDeDisco(pos++)){
        if(num==tema.getGenero()){
            tema.Mostrar();
            cout << endl;
        }
    }
}

#endif // FUNCIONESGLOBALESREPORTE_H_INCLUDED
