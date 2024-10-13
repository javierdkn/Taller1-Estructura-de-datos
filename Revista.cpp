#include "Revista.h"

Revista::Revista(string nombre, string isbn, string autor, int numeroEdicion, string mesPublicacion )
    : MaterialBibliografico(nombre,isbn,autor){
        this-> numeroEdicion = numeroEdicion;
        this-> mesPublicacion = mesPublicacion;

    }

int Revista::getNumeroEdicion() {
    return this-> numeroEdicion;
}
string Revista::getMesPublicacion() {
    return this-> mesPublicacion;
}

void Revista::mostrarInformacion() {
    cout << "-------------------------------\n";
    cout << "Nombre: " << nombre << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Autor: " << autor << endl;;
    cout << "Prestado: " << (prestado ? "Sí" : "No") << endl;

}

Revista::~Revista() {}