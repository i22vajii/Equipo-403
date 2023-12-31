#ifndef DIRECTOR_H
    #define DIRECTOR_H
    #include<string>
    #include<fstream>
    #include<vector>
    #include<iostream>
    #include"actividad.h"
    
    class Director{
        private:
            std::string nombrecompleto_;
            int telefono_;
            std::string correo_;
        public:
            void CargarDirector(std::string nombrecompleto, int telefono, std::string correo);
            void AprobarInscripcion();
            Actividad ActualizarActividad(Actividad a);
            bool MostrarInscritos(Actividad a);
            bool EnviarMail(std::string fac);
    };

#endif