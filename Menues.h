#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

///DECLARACIONES DE LOS MENUES

void Menu_Principal();

void Menu_Canciones();

void Menu_Interpretes();

void Menu_Generos();

void Menu_Reportes();

void Menu_Configuracion();

///////////////////////////////////////////////MENU PRINCIPAL

void Menu_Principal(){
    system("cls");
    cout << "\n-------MENU PRINCIPAL-------" << endl;
    cout << "----------------------------" << endl;
    cout << "1. MENU CANCIONES" << endl;
    cout << "2. MENU INTERPRETES" << endl;
    cout << "3. MENU GENEROS" << endl;
    cout << "4. MENU REPORTES" << endl;
    cout << "5. MENU CONFIGURACION" << endl;
    cout << "----------------------------" << endl;
    cout << "0. FIN DEL PROGRAMA" << endl;
    cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
}

///////////////////////////////////////////////MENU CANCIONES

void Menu_Canciones(){
    int opc;
    while(true){
        system("cls");
        cout << "\n----------MENU CANCIONES----------" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. AGREGAR CANCION" << endl;
        cout << "2. LISTAR CANCION POR ID" << endl;
        cout << "3. LISTAR TODAS LAS CANCIONES" << endl;
        cout << "4. MODIFICAR FECHA DE ESTRENO" << endl;
        cout << "5. ELIMINAR CANCION" << endl;
        cout << "----------------------------------" << endl;
        cout << "0. VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                Agregar_Registro_Cancion();
                break;
            case 2:
                Mostrar_Cancion_PorID();
                break;
            case 3:
                Mostrar_Cancion();
                break;
            case 4:
                Modificar_FechaEstreno_Cancion();
                break;
            case 5:
                Eliminar_Logico_Cancion();
                break;
            case 0:
                return;
                break;
            default:
                cout << "\nOPCION INCORRECTA" << endl;
                cout << endl;
                break;
        }
        system("pause");
    }
}

///////////////////////////////////////////////MENU INTERPRETES

void Menu_Interpretes(){
    int opc;
    while(true){
        system("cls");
        cout << "\n-----------MENU INTERPRETES-----------" << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. AGREGAR INTERPRETE" << endl;
        cout << "2. LISTAR INTERPRETE POR ID" << endl;
        cout << "3. LISTAR TODOS LOS INTERPRETES" << endl;
        cout << "4. MODIFICAR GENERO MUSICAL PRINCIPAL" << endl;
        cout << "5. ELIMINAR INTERPRETE" << endl;
        cout << "--------------------------------------" << endl;
        cout << "0. VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                Agregar_Registro_Interprete();
                break;
            case 2:
                Mostrar_Interprete_PorID();
                break;
            case 3:
                Mostrar_Interprete();
                break;
            case 4:
                Modificar_GeneroPrincipal_Interprete();
                break;
            case 5:
                Eliminar_Logico_Interprete();
                break;
            case 0:
                return;
                break;
            default:
                cout << "\nOPCION INCORRECTA" << endl;
                cout << endl;
                system("pause");
                break;
        }
        system("pause");
    }
}

///////////////////////////////////////////////MENU GENEROS

void Menu_Generos(){
    int opc;
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
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                Agregar_Registro_Genero();
                break;
            case 2:
                Mostrar_Genero_PorID();
                break;
            case 3:
                Mostrar_Genero();
                break;
            case 4:
                Modificar_FechaEstreno_Genero();
                break;
            case 0:
                return;
                break;
            default:
                cout << "\nOPCION INCORRECTA" << endl;
                cout << endl;
                break;
        }
        system("pause");
    }
}

///////////////////////////////////////////////MENU REPORTES

void Menu_Reportes(){
    int opc;
    while(true){
        system("cls");
        cout << "\n------------MENU REPORTES-----------" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. OPCION 1" << endl;
        cout << "2. OPCION 2" << endl;
        cout << "3. OPCION 3" << endl;
        cout << "4. OPCION 4" << endl;
        cout << "------------------------------------" << endl;
        cout << "0. VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                return;
                break;
            default:
                cout << "\nOPCION INCORRECTA" << endl;
                cout << endl;
                system("pause");
                break;
        }
    }
}

//////////////////////////////////////MENU CONFIGURACION

void Menu_Configuracion(){
    int opc;
    while(true){
        system("cls");
        cout << "\n----------------MENU CONFIGURACION---------------" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1. COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES" << endl;
        cout << "2. COPIA DE SEGURIDAD DEL ARCHIVO DE INTERPRETES" << endl;
        cout << "3. COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS" << endl;
        cout << "4. RESTAURAR EL ARCHIVO CANCIONES" << endl;
        cout << "5. RESTAURAR EL ARCHIVO INTERPRETES" << endl;
        cout << "6. RESTAURAR EL ARCHIVO GENEROS" << endl;
        cout << "7. ESTABLECER DATOS DE INICIO" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "0. VOLVER MENU PRINCIPAL" << endl;
        cout << "\nSELECCIONES UNA DE LAS OPCIONES: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1: if(respaldarCanciones()){
                        cout << "\nCANCIONES RESPALDADAS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "\nFALLO CRAR RESPALDO DE ARCHIVO" << endl;
                break;
            case 2: if(respaldarInterpretes()){
                        cout << "\nINTERPRETES RESPALDADOS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "\nFALLO CRAR RESPALDO DE ARCHIVO" << endl;
                break;
            case 3: if(respaldarGeneros()){
                        cout << "\nGENEROS RESPALDADOS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "\nFALLO CRAR RESPALDO DE ARCHIVO" << endl;
                break;
            case 4: if(recuperarCanciones()){
                        cout << "\nCANCIONES RECUPERADAS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "\nFALLO RECUPERACION DEL ARCHIVO" << endl;
                break;
            case 5: if(recuperarInterpretes()){
                        cout << "\nINTERPRETES RECUPERADAOS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "\nFALLO RECUPERACION DEL ARCHIVO" << endl;
                break;
            case 6: if(recuperarGeneros()){
                        cout << "\nGENERO RECUPERADOS EXITOSAMENTE" << endl;
                        break;
                    }
                    cout << "\nFALLO RECUPERACION DEL ARCHIVO" << endl;
                break;
            case 7:
                break;
            case 0: return;
                break;
            default: cout << "OPCION INCORRECTA" << endl;
                break;
        }
        cout << endl;
        system("pause");
    }
}

#endif // MENUES_H_INCLUDED
