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
    std::cout<<"1. f1"<<std:: endl;
    std::cout<<"2. f2"<<std:: endl;
    std::cout<<"3. f3"<<std:: endl;
    std::cout<<"4. f4"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std:: cin>>opcvisit;
    system("clear");
    switch(opcvisit){
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
    std::cout<<"1. f1"<<std:: endl;
    std::cout<<"2. f2"<<std:: endl;
    std::cout<<"3. f3"<<std:: endl;
    std::cout<<"4. f4"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std:: cin>>opcuser;
    system("clear");
    switch(opcuser){
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
    }while(opcuser!=0);

}

void menu_organizador(){
    int opcorganizador=0;
    do{
    std::cout<<"Elija una opcion"<<std:: endl;
    std::cout<<"1. f1"<<std:: endl;
    std::cout<<"2. f2"<<std:: endl;
    std::cout<<"3. f3"<<std:: endl;
    std::cout<<"4. f4"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std:: cin>>opcorganizador;
    system("clear");
    switch(opcorganizador){
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
    std::cout<<"1. f1"<<std:: endl;
    std::cout<<"2. f2"<<std:: endl;
    std::cout<<"3. f3"<<std:: endl;
    std::cout<<"4. f4"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std:: cin>>opcdirector;
    system("clear");
    switch(opcdirector){
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