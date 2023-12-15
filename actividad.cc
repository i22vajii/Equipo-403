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

bool ComprobarFecha(std::string fecha){
    time_t tiempo = time(NULL);
    char hoy[11];
    int n, nhoy;
    //Guardamos en hoy la fecha actual
    strftime(hoy,11,"%d/%m/%Y",localtime(&tiempo));
    nhoy= hoy[6]*1000 + hoy[7]*100 + hoy[8]*10 + hoy[9];
    n= fecha[6]*1000 + fecha[7]*100 + fecha[8]*10 + fecha[9];
    //Comprobamos si el año actual es mayor que el introducido
    if(nhoy>n){
        return false;
    }
    //Comprobamos si el año actual es menor que el introducido
    else if(n>nhoy){
        return true;
    }
    //Comprobamos si el año actual es igual que el introducido
    else{
        nhoy= hoy[3]*10 + hoy[4];
        n= fecha[3]*10 + fecha[4];
        //Comprobamos si el mes actual es mayor que el introducido
        if(nhoy>n){
            return false;
        }
        //Comprobamos si el mes actual es menor que el introducido
        else if(n>nhoy){
            return true;
        }
        //Comprobamos si el mes actual es igual que el introducido
        else{
            nhoy= hoy[0]*10 + hoy[1];
            n= fecha[0]*10 + fecha[1];
            //Comprobamos si el dia actual es mayor que el introducido
            if(nhoy>n){
                return false;
            }
            //Comprobamos si el dia actual es igual o menor que el introducido
            else{
                return true;
            }
        }
    }
}