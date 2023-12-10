#ifndef ACTIVIDAD_H
    #define ACTIVIDAD_H
    #include<string>
    #include<vector>
    #include<iostream>

    class Actividad{
        private:
            std::string nombre_;
            std::string descripcion_;
            std::string fecha_;
            float coste_;
            int aforo_;
            int aforo_ocupado_;
        public:
            Actividad(std::string nombre, std::string descripcion, std::string fecha, float coste, int aforo);
            std::string GetNombre(){return nombre_;}
            std::string GetDescripcion(){return descripcion_;}
            std::string GetFecha(){return fecha_;}
            float GetCoste(){return coste_;}
            int GetAforo(){return aforo_;}
            int GetAforoOcupado(){return aforo_ocupado_;}
            void SetNombre(std::string nombre){nombre_=nombre;}
            void SetDescripcion(std::string descripcion){descripcion_=descripcion;}
            void SetFecha(std::string fecha){fecha_=fecha;}
            void SetCoste(float coste){coste_=coste;}
            void SetAforo(int aforo){aforo_=aforo;}
            void SetNombre(std::string nombre){nombre_=nombre;}

    };

    void VerActividades(std::vector<Actividad> va);

#endif