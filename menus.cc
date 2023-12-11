#include"menus.h"
#include<iostream>

void menu_roles(){
    int rol=0;
    do{
    std::cout<<"Elija un rol:"<<std:: endl;
    std::cout<<"1. Visitante"<<std:: endl;
    std::cout<<"2. Usuario"<<std:: endl;
    std::cout<<"3. Director"<<std:: endl;
    std::cout<<"4. Organizador"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std ::cin>>rol;
    system("clear");
    switch(rol){
        case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
        case 1:
            menu_visitante();
            break;
        case 2:
            menu_usuario();
            break;
        case 3:
            menu_organizador();
            break;
        case 4:
            menu_director();
            break;
        default :
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
    }
    }while(rol!=0);
}

void menu_visitante(){
    int opcvisit=0;
    do{
    std::cout<<"Elija una opcion"<<std:: endl;
    std::cout<<"1. Ver actividades"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std:: cin>>opcvisit;
    system("clear");
    switch(opcvisit){
        case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
        case 1:
            //VerActiviades();
            break;
        default :
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
    }
    }while(opcvisit!=0);

}

void menu_usuario(){
    int opcuser=0;
    do{
    std::cout<<"Elija una opcion"<<std:: endl;
    std::cout<<"1. Ver actividades"<<std:: endl;
    std::cout<<"2. Hacer preisncripcion"<<std:: endl;
    std::cout<<"3. Cancelar preisncripcion"<<std:: endl;
    std::cout<<"4. Pago"<<std:: endl;
    std::cout<<"5. Devolucion de pago"<<std::endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std:: cin>>opcuser;
    system("clear");
    switch(opcuser){
        case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
        case 1:
            //VeraActividades();
            break;
        case 2:
            //PreisncribrirUsuario();
            break;
        case 3:
            //CancelarPreisncripcion();
            break;
        case 4:
            //Pago();
            break;
        case 5:
            //funcion
            break;
        default:
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
    }
    }while(opcuser!=0);

}

void menu_organizador(){
    int opcorganizador=0;
    do{
    std::cout<<"Elija una opcion"<<std:: endl;
    std::cout<<"1. "<<std:: endl;
    std::cout<<"2. f2"<<std:: endl;
    std::cout<<"3. f3"<<std:: endl;
    std::cout<<"4. f4"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std:: cin>>opcorganizador;
    system("clear");
    switch(opcorganizador){
        case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
        case 1:
            //funcion
            break;
        case 2:
            //funcion
            break;
        case 3:
            //funcion
            break;
        case 4:
            //funcion
            break;
        default:
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
    }
    }while(opcorganizador!=0);

}

void menu_director(){
    int opcdirector=0;
    do{
    std::cout<<"Elija una opcion"<<std:: endl;
    std::cout<<"1. Ver actividades"<<std:: endl;
    std::cout<<"2. Hacer preisncripcion"<<std:: endl;//pensar
    std::cout<<"3. Cancelar preisncripcion"<<std:: endl;
    std::cout<<"4. Pago"<<std:: endl;
    std::cout<<"5. Devolucion de pago"<<std::endl;//hasta aqui
    std::cout<<"6. Aprobar preisncripciones"<<std:: endl;
    std::cout<<"7. Actualizar Actividad"<<std:: endl;
    std::cout<<"8. Aprobar pago"<<std:: endl;
    std::cout<<"9. "<<std:: endl;
    std::cout<<"5. "<<std::endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std:: cin>>opcdirector;
    system("clear");
    switch(opcdirector){
        case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
        case 1:
            //funcion
            break;
        case 2:
            //funcion
            break;
        case 3:
            //funcion
            break;
        case 4:
            //funcion
            break;
        default:
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
    }
    }while(opcdirector!=0);

}