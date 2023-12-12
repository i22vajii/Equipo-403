#include<iostream>
#include<fstream>
#include"actividad.h"
int main(){
    std::fstream fs;
    std::vector<Actividad> vectact;
       int rol=0;
       int opc=0;
       std::string id;
       std::string descricion;
       std::string fecha;
       std::string nombre;
       std::string aux;
       float coste;
       int aforo;
    std::ifstream archivo("Actividades.txt");
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
    }
    do{//roles
    std::cout<<"Elija un rol:"<<std:: endl;
    std::cout<<"1. Visitante"<<std:: endl;
    std::cout<<"2. Usuario"<<std:: endl;
    std::cout<<"3. Director"<<std:: endl;
    std::cout<<"4. Organizador"<<std:: endl;
    std::cout<<"0. Salir:"<<std:: endl;
    std ::cin>>rol;
    system("clear");
    switch(rol){
        case 0://salir
            std::cout<<"Saliendo del programa"<<std::endl;
            break;
        case 1:// visitante
            do{
                std::cout<<"Elija una opcion"<<std:: endl;
                std::cout<<"1. Ver actividades"<<std:: endl;
                std::cout<<"0. Salir:"<<std:: endl;
                std:: cin>>opc;
                system("clear");
                switch(opc){
                    case 0:
                        std::cout<<"Saliendo del programa"<<std::endl;
                        break;
                    case 1:
                        //VerActiviades();
                        break;
                    default :
                        std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
                        break;
                }
                }while(opc!=0);
;
            break;
        case 2:// usuario
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
        case 3: //director
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
        default :
            std::cout<<"Opcion incorrecta la opcion debe estar comprendida entre 0 y 4"<<std:: endl;
            break;
    }
    }while(rol!=0);
    fs.open("Actividades.txt",std::fstream::out);
    for (int i=0;vectact.size()>i;i++){
        fs<<(vectact[i].GetId())<<std::endl;
        fs<<(vectact[i].GetNombre())<<std::endl;
        fs<<(vectact[i].GetDescripcion())<<std::endl;
        fs<<(vectact[i].GetFecha())<<std::endl;
        fs<<(vectact[i].GetCoste())<<std::endl;
        fs<<(vectact[i].GetAforo())<<std::endl;
    }
    fs.close();
}

void menu_visitante(){
    int opcvisit=0;
    
}

void menu_usuario(){
    int opcuser=0;
    

}

void menu_organizador(){
    int opcorganizador=0;
    

}

void menu_director(){
    int opcdirector=0;

}