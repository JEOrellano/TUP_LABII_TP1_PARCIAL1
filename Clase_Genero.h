#ifndef CLASE_GENERO_H_INCLUDED
#define CLASE_GENERO_H_INCLUDED

class Genero{
    private:
        int ID_Genero;
        char Nombre[40];
        int Pais; ///ENTERO DE 1-100
        int Tipo_Instrumentacion; ///1-5
        bool Estado;
    public:
        ///CONSTRUCTOR
        Genero(int G = 0, const char *N = "SIN NOMBRE", int O = 0, int I = 0, bool E = false){
            ID_Genero = G;
            strcpy(Nombre, N);
            Pais = O;
            Tipo_Instrumentacion = I;
            Estado = E;
        }
        ///METODOS
        bool Cargar(int ID_G);
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();
        ///SETS
        void setID_Genero(int var){ID_Genero = var;}
        void setNombre(const char *P){strcpy(Nombre, P);}
        bool setPais(int var){
            if(var>=1 && var<=100){
                Pais = var;
                return true;
            }
            return false;
        }
        bool setTipo_Instrumentacion(int var){
            if(var>=1 && var<=5){
                Tipo_Instrumentacion = var;
                return true;
            }
            return false;
        }
        void setEstado(bool ban){Estado = ban;}
        ///GETS
        int getID_Genero(){return ID_Genero;}
        const char *getNombre(){return Nombre;}
        int getPais(){return Pais;}
        int getTipo_Instrumentacion(){return Tipo_Instrumentacion;}
        bool getEstado(){return Estado;}
        /// DESTRUCTOR
        ~Genero(){}
};

//////////////////////////// CARGAR GENERO

bool Genero::Cargar(int ID_G){
    //cout << "ID GENERO: ";
    //cin >> idGenero;
    setID_Genero(ID_G);
    cout << "\nNOMBRE: ";
    cargarCadena(Nombre, 39);
    setNombre(Nombre);
    cout << "PAIS DE ORIGEN: ";
    cin >> Pais;
    if(!setPais(Pais)){
        cout << "\NPAIS DE ORIGEN DEBE ESTAR ENTRE 1 Y 100" << endl;
        cout << endl;
        return false;
    }
    cout << "TIPO DE INSTRUMENTACION: ";
    cin >> Tipo_Instrumentacion;
    if(!setTipo_Instrumentacion(Tipo_Instrumentacion)){
        cout << "\nTIPO DE INSTRUMENTACION DEBE ESTAR ENTRE 1 Y 5" << endl;
        cout << endl;
        return false;
    }
    Estado = 1;
    setEstado(Estado);
    return true;
}

//////////////////////////// MOSTRAR GENERO

void Genero::Mostrar(){
    if(Estado){
        cout << "\nID GENERO: " << ID_Genero << endl;
        cout << "NOMBRE: " << Nombre << endl;
        cout << "PAIS DE ORIGEN: " << Pais << endl;
        cout << "TIPO DE INSTRUMENTACION: " << Tipo_Instrumentacion << endl;
    }
}

//////////////////////////// LEER DISCO

bool Genero::LeerDeDisco(int pos){
    FILE *P;
    P = fopen(GENEROS, "rb");
    if(P == NULL){
        return false;
    }
    fseek(P, sizeof(Genero) * pos, 0);
    bool Leyo = fread(this, sizeof(Genero), 1, P);
    fclose(P);
    return Leyo;
}

//////////////////////////// GREBAR EN DISCO

bool Genero::GrabarEnDisco(){
    FILE *P;
    P = fopen(GENEROS, "ab");
    if(P == NULL){
        return false;
    }
    bool Escribio = fwrite(this, sizeof(Genero), 1, P);
    fclose(P);
    return Escribio;
}

#endif // CLASE_GENERO_H_INCLUDED
