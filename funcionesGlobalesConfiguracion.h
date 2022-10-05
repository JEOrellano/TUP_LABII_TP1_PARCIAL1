#ifndef FUNCIONESGLOBALESCONFIGURACION_H_INCLUDED
#define FUNCIONESGLOBALESCONFIGURACION_H_INCLUDED

/// POROTIPOS FUNCIONES GLOBALES CONFIGURACION

bool respaldarCanciones(); /// copia de seguridad del archivo Canciones.dat

bool respaldarInterpretes(); /// copia de seguridad del archivo Interpretes.dat

bool respaldarGeneros(); /// copia de seguridad del archivo Generos.dat

bool recuperarCanciones(); /// restablece copia de seguridad del archivo Canciones.dat desde Canciones.bkp

bool recuperarInterpretes(); /// restablece copia de seguridad del archivo Interpretes.dat desde Interpretes.bkp

bool recuperarGeneros(); /// restablece copia de seguridad del archivo Generos.dat desde Generos.bkp

bool cargarDatosInicio(); /// restablece los datos iniciales todos los archivos de archivos Generos.ini, Cnaciones.ini, Interpretes.ini.



/// OPCION 1

bool respaldarCanciones(){
    Cancion tema;
    FILE *p;
    int pos = 0;
    p = fopen(RESPALDOCANCIONES, "wb");
    if(p == NULL){
        return false;
    }
    while(tema.LeerDeDisco(pos++)){
        fwrite(&tema, sizeof tema, 1, p);
    }
    fclose(p);
    return true;
}

/// OPCION 2

bool respaldarInterpretes(){
    Interprete cantor;
    FILE *p;
    int pos = 0;
    p = fopen(RESPALDOINTERPRETES, "wb");
    if(p == NULL){
        return false;
    }
    while(cantor.LeerDeDisco(pos++)){
        fwrite(&cantor, sizeof cantor, 1, p);
    }
    fclose(p);
    return true;
}

/// OPCION 3

bool respaldarGeneros(){
    Genero gen;
    FILE *p;
    int pos = 0;
    p = fopen(RESPALDOGENEROS, "wb");
    if(p == NULL){
        return false;
    }
    while(gen.LeerDeDisco(pos++)){
        fwrite(&gen, sizeof gen, 1, p);
    }
    fclose(p);
    return true;
}

/// OPCION 4

bool recuperarCanciones(){
    Cancion tema;
    FILE *pDat, *pBkp;
    pDat = fopen(CANCIONES, "wb");
    if(pDat == NULL){
        return false;
    }
    pBkp = fopen(RESPALDOCANCIONES, "rb");
    if(pBkp == NULL){
        fclose(pDat);
        return false;
    }
    cout << endl;
    while(fread(&tema, sizeof tema, 1, pBkp) == 1){
            fwrite(&tema, sizeof tema, 1, pDat);
            cout << "CANCION " << tema.getIdCancion() << " " << tema.getNombre() << " " << "RECUPERADA" << endl;
    }
    fclose(pBkp);
    fclose(pDat);
    return true;
}

/// OPCION 5

bool recuperarInterpretes(){
    Interprete cantor;
    FILE *pDat, *pBkp;
    pDat = fopen(INTERPRETES, "wb");
    if(pDat == NULL){
        return false;
    }
    pBkp = fopen(RESPALDOINTERPRETES, "rb");
    if(pBkp == NULL){
        fclose(pDat);
        return false;
    }
    cout << endl;
    while(fread(&cantor, sizeof cantor, 1, pBkp) == 1){
            fwrite(&cantor, sizeof cantor, 1, pDat);
            cout << "INTERPRETE " << cantor.getIdInterprete() << " " <<cantor.getNombre() << " " << "RECUPERADO" << endl;
    }
    fclose(pBkp);
    fclose(pDat);
    return true;
}

/// OPCION 6

bool recuperarGeneros(){
    Genero gen;
    FILE *pDat, *pBkp;
    pDat = fopen(GENEROS, "wb");
    if(pDat == NULL){
        return false;
    }
    pBkp = fopen(RESPALDOGENEROS, "rb");
    if(pBkp == NULL){
        fclose(pDat);
        return false;
    }
    cout << endl;
    while(fread(&gen, sizeof gen, 1, pBkp) == 1){
            fwrite(&gen, sizeof gen, 1, pDat);
            cout << "GENERO " << gen.getIdGenero() << " " << gen.getNombre() << " " << "RECUPERADO" <<endl;
    }
    fclose(pBkp);
    fclose(pDat);
    return true;
}

/// OPCION 7

bool cargarDatosInicio(){
    /// CANCIONES INICIO
    Cancion tema;
    FILE *pDat, *pIni;
    pDat = fopen(CANCIONES, "wb");
    if(pDat == NULL){
        return false;
    }
    pIni = fopen("Canciones.ini", "rb");
    if(pIni == NULL){
        fclose(pDat);
        return false;
    }
    cout << endl;
    while(fread(&tema, sizeof tema, 1, pIni) == 1){
            fwrite(&tema, sizeof tema, 1, pDat);
            cout << "CANCION " << tema.getIdCancion() << " " << tema.getNombre() << " " << "INICIADA" << endl;
    }
    fclose(pIni);
    fclose(pDat);

    /// INTERPRETES INICIO
    Interprete cantor;
    pDat = fopen(INTERPRETES, "wb");
    if(pDat == NULL){
        return false;
    }
    pIni = fopen("Interpretes.ini", "rb");
    if(pIni == NULL){
        fclose(pDat);
        return false;
    }
    cout << endl;
    while(fread(&cantor, sizeof cantor, 1, pIni) == 1){
            fwrite(&cantor, sizeof cantor, 1, pDat);
            cout << "INTERPRETE " << cantor.getIdInterprete() << " " <<cantor.getNombre() << " " << "INICIADO" << endl;
    }
    fclose(pIni);
    fclose(pDat);

    /// GENEROS INICIO
    Genero gen;
    pDat = fopen(GENEROS, "wb");
    if(pDat == NULL){
        return false;
    }
    pIni = fopen("Generos.ini", "rb");
    if(pIni == NULL){
        fclose(pDat);
        return false;
    }
    cout << endl;
    while(fread(&gen, sizeof gen, 1, pIni) == 1){
            fwrite(&gen, sizeof gen, 1, pDat);
            cout << "GENERO " << gen.getIdGenero() << " " << gen.getNombre() << " " << "INICIADO" <<endl;
    }
    fclose(pIni);
    fclose(pDat);
    return true;
}

#endif // FUNCIONESGLOBALESCONFIGURACION_H_INCLUDED
