#ifndef FUNCIONESGLOBALESCANCION_H_INCLUDED
#define FUNCIONESGLOBALESCANCION_H_INCLUDED

/// PROTOTIPOS PUNTO NUMERO 1 AGREGAR CANCION

int contarRegistroCancion();

Cancion cargarCancion();

int agregarRegistroCancion();

/// PROTOTIPOS PUNTO NUMERO 2 LISTAR CANCION POR ID

int buscarIdCancion(int idC);

Cancion leerRegistroCancion(int pos);

bool mostrarCancionPorId();

/// PROTOTIPO PUNTO NUMERO 3 LISTAR TODAS LAS CANCIONES

void mostrarCancion();

/// PROTOTIPOS PUNTO NUMERO 4 MODIFICAR FECHA DE ESTRENO

bool sobreEscribirRegistroCancion(Cancion tema, int pos);

bool modificarFechaEstrenoCancion();

/// PROTOTIPO PUNTO NUMERO 5 ELIMINAR LOGICA CANCION

bool eliminarLogicoCancion();

///////// DEFINICIONES PUNTO 1 AGREGAR CANCION

int contarRegistroCancion(){
    int cant;
    FILE *p;
    p = fopen(CANCIONES, "ab");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Cancion);
    fclose(p);
    return cant;
}

Cancion cargarCancion(){
    Cancion tema;
    int idC, idI;
    Fecha fecha;
    cout << "\nID INTERPRETE: ";
    cin >> idI;
    if(validarInterprete(idI) == false){
        cout << "\nEL INTERPRETE INGERSADO ES INVALIDO. NO ESTA REGISTRADO O FUE BORRADO" << endl;
        tema.setEstado(false);
        return tema;
    }
    cout << "INGRESE FECHA DE ESTRENO: " << endl;
    if(fecha.Cargar() == false){
        cout << "FALLO CARGAR FECHA" << endl;
        tema.setEstado(false);
        return tema;
    }
    if(validarFecha(fecha) == false){
        cout << "LA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A LA DE HOY" << endl;
        tema.setEstado(false);
        return tema;
    }
    idC = contarRegistroCancion();
    if(idC == -1){
        tema.setEstado(false);
        return tema;
    }
    idC += 1;
    if(tema.Cargar(idC, fecha, idI) == false){
        cout << "FALLO CARGAR TEMA" << endl;
        tema.setEstado(false);
        return tema;
    }
    return tema;
}

int agregarRegistroCancion(){
    Cancion tema;
    tema = cargarCancion();
    if(tema.getEstado() == false){ /// ERROR EN FECHA o FALLO APERTURA ARCHIVO
        return -1;
    }
    if(tema.GrabarEnDisco()){ /// GRABO EN DISCO
        return 0;
    }
    return -2; /// FALLO GRABAR EN DISCO
}

///////// DEFINICIONES PUNTO 2 LISTAR CANCION POR ID

int buscarIdCancion(int idC){
    Cancion tema;
    int pos = 0;
    while(tema.LeerDeDisco(pos)){
        if(idC == tema.getIdCancion()){
            if(tema.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

Cancion leerRegistroCancion(int pos){
    Cancion tema;
    tema.setIdCancion(-1);
    FILE *p;
    p = fopen(CANCIONES,"rb");
    if(p == NULL){
        return tema;
    }
    fseek(p, pos * sizeof tema, 0);
    fread(&tema, sizeof tema, 1, p);
    fclose(p);
    return tema;
}

bool mostrarCancionPorId(){
    Cancion tema;
    int idC, pos;
    cout << "\nINGRESE EL NUMERO DE ID DE LA CANCION DEL REGISTRO A MOSTRAR: ";
    cin >> idC;
    pos = buscarIdCancion(idC);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DEL NUMERO DE CANCION EN EL ARCHIVO" << endl;
        return false;
    }
    tema = leerRegistroCancion(pos);
    tema.Mostrar();
    cout << endl;
    return true;
}

///////// DEFINICIONES PUNTO 3 LISTAR TODAS LAS CANCIONES

void mostrarCancion(){
    Cancion Tema;
    int pos = 0;
    while(Tema.LeerDeDisco(pos)){
        Tema.Mostrar();
        pos++;
    }
}

///////// DEFINICIONES PUNTO 4 MODIFICAR FECHA DE ESTRENO

bool sobreEscribirRegistroCancion(Cancion tema, int pos){
    FILE *p;
    p = fopen(CANCIONES, "rb+");
    if(p == NULL)return false;
    fseek(p, sizeof tema * pos, 0);
    bool escribio = fwrite(&tema, sizeof tema, 1, p);
    fclose(p);
    return escribio;
}

bool modificarFechaEstrenoCancion(){
    Cancion tema;
    int idC, pos;
    Fecha fecha;
    cout << "\nINGRESE EL ID CANCION DEL REGISTRO A MODIFICAR FECHA DE ESTRENO: ";
    cin >> idC;
    pos = buscarIdCancion(idC);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE CANCION EN EL ARCHIVO" << endl;
        cout << endl;
        return false;
    }
    tema = leerRegistroCancion(pos);
    cout << "\nINGRESE LA NUEVA FECHA DE ESTRENO: " << endl;
    if(fecha.Cargar() == false){
        tema.setEstado(false);
        return false;
    }
    if(validarFecha(fecha) == false){
        return false;
    }
    tema.setFechaEstreno(fecha);
    return sobreEscribirRegistroCancion(tema, pos);
}

///////// DEFINICIONES PUNTO 5 ELIMINAR LOGICA CANCION

bool eliminarLogicoCancion(){
    Cancion tema;
    int idC, pos;
    cout << "\nINGRESE EL ID DE CANCION DEL REGISTRO A DAR DE BAJA: ";
    cin >> idC;
    pos = buscarIdCancion(idC);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE CANCION EN EL ARCHIVO" << endl;
        return false;
    }
    tema = leerRegistroCancion(pos);
    tema.setEstado(false);
    return sobreEscribirRegistroCancion(tema, pos);
}

#endif // FUNCIONESGLOBALESCANCION_H_INCLUDED
