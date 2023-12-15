#include"organizador.h"

Actividad Organizador::CrearActividad(std::vector<Actividad> va){
    std::string id, nombre, descripcion, fecha;
    float coste;
    int aforo, aux;
    bool valido;
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
            std::cout<<"Ya existe una actividad con ese id"<<std::endl;
        }
    }while(aux>0);
    std::cout<<"Introduzca el nombre de la actividad"<<std::endl;
    getchar();
    std::getline(std::cin,nombre);
    std::cout<<"Introduzca la descripcion de la actividad"<<std::endl;
    getchar();
    std::getline(std::cin,descripcion);
    //Comprobamos que la fecha se valida y que sea mayor o igual a la actual
    do{
        std::cout<<"Introduzca la fecha de la actividad (dd/mm/aaaa)"<<std::endl;
        std::cin>>fecha;
        if(fecha.size()!=10){
            valido=false;
            std::cout<<"La fecha introducida no tiene el formato correcto"<<std::endl;
        }
        else{
            valido= FormatoFecha(fecha);
            if(valido==true){
                valido=ComprobarFecha(fecha);
                if(valido==false){
                    std::cout<<"La fecha introducida no es mayor o igual a la actual"<<std::endl;
                }
            }
        }
    }while(valido==false);
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