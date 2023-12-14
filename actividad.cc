#include "actividad.h"

Actividad::Actividad(std::string id,std::string nombre, std::string descripcion, std::string fecha, float coste, int aforo){
    id_=id;
    nombre_=nombre;
    descripcion_=descripcion;
    fecha_=fecha;
    coste_=coste;
    aforo_=aforo;
}

void VerActividades(std::vector<Actividad> va){
    int aux;
    std::cout<<"Seleccione la actividad de la que quiere ver toda la informacion:"<<std::endl;
    //Muestra por pantalla todas las actividades
    aux=SeleccionarActividad(va);
    system("clear");
    //Muestra toda la informacion de la actividad seleccionada
    std::cout<<"Id: "<<(va[aux].GetId())<<std::endl<<
    "Nombre: "<<(va[aux].GetNombre())<<std::endl<<
    "Descripcion: "<<(va[aux].GetDescripcion())<<std::endl<<
    "Fecha: "<<(va[aux].GetFecha())<<std::endl<<
    "Coste: "<<(va[aux].GetCoste())<<std::endl<<
    "Aforo: "<<(va[aux].GetAforo())<<std::endl;
}

int SeleccionarActividad(std::vector<Actividad> vectact){
    int auxint;
    for(int i=0;vectact.size()>i;i++){
        std::cout<<i<<". "<<(vectact[i].GetNombre())<<std::endl;
    }
    //Selecciona una actividad
    do{
        std::cin>>auxint;
        //Comprueba que la actividad seleccionada es valida
        if(auxint<0 || auxint>=vectact.size()){
            std::cout<<"El numero introducido no es un numero valido, vuelva a introducirlo"<<std::endl;
        }
    }while(auxint<0 || auxint>=vectact.size());
    return auxint;
}