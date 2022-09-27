#ifndef FUNCIONES_CLASE_INTERPRETE_H_INCLUDED
#define FUNCIONES_CLASE_INTERPRETE_H_INCLUDED

/// DECLARACION FUNCIONES PUNTO NUMERO 1 AGREGAR INTERPRETE

int ContarRegistroInterprete();

Interprete Cargar_Interprete();

void Agregar_Registro_Interprete();

/// DECLARACION FUNCIONES PUNTO NUMERO 2 LISTAR INTERPRETE POR ID

int BuscarID_Interprete(int idI);

Interprete LeerRegistro_Interprete(int pos);

void Mostrar_Interprete_PorID();

/// DECLARACION FUNCIONES PUNTO NUMERO 3 LISTAR TODOS LOS INTERPRETES

void Mostrar_Interprete();

/// DECLARACION FUNCIONES PUNTO NUMERO 4 MODIFICAR GENERO MUSICAL PRINCIPAL

bool SobreEscribir_Registro_Interprete(Interprete Cantor, int pos);

void Modificar_GeneroPrincipal_Interprete();

/// DECLARACION FUNCIONES PUNTO NUMERO 5 ELIMINAR LOGICA INTERPRETE

void Eliminar_Logico_Interprete();

//////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 1 AGREGAR INTERPRETE

int ContarRegistroInterprete(){
    int cant;
    FILE *P;
    P = fopen(INTERPRETES, "rb");
    if(P == NULL){
        return 0;
    }
    fseek(P, 0, 2);
    cant = ftell(P)/sizeof(Interprete);
    fclose(P);
    return cant;
}

Interprete Cargar_Interprete(){
    Interprete Cantor;
    int ID_I;
    Fecha fecha;
    cout << "\nINGRESE FECHA DE INICIO DE ACTIVIDAD: " << endl;
    if(fecha.Cargar() == false){
        cout << "\nFALLO CARGAR FECHA" << endl;
        cout << endl;
        Cantor.setEstado(false);
        return Cantor;
    }
    if(validarFecha(fecha) == false){
        cout << "\nLA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A HOY" << endl;
        cout << endl;
        Cantor.setEstado(false);
        return Cantor;
    }
    ID_I = ContarRegistroInterprete() + 1;
    if(ID_I == -2){
        cout << "\nFALLO APERTURA DEL ARCHIVO" << endl;
        cout << endl;
        Cantor.setEstado(false);
        return Cantor;
    }
    Cantor.Cargar(ID_I,fecha);
    return Cantor;
}

void Agregar_Registro_Interprete(){
    Interprete Cantor;
    Cantor = Cargar_Interprete();
    if(Cantor.getEstado() == false){ /// ERROR EN FECHA o FALLO APERTURA ARCHIVO
        return;
    }
    if(Cantor.GrabarEnDisco()){ /// GRABO EN DISCO
        cout << "\nINTERPRETE GUARDADO" << endl;
        cout << endl;
        return;
    }
    cout << "\nFALLO AL GRABAR EN EL DISCO" << endl;
    cout << endl;
    return; /// FALLO GRABAR EN DISCO
}

//////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 2 LISTAR INTERPRETE POR ID

