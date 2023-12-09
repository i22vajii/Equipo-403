#include"usuario.h"

Usuario::Usuario(std::string nombrecompleto, int telefono, std::string correo){
    nombrecompleto_=nombrecompleto;
    telefono_=telefono;
    correo_=correo;
}

void Usuario::VerActividades(std::vector<Actividad> va){
    int aux;
    std::cout<<"Seleccione la actividad de la que quiere ver toda la informacion:"<<std::endl;
    //Muestra por pantalla todas las actividades
    for(int i=0;va.size()>i;i++){
        std::cout<<i<<". "<<(va[i].GetNombre())<<std::endl;
    }
    //Selecciona una actividad
    do{
        std::cin>>aux;
        //Comprueba que la actividad seleccionada es valida
        if(aux<0 || aux>va.size()){
            std::cout<<"El numero introducido no es un numero valido, vuelva a introducirlo"<<std::endl;
        }
    }while(aux<0 || aux>va.size());
    //Muestra toda la informacion de la actividad seleccionada
    std::cout<<"Nombre:"<<(va[aux].GetNombre())<<std::endl<<
    "Descripcion:"<<(va[aux].GetDescripcion())<<std::endl<<
    "Fecha:"<<(va[aux].GetFecha())<<std::endl<<
    "Coste:"<<(va[aux].GetCoste())<<std::endl<<
    "Aforo:"<<(va[aux].GetAforo())<<std::endl<<
    "Aforo Ocupado:"<<(va[aux].GetAforoOcupado())<<std::endl;
}

bool Usuario::PreinscribirUsuario(Actividad a){
    std::fstream fs;
    std::string nomusu;
    std::string nomact;
    //Comprueba si el usuario ya tiene una solicitud hecha en esa actividad
    fs.open("Solicitudes.txt",std::fstream::in);
        while(fs.eof()==false){
            fs>>nomact;
            fs>>nomusu;
            if(nomact==a.GetNombre() && nomusu==nombrecompleto_){
                std::cout<<"Error al hacer la solicitud, el usuario ya tiene una solicitud hecha"<<std::endl;
                return false;
            }
        }
    fs.close();
    //Comprueba si el usuario ya esta preinscrito en la actividad
    fs.open((a.GetNombre()+".txt"),std::fstream::in);
        while(fs.eof()==false){
            fs>>nomusu;
            if(nomusu==nombrecompleto_){
                std::cout<<"Error al hacer la solicitud, el usuario ya esta preinscrito a esta actividad"<<std::endl;
                return false;
            }
        }
    fs.close();
    //Hace la solicitud a la preinscripcion
    fs.open("Solicitudes.txt",std::fstream::app);
    fs<<a.GetNombre()<<std::endl<<nombrecompleto_<<std::endl;
    fs.close();
    return true;
}