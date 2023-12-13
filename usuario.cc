#include"usuario.h"

void Usuario::CargarUsuario(std::string nombrecompleto, int telefono, std::string correo){
    nombrecompleto_=nombrecompleto;
    telefono_=telefono;
    correo_=correo;
}

bool Usuario::PreinscribirUsuario(Actividad a){
    std::fstream fs;
    std::string correousu;
    std::string idact;
    //Comprueba si el usuario ya tiene una solicitud hecha en esa actividad
    fs.open("Solicitudes.txt",std::fstream::in);
        while(fs.eof()==false){
            getline(fs,idact);
            getline(fs,correousu);
            if(idact==a.GetId() && correousu==correo_){
                std::cout<<"Error al hacer la solicitud, el usuario ya tiene una solicitud hecha"<<std::endl;
                return false;
            }
        }
    fs.close();
    //Comprueba si el usuario ya esta preinscrito en la actividad
    fs.open((a.GetId()+".txt"),std::fstream::in);
        while(fs.eof()==false){
            getline(fs,correousu);
            if(correousu==nombrecompleto_){
                std::cout<<"Error al hacer la solicitud, el usuario ya esta preinscrito a esta actividad"<<std::endl;
                return false;
            }
        }
    fs.close();
    //Hace la solicitud a la preinscripcion
    fs.open("Solicitudes.txt",std::fstream::app);
    fs<<a.GetId()<<std::endl<<correo_<<std::endl;
    fs.close();
    return true;
}

bool Usuario::CancelarPreinscripcion(Actividad a){
    std::vector<std::string> vusu;
    std::string aux;
    std::fstream fs;
    bool borrar;
    fs.open(a.GetId()+".txt", std::fstream::in);
    while(fs.eof()==false){
        getline(fs,aux);
        if(aux!=correo_){
            vusu.push_back(aux);
        }
        else{
            borrar=true;
            std::cout<<"Usuario borrado de la actividad"<<std::endl;
        }
    }
    fs.close();
    fs.open(a.GetId()+".txt", std::fstream::out);
    for(int i=0; vusu.size()>i; i++){
        fs<<vusu[i];
    }
    fs.close();
    if(borrar!=true){
        std::cout<<"El usuario no se ha encontrado en la actividad"<<std::endl;
        return false;
    }
    return true;
}

void Usuario::VerInscripciones(std::vector<Actividad>vectact, std::string correo){
    std::string aux;
    int cont;
    for (int i=0;vectact.size()>i;i++){
        cont=0;
        std::ifstream fs(vectact[i].GetId()+".txt");
        while(fs.eof()==false){
            getline(fs,aux);
            if(aux==correo && cont<vectact[i].GetAforo()){
                std::cout<<"Inscrito en la actividad: "<<vectact[i].GetNombre()<<std::endl;
            }
            if(aux==correo && cont>=vectact[i].GetAforo()){
                std::cout<<"En lista de espera en la actividad: "<<vectact[i].GetNombre()<<std::endl;
            }
            cont++;
        }
    }
}