#ifndef CLASE_FECHA_H_INCLUDED
#define CLASE_FECHA_H_INCLUDED

/// CLASE FECHA

class Fecha{
    private:
        int Dia;
        int Mes;
        int Anio;
    public:
         /// CONSTRUCTOR
        Fecha(int D = 1, int M = 1, int A = 1900){
            Dia = D;
            Mes = M;
            Anio = A;
        }
        /// METODOS
        bool Cargar();
        void Mostrar();
        /// SETS
        bool setDia(int var){
            if (var>=1 && var<=31){
                Dia = var;
                return true;
            }
            return false;
        }
        bool setMes(int var){
            if (var>=1 && var<=12){
                Mes = var;
                return true;
            }
            return false;
        }
        bool setAnio(int var){
            if (var>=0){
                Anio = var;
                return true;
            }
            return false;
        }
        /// GEST
        int getDia(){return Dia;}
        int getMes(){return Mes;}
        int getAnio(){return Anio;}
        /// DESTRUCTOR
        ~Fecha(){}
};

////////////////////////// CARGAR

bool Fecha::Cargar(){
    cout << "DIA: ";
    cin >> Dia;
    if(!setDia(Dia)){
        cout << "\nEL DIA DEBE ESTAR ENTRE 1 Y 31" << endl;
        return false;
    }
    cout << "MES: ";
    cin >> Mes;
    if(!setMes(Mes)){
        cout << "\nEL MES DEBE ESTAR ENTRE 1 Y 12" << endl;
        return false;
    }
    cout << "ANIO: ";
    cin >> Anio;
    if(!setAnio(Anio)){
        cout << "\nEL ANIO DEBE SER POSTIVO" << endl;
        return false;
    }
    return true;
}

////////////////////////// MOSTRAR

void Fecha::Mostrar(){
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}

///////////////////////// PROTOTIPO VALIDAR FECHA

bool validarFecha(Fecha f);

///////////////////////// DEFINICION VALIDAR FECHA

bool validarFecha(Fecha f){
    time_t tiempo;
    struct tm *hoy;

    tiempo = time(NULL);
    hoy = localtime(&tiempo);
    if(f.getAnio() > (1900+hoy->tm_year)){
        cout << "\nEL ANIO DEBE SER MENOR O IGUAL AL ACTUAL" << endl;
        return false;
    }
    else{
        if(f.getMes() > (hoy->tm_mon+1) && f.getAnio() == (1900+hoy->tm_year)){
        cout << "\nEL MES DEBE SER MENOR O IGUAL AL DEL CORRIENTE ANIO" << endl;
        return false;
        }
        else{
            if(f.getDia() > hoy->tm_mday && f.getMes() == (hoy->tm_mon+1) && f.getAnio() == (1900+hoy->tm_year)){
                cout << "\nLA FECHA DEBE SER MENOR O IGUAL A LA ACTUAL" << endl;
                return false;
            }
        }
    }
    return true;
}

#endif // CLASE_FECHA_H_INCLUDED
