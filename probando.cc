    #include<fstream>
    #include<string>
    #include<iostream>
    #include<vector>
    #include"actividad.h"
  void verinscripciones(std::vector<Actividad>vectact,std::string nombre){
  std::string aux;
  for (int i=0;vectact.size()>i;i++){
  std::ifstream fs(vectact[i].GetId()+".txt");
  while(fs.eof()==false){
    getline(fs,aux);
    if(aux==nombre){
      std::cout<<vectact[i].GetNombre()<<std::endl;
    }
  }
}
}
    int main(){
   /* std::string usuario1;
    std:: string usuario;
    std::string contraseña1;
    std::string contraseña;
    std::string nombre;
    std::string correo;
    std::string aux1;
    int telefono;
   std::string aux2;
    int rol;
    //inicio de sesion
    std::cout<<"usuario: "<<std::endl;
    std::cin>>usuario1;
    std::cout<<"contraseña: "<<std::endl;
    std::cin>>contraseña1;
    std::ifstream archivo("sesion.txt");
    while(archivo.eof()==false){
        getline(archivo,usuario);
        getline(archivo,contraseña);
        getline(archivo,aux1);
        getline(archivo,nombre);
        getline(archivo,aux2);
        getline(archivo,correo);
        
        if(usuario1==usuario && contraseña1==contraseña){
          std::cout<<nombre<<std::endl; 
          std::cout<<aux2<<std::endl; 
          std::cout<<correo<<std::endl; 
          std::cout<<aux1<<std::endl;
          rol=stoi(aux1);
          std::cout<<rol<<std::endl;  
        }
    }

*/
//probar ver iscrito
std::vector<Actividad>vectac;
std::string nombre;
verinscripciones(vectac,nombre);

    }
    























    

    }
    