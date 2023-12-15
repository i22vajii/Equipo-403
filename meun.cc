#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"actividad.h"
#include"usuario.h"
#include"director.h"
#include"organizador.h"

int main(){
    system("clear");
    std::fstream fs;
    Usuario u;
    Director d;
    Organizador o;
    std::vector<Actividad> vectact;
        std::string id, descripcion, fecha, nombre, aux;
        float coste;
        int aforo;
    //Variables login:
    std::string usuario1, usuario, contraseña1, contraseña, nombre1, correo, auxrol, telefono;
    //Switch
    int rol, opc, opcexterior;
    //Auxiliares
    int auxint=0;
    //Volcado de fichero a vector
    fs.open("Actividades.txt",std::fstream::in);
    while(fs.eof()==false){
        getline(fs,id);
        getline(fs,nombre);
        getline(fs,descripcion);
        getline(fs,fecha);
        getline(fs,aux);
        coste=stof(aux);
        getline(fs,aux);
        aforo=stoi(aux);
        Actividad aux(id,nombre,descripcion,fecha,coste,aforo);
        //Comprobamos que las actividades aun no se han realizado
        if(ComprobarFecha(fecha)==true){
            vectact.push_back(aux);
        }
    }
    fs.close();
    
    do{
        std::cout<<std::endl<<"Elija una opcion:"<<std:: endl;
        std::cout<<"1. Ver actividades"<<std:: endl;
        std::cout<<"2. Iniciar sesion"<<std:: endl;
        std::cout<<"3. Registrarse"<<std:: endl;
        std::cout<<"0. Salir"<<std:: endl;
        std::cin>>opcexterior;
        system("clear");
        switch(opcexterior){
            case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
                break;
            case 1:
                VerActividades(vectact);
                break;
            case 2: 
                //Inicio de sesion
                auxint=0;
                std::cout<<"Introduzca su usuario: "<<std::endl;
                std::cin>>usuario1;
                std::cout<<"Introduzca su contraseña: "<<std::endl;
                std::cin>>contraseña1;
                fs.open("sesion.txt",std::fstream::in);
                while(fs.eof()==false){
                    getline(fs,usuario);
                    getline(fs,contraseña);
                    getline(fs,auxrol);
                    getline(fs,nombre1);
                    getline(fs,telefono);
                    getline(fs,correo);
                    //Comprobamos si el usuario existe pero la contraseña es incorrecta
                    if(usuario1==usuario && contraseña1!=contraseña){
                        auxint=2;
                    }
                    //Comprobamos si el usuario es correcto y la contraseña tambien
                    if(usuario1==usuario && contraseña1==contraseña){
                        rol=stoi(auxrol);
                        auxint=1;
                        switch(rol){
                            case 2:
                                u.CargarUsuario(nombre1,stoi(telefono),correo);
                                break;
                            case 3:
                                d.CargarDirector(nombre1,stoi(telefono),correo);
                                break;
                            case 4:
                                o.CargarDirector(nombre1,stoi(telefono),correo);
                                break;
                        }
                    }
                }
                fs.close();
                system("clear");
                if(auxint==0){
                    std::cout<<"Usuario no registrado"<<std::endl;
                }
                if(auxint==2){
                    std::cout<<"Contraseña erronea"<<std::endl;
                }
                switch(rol){
                    case 2://Usuario
                        std::cout<<"Accediendo como usuario"<<std::endl;
                        do{
                            std::cout<<std::endl<<"Elija una opcion"<<std::endl;
                            std::cout<<"1. Ver actividades"<<std:: endl;
                            std::cout<<"2. Hacer preinscripcion"<<std:: endl;
                            std::cout<<"3. Cancelar preinscripcion"<<std:: endl;
                            std::cout<<"4. Ver mis preinscripciones"<<std:: endl;
                            std::cout<<"0. Salir"<<std:: endl;
                            std::cin>>opc;
                            system("clear");
                            switch(opc){
                                case 0:
                                    std::cout<<"Cerrando sesion"<<std::endl;
                                    break;
                                case 1:
                                    VerActividades(vectact);
                                    break;
                                case 2:
                                    std::cout<<"Seleccione una actividad:"<<std::endl;
                                    auxint=SeleccionarActividad(vectact);
                                    system("clear");
                                    u.PreinscribirUsuario(vectact[auxint]);
                                    break;
                                case 3:
                                    std::cout<<"Seleccione la actividad de la que desea cancelar la preinscripcion"<<std::endl;
                                    auxint=SeleccionarActividad(vectact);
                                    system("clear");
                                    u.CancelarPreinscripcion(vectact[auxint]);
                                    break;
                                case 4:
                                    u.VerInscripciones(vectact,u.GetCorreo());
                                    break;
                                default:
                                    std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
                                    break;
                            }
                            }while(opc!=0);
                        break;
                    case 3://Director Academico
                        std::cout<<"Accediendo como director academico"<<std::endl;
                        do{
                            std::cout<<std::endl<<"Elija una opcion"<<std:: endl;
                            std::cout<<"1. Ver actividades"<<std:: endl;
                            std::cout<<"2. Aprobar preisncripciones"<<std:: endl;
                            std::cout<<"3. Actualizar Actividad"<<std:: endl;
                            std::cout<<"4. Mostrar Inscritos"<<std:: endl;
                            std::cout<<"0. Salir"<<std:: endl;
                            std::cin>>opc;
                            system("clear");
                            switch(opc){
                                case 0:
                                    std::cout<<"Cerrando sesion"<<std::endl;
                                    break;
                                case 1:
                                    VerActividades(vectact);
                                    break;
                                case 2:
                                    d.AprobarInscripcion();
                                    break;
                                case 3:
                                    std::cout<<"Seleccione la actividad que desea actualizar:"<<std::endl;
                                    auxint=SeleccionarActividad(vectact);
                                    system("clear");
                                    vectact[auxint]=d.ActualizarActividad(vectact[auxint]);
                                    break;
                                case 4:
                                    std::cout<<"Seleccione la actividad de la que quiere ver los usuarios inscritos:"<<std::endl;
                                    auxint=SeleccionarActividad(vectact);
                                    system("clear");
                                    d.MostrarInscritos(vectact[auxint]);
                                    break;
                                default:
                                    std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
                                    break;
                            }
                        }while(opc!=0);
                        break;
                    case 4://Organizador
                        std::cout<<"Accediendo como organizador"<<std::endl;
                        do{
                            std::cout<<std::endl<<"Elija una opcion"<<std:: endl;
                            std::cout<<"1. Ver actividades"<<std:: endl;
                            std::cout<<"2. Aprobar preisncripciones"<<std:: endl;
                            std::cout<<"3. Actualizar Actividad"<<std:: endl;
                            std::cout<<"4. Mostrar Inscritos"<<std:: endl;
                            std::cout<<"5. Crear Actividad"<<std::endl;
                            std::cout<<"0. Salir"<<std:: endl;
                            std:: cin>>opc;
                            system("clear");
                            switch(opc){
                                case 0:
                                    std::cout<<"Cerrando sesion"<<std::endl;
                                    break;
                                case 1:
                                    VerActividades(vectact);
                                    break;
                                case 2:
                                    o.AprobarInscripcion();
                                    break;
                                case 3:
                                    std::cout<<"Seleccione la actividad que desea actualizar:"<<std::endl;
                                    auxint=SeleccionarActividad(vectact);
                                    system("clear");
                                    vectact[auxint]=o.ActualizarActividad(vectact[auxint]);
                                    break;
                                case 4:
                                    std::cout<<"Seleccione la actividad de la que quiere ver los usuarios inscritos:"<<std::endl;
                                    auxint=SeleccionarActividad(vectact);
                                    system("clear");
                                    o.MostrarInscritos(vectact[auxint]);
                                    break;
                                case 5:
                                    vectact.push_back(o.CrearActividad(vectact));
                                    break;
                                default:
                                    std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 5"<<std:: endl;
                                    break;
                            }
                        }while(opc!=0);
                        break;
                }
                break;
        case 3:
            std::cout<<"Introduzca su usuario (sin espacios):"<<std::endl;
            std::cin>>usuario;
            std::cout<<"Introduzca su contraseña:"<<std::endl;
            std::cin>>contraseña;
            std::cout<<"Introduzca su nombre:"<<std::endl;
            getchar();
            std::getline(std::cin,nombre1);
            std::cout<<"Introduzca su telefono:"<<std::endl;
            std::cin>>auxint;
            std::cout<<"Introduzca su correo:"<<std::endl;
            std::cin>>correo;

            fs.open("sesion.txt",std::fstream::app);
            fs<<usuario<<std::endl;
            fs<<contraseña<<std::endl;
            fs<<"2"<<std::endl;
            fs<<nombre1<<std::endl;
            fs<<auxint<<std::endl;
            fs<<correo<<std::endl;
            fs.close();
            
            break;
        default:
            std::cout<<"El valor introducido no es un valor valido"<<std::endl;
            break;
        }                   
    }while(opcexterior!=0);
    //Volcado de vector a fichero
    fs.open("Actividades.txt",std::fstream::out);
    for(int i=0;vectact.size()>i;i++){
        fs<<(vectact[i].GetId())<<std::endl;
        fs<<(vectact[i].GetNombre())<<std::endl;
        fs<<(vectact[i].GetDescripcion())<<std::endl;
        fs<<(vectact[i].GetFecha())<<std::endl;
        fs<<(vectact[i].GetCoste())<<std::endl;
        fs<<(vectact[i].GetAforo());
        //Para que no duplique la ultimna actividad
        if(vectact.size()>(i+1)){
            fs<<std::endl;
        }
    }
    fs.close();
}