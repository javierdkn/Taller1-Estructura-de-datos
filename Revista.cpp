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
    MaterialBibliografico::mostrarInformacion();  
    cout << "EL numero de edicion: " << numeroEdicion << endl;
    cout << "El mes publicacion: " << mesPublicacion << endl;
}

Revista::~Revista() {}