int BuscarID_Interprete(int ID_I){
    Interprete Cantor;
    int pos = 0;
    while(Cantor.LeerDeDisco(pos)){
        if(ID_I == Cantor.getID_Interprete()){
            if(Cantor.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

Interprete LeerRegistro_Interprete(int pos){
    Interprete Cantor;
    Cantor.setID_Interprete(-1);
    FILE *P;
    P = fopen(INTERPRETES,"rb");
    if(P == NULL){
        return Cantor;
    }
    fseek(P, pos * sizeof Cantor, 0);
    fread(&Cantor, sizeof Cantor, 1, P);
    fclose(P);
    return Cantor;
}

void Mostrar_Interprete_PorID(){ /// FILTRA LISTADO POR ID NUMERO DE INTERPRETE
    Interprete Cantor;
    int ID_I, pos;
    /// buscar el interprete a mostrar
    cout << "\nINGRESE EL NUMERO DE ID INTERPRETE DEL REGISTRO A MOSTRAR: ";
    cin >> ID_I;
    /// leer si existe el interprete
    pos = BuscarID_Interprete(ID_I);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID NUMERO DE INTERPRETE EN EL ARCHIVO" << endl;
        cout << endl;
        return;
    }
    Cantor = LeerRegistro_Interprete(pos);
    /// LISTAR EL INTERPRETE FILTRADO
    Cantor.Mostrar();
    cout << endl;
    return;
}

//////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 3 LISTAR TODOS LOS INTERPRETES

void Mostrar_Interprete(){
    Interprete Cantor;
    int pos = 0;
    while(Cantor.LeerDeDisco(pos)){
        Cantor.Mostrar();
        cout << endl;
        pos++;
    }
}

//////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 4 MODIFICAR GENERO MUSICAL PRINCIPAL

bool SobreEscribir_Registro_Interprete(Interprete Cantor, int pos){
    FILE *P;
    P = fopen(INTERPRETES, "rb+"); ///+ le agrega al modo lo que le falta
    if(P == NULL)return false;
    fseek(P, sizeof Cantor * pos, 0);
    bool Escribio = fwrite(&Cantor, sizeof Cantor, 1, P);
    fclose(P);
    return Escribio;
}

void Modificar_GeneroPrincipal_Interprete(){
    Interprete Cantor;
    int ID_I, pos, Gen_Mus;
    /// buscar el interprete a modificar genero musical principal
    cout << "\nINGRESE EL ID INTERPRETE DEL REGISTRO A MODIFICAR GENERO MUSICAL PRINCIPAL: ";
    cin >> ID_I;
    /// leer si existe el interprete
    pos = BuscarID_Interprete(ID_I);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE INTERPRETE EN EL ARCHIVO" << endl;
        cout << endl;
        return;
    }
    Cantor = LeerRegistro_Interprete(pos);
    /// cambiar el genero musical del campo
    cout << "\nINGRESE EL NUEVO GENERO MUSICAL PRINCIPAL: ";
    cin >> Gen_Mus;
    if(Cantor.setGenero(Gen_Mus) == false){
        cout << "\nEL GENERO MUSICAL INGRESADO ES INVALIDO. DEBER SER 1 AL 10" << endl;
        cout << endl;
        return;
    }
    /// sobreescribir el registro
    if(SobreEscribir_Registro_Interprete(Cantor, pos)){
        cout << "REGISTRO MODIFICADO" << endl;
        cout << endl;
        return;
    }
     cout << "ERROR EN LA MODIFICACION DEL REGISTRO " << endl;
     cout << endl;
     return;
}

//////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 5 ELIMINAR LOGICA INTERPRETE

void Eliminar_Logico_Interprete(){
    Interprete Cantor;
    int ID_I, pos;
    /// buscar el registro a eliminar
    cout << "\nINGRESE EL ID DE INTERPRETE DEL REGISTRO A DAR DE BAJA: ";
    cin >> ID_I;
    /// leer si existe el registro
    pos = BuscarID_Interprete(ID_I);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE INTERPRETE EN EL ARCHIVO" << endl;
        cout << endl;
        return;
    }
    Cantor = LeerRegistro_Interprete(pos);
    /// cambiar el estado del campo
    Cantor.setEstado(false);
    /// sobreescribir el registro
    if(SobreEscribir_Registro_Interprete(Cantor, pos)){
        cout << "\nREGISTRO BORRADO" << endl;
        cout << endl;
        return;
    }
    cout << "\nERROR EN EL BORRADO DEL REGISTRO" << endl;
    cout << endl;
    return;
}

#endif // FUNCIONES_CLASE_INTERPRETE_H_INCLUDED
