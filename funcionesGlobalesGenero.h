#ifndef FUNCIONESGLOBALESGENERO_H_INCLUDED
#define FUNCIONESGLOBALESGENERO_H_INCLUDED

/// PROTOTIPOS PUNTO NUMERO 1 AGREGAR GENERO

int contarRegistroGenero();

Genero cargarGenero();

int agregarRegistroGenero();

/// PROTOTIPOS PUNTO NUMERO 2 LISTAR GENERO POR ID

int buscarIdGenero(int idG);

Genero leerRegistroGenero(int pos);

/// PROTOTIPOS PUNTO NUMERO 3 LISTAR TODOS LOS GENEROS

void mostrarGenero();

/// PROTOTIPOS PUNTO NUMERO 4 MODIFICAR TIPO DE INSTRUMENTACION

bool sobreEscribirRegistroGenero(Genero gen, int pos);

bool modificarTipoInstrumentacionGenero();

///////// DEFINICIONES PUNTO 1 AGREGAR GENERO

int contarRegistroGenero(){
    int cant;
    FILE *p;
    p = fopen(GENEROS, "ab");
    if(p == NULL){
        return -1;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Genero);
    fclose(p);
    return cant;
}

Genero cargarGenero(){
    Genero gen;
    int idG;
    idG = contarRegistroGenero();
    if(idG == -1){
        cout << "\nFALLO APERTURA DEL ARCHIVO, NO EXISTE O ESTA VACIO" << endl;
        gen.setEstado(false);
        return gen;
    }
    idG += 1;
    gen.Cargar(idG);
    return gen;
}

int agregarRegistroGenero(){
    Genero gen;
    gen = cargarGenero();
    if(gen.getEstado() == false){ /// ERROR EN VALIDACION CARGA o FALLO APERTURA ARCHIVO
        return -1;
    }
    if(gen.GrabarEnDisco()){ /// GRABO EN DISCO
        return 0;
    }
    return -2; /// FALLO GRABAR EN DISCO
}

///////// DEFINICIONES PUNTO 2 LISTAR GENERO POR ID

int buscarIdGenero(int idG){
    Genero gen;
    int pos = 0;
    while(gen.LeerDeDisco(pos)){
        if(idG == gen.getIdGenero()){
            return pos;
        }
        pos++;
    }
    return -1;
}

Genero leerRegistroGenero(int pos){
    Genero gen;
    gen.setIdGenero(-1);
    FILE *p;
    p = fopen(GENEROS,"rb");
    if(p == NULL){
        return gen;
    }
    fseek(p, pos * sizeof gen, 0);
    fread(&gen, sizeof gen, 1, p);
    fclose(p);
    return gen;
}

bool mostrarGeneroPorId(){
    Genero gen;
    int idG, pos;
    cout << "\nINGRESE EL NUMERO DE ID DEL GENERO MUSICAL A MOSTRAR: ";
    cin >> idG;
    pos = buscarIdGenero(idG);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID  DEL GENERO MUSICAL EN EL ARCHIVO" << endl;
        return false;
    }
    gen = leerRegistroGenero(pos);
    gen.Mostrar();
    return true;
}

///////// DEFINICIONES PUNTO 3 LISTAR TODOS LOS GENEROS

void mostrarGenero(){
    Genero gen;
    int pos = 0;
    while(gen.LeerDeDisco(pos)){
        gen.Mostrar();
        pos++;
    }
}

///////// DEFINICIONES PUNTO 4 MODIFICAR TIPO DE INSTRUMENTACION

bool sobreEscribirRegistroGenero(Genero gen, int pos){
    FILE *p;
    p = fopen(GENEROS, "rb+");
    if(p == NULL)return false;
    fseek(p, sizeof gen * pos, 0);
    bool escribio = fwrite(&gen, sizeof gen, 1, p);
    fclose(p);
    return escribio;
}

bool modificarTipoInstrumentacionGenero(){
    Genero gen;
    int idG, pos, tInst;
    cout << "\nINGRESE EL ID GENERO DEL REGISTRO A MODIFICAR TIPO DE INSTRUMENTACION: ";
    cin >> idG;
    pos = buscarIdGenero(idG);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE GENERO MUSICAL EN EL ARCHIVO" << endl;
        return false;
    }
    gen = leerRegistroGenero(pos);
    cout << "\nINGRESE EL NUEVO TIPO DE INSTRUMENTO: ";
    cin >> tInst;
    if(!gen.setTipoInstrumentacion(tInst)){
        cout << "\nTIPO DE INSTRUMENTACION DEBE ESTAR ENTRE 1 Y 5" << endl;
        return false;
    }
    return sobreEscribirRegistroGenero(gen, pos);
}

#endif // FUNCIONESGLOBALESGENERO_H_INCLUDED
