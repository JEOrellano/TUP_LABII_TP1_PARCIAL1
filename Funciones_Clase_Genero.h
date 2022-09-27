#ifndef FUNCIONES_CLASE_GENERO_H_INCLUDED
#define FUNCIONES_CLASE_GENERO_H_INCLUDED

/// DECLARACION FUNCIONES PUNTO NUMERO 1 AGREGAR GENERO

int Contar_Registro_Genero();

Genero Cargar_Genero();

void Agregar_Registro_Genero();

/// DECLARACION FUNCIONES PUNTO NUMERO 2 LISTAR GENERO POR ID

int BuscarID_Genero(int ID_G);

Genero LeerRegistro_Genero(int pos);

void Mostrar_Genero_PorID();

/// DECLARACION FUNCIONES PUNTO NUMERO 3 LISTAR TODOS LOS GENEROS

void Mostrar_Genero();

/// DECLARACION FUNCIONES PUNTO NUMERO 4 MODIFICAR TIPO DE INSTRUMENTACION

bool SobreEscribir_Registro_Genero(Genero gen, int pos);

void Modificar_FechaEstreno_Genero();

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 1 AGREGAR GENERO

int Contar_Registro_Genero(){
    int cant;
    FILE *P;
    P = fopen(GENEROS, "rb");
    if(P == NULL){
        return 0;
    }
    fseek(P, 0, 2);
    cant = ftell(P)/sizeof(Genero);
    fclose(P);
    return cant;
}

Genero Cargar_Genero(){
    Genero Gen;
    int ID_G;
    ID_G = Contar_Registro_Genero() + 1;
    if(ID_G == 0){
        cout << "\nFALLO APERTURA DEL ARCHIVO, NO EXISTE O ESTA VACIO" << endl;
        cout << endl;
        Gen.setEstado(false);
        return Gen;
    }
    Gen.Cargar(ID_G);
    return Gen;
}

void Agregar_Registro_Genero(){
    Genero Gen;
    Gen = Cargar_Genero();
    if(Gen.getEstado() == false){ /// ERROR EN VALIDACION CARGA o FALLO APERTURA ARCHIVO
        return;
    }
    if(Gen.GrabarEnDisco()){ /// GRABO EN DISCO
        cout << "\nGENERO GUARDADO" << endl;
        cout << endl;
        return;
    }
    cout << "\nFALLO GRABAR EN DISCO" << endl;
    cout << endl;
    return; /// FALLO GRABAR EN DISCO
}

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 2 LISTAR GENERO POR ID

int BuscarID_Genero(int ID_G){
    Genero Gen;
    int pos = 0;
    while(Gen.LeerDeDisco(pos)){
        if(ID_G == Gen.getID_Genero()){
            return pos;
        }
        pos++;
    }
    return -1;
}

Genero LeerRegistro_Genero(int pos){
    Genero Gen;
    Gen.setID_Genero(-1);
    FILE *P;
    P = fopen(GENEROS,"rb");
    if(P == NULL){
        return Gen;
    }
    fseek(P, pos * sizeof Gen, 0);
    fread(&Gen, sizeof Gen, 1, P);
    fclose(P);
    return Gen;
}

void Mostrar_Genero_PorID(){ /// FILTRA LISTADO POR ID NUMERO DE INTERPRETE
    Genero Gen;
    int ID_G, pos;
    /// buscar el genero a mostrar
    cout << "\nINGRESE EL NUMERO DE ID GENERO MUSICAL DEL REGISTRO A MOSTRAR: ";
    cin >> ID_G;
    /// leer si existe el genero
    pos = BuscarID_Genero(ID_G);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID  DEL GENERO MUSICAL EN EL ARCHIVO" << endl;
        cout << endl;
        return;
    }
    Gen = LeerRegistro_Genero(pos);
    /// LISTAR EL INTERPRETE FILTRADO
    Gen.Mostrar();
    cout << endl;
    return;
}

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 3 LISTAR TODOS LOS GENEROS

void Mostrar_Genero(){
    Genero Gen;
    int pos = 0;
    while(Gen.LeerDeDisco(pos)){
        Gen.Mostrar();
        cout << endl;
        pos++;
    }
}

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 4 MODIFICAR TIPO DE INSTRUMENTACION

bool SobreEscribir_Registro_Genero(Genero Gen, int pos){
    FILE *P;
    P = fopen(GENEROS, "rb+"); ///+ le agrega al modo lo que le falta
    if(P == NULL){
        return false;
    }
    fseek(P, sizeof Gen * pos, 0);
    bool Escribio = fwrite(&Gen, sizeof Gen, 1, P);
    fclose(P);
    return Escribio;
}

void Modificar_FechaEstreno_Genero(){
    Genero Gen;
    int ID_G, pos, T_Inst;
    /// buscar el genero musical a modificar tipo de instrumentacion
    cout << "\nINGRESE EL ID GENERO DEL REGISTRO A MODIFICAR TIPO DE INSTRUMENTACION: ";
    cin >> ID_G;
    /// leer si existe el genero musical
    pos = BuscarID_Genero(ID_G);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE GENERO MUSICAL EN EL ARCHIVO" << endl;
        cout << endl;
        return;
    }
    Gen = LeerRegistro_Genero(pos);
    /// cambiar el tipo de instrumento del campo
    cout << "\nINGRESE EL NUEVO TIPO DE INSTRUMENTO: ";
    cin >> T_Inst;
    if(!Gen.setTipo_Instrumentacion(T_Inst)){
        cout << "\nTIPO DE INSTRUMENTACION DEBE ESTAR ENTRE 1 Y 5" << endl;
        cout << endl;
        return;
    }
    /// sobreescribir el registro
    if(SobreEscribir_Registro_Genero(Gen, pos)==false){
        cout << "\nERROR EN LA MODIFICACION DEL REGISTRO " << endl;
        cout << endl;
        return;
    }
    cout << "\nREGISTRO MODIFICADO" << endl;
    cout << endl;
    return;
}

#endif // FUNCIONES_CLASE_GENERO_H_INCLUDED
