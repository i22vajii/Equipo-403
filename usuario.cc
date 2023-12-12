#include"usuario.h"

Usuario::Usuario(std::string nombrecompleto, int telefono, std::string correo){
    nombrecompleto_=nombrecompleto;
    telefono_=telefono;
    correo_=correo;
}

bool Usuario::PreinscribirUsuario(Actividad a){
    std::fstream fs;
    std::string nomusu;
    std::string idact;
    //Comprueba si el usuario ya tiene una solicitud hecha en esa actividad
    fs.open("Solicitudes.txt",std::fstream::in);
        while(fs.eof()==false){
            fs>>idact;
            fs>>nomusu;
            if(idact==a.GetId() && nomusu==nombrecompleto_){
                std::cout<<"Error al hacer la solicitud, el usuario ya tiene una solicitud hecha"<<std::endl;
                return false;
            }
        }
    fs.close();
    //Comprueba si el usuario ya esta preinscrito en la actividad
    fs.open((a.GetId()+".txt"),std::fstream::in);
        while(fs.eof()==false){
            fs>>nomusu;
            if(nomusu==nombrecompleto_){
                std::cout<<"Error al hacer la solicitud, el usuario ya esta preinscrito a esta actividad"<<std::endl;
                return false;
            }
        }
    fs.close();
    //Hace la solicitud a la preinscripcion
    fs.open("Solicitudes.txt",std::fstream::app);
    fs<<a.GetId()<<std::endl<<nombrecompleto_<<std::endl;
    fs.close();
    return true;
}