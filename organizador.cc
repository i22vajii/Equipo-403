#include"organizador.h"

Actividad Organizador::CrearActividad(){
    std::string id, nombre, descripcion, fecha;
    float coste;
    int aforo;
    std::cout<<"Introduzca el id de la actividad, ten en cuenta que posteriormente no se podra modificar"<<std::endl;
    std::cin>>id;
    std::cout<<"Introduzca el nombre de la actividad"<<std::endl;
    std::cin>>nombre;
    std::cout<<"Introduzca la descripcion de la actividad"<<std::endl;
    std::cin>>descripcion;
    std::cout<<"Introduzca la fecha de la actividad"<<std::endl;
    std::cin>>fecha;
    do{
        std::cout<<"Introduzca el coste de la actividad"<<std::endl;
        std::cin>>coste;
        if(coste<0){
            std::cout<<"El coste introducido no es valido"<<std::endl;
        }
    }while(coste<0);
    do{
        std::cout<<"Introduzca el aforo de la actividad"<<std::endl;
        std::cin>>aforo;
        if(aforo<0){
            std::cout<<"El aforo introducido no es valido"<<std::endl;
        }
    }while(aforo<0);
    Actividad a(id,nombre,descripcion,fecha,coste,aforo);
    return a;
}