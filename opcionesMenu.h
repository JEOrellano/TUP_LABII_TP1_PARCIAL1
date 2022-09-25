#ifndef OPCIONESMENU_H_INCLUDED
#define OPCIONESMENU_H_INCLUDED

/// DECLARACION DE MENUS

void menuPrincipal();

void menuCanciones();

void menuGeneros();

//void menuReportes();

//void menuConfiguracion();

/// DEFINICIONES DE MENUS

// MENU CANCIONES
void menuCanciones(){
    int opc, valorAgregarCancion;
    while(true){
        system("cls");
        cout << "MENU CANCIONES" << endl;
        cout << "-----------------------------" << endl;
        cout << "1) AGREGAR CANCION" << endl;
        cout << "2) LISTAR CANCION POR ID" << endl;
        cout << "3) LISTAR TODAS LAS CANCIONES" << endl;
        cout << "4) MODIFICAR FECHA DE ESTRENO" << endl;
        cout << "5) ELIMINAR CANCION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarCancion = agregarRegistroCancion();
                    if(valorAgregarCancion == -2){
                        cout << "FALLO GRABAR EN DISCO " << endl;
                        return;
                    }
                    else{
                        if(valorAgregarCancion == -1){
                            cout << "ERROR DATOS INVALIDOS INGRESADOS O FALLO APERTURA DE ARCHIVO" << endl;
                            return;
                        }
                    }
                    cout << "CANCION CARGADA" << endl;
                break;
            case 2: if(mostrarCancionPorId() == false){
                        cout << "ERROR EN LA BUSQUEDA DE LA CANCION" << endl;
                    }
                    else{
                        cout << "CANCION LISTADA" << endl;
                    }
                break;
            case 3: mostrarCancion();
                break;
            case 4: if(modificarFechaEstrenoCancion() == false){
                        cout << "ERROR EN LA MODIFICACION DEL REGISTRO " << endl;
                    }
                    else{
                        cout << "REGISTRO MODIFICADO" << endl;
                    }
                break;
            case 5: if(eliminarLogicoCancion() == false){
                        cout << "ERROR EN EL BORRADO DEL REGISTRO" << endl;
                    }
                    else{
                        cout << "REGISTRO BORRADO" << endl;
                    }
                break;
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

// MENU INTERPRETES
void menuInterpretes(){
    int opc, valorAgregarInterprete;
    while(true){
        system("cls");
        cout << "MENU INTERPRETES" << endl;
        cout << "-----------------------------" << endl;
        cout << "1) AGREGAR INTERPRETE" << endl;
        cout << "2) LISTAR INTERPRETE POR ID" << endl;
        cout << "3) LISTAR TODOS LOS INTERPRETES" << endl;
        cout << "4) MODIFICAR GENERO MUSICAL PRINCIPAL" << endl;
        cout << "5) ELIMINAR INTERPRETE" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarInterprete = agregarRegistroInterprete();
                    if(valorAgregarInterprete== -2){
                        cout << "FALLO GRABAR EN DISCO " << endl;
                        return;
                    }
                    else{
                        if(valorAgregarInterprete == -1){
                            cout << "ERROR DATOS INVALIDOS INGRESADOS O FALLO APERTURA DE ARCHIVO" << endl;
                            return;
                        }
                    }
                    cout << "INTERPRETE CARGADO" << endl;
                break;
            case 2: if(mostrarInterpretePorId() == false){
                        cout << "ERROR EN LA BUSQUEDA DEL INTERPRETE" << endl;
                    }
                    else{
                        cout << "INTERPRETE LISTADO" << endl;
                    }
                break;
            case 3: mostrarInterprete();
                break;
            case 4: if(modificarGeneroPrincipalInterprete() == false){
                        cout << "ERROR EN LA MODIFICACION DEL REGISTRO " << endl;
                    }
                    else{
                        cout << "REGISTRO MODIFICADO" << endl;
                    }
                break;
            case 5: if(eliminarLogicoInterprete() == false){
                        cout << "ERROR EN EL BORRADO DEL REGISTRO" << endl;
                    }
                    else{
                        cout << "REGISTRO BORRADO" << endl;
                    }
                break;
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

/// MENU GENEROS

void menuGeneros(){
    int opc, valorAgregarGenero;
    while(true){
        system("cls");
        cout << "MENU GENEROS" << endl;
        cout << "-----------------------------" << endl;
        cout << "1) AGREGAR GENERO" << endl;
        cout << "2) LISTAR GENERO POR ID" << endl;
        cout << "3) LISTAR TODOS LOS GENEROS" << endl;
        cout << "4) MODIFICAR TIPO DE INSTRUMENTACION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarGenero = agregarRegistroGenero();
                    if(valorAgregarGenero == -2){
                        cout << "FALLO GRABAR EN DISCO " << endl;
                        return;
                    }
                    else{
                        if(valorAgregarGenero == -1){
                            cout << "DATOS INVALIDOS O FALLO APERTURA DE ARCHIVO" << endl;
                            return;
                        }
                    }
                    cout << "GENERO CARGADO" << endl;
                break;
            case 2: if(mostrarGeneroPorId() == false){
                        cout << "ERROR EN LA BUSQUEDA DEL GENERO" << endl;
                    }
                    else{
                        cout << "GENERO LISTADO" << endl;
                    }
                break;
            case 3: mostrarGenero();
                break;
            case 4: if(modificarTipoInstrumentacionGenero() == false){
                        cout << "ERROR EN LA MODIFICACION DEL REGISTRO " << endl;
                    }
                    else{
                        cout << "REGISTRO MODIFICADO" << endl;
                    }
                break;
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

/// MENU REPORTES

void menuReportes(){
    int opc, valorAgregarReporte;
    while(true){
        system("cls");
        cout << "MENU REPORTES" << endl;
        cout << "-----------------------------" << endl;
        cout << "1) OPCION 1" << endl;
        cout << "2) OPCION 2" << endl;
        cout << "3) OPCION 3" << endl;
        cout << "4) OPCION 4" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: system("pause");
                break;
            case 2: system("pause");
                break;
            case 3: system("pause");
                break;
            case 4: system("pause");
                break;
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

/// MENU CONFIGIRACION

void menuConfiguracion(){
    int opc, valorAgregarConfiguracion;
    while(true){
        system("cls");
        cout << "MENU CONFIGURACION" << endl;
        cout << "-----------------------------" << endl;
        cout << "1) COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES" << endl;
        cout << "2) COPIA DE SEGURIDAD DEL ARCHIVO DE INTERPRETES" << endl;
        cout << "3) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS" << endl;
        cout << "4) RESTAURAR EL ARCHIVO CANCIONES" << endl;
        cout << "5) RESTAURAR EL ARCHIVO INTERPRETES" << endl;
        cout << "6) RESTAURAR EL ARCHIVO GENEROS" << endl;
        cout << "7) ESTABLECER DATOS DE INICIO" << endl;
        cout << "-----------------------------" << endl;
        cout << "0) VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: if(respaldarCanciones()){
                       cout << "CANCIONES RESPALDADAS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "FALLO CRAR RESPALDO DE ARCHIVO" << endl;
                break;
            case 2: if(respaldarInterpretes()){
                       cout << "INTERPRETES RESPALDADOS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "FALLO CRAR RESPALDO DE ARCHIVO" << endl;
                break;
            case 3: if(respaldarGeneros()){
                       cout << "GENEROS RESPALDADOS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "FALLO CRAR RESPALDO DE ARCHIVO" << endl;
                break;
            case 4: if(recuperarCanciones()){
                        cout << "CANCIONES RECUPERADAS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "FALLO RECUPERACION DEL ARCHIVO" << endl;
                break;
            case 5: if(recuperarInterpretes()){
                        cout << "INTERPRETES RECUPERADAOS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "FALLO RECUPERACION DEL ARCHIVO" << endl;
                break;
            case 6: if(recuperarGeneros()){
                        cout << "GENERO RECUPERADOS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "FALLO RECUPERACION DEL ARCHIVO" << endl;
                break;
            case 7: system("pause");
                break;
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

/// MENU PRINCIPAL
void menuPrincipal(){
    system("cls");
    cout << "MENU PRINCIPAL" << endl;
    cout << "---------------------" << endl;
    cout << "1) MENU CANCIONES" << endl;
    cout << "2) MENU INTERPRETES" << endl;
    cout << "3) MENU GENEROS" << endl;
    cout << "4) MENU REPORTES" << endl;
    cout << "5) MENU CONFIGURACION" << endl;
    cout << "---------------------" << endl;
    cout << "0) FIN DEL PROGRAMA" << endl;
    cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
}

#endif // OPCIONESMENU_H_INCLUDED
