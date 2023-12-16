#ifndef USUARIO_H
    #define USUARIO_H
    #include"actividad.h"
    #include<string>
    #include<vector>
    #include<iostream>
    #include<fstream>

    class Usuario{
        private:
            std::string nombrecompleto_;
            int telefono_;
            std::string correo_;
        public:
            void CargarUsuario(std::string nombrecompleto, int telefono, std::string correo);
            bool PreinscribirUsuario(Actividad a);
            bool CancelarPreinscripcion(Actividad a);
            void VerInscripciones(std::vector<Actividad>vectact,std::string correo);
            std::string GetCorreo(){return correo_;}
    };
    
    void RegistrarUsuario();

#endif