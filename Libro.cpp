#include "Libro.h"

Libro::Libro(string nombre, string isbn, string autor, string fechaPublicacion, string resumen ): MaterialBibliografico(nombre,isbn,autor){
        this-> fechaPublicacion = fechaPublicacion;
        this-> resumen = resumen;

}

string Libro::getFechaPublicacion() {
    return this-> fechaPublicacion;
}
string Libro::getResumen() {
    return this-> resumen;
}

void Libro::mostrarInformacion() {
    cout << "-------------------------------\n";
    cout << "Nombre: " << nombre << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Autor: " << autor << endl;;
    cout << "Prestado: " << (prestado ? "Sí" : "No") << endl;
}

Libro::~Libro() {}