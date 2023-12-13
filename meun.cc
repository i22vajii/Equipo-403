#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"actividad.h"
#include"usuario.h"
#include"director.h"
#include"organizador.h"

int main(){
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
    int auxint;
    bool mensaje;
    // vocado de fichero a vector
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
        vectact.push_back(aux);
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
                //inicio de sesion
                std::cout<<"usuario: "<<std::endl;
                std::cin>>usuario1;
                std::cout<<"contraseña: "<<std::endl;
                std::cin>>contraseña1;
                fs.open("sesion.txt",std::fstream::in);
                while(fs.eof()==false){
                    getline(fs,usuario);
                    getline(fs,contraseña);
                    getline(fs,auxrol);
                    getline(fs,nombre1);
                    getline(fs,telefono);
                    getline(fs,correo);
                    if(usuario1==usuario && contraseña1==contraseña){
                        rol=stoi(auxrol);
                        mensaje=true;
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
                if(mensaje!=true){
                    std::cout<<"Usuario no registrado"<<std::endl;
                }
                case 3:
                    //Registrarse
                    break;
                switch(rol){
                    case 2://usuario
                        do{
                            std::cout<<std::endl<<"Elija una opcion"<<std::endl;
                            std::cout<<"1. Ver actividades"<<std:: endl;
                            std::cout<<"2. Hacer preinscripcion"<<std:: endl;
                            std::cout<<"3. Cancelar preinscripcion"<<std:: endl;
                            std::cout<<"4. Ver mis preinscripciones"<<std:: endl;
                            std::cout<<"0. Salir:"<<std:: endl;
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
                                    std::cout<<"Seleccione una actividad:"<<std::endl;
                                    auxint=SeleccionarActividad(vectact);
                                    u.PreinscribirUsuario(vectact[auxint]);
                                    break;
                                case 3:
                                    //CancelarPreisncripcion();
                                    break;
                                case 4:
                                    //Pago();
                                    break;
                                default:
                                    std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
                                    break;
                            }
                            }while(opc!=0);
                                break;
                        break;
                    case 3://director
                        do{
                            std::cout<<std::endl<<"Elija una opcion"<<std:: endl;
                            std::cout<<"1. Ver actividades"<<std:: endl;
                            std::cout<<"2. Aprobar preisncripciones"<<std:: endl;
                            std::cout<<"3. Actualizar Actividad"<<std:: endl;
                            std::cout<<"4. Mostrar Inscritos"<<std:: endl;
                            std::cout<<"0. Salir:"<<std:: endl;
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
                                    //funcion
                                    break;
                                case 3:
                                    //funcion
                                    break;
                                case 4:
                                    //funcion
                                    break;
                                default:
                                    std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
                                    break;
                            }
                        }while(opc!=0);
                        break;
                    case 4://organizador
                        do{
                            std::cout<<std::endl<<"Elija una opcion"<<std:: endl;
                            std::cout<<"1. Ver actividades"<<std:: endl;
                            std::cout<<"2. Aprobar preisncripciones"<<std:: endl;
                            std::cout<<"3. Actualizar Actividad"<<std:: endl;
                            std::cout<<"4. Mostrar Inscritos"<<std:: endl;
                            std::cout<<"5. Crear Actividad"<<std::endl;
                            std::cout<<"0. Salir:"<<std:: endl;
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
                                    //funcion
                                    break;
                                case 3:
                                    //funcion
                                    break;
                                case 4:
                                    //funcion
                                    break;
                                default:
                                    std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
                                    break;
                            }
                        }while(opc!=0);
                        break;
                }
            break;
        default:
            std::cout<<"El valor introducido no es un valor valido"<<std::endl;
            break;
        }                   
    }while(opcexterior!=0);
    //vocado de vector a fichero
    fs.open("Actividades.txt",std::fstream::out);
    for(int i=0;vectact.size()>i;i++){
        fs<<(vectact[i].GetId())<<std::endl;
        fs<<(vectact[i].GetNombre())<<std::endl;
        fs<<(vectact[i].GetDescripcion())<<std::endl;
        fs<<(vectact[i].GetFecha())<<std::endl;
        fs<<(vectact[i].GetCoste())<<std::endl;
        fs<<(vectact[i].GetAforo())<<std::endl;
    }
    fs.close();
}