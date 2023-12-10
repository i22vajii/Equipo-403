#ifndef ORGANIZADOR_H
    #define ORGANIZADOR_H
    #include"director.h"
    #include"actividad.h"

    class Organizador:public Director{
        private:
        public:
            Actividad CrearActividad();
    };

#endif