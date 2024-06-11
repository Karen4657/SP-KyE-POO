#include "Video.hpp"     //Hecho por Estrella Lolbeth y Karen Vasquez en conjunto
#include "Peliculas.hpp"
#include "Serie.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Video::Video(string id, string nombre, string duracion, string genero, float calificacion) 
    : id(id), nombre(nombre), duracion(duracion), genero(genero), calificacion(calificacion) {}

float Video::getCalificacion() const {
    return calificacion;
}

string Video::getGenero() const {
    return genero;
}

string Video::getNombre() const {
    return nombre;
}

void Video::leerArchivo(vector<Video*>& videos) {
    ifstream file("info.csv");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    string line;
    getline(file, line); // Leer la cabecera

    while (getline(file, line)) {
        stringstream ss(line);
        string id, nombre, duracion, episodiosStr, genero, calificacionStr, temporadasStr, episodios;
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, duracion, ',');
        getline(ss, episodiosStr, ',');
        getline(ss, genero, ',');
        getline(ss, calificacionStr, ',');
        getline(ss, temporadasStr, ',');
        getline(ss, episodios, ',');

        try {
            float calificacion = calificacionStr.empty() ? 0.0f : stof(calificacionStr);
            int episodiosNum = (episodiosStr.empty() || episodiosStr == "null") ? 0 : stoi(episodiosStr);
            int temporadas = (temporadasStr.empty() || temporadasStr == "null") ? 0 : stoi(temporadasStr);

            if (episodiosNum > 0 && temporadas > 0) {
                Serie* serie = new Serie(id, nombre, duracion, genero, calificacion, episodiosNum, temporadas);
                stringstream episodiosStream(episodios);
                string episodio;
                while (getline(episodiosStream, episodio, ';')) {
                    serie->agregarEpisodio(episodio, 1); // Se asigna temporada 1 por defecto
                }
                videos.push_back(serie);
            } else {
                Peliculas* pelicula = new Peliculas(id, nombre, duracion, genero, calificacion);
                videos.push_back(pelicula);
            }
        } catch (const invalid_argument& e) {
            cerr << "Error al convertir los datos: " << e.what() << endl;//Manejo de std::invalid_argument y std::out_of_range al leer y convertir datos del archivo CSV.El manejo de excepciones garantiza que el programa pueda gestionar errores inesperados durante la ejecución, mejorando la robustez y la fiabilidad del código.
        } catch (const out_of_range& e) {
            cerr << "Valor fuera de rango: " << e.what() << endl;
        }
    }

    file.close();
}
void Video::mostrarPeliculasPorCalificacion(const vector<Video*>& videos, float calificacionMinima) {
    for (const auto& video : videos) {
        Peliculas* pelicula = dynamic_cast<Peliculas*>(video);
        if (pelicula && pelicula->getCalificacion() >= calificacionMinima) {
            pelicula->mostrar();
        }
    }
}

void Video::mostrarVideosPorCalificacion(const vector<Video*>& videos, float calificacionMinima) {
    for (const auto& video : videos) {
        if (video->getCalificacion() >= calificacionMinima) {
            video->mostrar();
        }
    }
}

void Video::mostrarVideosPorGenero(const vector<Video*>& videos, const string& genero) {
    for (const auto& video : videos) {
        if (video->getGenero() == genero) {
            video->mostrar();
        }
    }
}

void Video::mostrarEpisodiosPorCalificacion(const vector<Video*>& videos, const string& nombreSerie, float calificacionMinima) {
    for (const auto& video : videos) {
        Serie* serie = dynamic_cast<Serie*>(video);
        if (serie && serie->getNombre() == nombreSerie && serie->getCalificacion() >= calificacionMinima) {
            serie->mostrar();
        }
    }
}

void Video::calificarVideo(vector<Video*>& videos, const string& nombre, float nuevaCalificacion) {
    for (auto& video : videos) {
        if (video->getNombre() == nombre) {
            video->calificar(nuevaCalificacion);
            break;
        }
    }
}

void Video::mostrarPeliculas(const vector<Video*>& videos) {
    for (const auto& video : videos) {
        Peliculas* pelicula = dynamic_cast<Peliculas*>(video); //Uso de dynamic_cast para convertir punteros a Peliculas y Serie desde punteros a Video.El polimorfismo permite tratar a objetos de diferentes clases derivadas como objetos de la clase base Video, facilitando la gestión y manipulación de colecciones de videos de diferentes tipos.
        if (pelicula) {
            pelicula->mostrar();
        }
    }
}

void Video::mostrarEpisodios(const vector<Video*>& videos) {
    for (const auto& video : videos) {
        Serie* serie = dynamic_cast<Serie*>(video);
        if (serie) {
            serie->mostrar();
        }
    }
}

void Video::mostrarVideos(const vector<Video*>& videos) {
    for (const auto& video : videos) {
        video->mostrar();
    }
}
