#ifndef ORGANIZADOR_H
    #define ORGANIZADOR_H
    #include"director.h"
    #include"actividad.h"

    class Organizador:public Director{
        private:
            std::string nombrecompleto_;
            int telefono_;
            std::string correo_;
        public:
            Actividad CrearActividad(std::vector<Actividad> va);
    };

#endif