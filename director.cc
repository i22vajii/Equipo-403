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