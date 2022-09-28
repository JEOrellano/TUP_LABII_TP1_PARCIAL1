#ifndef FUNCIONESGLOBALESGENERO_H_INCLUDED
#define FUNCIONESGLOBALESGENERO_H_INCLUDED

/// PROTOTIPOS FUNCIONES GLOBALES GENERO

int contarRegistroGenero();

Genero cargarGenero();

int agregarRegistroGenero();

bool mostrarGeneroPorId();

int buscarIdGenero(int idG);

void mostrarInterprete();

/// DEFINICIONES FUNCIONES GLOBALES GENERO

// PUNTO 1 AGREGAR GENERO

int contarRegistroGenero(){
    int cant;
    FILE *p;
    p = fopen(GENEROS, "rb");
    if(p == NULL){
        return 0;
    }
    fseek(p, 0, 2);
    cant = ftell(p)/sizeof(Genero);
    fclose(p);
    return cant;
}

Genero cargarGenero(){
    Genero gen;
    int idG;

    idG = contarRegistroGenero() + 1;
    if(idG == 1){
        cout << "FALLO APERTURA DEL ARCHIVO, NO EXISTE O ESTA VACIO" << endl;
    }
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

// PUNTO 2 LISTAR GENERO POR ID
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
    /// int desplazamiento = pos * sizeof tema;
    /// cantidad de bytes que necesito desplazarme
    /// 0 SEEK_SET DESDE EL PRINCIPIO DEL ARCHIVO
    /// 1 SEEK_CUR DESDE LA POSICION ACTUACL
    /// 2 SEEK_END DESDE LA POSICION FINAL
    fseek(p, pos * sizeof gen, 0);
    fread(&gen, sizeof gen, 1, p);
    fclose(p);
    return gen;
}

bool mostrarGeneroPorId(){ /// FILTRA LISTADO POR ID NUMERO DE INTERPRETE
    Genero gen;
    int idG, pos;
    /// buscar el genero a mostrar
    cout << "INGRESE EL NUMERO DE ID GENERO MUSICAL DEL REGISTRO A MOSTRAR: ";
    cin >> idG;
    /// leer si existe el genero
    pos = buscarIdGenero(idG);
    if(pos == -1){
        cout << "NO EXISTE EL ID  DEL GENERO MUSICAL EN EL ARCHIVO" << endl;
        return false;
    }
    gen = leerRegistroGenero(pos);
    /// LISTAR EL INTERPRETE FILTRADO
    gen.Mostrar();
    return true;
}

// PUNTO 3 LISTAR TODOS LOS GENEROS
void mostrarGenero(){
    Genero gen;
    int pos = 0;
    while(gen.LeerDeDisco(pos)){
        gen.Mostrar();
        cout << endl;
        pos++;
    }
}

// PUNTO 4 MODIFICAR TIPO DE INSTRUMENTACION
bool sobreEscribirRegistroGenero(Genero gen, int pos){
    FILE *p;
    p = fopen(GENEROS, "rb+"); ///+ le agrega al modo lo que le falta
    if(p == NULL)return false;
    fseek(p, sizeof gen * pos, 0);
    bool escribio = fwrite(&gen, sizeof gen, 1, p);
    fclose(p);
    return escribio;
}

bool modificarTipoInstrumentacionGenero(){
    Genero gen;
    int idG, pos, tInst;
    /// buscar el genero musical a modificar tipo de instrumentacion
    cout << "INGRESE EL ID GENERO DEL REGISTRO A MODIFICAR TIPO DE INSTRUMENTACION: ";
    cin >> idG;
    /// leer si existe el genero musical
    pos = buscarIdGenero(idG);
    if(pos == -1){
        cout << "NO EXISTE EL ID DE GENERO MUSICAL EN EL ARCHIVO" << endl;
        return false;
    }
    gen = leerRegistroGenero(pos);
    /// cambiar el tipo de instrumento del campo
    cout << "INGRESE EL NUEVO TIPO DE INSTRUMENTO: ";
    cin >> tInst;
    if(!gen.setTipoInstrumentacion(tInst)){
        cout << "TIPO DE INSTRUMENTACION DEBE ESTAR ENTRE 1 Y 5" << endl;
        return false;
    }
    /// sobreescribir el registro
    return sobreEscribirRegistroGenero(gen, pos);
}

#endif // FUNCIONESGLOBALESGENERO_H_INCLUDED
