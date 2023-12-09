#include "actividad.h"

Actividad::Actividad(std::string nombre, std::string descripcion, std::string fecha, float coste, int aforo, int aforo_ocupado){
    nombre_=nombre;
    descripcion_=descripcion;
    fecha_=fecha;
    coste_=coste;
    aforo_=aforo;
    aforo_ocupado_=aforo_ocupado;
}