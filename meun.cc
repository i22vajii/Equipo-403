#include<iostream>
#include<fstream>
#include"actividad.h"
#include"usuario.h"
#include"director.h"
#include"organizador.h"

int main(){
    //variables
    //inicio de sesion:
    std::string usuario1;
    std:: string usuario;
    std::string contraseña1;
    std::string contraseña;
    std::string nombre1;
    std::string correo;
    std::string aux1;
    int telefono;
    std::string aux2;
    int rol;
    std::ifstream fichero("sesion.txt");
    //
    int opc=0;
    int opcexterior=0;
   /* std::fstream fs;//inicio volcado
    std::vector<Actividad> vectact;
       std::string id;
       std::string descricion;
       std::string fecha;
       std::string nombre;
       std::string aux;
       float coste;
       int aforo;
    std::ifstream archivo("Actividades.txt");// vocado de fichero a vector
    while(archivo.eof()==false){
        getline(archivo,id);
        getline(archivo,nombre);
        getline(archivo,descricion);
        getline(archivo,fecha);
        getline(archivo,aux);
        coste=stof(aux);
        getline(archivo,aux);
        aforo=stoi(aux);
        Actividad aux(id,nombre,descricion,fecha,coste,aforo);
        vectact.push_back(aux);
    }*/
    
    do{
        std::cout<<"Elija una opcion:"<<std:: endl;
        std::cout<<"1. Ver actividades"<<std:: endl;
        std::cout<<"2. Iniciar sesion"<<std:: endl;
        std::cout<<"0. Salir"<<std:: endl;
        std::cin>>opcexterior;
        system("clear");
        switch(opcexterior){
            case 0:
            std::cout<<"Saliendo del programa"<<std::endl;
            case 1:
             // ver acticividades
                break;
            case 2: 
                    //inicio de sesion
                    std::cout<<"usuario: "<<std::endl;
                    std::cin>>usuario1;
                    std::cout<<"contraseña: "<<std::endl;
                    std::cin>>contraseña1;
                    while(fichero.eof()==false){
                        getline(fichero,usuario);
                        getline(fichero,contraseña);
                        getline(fichero,aux1);
                        getline(fichero,nombre1);
                        getline(fichero,aux2);
                        getline(fichero,correo);
                        
                        if(usuario1==usuario && contraseña1==contraseña){
                        std::cout<<nombre1<<std::endl; 
                        std::cout<<aux2<<std::endl; 
                        std::cout<<correo<<std::endl; 
                        std::cout<<aux1<<std::endl;
                        rol=stoi(aux1);  
                        }
                    }
                    system("clear");
                    /*
                    std::cout<<rol<<std::endl;*/
                    switch(rol){
                        case 2://usuario
                            //Usuario u(nombre,telefono,correo);
                            do{
                                std::cout<<"Elija una opcion"<<std:: endl;
                                std::cout<<"1. Ver actividades"<<std:: endl;
                                std::cout<<"2. Hacer preisncripcion"<<std:: endl;
                                std::cout<<"3. Cancelar preisncripcion"<<std:: endl;
                                std::cout<<"4. Pago"<<std:: endl;
                                std::cout<<"5. Devolucion de pago"<<std::endl;
                                std::cout<<"0. Salir:"<<std:: endl;
                                std:: cin>>opc;
                                system("clear");
                                switch(opc){
                                    case 0:
                                        std::cout<<"Saliendo del programa"<<std::endl;
                                        break;
                                    case 1:
                                        //VeraActividades();
                                        break;
                                    case 2:
                                        //PreisncribrirUsuario();
                                        break;
                                    case 3:
                                        //CancelarPreisncripcion();
                                        break;
                                    case 4:
                                        //Pago();
                                        break;
                                    case 5:
                                        //funcion
                                        break;
                                    default:
                                        std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
                                        break;
                                }
                                }while(opc!=0);
                                    break;
                            break;
                        case 3://director
                            //Director d(nombre,telefono,correo);
                            do{
                                std::cout<<"Elija una opcion"<<std:: endl;
                                std::cout<<"1. "<<std:: endl;
                                std::cout<<"2. f2"<<std:: endl;
                                std::cout<<"3. f3"<<std:: endl;
                                std::cout<<"4. f4"<<std:: endl;
                                std::cout<<"0. Salir:"<<std:: endl;
                                std:: cin>>opc;
                                system("clear");
                                switch(opc){
                                    case 0:
                                        std::cout<<"Saliendo del programa"<<std::endl;
                                        break;
                                    case 1:
                                        //funcion
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
                            //Organizador o(nombre,telefono,correo);
                            do{
                                std::cout<<"Elija una opcion"<<std:: endl;
                                std::cout<<"1. Ver actividades"<<std:: endl;
                                std::cout<<"2. Hacer preisncripcion"<<std:: endl;//pensar
                                std::cout<<"3. Cancelar preisncripcion"<<std:: endl;
                                std::cout<<"4. Pago"<<std:: endl;
                                std::cout<<"5. Devolucion de pago"<<std::endl;//hasta aqui
                                std::cout<<"6. Aprobar preisncripciones"<<std:: endl;
                                std::cout<<"7. Actualizar Actividad"<<std:: endl;
                                std::cout<<"8. Aprobar pago"<<std:: endl;
                                std::cout<<"9. "<<std:: endl;
                                std::cout<<"5. "<<std::endl;
                                std::cout<<"0. Salir:"<<std:: endl;
                                std:: cin>>opc;
                                system("clear");
                                switch(opc){
                                    case 0:
                                        std::cout<<"Saliendo del programa"<<std::endl;
                                        break;
                                    case 1:
                                        //funcion
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
                        default:
                           // opcion coprendia entree 0 y 4
                            break;
                    }
                    break;
                    default:
                    // opcion coprendia entree 0 y 4
                        break;
                        }

                        
    }while(opcexterior!=0);
    //vocado de vector a fichero
    /*fs.open("Actividades.txt",std::fstream::out);
    for (int i=0;vectact.size()>i;i++){
        fs<<(vectact[i].GetId())<<std::endl;
        fs<<(vectact[i].GetNombre())<<std::endl;
        fs<<(vectact[i].GetDescripcion())<<std::endl;
        fs<<(vectact[i].GetFecha())<<std::endl;
        fs<<(vectact[i].GetCoste())<<std::endl;
        fs<<(vectact[i].GetAforo())<<std::endl;
    }
    fs.close();*/
}