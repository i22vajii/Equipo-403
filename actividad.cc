#include "actividad.h"

Actividad::Actividad(std::string nombre, std::string descripcion, std::string fecha, float coste, int aforo){
    nombre_=nombre;
    descripcion_=descripcion;
    fecha_=fecha;
    coste_=coste;
    aforo_=aforo;
    aforo_ocupado_=0;
}

void VerActividades(std::vector<Actividad> va){
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
        if(aux<0 || aux>=va.size()){
            std::cout<<"El numero introducido no es un numero valido, vuelva a introducirlo"<<std::endl;
        }
    }while(aux<0 || aux>=va.size());
    //Muestra toda la informacion de la actividad seleccionada
    std::cout<<"Nombre:"<<(va[aux].GetNombre())<<std::endl<<
    "Descripcion:"<<(va[aux].GetDescripcion())<<std::endl<<
    "Fecha:"<<(va[aux].GetFecha())<<std::endl<<
    "Coste:"<<(va[aux].GetCoste())<<std::endl<<
    "Aforo:"<<(va[aux].GetAforo())<<std::endl<<
    "Aforo Ocupado:"<<(va[aux].GetAforoOcupado())<<std::endl;
}