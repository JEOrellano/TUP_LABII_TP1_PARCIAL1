#ifndef CLASE_CANCION_H_INCLUDED
#define CLASE_CANCION_H_INCLUDED

class Cancion{
    private:
        int ID_Cancion;
        char Nombre[30];
        char NombreAutor[30];
        int ID_Interprete; /// debe existir en el archivo interprete
        Fecha FechaEstreno; /// valida anterior o igual a la fecha actual
        float Duracion; ///valor positivo
        int Genero; ///1-10
        bool Estado;
    public:
        ///CONSTRUCTOR
        Cancion(int C = 0, const char *N = "SIN NOMBRE", const char *NA = "SIN AUTOR", int I = 0,float D = 0, int G = 0, bool E = false){
            ID_Cancion = C;
            strcpy(Nombre, N);
            strcpy(NombreAutor, NA);
            ID_Interprete = I;
            Duracion = D;
            Genero = G;
            Estado = E;
        }
        ///METODOS
        bool Cargar(int ID_C, Fecha fecha, int ID_I);
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();
        ///SETS
        void setID_Cancion(int var){ID_Cancion = var;}
        void setNombre(const char *P){strcpy(Nombre,P);}
        void setNombreAutor(const char *P){strcpy(NombreAutor,P);}
        void setID_Interprete(int var){ID_Interprete = var;}
        void setFechaEstreno(Fecha F){FechaEstreno = F;}
        bool setDuracion(int var){
            if(var>0){
                Duracion = var;
                return true;
            }
            return false;
        }
        bool setGenero(int var){
            if(var>=0 && var<=10){
                Genero = var;
                return true;
            }
            return false;
        }
        void setEstado(bool ban){Estado = ban;}
        ///GETS
        int getID_Cancion(){return ID_Cancion;}
        const char *getNombre(){return Nombre;}
        const char *getNombreAutor(){return NombreAutor;}
        int getID_Interprete(){return ID_Interprete;}
        Fecha getFechaEstreno(){return FechaEstreno;}
        float getDuracion(){return Duracion;}
        int getGenero(){return Genero;}
        bool getEstado(){return Estado;}

        /// DESTRUCTOR
        ~Cancion(){}
};

////////////////////////// CARGAR CANCION

bool Cancion::Cargar(int ID_C, Fecha fecha, int ID_I){
    //cout << "ID CANCION: ";
    //cin >> idCancion;
    setID_Cancion(ID_C);
    cout << "NOMBRE: ";
    cargarCadena(Nombre, 29);
    setNombre(Nombre);
    cout << "NOMBRE DEL AUTOR: ";
    cargarCadena(NombreAutor, 29);
    setNombreAutor(NombreAutor);
    //cout << "ID INTERPRETE: ";
    //cin >> idInterprete;
    setID_Interprete(ID_Interprete);
    //cout << "FECHA DE ESTRENO: ";
    //fechaEstreno.Cargar();
    setFechaEstreno(fecha);
    cout << "DURACION DE LA CANCION: ";
    cin >> Duracion;
    if(!setDuracion(Duracion)){
        cout << "LA DURACION DEBE SER UN VALOR POSITIVO" << endl;
        return false;
    }
    cout << "GENERO MUSICAL: ";
    cin >> Genero;
    if(!setGenero(Genero)){
        cout << "GENERO MUSICAL DEBE ESTAR ENTRE 1 Y 10" << endl;
        return false;
    }
    Estado = 1;
    setEstado(Estado);
    return true;
}

////////////////////////// MOSTRAR CANCION

void Cancion::Mostrar(){
    if(Estado){
        cout << "ID CANCION: "<< ID_Cancion << endl;
        cout << "NOMBRE: " << Nombre << endl;
        cout << "NOMBRE DEL AUTOR: " << NombreAutor << endl;
        cout << "ID INTERPRETE: " << ID_Interprete  << endl;
        cout << "FECHA DE ESTRENO: " << endl;
        FechaEstreno.Mostrar();
        cout << "DURACION DE LA CANCION: " << Duracion << endl;
        cout << "GENERO MUSICAL: " << Genero << endl;
        cout << endl;
    }
}

////////////////////////// LEER EN DISCO

bool Cancion::LeerDeDisco(int pos){
    FILE *P;
    P = fopen(CANCIONES, "rb");
    if(P == NULL){
        return false;
    }
    fseek(P, sizeof(Cancion) * pos, 0);
    bool Leyo = fread(this, sizeof(Cancion), 1, P);
    fclose(P);
    return Leyo;
}

//////////////////////////GRABAR EN DISCO

bool Cancion::GrabarEnDisco(){
    FILE *P;
    P = fopen(CANCIONES, "ab");
    if(P == NULL){
        return false;
    }
    bool Escribio = fwrite(this, sizeof(Cancion), 1, P);
    fclose(P);
    return Escribio;
}

#endif // CLASE_CANCION_H_INCLUDED
