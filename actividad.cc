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
    int dia, diahoy, mes, meshoy, year, yearhoy;
    std::string auxhoy, aux;
    //Introducimos la fecha del ordenador en hoy
    strftime(hoy,11,"%d/%m/%Y",localtime(&tiempo));
    //Guardamos el dia, mes y año de hoy y el introducido en las variables
    for(int i=0;10>i;i++){
        auxhoy.push_back(hoy[i]);
        aux.push_back(fecha[i]);
        if(i==1 || i==4){
            if(i==1){
                dia=stoi(aux);
                diahoy=stoi(auxhoy);
            }
            else{
                mes=stoi(aux);
                meshoy=stoi(auxhoy);
            }
            aux.clear();
            auxhoy.clear();
            i++;
        }
    }
    year=stoi(aux);
    yearhoy=stoi(auxhoy);
    //Comprobamos si el año actual es mayor que el introducido
    if(yearhoy>year){
        return false;
    }
    //Comprobamos si el año actual es menor que el introducido
    else if(year>yearhoy){
        return true;
    }
    else{
        //Comprobamos si el mes actual es mayor que el introducido
        if(meshoy>mes){
            return false;
        }
        //Comprobamos si el mes actual es menor que el introducido
        else if(mes>meshoy){
            return true;
        }
        else{
            //Comprobamos si el año actual es mayor que el introducido
            if(diahoy>dia){
                return false;
            }
            else{
                return true;
            }
        }
    }
}

bool FormatoFecha(std::string fecha){
    int mes, dia, year;
    std::string aux;
    //Guardamos el dia, mes y año en sus variables
    for(int i=0;10>i;i++){
        aux.push_back(fecha[i]);
        if(i==1 || i==4){
            if(i==1){
                dia=stoi(aux);
            }
            else{
                mes=stoi(aux);
            }
            aux.clear();
            i++;
        }
    }
    year=stoi(aux);
    //Comprobamos que el dia sea como minimo 1
    if(dia<1){
        std::cout<<"El dia no puede ser menor que 1"<<std::endl;
        return false;
    }
    else{
        //Comprobamos que el no sea mayor que el dia maximo de cada mes
        switch(mes){
            case 1:
                if(dia>31){
                    std::cout<<"Enero no tiene mas de 31 dias"<<std::endl;
                    return false;
                }
            break;
            case 2:
                if(year%4==0){
                    if(dia>29){
                        std::cout<<"Febrero en año bisiesto no tiene mas de 29 dias"<<std::endl;
                        return false;
                    }
                }
                else{
                    if(dia>28){
                        std::cout<<"Febrero no tiene mas de 28 dias"<<std::endl;
                        return false;
                    }
                }
            break;
            case 3:
                if(dia>31){
                    std::cout<<"Marzo no tiene mas de 31 dias"<<std::endl;
                    return false;
                }
            break;
            case 4:
                if(dia>30){
                    std::cout<<"Abril no tiene mas de 30 dias"<<std::endl;
                    return false;
                }
            break;
            case 5:
                if(dia>31){
                    std::cout<<"Mayo no tiene mas de 31 dias"<<std::endl;
                    return false;
                }
            break;
            case 6:
                if(dia>30){
                    std::cout<<"Junio no tiene mas de 30 dias"<<std::endl;
                    return false;
                }
            break;
            case 7:
                if(dia>31){
                    std::cout<<"Julio no tiene mas de 31 dias"<<std::endl;
                    return false;
                }
            break;
            case 8:
                if(dia>31){
                    std::cout<<"Agosto no tiene mas de 31 dias"<<std::endl;
                    return false;
                }
            break;
            case 9:
                if(dia>30){
                    std::cout<<"Septimebre no tiene mas de 30 dias"<<std::endl;
                    return false;
                }
            break;
            case 10:
                if(dia>31){
                    std::cout<<"Octubre no tiene mas de 31 dias"<<std::endl;
                    return false;
                }
            break;
            case 11:
                if(dia>30){
                    std::cout<<"Noviembre no tiene mas de 30 dias"<<std::endl;
                    return false;
                }
            break;
            case 12:
                if(dia>31){
                    std::cout<<"Diciembre no tiene mas de 31 dias"<<std::endl;
                    return false;
                }
            break;
            default:
                std::cout<<"El mes tiene que ser mayor que 0 y menor que 13"<<std::endl;
                return false;
            break;
        }
    }
    return true;
}