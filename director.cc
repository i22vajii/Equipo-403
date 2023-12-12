#include"director.h"

void Director::AprobarInscripcion(){
    std::fstream fs;
    std::vector<std::string> vusu;
    std::vector<std::string> vact;
    std::string aux;
    int n;
    //Copia toda la informacion del fichero Solicitudes.txt en los vectores vact y vusu
    fs.open("Solicitudes.txt",std::fstream::in);
    while(fs.eof()==false){
        fs>>aux;
        vact.push_back(aux);
        fs>>aux;
        vusu.push_back(aux);
    }
    fs.close();
    //Muestra por pantalla las solicitudes
    std::cout<<"Indica la solicitud que desea aprobar"<<std::endl;
    for(int i=0;vusu.size()>i;i++){
        std::cout<<i<<". El usuario "<<vusu[i]<<" desea hacer una preinscripcion a la actividad con id "<<vact[i]<<std::endl;
    }
    //Seleccion de la solicitud que se desea aprobar
    do{
    std::cin>>n;
        if(n<0 || n>=vusu.size()){
            std::cout<<"El numero introducido no es un numero valido, vuelva a introducirlo"<<std::endl;
        }
    }while(n<0 || n>=vusu.size());
    //Se añade al usuario en el fichero de la actividad
    fs.open((vact[n]+".txt"),std::fstream::app);
    fs<<vusu[n];
    fs.close();
    //Se añade toda la informacion de nuevo al fichero Solicitudes.txt exceptuando la solicitud ya aprobada
    fs.open("Solicitudes.txt",std::fstream::out);
    for(int i=0;vusu.size()>i;i++){
        if(i!=n){
            fs<<vact[i]<<std::endl<<vusu[i]<<std::endl;   
        }
    }
    fs.close();
}

Actividad Director::ActualizarActividad(Actividad a){
    std::string aux;
    float coste;
    int opc;
    //Mostramos la informacion de la actividad que vamos a modificar
    std::cout<<"La actividad seleccionada tiene la siguiente informacion:"<<std::endl<<
    "Id: "<<(a.GetId())<<std::endl<<
    "Nombre: "<<(a.GetNombre())<<std::endl<<
    "Descripcion: "<<(a.GetDescripcion())<<std::endl<<
    "Fecha: "<<(a.GetFecha())<<std::endl<<
    "Coste: "<<(a.GetCoste())<<std::endl<<
    "Aforo: "<<(a.GetAforo())<<std::endl;
    //El id no se modifica
    //Modificamos el nombre
    std::cout<<"Introduzca 0 si quiere modificar el nombre, introduzca cualquier otro valor para NO modificarlo"<<std::endl;
    std::cin>>opc;
    if(opc==0){
        std::cout<<"Introduzca el nuevo nombre de la actividad"<<std::endl;
        std::cin>>aux;
        a.SetNombre(aux);
    }
    //Modificamos la descripcion
    std::cout<<"Introduzca 0 si quiere modificar la descripcion, introduzca cualquier otro valor para NO modificarlo"<<std::endl;
    std::cin>>opc;
    if(opc==0){
        std::cout<<"Introduzca la nueva descripcion de la actividad"<<std::endl;
        std::cin>>aux;
        a.SetDescripcion(aux);
    }
    //Modificamos la fecha
    std::cout<<"Introduzca 0 si quiere modificar la fecha, introduzca cualquier otro valor para NO modificarlo"<<std::endl;
    std::cin>>opc;
    if(opc==0){
        std::cout<<"Introduzca la nueva fecha de la actividad"<<std::endl;
        std::cin>>aux;
        a.SetFecha(aux);
    }
    //Modificamos el coste
    std::cout<<"Introduzca 0 si quiere modificar el coste, introduzca cualquier otro valor para NO modificarlo"<<std::endl;
    std::cin>>opc;
    if(opc==0){
        do{
            std::cout<<"Introduzca el nuevo coste de la actividad"<<std::endl;
            std::cin>>coste;
            if(coste<0){
                std::cout<<"El coste introducido no es valido"<<std::endl;
            }
        }while(coste<0);
        a.SetCoste(coste);
    }
    //Modifcamos el aforo
    std::cout<<"Introduzca 0 si quiere modificar el aforo, introduzca cualquier otro valor para NO modificarlo"<<std::endl;
    std::cin>>opc;
    if(opc==0){
        do{
            std::cout<<"Introduzca el nuevo aforo de la actividad"<<std::endl;
            std::cin>>opc;
            if(opc<0){
                std::cout<<"El aforo introducido no es valido"<<std::endl;
            }
        }while(opc<0);
        a.SetAforo(opc);
    }
    //Mostramos la actividad modificada
    std::cout<<"La actividad modificada tiene la siguiente informacion:"<<std::endl<<
    "Id: "<<(a.GetId())<<std::endl<<
    "Nombre: "<<(a.GetNombre())<<std::endl<<
    "Descripcion: "<<(a.GetDescripcion())<<std::endl<<
    "Fecha: "<<(a.GetFecha())<<std::endl<<
    "Coste: "<<(a.GetCoste())<<std::endl<<
    "Aforo: "<<(a.GetAforo())<<std::endl;
    //Devolvemos la actividad modificada
    return a;
}