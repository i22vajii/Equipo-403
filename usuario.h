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
            Usuario(std::string nombrecompleto, int telefono, std::string correo);
            void VerActividades(std::vector<Actividad> va);
            bool PreinscribirUsuario(Actividad a);
    };

#endif