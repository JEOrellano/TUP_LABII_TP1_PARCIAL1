#ifndef CLSCANCION_H_INCLUDED
#define CLSCANCION_H_INCLUDED

class Cancion{
    private:
        int idCancion;
        char nombre[30];
        char nombreAutor[30];
        int idInterprete;
        Fecha fechaEstreno;
        float duracion;
        int genero;
        bool estado;
    public:
        ///CONSTRUCTOR
        Cancion(int c = 0, const char *n = "sin nombre", const char *na = "sin autor", int i = 0, float t = 0, int g = 0, bool e = false){
            idCancion = c;
            strcpy(nombre, n);
            strcpy(nombreAutor, na);
            idInterprete = i;
            duracion = t;
            genero = g;
            estado = e;
        }
        /// METODOS
        bool Cargar(int idC, Fecha fecha, int idI);
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();

        ///SETS
        void setIdCancion(int c){idCancion = c;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setNombreAutor(const char *n){strcpy(nombreAutor, n);}
        void setIdInterprete(int i){idInterprete = i;}
        void setFechaEstreno(Fecha f){fechaEstreno = f;}
        bool setDuracion(float t){
            if(t > 0){
                duracion = t;
                return true;
            }
            return false;
        }
        bool setGenero(int g){
            if(g >= 1 && g <= 10){
                genero = g;
                return true;
            }
            return false;
        }
        void setEstado(bool e){estado = e;}

        ///GETS
        int getIdCancion(){return idCancion;}
        const char *getNombre(){return nombre;}
        const char *getNombreAutor(){return nombreAutor;}
        int getIdInterprete(){return idInterprete;}
        Fecha getFechaEstreno(){return fechaEstreno;}
        float getDuracion(){return duracion;}
        int getGenero(){return genero;}
        bool getEstado(){return estado;}

        /// DESTRUCTOR
        ~Cancion(){}
};

//////////////CARGAR CANCION

bool Cancion::Cargar(int idC, Fecha fecha, int idI){
    setIdCancion(idC);
    cout << "NOMBRE: ";
    cargarCadena(nombre, 29);
    setNombre(nombre);
    cout << "NOMBRE DEL AUTOR: ";
    cargarCadena(nombreAutor, 29);
    setNombreAutor(nombreAutor);
    setIdInterprete(idI);
    setFechaEstreno(fecha);
    cout << "DURACION DE LA CANCION: ";
    cin >> duracion;
    if(!setDuracion(duracion)){
        cout << "\nLA DURACION DEBE SER UN VALOR POSITIVO" << endl;
        cout << endl;
        return false;
    }
    cout << "GENERO MUSICAL: ";
    cin >> genero;
    if(!setGenero(genero)){
        cout << "\nGENERO MUSICAL DEBE ESTAR ENTRE 1 Y 10" << endl;
        cout << endl;
        return false;
    }
    estado = 1;
    setEstado(estado);
    return true;
}

//////////////MOSTRAR CANCION

void Cancion::Mostrar(){
    if(estado){
        cout << "\nID CANCION: "<< idCancion << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "NOMBRE DEL AUTOR: " << nombreAutor << endl;
        cout << "ID INTERPRETE: " << idInterprete  << endl;
        cout << "FECHA DE ESTRENO: " << endl;
        fechaEstreno.Mostrar();
        cout << "DURACION DE LA CANCION: " << duracion << endl;
        cout << "GENERO MUSICAL: " << genero << endl;
    }
}

//////////////LEER DE DISCO CANCION

bool Cancion::LeerDeDisco(int pos){
    FILE *p;
    p = fopen(CANCIONES, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Cancion) * pos, 0);
    bool leyo = fread(this, sizeof(Cancion), 1, p);
    fclose(p);
    return leyo;
}

//////////////GRABRA EN DISCO CANCION

bool Cancion::GrabarEnDisco(){
    FILE *p;
    p = fopen(CANCIONES, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(this, sizeof(Cancion), 1, p);
    fclose(p);
    return escribio;
}

#endif // CLSCANCION_H_INCLUDED
