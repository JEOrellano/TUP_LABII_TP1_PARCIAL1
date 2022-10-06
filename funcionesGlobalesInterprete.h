#ifndef FUNCIONESGLOBALESINTERPRETE_H_INCLUDED
#define FUNCIONESGLOBALESINTERPRETE_H_INCLUDED

/// PROTOTIPOS PUNTO NUMERO 1 AGREGAR INTERPRETE

int contarRegistroInterprete();

Interprete cargarInterprete();

int agregarRegistroInterprete();

/// PROTOTIPOS PUNTO NUMERO 2 LISTAR INTERPRETE POR ID

int buscarIdInterprete(int idI);

Interprete leerRegistroInterprete(int pos);

bool mostrarInterpretePorId();

/// PROTOTIPOS PUNTO NUMERO 3 LISTAR TODOS LOS INTERPRETES

void mostrarInterprete();

/// PROTOTIPOS PUNTO NUMERO 4 MODIFICAR GENERO MUSICAL PRINCIPAL

bool sobreEscribirRegistroInterprete(Interprete cantor, int pos);

bool modificarGeneroPrincipalInterprete();

/// PROTOTIPOS PUNTO NUMERO 5 ELIMINAR LOGICA INTERPRETE

bool eliminarLogicoInterprete();

///////// DEFINICIONES PUNTO 1 AGREGAR INTERPRETE

int contarRegistroInterprete(){
    int cant;
    FILE *p;
    p = fopen(INTERPRETES, "ab");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Interprete);
    fclose(p);
    return cant;
}

Interprete cargarInterprete(){
    Interprete cantor;
    int idI;
    Fecha fecha;
    cout << "\nINGRESE FECHA DE INICIO DE ACTIVIDAD: " << endl;
    if(fecha.Cargar() == false){
        cout << "FALLO CARGAR FECHA" << endl;
        cantor.setEstado(false);
        return cantor;
    }

    if(validarFecha(fecha) == false){
        cout << "\nLA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A LA DE HOY" << endl;
        cantor.setEstado(false);
        return cantor;
    }
    idI = contarRegistroInterprete();
    if(idI == -1){
        cantor.setEstado(false);
        return cantor;
    }
    idI += 1;
    cantor.Cargar(idI, fecha);
    return cantor;
}

int agregarRegistroInterprete(){
    Interprete cantor;
    cantor = cargarInterprete();
    if(cantor.getEstado() == false){ /// ERROR EN FECHA o FALLO APERTURA ARCHIVO
        return -1;
    }
    if(cantor.GrabarEnDisco()){ /// GRABO EN DISCO
        return 0;
    }
    return -2; /// FALLO GRABAR EN DISCO
}

///////// DEFINICIONES PUNTO 2 LISTAR INTERPRETE POR ID

int buscarIdInterprete(int idI){
    Interprete cantor;
    int pos = 0;
    while(cantor.LeerDeDisco(pos)){
        if(idI == cantor.getIdInterprete()){
            if(cantor.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

Interprete leerRegistroInterprete(int pos){
    Interprete cantor;
    cantor.setIdInterprete(-1);
    FILE *p;
    p = fopen(INTERPRETES,"rb");
    if(p == NULL){
        return cantor;
    }
    fseek(p, pos * sizeof cantor, 0);
    fread(&cantor, sizeof cantor, 1, p);
    fclose(p);
    return cantor;
}

bool mostrarInterpretePorId(){
    Interprete cantor;
    int idI, pos;
    cout << "\nINGRESE EL NUMERO DE ID INTERPRETE DEL REGISTRO A MOSTRAR: ";
    cin >> idI;
    pos = buscarIdInterprete(idI);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID NUMERO DE INTERPRETE EN EL ARCHIVO" << endl;
        return false;
    }
    cantor = leerRegistroInterprete(pos);
    cout << endl;
    cantor.Mostrar();
    return true;
}

///////// DEFINICIONES PUNTO 3 LISTAR TODOS LOS INTERPRETES

void mostrarInterprete(){
    Interprete cantor;
    int pos = 0;
    while(cantor.LeerDeDisco(pos)){
        cantor.Mostrar();
        pos++;
    }
}

///////// DEFINICIONES PUNTO 4 MODIFICAR GENERO MUSICAL PRINCIPAL

bool sobreEscribirRegistroInterprete(Interprete cantor, int pos){
    FILE *p;
    p = fopen(INTERPRETES, "rb+");
    if(p == NULL)return false;
    fseek(p, sizeof cantor * pos, 0);
    bool escribio = fwrite(&cantor, sizeof cantor, 1, p);
    fclose(p);
    return escribio;
}

bool modificarGeneroPrincipalInterprete(){
    Interprete cantor;
    int idI, pos, genMus;
    cout << "\nINGRESE EL ID INTERPRETE DEL REGISTRO A MODIFICAR: ";
    cin >> idI;
    pos = buscarIdInterprete(idI);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE INTERPRETE EN EL ARCHIVO" << endl;
        return false;
    }
    cantor = leerRegistroInterprete(pos);
    cout << "\nINGRESE EL NUEVO GENERO MUSICAL PRINCIPAL: ";
    cin >> genMus;
    if(cantor.setGenero(genMus) == false){
        cout << "\nEL GENERO MUSICAL INGRESADO ES INVALIDO. DEBER SER 1 AL 10" << endl;
        return false;
    }
    return sobreEscribirRegistroInterprete(cantor, pos);
}

///////// DEFINICIONES PUNTO 5 ELIMINAR LOGICA INTERPRETE

bool eliminarLogicoInterprete(){
    Interprete cantor;
    int idI, pos;
    cout << "\nINGRESE EL ID DE INTERPRETE DEL REGISTRO A DAR DE BAJA: ";
    cin >> idI;
    pos = buscarIdInterprete(idI);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE INTERPRETE EN EL ARCHIVO" << endl;
        return false;
    }
    cantor = leerRegistroInterprete(pos);
    cantor.setEstado(false);
    return sobreEscribirRegistroInterprete(cantor, pos);
}

#endif // FUNCIONESGLOBALESINTERPRETE_H_INCLUDED
