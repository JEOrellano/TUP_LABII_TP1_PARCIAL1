#ifndef CLSGENERO_H_INCLUDED
#define CLSGENERO_H_INCLUDED

class Genero{
    private:
        int idGenero;
        char nombre[40];
        int paisOrigen;
        int tipoInstrumentacion;
        bool estado;
    public:
        ///CONSTRUCTOR
        Genero(int g = 0, const char *n = "sin nombre", int o = 0, int i = 0, bool e = false){
            idGenero = g;
            strcpy(nombre, n);
            paisOrigen = o;
            tipoInstrumentacion = i;
            estado = e;
        }
        /// METODOS
        bool Cargar(int idG);
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();

        ///SETS
        void setIdGenero(int g){idGenero = g;}
        void setNombre(const char *n){strcpy(nombre, n);}
        bool setPaisOrigen(int o){
            if(o >= 1 && o <= 100){
                paisOrigen = o;
                return true;
            }
            return false;
        }
        bool setTipoInstrumentacion(int i){
            if(i >= 1 && i <= 5){
                tipoInstrumentacion = i;
                return true;
            }
            return false;
        }
        void setEstado(bool e){estado = e;}

        ///GETS
        int getIdGenero(){return idGenero;}
        const char *getNombre(){return nombre;}
        int getPaisOrigen(){return paisOrigen;}
        int getTipoInstrumentacion(){return tipoInstrumentacion;}
        bool getEstado(){return estado;}
        /// DESTRUCTOR
        ~Genero(){}
};

/////////////////// CARGAR GENERO

bool Genero::Cargar(int idG){
    //cout << "ID GENERO: ";
    //cin >> idGenero;
    setIdGenero(idG);
    cout << "\nNOMBRE: ";
    cargarCadena(nombre, 39);
    setNombre(nombre);
    cout << "PAIS DE ORIGEN: ";
    cin >> paisOrigen;
    if(!setPaisOrigen(paisOrigen)){
        cout << "\nERROR, PAIS DE ORIGEN DEBE ESTAR ENTRE 1 Y 100" << endl;
        return false;
    }
    cout << "TIPO DE INSTRUMENTACION: ";
    cin >> tipoInstrumentacion;
    if(!setTipoInstrumentacion(tipoInstrumentacion)){
        cout << "\nERROR, TIPO DE INSTRUMENTACION DEBE ESTAR ENTRE 1 Y 5" << endl;
        return false;
    }
    estado = 1;
    setEstado(estado);
    return true;
}

/////////////////// MOSTRAR GENERO

void Genero::Mostrar(){
    if(estado){
        cout << "\nID GENERO: " << idGenero << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "PAIS DE ORIGEN: " << paisOrigen << endl;
        cout << "TIPO DE INSTRUMENTACION: " << tipoInstrumentacion << endl;
    }
}

/////////////////// LEER DE DISCO GENERO

bool Genero::LeerDeDisco(int pos){
    FILE *p;
    p = fopen(GENEROS, "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Genero) * pos, 0);
    bool leyo = fread(this, sizeof(Genero), 1, p);
    fclose(p);
    return leyo;
}

///////////////////  GRABAR EN DISCO GENERO

bool Genero::GrabarEnDisco(){
    FILE *p;
    p = fopen(GENEROS, "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(this, sizeof(Genero), 1, p);
    fclose(p);
    return escribio;
}

#endif // CLSGENERO_H_INCLUDED
