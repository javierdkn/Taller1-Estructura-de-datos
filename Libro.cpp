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
    MaterialBibliografico::mostrarInformacion();  
    cout << "fechaPublicacion: " << fechaPublicacion << endl;
    cout << "resumen: " << resumen << endl;
}

Libro::~Libro() {}