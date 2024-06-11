#include "Peliculas.hpp" //Hecho por Karen Vasquez

Peliculas::Peliculas(string id, string nombre, string duracion, string genero, float calificacion) 
    : Video(id, nombre, duracion, genero, calificacion) {}

void Peliculas::calificar(float nuevaCalificacion) { //calificar y mostrar son métodos virtuales puros en Video, sobrescritos en Peliculas.La sobrescritura permite que Peliculas y Serie implementen sus propias versiones de los métodos definidos en Video, permitiendo comportamientos específicos según el tipo de video.
    calificacion = nuevaCalificacion;
}

void Peliculas::mostrar() const {
    cout << "Pelicula: " << nombre << ", Duracion: " << duracion << ", Genero: " << genero 
         << ", Calificacion: " << calificacion << endl;
}
