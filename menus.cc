#include"menus.h"

void menu_roles(){
    int rol=0;
    do{
    std::cout<<"Elija un rol:"<<std:: endl;
    std::cout<<"1. Visitante"<<std:: endl;
    std::cout<<"2. Usuario"<<std:: endl;
    std::cout<<"3. Director"<<std:: endl;
    std::cout<<"4. Organizador"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    // poner limpiar pantalla
    cin>>rol;
    switch
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
        case : // or default ??
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
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
    cin>>opcvisit;
    // poner limpiar pantalla
    switch
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
        case : // or default ??
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
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
    cin>>opcuser;
    // poner limpiar pantalla
    switch
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
        case : // or default ??
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
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
    cin>>opcorganizador;
    // poner limpiar pantalla
    switch
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
        case : // or default ??
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
    }while(opcorganizador!=0);

}

void menu_visitante(){
    int opcdirector=0;
    do{
    std::cout<<"Elija una opcion"<<std:: endl;
    std::cout<<"1. f1"<<std:: endl;
    std::cout<<"2. f2"<<std:: endl;
    std::cout<<"3. f3"<<std:: endl;
    std::cout<<"4. f4"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    cin>>opcdirector;
    // poner limpiar pantalla
    switch
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
        case : // or default ??
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
    }while(opcdirector!=0);

}