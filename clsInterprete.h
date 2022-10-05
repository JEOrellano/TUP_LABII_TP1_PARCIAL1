#ifndef CLSINTERPRETE_H_INCLUDED
#define CLSINTERPRETE_H_INCLUDED

class Interprete{
    private:
        int idInterprete;
        char nombre[40];
        int nacionalidad;
        int tipo;
        int genero;
        Fecha fechaInicioActividad;
        bool estado;
    public:
        ///CONSTRUCTOR
        Interprete(int i = 0, const char *n = "sin nombre", int nac = 0, int t = 0, int g = 0, bool e = false){
            idInterprete = i;
            strcpy(nombre, n);
            nacionalidad = nac;
            tipo = t;
            genero = g;
            estado = e;
        }
        /// METODOS
        bool Cargar(int idI, Fecha fecha);
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();

        ///SETS
        void setIdInterprete(int i){idInterprete = i;}
        void setNombre(const char *n){strcpy(nombre, n);}
        bool setNacionalidad(int nac){
            if(nac >= 1 && nac <= 100){
                nacionalidad = nac;
                return true;
            }
            return false;
        }
        bool setTipo(int t){
            if(t >= 1 && t <= 5){
                tipo = t;
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
        void setFechaInicioActividad(Fecha f){fechaInicioActividad = f;}
        void setEstado(bool e){estado = e;}

        ///GETS
        int getIdInterprete(){return idInterprete;}
        const char *getNombre(){return nombre;}
        int getNacionalidad(){return nacionalidad;}
        int getTipo(){return tipo;}
        int getGenero(){return genero;}
        Fecha getFechaInicioActividad(){return fechaInicioActividad;}
        bool getEstado(){return estado;}

        /// DESTRUCTOR
        ~Interprete(){}
};

//////////////// CARGAR INTERPRETE

bool Interprete::Cargar(int idI, Fecha fecha){
    setIdInterprete(idI);
    cout << "NOMBRE: ";
    cargarCadena(nombre, 39);
    setNombre(nombre);
    cout << "NACIONALIDAD: ";
    cin >> nacionalidad;
    if(!setNacionalidad(nacionalidad)){
        cout << "\nNACIONALIDAD DEBE ESTAR ENTRE 1 Y 100" << endl;
        return false;
    }
    cout << "TIPO DE INTERPRETE: ";
    cin >> tipo;
    if(!setTipo(tipo)){
        cout << "\nTIPO DE INTERPRETE DEBE ESTAR ENTRE 1 Y 5" << endl;
        return false;
    }
    cout << "GENERO MUSICAL PRINCIPAL: ";
    cin >> genero;
    if(!setGenero(genero)){
        cout << "\nGENERO MUSICAL PRINCIPAL DEBE ESTAR ENTRE 1 Y 10" << endl;
        return false;
    }
    setFechaInicioActividad(fecha);
    estado = 1;
    setEstado(estado);
    return true;
}

//////////////// MOSTRAR INTERPRETE

void Interprete::Mostrar(){
    if(estado){
        cout << "\nID INTERPRETE: "<< idInterprete << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "NACIONALIDAD: " << nacionalidad  << endl;
        cout << "TIPO DE INTERPRETE: " << tipo << endl;
        cout << "GENERO MUSICAL: " << genero << endl;
        cout << "FECHA DE INICIO DE ACTIVIDAD: " << endl;
        fechaInicioActividad.Mostrar();
    }
}

//////////////// LEER DE DISCO INTERPRETE

bool Interprete::LeerDeDisco(int pos){
    FILE *p;
    p = fopen(INTERPRETES, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Interprete) * pos, 0);
    bool leyo = fread(this, sizeof(Interprete), 1, p);
    fclose(p);
    return leyo;
}

//////////////// GRABAR EN DISCO INTERPRETE

bool Interprete::GrabarEnDisco(){
    FILE *p;
    p = fopen(INTERPRETES, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(this, sizeof(Interprete), 1, p);
    fclose(p);
    return escribio;
}

/// PROTOTIPO VALIDAR INTERPRETE

bool validarInterprete(int idI);

//////////////// DEFINICION VALIDAR INTERPRETE;

bool validarInterprete(int idI){
    Interprete cantor;
    int pos = 0;
    while(cantor.LeerDeDisco(pos)){
        if(idI == cantor.getIdInterprete()){
            return cantor.getEstado();
        }
        pos++;
    }
    return false;
}

#endif // CLSINTERPRETE_H_INCLUDED
