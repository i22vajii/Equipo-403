#include"organizador.h"
Organizador::Organizador(std::string nombrecompleto, int telefono, std::string correo){
    nombrecompleto_=nombrecompleto;
    telefono_=telefono;
    correo_=correo;
}

Actividad Organizador::CrearActividad(std::vector<Actividad> va){
    std::string id, nombre, descripcion, fecha;
    float coste;
    int aforo, aux;
    do{
        aux=0;
        std::cout<<"Introduzca el id de la actividad, ten en cuenta que posteriormente no se podra modificar"<<std::endl;
        std::cin>>id;
        //Comprobamos que no haya ningun id igual al introducido
        for(int i=0; va.size()>i; i++){
            if(id==va[i].GetId()){
                aux++;
            }
        }
        if(aux>0){
            std::cout<<"Ya existe una actividad que tiene ese id"<<std::endl;
        }
    }while(aux>0);
    std::cout<<"Introduzca el nombre de la actividad"<<std::endl;
    std::cin>>nombre;
    std::cout<<"Introduzca la descripcion de la actividad"<<std::endl;
    std::cin>>descripcion;
    std::cout<<"Introduzca la fecha de la actividad"<<std::endl;
    std::cin>>fecha;
    //Comprobamos que coste>=0
    do{
        std::cout<<"Introduzca el coste de la actividad"<<std::endl;
        std::cin>>coste;
        if(coste<0){
            std::cout<<"El coste introducido no es valido"<<std::endl;
        }
    }while(coste<0);
    //Comprobamos que aforo>=0
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