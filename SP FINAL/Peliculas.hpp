#ifndef PELICULAS_HPP //Hecho por Karen Vasquez
#define PELICULAS_HPP

#include "Video.hpp"

class Peliculas : public Video {  //Película hereda de video para compartir una interfaz común definida por Video
public:
    Peliculas(string id, string nombre, string duracion, string genero, float calificacion);
    void calificar(float nuevaCalificacion) override;
    void mostrar() const override;
};

#endif // PELICULAS_HPP
