#ifndef FUNCIONES_CLASE_CANCION_H_INCLUDED
#define FUNCIONES_CLASE_CANCION_H_INCLUDED

/// DECLARACION FUNCIONES PUNTO NUMERO 1 AGREGAR CANCION

int ContarRegistroCancion();

Cancion Cargar_Cancion();

void Agregar_Registro_Cancion();

/// DECLARACION FUNCIONES PUNTO NUMERO 2

int BuscarID_Cancion(int ID_C);

Cancion LeerRegistroCancion(int pos);

void Mostrar_CancionPorId();

/// DECLARACION FUNCIONES PUNTO NUMERO 3

void MostrarCancion();

/// DECLARACION FUNCIONES PUNTO NUMERO 4

bool SobreEscribir_Registro_Cancion(Cancion tema, int pos);

bool Modificar_FechaEstreno_Cancion();

/// DECLARACION FUNCIONES PUNTO NUMERO 5

bool Eliminar_Logico_Cancion();

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 1 AGREGAR CANCION

int ContarRegistroCancion(){
    int cant;
    FILE *P;
    P = fopen(CANCIONES, "rb");
    if(P == NULL){
        return 0;
    }
    fseek(P, 0, 2);
    cant = ftell(P)/sizeof(Cancion);
    fclose(P);
    return cant;
}

Cancion Cargar_Cancion(){
    Cancion Tema;
    int ID_C, ID_I;
    Fecha fecha;
    cout << "ID INTERPRETE: ";
    cin >> ID_I;
    if(validarInterprete(ID_I) < 1){
        Tema.setEstado(false);
        return Tema;
    }
    cout << "INGRESE FECHA DE ESTRENO: " << endl;
    if(fecha.Cargar() == false){
        cout << "\nFALLO CARGAR FECHA" << endl;
        cout << endl;
        Tema.setEstado(false);
        return Tema;
    }
    if(validarFecha(fecha) == false){
        cout << "\nLA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A HOY" << endl;
        cout << endl;
        Tema.setEstado(false);
        return Tema;
    }
    ID_C = ContarRegistroCancion() + 1;
    if(Tema.Cargar(ID_C, fecha, ID_I) == false){
        cout << "\nFALLO CARGAR TEMA" << endl;
        Tema.setEstado(false);
        return Tema;
    }
    return Tema;
}

void Agregar_Registro_Cancion(){
    Cancion Tema;
    Tema = Cargar_Cancion();
    if(Tema.getEstado() == false){
        return;
    }
    if(Tema.GrabarEnDisco()){
        cout << "\nCANCION GRABADA" << endl;
        cout << endl;
        return;
    }
    cout << "\nFALLO AL GRABAR EN EL DISCO" << endl;
    cout << endl;
    return;
}

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 2 BUSCAR CANCION POR ID

int BuscarID_Cancion(int ID_C){
    Cancion Tema;
    int pos = 0;
    while(Tema.LeerDeDisco(pos)){
        if(ID_C == Tema.getID_Cancion()){
            if(Tema.getEstado()){
                return pos;
            }
        }
        pos++;
    }
    return -1;
}

Cancion LeerRegistroCancion(int pos){
    Cancion Tema;
    Tema.setID_Cancion(-1);
    FILE *P;
    P = fopen(CANCIONES,"rb");
    if(P == NULL){
        return Tema;
    }
    fseek(P, pos * sizeof Tema, 0);
    fread(&Tema, sizeof Tema, 1, P);
    fclose(P);
    return Tema;
}

void Mostrar_Cancion_PorID(){
    Cancion Tema;
    int ID_C, pos;
    /// buscar la cancion a mostrar
    cout << "\nINGRESE EL NUMERO DE ID DE CANCION DEL REGISTRO A MOSTRAR: ";
    cin >> ID_C;
    /// leer si existe la cancion
    pos = BuscarID_Cancion(ID_C);
    if(pos == -1){
        cout << "\nNO EXISTE EL IDNUMERO DE CANCION EN EL ARCHIVO" << endl;
        cout << endl;
        return;
    }
    Tema = LeerRegistroCancion(pos);
    /// LISTAR LA CANCION FILTRADA
    Tema.Mostrar();
    return;
}

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 3 LISTAR TODAS LAS CANCIONES

void Mostrar_Cancion(){

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 4 MODIFICAR FECHA DE ESTRENO

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 4 MODIFICAR FECHA DE ESTRENO
    Cancion tema;
    int pos = 0;
    while(tema.LeerDeDisco(pos)){
        tema.Mostrar();
        cout << endl;
        pos++;
    }
}

bool SobreEscribir_Registro_Cancion(Cancion Tema, int pos){
    FILE *P;
    P = fopen(CANCIONES, "rb+"); ///+ le agrega al modo lo que le falta
    if(P == NULL)return false;
    fseek(P, sizeof Tema * pos, 0);
    bool Escribio = fwrite(&Tema, sizeof Tema, 1, P);
    fclose(P);
    return Escribio;
}

bool Modificar_FechaEstreno_Cancion(){
    Cancion Tema;
    int ID_C, pos;
    Fecha fecha;
    /// buscar la cancion a modificar fecha de estreno
    cout << "\nINGRESE EL ID CANCION DEL REGISTRO A MODIFICAR FECHA DE ESTRENO: ";
    cin >> ID_C;
    /// leer si existe la cancion
    pos = BuscarID_Cancion(ID_C);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE CANCION EN EL ARCHIVO" << endl;
        cout << endl;
        return false;
    }
    Tema = LeerRegistroCancion(pos);
    /// cambiar la categoria del campo
    cout << "\nINGRESE LA NUEVA FECHA DE ESTRENO: " << endl;
    if(fecha.Cargar() == false){
        cout << "\nFALLO CARGAR FECHA" << endl;
        cout << endl;
        Tema.setEstado(false);
        return false;
    }
    if(validarFecha(fecha) == false){
        cout << "\nLA FECHA INGRESADA ES INVALIDA. DEBER SER MENOR O IGUAL A HOY" << endl;
        cout << endl;
        return false;
    }
    Tema.setFechaEstreno(fecha);
    /// sobreescribir el registro
    if(SobreEscribir_Registro_Cancion(Tema, pos)==false){;
        cout << "\nERROR EN LA MODIFICACION DEL REGISTRO " << endl;
        cout << endl;
    }
    else{
        cout << "\nREGISTRO MODIFICADO" << endl;
        cout << endl;
    }
}

/////////////////////// DESARROLLO FUNCIONES PUNTO NUMERO 5 ELIMINAR LOGICO CANCION

bool Eliminar_Logico_Cancion(){
    Cancion Tema;
    int ID_C, pos;
    /// buscar el registro a eliminar
    cout << "\nINGRESE EL ID DE CANCION DEL REGISTRO A DAR DE BAJA: ";
    cin >> ID_C;
    /// leer si existe el registro
    pos = BuscarID_Cancion(ID_C);
    if(pos == -1){
        cout << "\nNO EXISTE EL ID DE CANCION EN EL ARCHIVO" << endl;
        cout << endl;
        return false;
    }
    Tema = LeerRegistroCancion(pos);
    /// cambiar el estado del campo
    Tema.setEstado(false);
    /// sobreescribir el registro
    if(SobreEscribir_Registro_Cancion(Tema, pos)==false){
        cout << "\nERROR EN EL BORRADO DEL REGISTRO" << endl;
        cout << endl;
    }
    else{
        cout << "\nREGISTRO BORRADO" << endl;
        cout << endl;
    }
}

#endif // FUNCIONES_CLASE_CANCION_H_INCLUDED
