#ifndef VIDEO_HPP//Hecho por Estrella Lolbeth y Karen Vasquez en conjunto
#define VIDEO_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Video { //Video es una clase abstracta con métodos virtuales puros calificar y mostrar.Las clases abstractas proporcionan una interfaz común para las clases derivadas y aseguran que estas implementen los métodos esenciales definidos en la clase base.
protected: //protected se utiliza para permitir que las clases derivadas accedan a los miembros de Video.
    string id;
    string nombre;
    string duracion;
    string genero;
    float calificacion;

public: //public se utiliza para los métodos accesibles desde fuera de la clase.El uso correcto de modificadores de acceso garantiza la encapsulación y control de acceso a los datos, permitiendo que solo los métodos necesarios sean visibles públicamente.
    Video(string id, string nombre, string duracion, string genero, float calificacion);
    virtual ~Video() = default; // Destructor virtual
    virtual void calificar(float nuevaCalificacion) = 0; // Método abstracto
    virtual void mostrar() const = 0; // Método abstracto
    virtual float getCalificacion() const;
    virtual string getGenero() const;
    virtual string getNombre() const;

    static void leerArchivo(vector<Video*>& videos);
    static void mostrarPeliculasPorCalificacion(const vector<Video*>& videos, float calificacionMinima);
    static void mostrarVideosPorCalificacion(const vector<Video*>& videos, float calificacionMinima);
    static void mostrarVideosPorGenero(const vector<Video*>& videos, const string& genero);
    static void mostrarEpisodiosPorCalificacion(const vector<Video*>& videos, const string& nombreSerie, float calificacionMinima);
    static void calificarVideo(vector<Video*>& videos, const string& nombre, float nuevaCalificacion);
    static void mostrarPeliculas(const vector<Video*>& videos);
    static void mostrarEpisodios(const vector<Video*>& videos);
    static void mostrarVideos(const vector<Video*>& videos);

    // Sobrecarga de operador
    bool operator<(const Video& other) const { //Sobrecarga del operador < en la clase Video.La sobrecarga de operadores permite comparar objetos de Video directamente, lo cual puede ser útil para ordenar o clasificar videos según su calificación.
        return calificacion < other.calificacion;
    }
};

#endif // VIDEO_HPP
