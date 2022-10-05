#ifndef OPCIONESMENU_H_INCLUDED
#define OPCIONESMENU_H_INCLUDED

/// DECLARACION DE MENUS

void menuPrincipal();

void menuCanciones();

void menuGeneros();

void menuReportes();

void menuConfiguracion();

/// DEFINICIONES DE MENUS

/////////////////////////////////////////////////// MENU CANCIONES

void menuCanciones(){
    int opc, valorAgregarCancion;
    while(true){
        system("cls");
        cout << "\n--------MENU CANCIONES-------" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. AGREGAR CANCION" << endl;
        cout << "2. LISTAR CANCION POR ID" << endl;
        cout << "3. LISTAR TODAS LAS CANCIONES" << endl;
        cout << "4. MODIFICAR FECHA DE ESTRENO" << endl;
        cout << "5. ELIMINAR CANCION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0. VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarCancion = agregarRegistroCancion();
                    if(valorAgregarCancion == 0){
                        cout << "\nCANCION CARGADA" << endl;
                    }
                    else if(valorAgregarCancion == -2){
                        cout << "\nFALLO AL GRABAR EN EL DISCO" << endl;
                    }
                break;
            case 2: if(mostrarCancionPorId() == false){
                        cout << "\nERROR EN LA BUSQUEDA DE LA CANCION" << endl;
                    }
                break;
            case 3: mostrarCancion();
                break;
            case 4: if(modificarFechaEstrenoCancion() == false){
                        cout << "ERROR EN LA MODIFICACION DEL REGISTRO " << endl;
                    }
                    else{
                        cout << "\nREGISTRO MODIFICADO" << endl;
                    }
                break;
            case 5: if(eliminarLogicoCancion() == false){
                        cout << "\nERROR EN EL BORRADO DEL REGISTRO" << endl;
                    }
                    else{
                        cout << "\nREGISTRO BORRADO" << endl;
                    }
                break;
            case 0: return;
                break;
            default: cout << "\nOPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

/////////////////////////////////////////////////////// MENU INTERPRETES

void menuInterpretes(){
    int opc, valorAgregarInterprete;
    while(true){
        system("cls");
        cout << "\n----------MENU INTERPRETES-----------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. AGREGAR INTERPRETE" << endl;
        cout << "2. LISTAR INTERPRETE POR ID" << endl;
        cout << "3. LISTAR TODOS LOS INTERPRETES" << endl;
        cout << "4. MODIFICAR GENERO MUSICAL PRINCIPAL" << endl;
        cout << "5. ELIMINAR INTERPRETE" << endl;
        cout << "-------------------------------------" << endl;
        cout << "0. VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarInterprete = agregarRegistroInterprete();
                    if(valorAgregarInterprete == 0){
                        cout << "\nINTERPRETE CARGADO" << endl;
                    }
                    else if(valorAgregarInterprete == -2){
                        cout << "\nFALLO GRABAR EN DISCO " << endl;
                    }
                break;
            case 2: if(mostrarInterpretePorId() == false){
                        cout << "\nERROR EN LA BUSQUEDA DEL INTERPRETE" << endl;
                    }
                break;
            case 3: mostrarInterprete();
                break;
            case 4: if(modificarGeneroPrincipalInterprete() == false){
                        cout << "\nERROR EN LA MODIFICACION DEL REGISTRO " << endl;
                    }
                    else{
                        cout << "\nREGISTRO MODIFICADO" << endl;
                    }
                break;
            case 5: if(eliminarLogicoInterprete() == false){
                        cout << "\nERROR EN EL BORRADO DEL REGISTRO" << endl;
                    }
                    else{
                        cout << "\nREGISTRO BORRADO" << endl;
                    }
                break;
            case 0: return;
                break;
            default: cout << "\nOPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

/////////////////////////////////////////////////////// MENU GENEROS

void menuGeneros(){
    int opc, valorAgregarGenero;
    while(true){
        system("cls");
        cout << "\n------------MENU GENEROS------------" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. AGREGAR GENERO" << endl;
        cout << "2. LISTAR GENERO POR ID" << endl;
        cout << "3. LISTAR TODOS LOS GENEROS" << endl;
        cout << "4. MODIFICAR TIPO DE INSTRUMENTACION" << endl;
        cout << "------------------------------------" << endl;
        cout << "0. VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: valorAgregarGenero = agregarRegistroGenero();
                    if(valorAgregarGenero == 0){
                        cout << "\nGENERO CARGADO" << endl;
                    }
                    else if(valorAgregarGenero == -2){
                        cout << "\nFALLO GRABAR EN DISCO " << endl;
                    }
                break;
            case 2: if(mostrarGeneroPorId() == false){
                        cout << "\nERROR EN LA BUSQUEDA DEL GENERO" << endl;
                    }
                break;
            case 3: mostrarGenero();
                break;
            case 4: if(modificarTipoInstrumentacionGenero() == false){
                        cout << "\nERROR EN LA MODIFICACION DEL REGISTRO" << endl;
                    }
                    else{
                        cout << "\nREGISTRO MODIFICADO" << endl;
                    }
                break;
            case 0: return;
                break;
            default: cout << "\nOPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

/////////////////////////////////////////////////////// MENU REPORTES

void menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout << "\n-------------MENU REPORTES------------" << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. LISTAR LOS INTERPRETES ARGENTINOS (NN 5)" << endl;
        cout << "2. MOSTRAR CANTIDAD DE GENEROS PRO CADA TIPO DE INTRUMNETACION" << endl;
        cout << "3. CREAR ARCHIVO interpretes2021.dat CON INTERPRETES INICIADOS EN 2021" << endl;
        cout << "--------------------------------------" << endl;
        cout << "0. VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                mostrarInterpretesArgentinos();
                break;
            case 2:
                mostrarCantidadGenerosPorTipoInstrumentacion();
                break;
            case 3:
                agregarRegistroInterprete2021();
                break;
            case 0: return;
                break;
            default: cout << "\nOPCION INCORRECTA" << endl;
                break;
        }
        system("pause");
        cout << endl;
    }
    return;
}

/////////////////////////////////////////////////////// MENU CONFIGIRACION

void menuConfiguracion(){
    int opc;
    while(true){
        system("cls");
        cout << "\n--------------MENU CONFIGURACION----------------" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES" << endl;
        cout << "2. COPIA DE SEGURIDAD DEL ARCHIVO DE INTERPRETES" << endl;
        cout << "3. COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS" << endl;
        cout << "4. RESTAURAR EL ARCHIVO CANCIONES" << endl;
        cout << "5. RESTAURAR EL ARCHIVO INTERPRETES" << endl;
        cout << "6. RESTAURAR EL ARCHIVO GENEROS" << endl;
        cout << "7. ESTABLECER DATOS DE INICIO" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "0. VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONE UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: if(respaldarCanciones()){
                        cout << "\nCANCIONES RESPALDADAS EXITOSAMENTE" << endl;
                    }
                    else{
                        cout << "\nFALLO CRAR RESPALDO DE ARCHIVO" << endl;
                    }
                break;
            case 2: if(respaldarInterpretes()){
                        cout << "\nINTERPRETES RESPALDADOS EXITOSAMENTE" << endl;
                    }
                    else{
                        cout << "\nFALLO CRAR RESPALDO DE ARCHIVO" << endl;
                    }
                break;
            case 3: if(respaldarGeneros()){
                        cout << "\nGENEROS RESPALDADOS EXITOSAMENTE" << endl;
                    }
                    else{
                        cout << "\nFALLO CRAR RESPALDO DE ARCHIVO" << endl;
                    }
                break;
            case 4: if(recuperarCanciones()){
                        cout << "\nCANCIONES RECUPERADAS EXITOSAMENTE" << endl;
                    }
                    else{
                        cout << "\nFALLO RECUPERACION DEL ARCHIVO" << endl;
                    }
                break;
            case 5: if(recuperarInterpretes()){
                        cout << "\nINTERPRETES RECUPERADAOS EXITOSAMENTE" << endl;
                    }
                    else{
                        cout << "\nFALLO RECUPERACION DEL ARCHIVO" << endl;
                    }
                break;
            case 6: if(recuperarGeneros()){
                        cout << "\nGENERO RECUPERADOS EXITOSAMENTE" << endl;
                    }
                    else{
                        cout << "\nFALLO RECUPERACION DEL ARCHIVO" << endl;
                    }
                break;
            case 7: cargarDatosInicio();
                break;
            case 0: return;
                break;
            default: cout << "\nOPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
    return;
}

/////////////////////////////////////////////////////// MENU PRINCIPAL

void menuPrincipal(){
    system("cls");
    cout << "\n---MENU PRINCIPAL----" << endl;
    cout << "---------------------" << endl;
    cout << "1. MENU CANCIONES" << endl;
    cout << "2. MENU INTERPRETES" << endl;
    cout << "3. MENU GENEROS" << endl;
    cout << "4. MENU REPORTES" << endl;
    cout << "5. MENU CONFIGURACION" << endl;
    cout << "---------------------" << endl;
    cout << "0. FIN DEL PROGRAMA" << endl;
    cout << "\nSELECCIONE UNA DE LAS OPCIONES: ";
}

#endif // OPCIONESMENU_H_INCLUDED
