#ifndef CLASE_INTERPRETE_H_INCLUDED
#define CLASE_INTERPRETE_H_INCLUDED

/// PROTOTIPO VALIDAR INTERPRETE

int validarInterprete(int idI);

///CLASE INTERPRETE

class Interprete{
    private:
        int ID_Interprete;
        char Nombre[40];
        int Nacionalidad; ///1-100
        int Tipo_Interprete; ///1-5
        int Genero_Musical_Principal; ///1-10
        Fecha fecha; /// valida anterior o igual a la fecha actual
        bool Estado;
    public:

        ///CONSTRUCTOR
        Interprete(int I = 0, const char *N = "SIN NOMBRE", int NAC = 0, int T = 0, int G = 0,bool E = false){
            ID_Interprete = I;
            strcpy(Nombre, N);
            Nacionalidad = NAC;
            Tipo_Interprete = T;
            Genero_Musical_Principal = G;
            Estado = E;
        }
        ///METODOS
        bool Cargar(int ID_I, Fecha fecha);
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();
        ///SETS
        void setID_Interprete(int var){ID_Interprete = var;}
        void setNombre(const char *P){strcpy(Nombre,P);}
        bool setNacionalidad(int var){
            if(var>=1 && var<=100){
                Nacionalidad = var;
                return true;
            }
            return false;
        }
        bool setTipo_Interprete(int var){
            if(var>=1 && var<=5){
                Tipo_Interprete = var;
                return true;
            }
            return false;
        }
        bool setGenero(int var){
            if(var>=1 && var<=10){
                Genero_Musical_Principal = var;
                return true;
            }
            return false;
        }
        void setFecha(Fecha f){fecha = f;}
        void setEstado(bool ban){Estado = ban;}
        ///GETS
        int getID_Interprete(){return ID_Interprete;}
        const char *getNombre(){return Nombre;}
        int getNacionalidad(){return Nacionalidad;}
        int getTipo_Interprete(){return Tipo_Interprete;}
        int getGenero_Mucical_Principal(){return Genero_Musical_Principal;}
        Fecha getFecha(){return fecha;}
        bool getEstado(){return Estado;}
        /// DESTRUCTOR
        ~Interprete(){}
};

////////////////////////// CARGAR INTERPRETE

bool Interprete::Cargar(int ID_I, Fecha fecha){
    //cout << "ID INTERPRETE: ";
    //cin >> idInterprete;
    setID_Interprete(ID_I);
    cout << "NOMBRE: ";
    cargarCadena(Nombre, 39);
    setNombre(Nombre);
    cout << "NACIONALIDAD: ";
    cin >> Nacionalidad;
    if(!setNacionalidad(Nacionalidad)){
        cout << "NACIONALIDAD DEBE ESTAR ENTRE 1 Y 100" << endl;
        return false;
    }
    cout << "TIPO DE INTERPRETE: ";
    cin >> Tipo_Interprete;
    if(!setTipo_Interprete(Tipo_Interprete)){
        cout << "TIPO DE INTERPRETE DEBE ESTAR ENTRE 1 Y 5" << endl;
        return false;
    }
    cout << "GENERO MUSICAL PRINCIPAL: ";
    cin >> Genero_Musical_Principal;
    if(!setGenero(Genero_Musical_Principal)){
        cout << "GENERO MUSICAL PRINCIPAL DEBE ESTAR ENTRE 1 Y 10" << endl;
        return false;
    }
    //cout << "FECHA DE INICIO DE ACTIVIDAD: ";
    //fechaInicioActividad.Cargar();
    setFecha(fecha);
    Estado = 1;
    setEstado(Estado);
    return true;
}

////////////////////////// MOSTRARINTERPRETE

void Interprete::Mostrar(){
    if(Estado){
        cout << "\nID INTERPRETE: "<< ID_Interprete << endl;
        cout << "NOMBRE: " << Nombre << endl;
        cout << "NACIONALIDAD: " << Nacionalidad  << endl;
        cout << "TIPO DE INTERPRETE: " << Tipo_Interprete << endl;
        cout << "GENERO MUSICAL: " << Genero_Musical_Principal << endl;
        cout << "FECHA DE INICIO DE ACTIVIDAD: " << endl;
        fecha.Mostrar();
    }
}

////////////////////////// LEER EN DISCO

bool Interprete::LeerDeDisco(int pos){
    FILE *P;
    P = fopen(INTERPRETES, "rb");
    if(P == NULL){
        return false;
    }
    fseek(P, sizeof(Interprete) * pos, 0);
    bool leyo = fread(this, sizeof(Interprete), 1, P);
    fclose(P);
    return leyo;
}

////////////////////////// GRABAR EN DISCO

bool Interprete::GrabarEnDisco(){
    FILE *P;
    P = fopen(INTERPRETES, "ab");
    if(P == NULL){
        return false;
    }
    bool escribio = fwrite(this, sizeof(Interprete), 1, P);
    fclose(P);
    return escribio;
}

///////////////////////// DESARROLLO VALIDAR INTERPRETE;

int validarInterprete(int ID_I){
    Interprete Cantor;
    int pos = 0, cont = 0;
    while(Cantor.LeerDeDisco(pos)){
        if(ID_I == Cantor.getID_Interprete()){
            return 1;
        }
        cont++;
        pos++;
    }
    if(cont==0){
        cout << "\nFALLO APERTURA DEL ARCHIVO, NO EXISTE O ESTA VACIO" << endl;
        cout << endl;
        return -1;
    }
    cout << "\nEL INTERPRETE INGERSADO ES INVALIDO, NO ESTA REGISTRADO O FUE BORRADO" << endl;
    cout << endl;
    return -2;
}

#endif // CLASE_INTERPRETE_H_INCLUDED
