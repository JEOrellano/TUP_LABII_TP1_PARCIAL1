#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

/// PROTOTIPOS FUNCIONES REPORTES

void mostrarInterpretesArgentinos();

void mostrarCantidadGenerosPorTipoInstrumentacion();

void agregarRegistroInterprete2021();

/// DEFINICIONES FUNCIONES REPORTES

/// PUNTO 1
void mostrarInterpretesArgentinos(){
    Interprete cantor;
    int posI = 0;
    cout << "INTERPRETES ARGENTINOS: " << endl;
    while(cantor.LeerDeDisco(posI++)){
        if(cantor.getNacionalidad() == 5 && cantor.getEstado()){
            cantor.Mostrar();
            cout << endl;
        }
    }
}

/// PUNTO 2
void mostrarCantidadGenerosPorTipoInstrumentacion(){
    Genero gen;
    int vContGenTI[5] = {0};
    int posG = 0;
    int i;
    while(gen.LeerDeDisco(posG++)){
        vContGenTI[gen.getTipoInstrumentacion() - 1]++;
    }
    cout << "CANTIDAD DE GENREROS POR CADA TIPO DE INSTRUMENTACION: " << endl;
    for(i = 0; i < 5; i++){
        cout << vContGenTI[i] << "\t" << i + 1 << endl;
    }
}

/// PUNTO 3

class Interprete2021{
    private:
        int idInterprete;
        char nombre[40];
        int repertorio;
    public:
        /// CONSTRUCTOR

        /// METODOS
        void Mostrar();
        bool LeerDeDisco(int pos);
        bool GrabarEnDisco();

        /// SETS
        void setIdInterprete(int i){idInterprete = i;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setRepertorio(int r){repertorio = r;}

        /// GETS
        int getIdInterprete(){return idInterprete;}
        const char *getNombre(){return nombre;}
        int getRepertorio(){return repertorio;}
};

void Interprete2021::Mostrar(){
    cout << "ID INTERPRETE: "<< idInterprete << endl;

    cout << "NOMBRE: " << nombre << endl;

    cout << "REPERTORIO: " << repertorio << endl;
}

bool Interprete2021::LeerDeDisco(int pos){
    FILE *p;
    p = fopen("interpretes2021.dat", "rb");
    if(p == NULL){
        return false;
    }
    fseek(p, sizeof(Interprete2021) * pos, 0);
    bool leyo = fread(this, sizeof(Interprete2021), 1, p);
    fclose(p);
    return leyo;
}

bool Interprete2021::GrabarEnDisco(){
    FILE *p;
    p = fopen("interpretes2021.dat", "ab");
    if(p == NULL){
        return false;
    }
    bool escribio = fwrite(this, sizeof(Interprete2021), 1, p);
    fclose(p);
    return escribio;
}

void agregarRegistroInterprete2021(){
    Interprete2021 artista;
    Interprete  cantor;
    Cancion tema;
    int posI2021;
    int posI = 0;
    int contCancion;
    while(cantor.LeerDeDisco(posI++)){
        if(cantor.getFechaInicioActividad().getAnio() == 2021 && cantor.getEstado()){
            artista.setIdInterprete(cantor.getIdInterprete());
            artista.setNombre(cantor.getNombre());
            posI2021 = 0;
            contCancion = 0;
            while(tema.LeerDeDisco(posI2021++)){
                if(tema.getIdInterprete() == cantor.getIdInterprete() && tema.getEstado()){
                   contCancion++;
                }
            }
            artista.setRepertorio(contCancion);
            artista.GrabarEnDisco();
        }
    }
}

#endif // REPORTES_H_INCLUDED
