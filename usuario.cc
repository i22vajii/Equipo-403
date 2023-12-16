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
            if(correousu==correo_){
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
    bool borrar=false;
    fs.open(a.GetId()+".txt", std::fstream::in);
    if(fs.fail()==false){
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
            fs<<vusu[i]<<std::endl;
        }
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
    int cont, auxint=0;
    for (int i=0;vectact.size()>i;i++){
        cont=0;
        std::ifstream fs(vectact[i].GetId()+".txt");
        if(fs.fail()==false){
            while(fs.eof()==false){
                getline(fs,aux);
                if(aux==correo && cont<vectact[i].GetAforo()){
                    auxint++;
                    std::cout<<"Inscrito en la actividad: "<<vectact[i].GetNombre()<<std::endl;
                }
                if(aux==correo && cont>=vectact[i].GetAforo()){
                    auxint++;
                    std::cout<<"En lista de espera en la actividad: "<<vectact[i].GetNombre()<<std::endl;
                }
                cont++;
            }
        }
    }
    std::cout<<"Estas inscrito a "<<auxint<<" actividades"<<std::endl;
}

void RegistrarUsuario(){
    std::fstream fs;
    std::string usuario, contraseña, nombre, correo, aux;
    int telefono;
    bool valido=true;
    //Pedimos al usuario que introduzca sus datos
    std::cout<<"Introduzca su usuario (sin espacios):"<<std::endl;
    do{
        std::cin>>usuario;
    //Comprobamos que no hay ningun usuario como el introducido
        valido=true;
        fs.open("sesion.txt",std::fstream::in);
        while(fs.eof()==false){
            std::getline(fs,aux);
            if(usuario==aux){
                valido=false;
                std::cout<<"Ya existe ese usuario, introduzca uno nuevo"<<std::endl;
            }
        }
        fs.close();
    }while(valido==false);
    std::cout<<"Introduzca su contraseña:"<<std::endl;
    std::cin>>contraseña;
    std::cout<<"Introduzca su nombre:"<<std::endl;
    getchar();
    std::getline(std::cin,nombre);
    std::cout<<"Introduzca su telefono:"<<std::endl;
    std::cin>>telefono;
    std::cout<<"Introduzca su correo:"<<std::endl;
    do{
    std::cin>>correo;
    //Comprobamos que no hay ningun usuario registrado con el mismo correo
        valido=true;
        fs.open("sesion.txt",std::fstream::in);
        while(fs.eof()==false){
            std::getline(fs,aux);
            if(correo==aux){
                valido=false;
                std::cout<<"Ya existe un usuario con ese correo, introduzca uno nuevo"<<std::endl;
            }
        }
        fs.close();
    }while(valido==false);
    //Introducimos los datos del usuario en el fichero sesion.txt
    fs.open("sesion.txt",std::fstream::app);
    fs<<usuario<<std::endl;
    fs<<contraseña<<std::endl;
    fs<<"2"<<std::endl;
    fs<<nombre<<std::endl;
    fs<<telefono<<std::endl;
    fs<<correo<<std::endl;
    fs.close();
}