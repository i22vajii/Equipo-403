#include"director.h"
void Director::CargarDirector(std::string nombrecompleto, int telefono, std::string correo){
    nombrecompleto_=nombrecompleto;
    telefono_=telefono;
    correo_=correo;
}

void Director::AprobarInscripcion(){
    std::fstream fs;
    std::vector<std::string> vusu;
    std::vector<std::string> vact;
    std::string aux;
    int n;
    //Copia toda la informacion del fichero Solicitudes.txt en los vectores vact y vusu
    fs.open("Solicitudes.txt",std::fstream::in);
    while(fs.eof()==false){
        getline(fs,aux);
        //Comprobamos que no es el ultimo std::endl
        if(aux!=""){
        vact.push_back(aux);
        }
        getline(fs,aux);
        //Comprobamos que no es el ultimo std::endl
        if(aux!=""){
        vusu.push_back(aux);
        }
    }
    fs.close();
    //Muestra por pantalla las solicitudes
    if(vact.empty()==false && vusu.empty()==false){
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
        system("clear");
        std::cout<<"Solicitud aprobada"<<std::endl;
    }
    else{
        std::cout<<"No hay ninguna solicitud"<<std::endl;
    }
}

Actividad Director::ActualizarActividad(Actividad a){
    std::string aux;
    float coste;
    int opc;
    bool valido=true;
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
        getchar();
        std::getline(std::cin,aux);
        a.SetNombre(aux);
    }
    //Modificamos la descripcion
    std::cout<<"Introduzca 0 si quiere modificar la descripcion, introduzca cualquier otro valor para NO modificarlo"<<std::endl;
    std::cin>>opc;
    if(opc==0){
        std::cout<<"Introduzca la nueva descripcion de la actividad"<<std::endl;
        getchar();
        std::getline(std::cin,aux);
        a.SetDescripcion(aux);
    }
    //Modificamos la fecha
    std::cout<<"Introduzca 0 si quiere modificar la fecha, introduzca cualquier otro valor para NO modificarlo"<<std::endl;
    getchar();
    std::cin>>opc;
    if(opc==0){
        do{
            std::cout<<"Introduzca la fecha de la actividad (dd/mm/aaaa)"<<std::endl;
            std::cin>>aux;
            if(aux.size()!=10){
                valido=false;
                std::cout<<"La fecha introducida no tiene el formato correcto"<<std::endl;
            }
            else{
                valido= FormatoFecha(aux);
                if(valido==true){
                    valido=ComprobarFecha(aux);
                    if(valido==false){
                        std::cout<<"La fecha introducida no es mayor o igual a la actual"<<std::endl;
                    }
                }
            }
        }while(valido==false);
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

bool Director::MostrarInscritos(Actividad a){
    std::fstream fs;
    std::string usu;
    int cont=0;
    //Recorremos todo el fichero de la actividad
    fs.open(a.GetId()+".txt",std::fstream::in);
    //Comprobamos si el fichero existe
    if(fs.fail()==false){
        while(fs.eof()==false){
            //Comprobamos si hemos superado el aforo
            if(cont==a.GetAforo()){
                std::cout<<"Los usuarios en lista de espera son:"<<std::endl;
            }
            //Mostramos el correo de los usuarios inscritos o en lista de espera
            getline(fs,usu);
            if(usu!=""){
                if(cont==0){
                    std::cout<<"Los usuarios inscritos son:"<<std::endl;
                }
                std::cout<<usu<<std::endl;
                cont++;
            }
        }
    }
    fs.close();
    if(cont==0){
        std::cout<<"No hay nadie inscrito en esta actividad"<<std::endl;
        return false;
    }
    return true;
}

bool Director::EnviarMail(std::string fac){
    std::fstream fs;
    std::string usuario, contraseña, nombre1, correo, auxrol, telefono,facultad;
    int cont=0;
    //Abrimos el fichero de los usuarios
    fs.open("sesion.txt",std::fstream::in);
    if(fs.fail()==false){
        while(fs.eof()==false){
            getline(fs,usuario);
            if(usuario!=""){
                getline(fs,contraseña);
                getline(fs,auxrol);
                getline(fs,nombre1);
                getline(fs,telefono);
                getline(fs,correo);
                getline(fs,facultad);
                //Enviamos el correo a los usuarios que pertenezcan a la facultad
                if(fac==facultad && stoi(auxrol)<3){
                    if(cont==0){
                        std::cout<<"Email enviados a :"<<std::endl;
                    }
                    cont++;
                    std::cout<<correo<<std::endl;
                }
            }
        }
        //Comprobamos el numero de emails enviados
        std::cout<<cont<<" email enviados."<<std::endl;
    }
    if(cont>0){
        return true;
    }
    else{
        return false;
    }
}