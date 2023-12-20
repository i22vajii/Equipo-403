#include"usuario.h"

void Usuario::CargarUsuario(std::string nombrecompleto, int telefono, std::string correo, std::string facultad){
    nombrecompleto_=nombrecompleto;
    telefono_=telefono;
    correo_=correo;
    facultad_=facultad;
}

bool Usuario::PreinscribirUsuario(Actividad a){
    std::fstream fs;
    std::string correousu;
    std::string idact;
    //Comprueba si el usuario ya tiene una solicitud hecha en esa actividad
    fs.open("Solicitudes.txt",std::fstream::in);
    if(fs.fail()==false){
        while(fs.eof()==false){
            getline(fs,idact);
            getline(fs,correousu);
            if(idact==a.GetId() && correousu==correo_){
                std::cout<<"Error al hacer la solicitud, el usuario ya tiene una solicitud hecha"<<std::endl;
                return false;
            }
        }
    }
    fs.close();
    //Comprueba si el usuario ya esta preinscrito en la actividad
    fs.open((a.GetId()+".txt"),std::fstream::in);
    if(fs.fail()==false){
        while(fs.eof()==false){
            getline(fs,correousu);
            if(correousu==correo_){
                std::cout<<"Error al hacer la solicitud, el usuario ya esta preinscrito a esta actividad"<<std::endl;
                return false;
            }
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
    //Recorremos todo el fichero de la activida pasada como parametro
    fs.open(a.GetId()+".txt", std::fstream::in);
    if(fs.fail()==false){
        while(fs.eof()==false){
            getline(fs,aux);
            //Añadimos todos los correos a un vector menos el del usuario que queremos eliminar
            if(aux!=correo_){
                vusu.push_back(aux);
            }
            //Eliminamos al ususario
            else{
                borrar=true;
                std::cout<<"Usuario borrado de la actividad"<<std::endl;
            }
        }
        fs.close();
        //Escribimos al resto de usuarios en el fichero de la actividad
        fs.open(a.GetId()+".txt", std::fstream::out);
        for(int i=0; vusu.size()>i; i++){
            fs<<vusu[i]<<std::endl;
        }
    }
    fs.close();
    //Si el usuario no esta en la actividad
    if(borrar!=true){
        std::cout<<"El usuario no se ha encontrado en la actividad"<<std::endl;
        return false;
    }
    return true;
}

void Usuario::VerInscripciones(std::vector<Actividad>vectact, std::string correo){
    std::string aux;
    int cont, auxint=0;
    //Recorremos todas las actividades
    for (int i=0;vectact.size()>i;i++){
        cont=0;
        std::ifstream fs(vectact[i].GetId()+".txt");
        if(fs.fail()==false){
            //Comprobamos que esta en el fichro de la actividad
            while(fs.eof()==false){
                getline(fs,aux);
                //Comprobamos si el usuario esta inscrito y lo escribimos por pantalla
                if(aux==correo && cont<vectact[i].GetAforo()){
                    auxint++;
                    std::cout<<"Inscrito en la actividad: "<<vectact[i].GetNombre()<<std::endl;
                }
                //Comprobamos si el ususario esta en la lista de espera y lo escribimos por pantalla
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

void RegistrarUsuario(std::vector<std::string> vfac){
    std::fstream fs;
    std::string usuario, contraseña, nombre, correo, aux;
    int telefono, opc;
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
    std::cout<<"Seleccione la facultad a la que pertenece:"<<std::endl;
    for(int i=0; vfac.size()>i; i++){
        std::cout<<i<<". "<<vfac[i]<<std::endl;
    }
    do{
        std::cin>>opc;
        if(opc<0 || opc>=vfac.size()){
            std::cout<<"El valor introducido no es un valor valido, vuelva a introducirlo"<<std::endl;
        }
    }while(opc<0 || opc>=vfac.size());
    //Introducimos los datos del usuario en el fichero sesion.txt
    fs.open("sesion.txt",std::fstream::app);
    fs<<usuario<<std::endl;
    fs<<contraseña<<std::endl;
    fs<<"2"<<std::endl;
    fs<<nombre<<std::endl;
    fs<<telefono<<std::endl;
    fs<<correo<<std::endl;
    fs<<vfac[opc]<<std::endl;
    fs.close();
    system("clear");
    std::cout<<"Usuario registrado"<<std::endl;
}