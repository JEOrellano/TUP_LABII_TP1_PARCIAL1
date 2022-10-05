#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia;
        int mes;
        int anio;

    public:
        /// CONSTRUCTOR
        Fecha(int d = 1, int m = 1, int a = 1900){
            dia = d;
            mes = m;
            anio = a;
        }

        /// METODOS
        bool Cargar();
        void Mostrar();

        /// SETS
        bool setDia(int d){
            if (d >= 1 && d <= 31){
                dia = d;
                return true;
            }
            return false;
        }
        bool setMes(int m){
            if (m >= 1 && m <= 12){
                mes = m;
                return true;
            }
            return false;
        }
        bool setAnio(int a){
            if (a >= 0){
                anio = a;
                return true;
            }
            return false;
        }

        /// GEST
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        /// DESTRUCTOR
        ~Fecha(){}
};

/////////////////////////////// CARGAR FECHA

bool Fecha::Cargar(){
    cout << "DIA: ";
    cin >> dia;
    if(!setDia(dia)){
        cout << "\nEL DIA DEBE ESTAR ENTRE 1 Y 31" << endl;
        cout << endl;
        return false;
    }
    cout << "MES: ";
    cin >> mes;
    if(!setMes(mes)){
        cout << "\nEL MES DEBE ESTAR ENTRE 1 Y 12" << endl;
        cout << endl;
        return false;
    }
    cout << "ANIO: ";
    cin >> anio;
    if(!setAnio(anio)){
        cout << "\nEL ANIO DEBE SER POSTIVO" << endl;
        cout << endl;
        return false;
    }
    return true;
}

/////////////////////////////// MOSTRAR FECHA

void Fecha::Mostrar(){
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}

/// PROTOTIPO VALIDAR FECHA

bool validarFecha(Fecha f);

/////////////////////////////// DEFINICION VALIDAR FECHA

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

#endif // CLSFECHA_H_INCLUDED
