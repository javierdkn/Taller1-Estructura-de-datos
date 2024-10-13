#include "MaterialBibliografico.h"


MaterialBibliografico::MaterialBibliografico(string nombre ,string isbn, string autor){
     this-> nombre = nombre;
     this-> isbn = isbn;
     this-> autor = autor;
     this-> prestado = false;

}

string MaterialBibliografico::getNombre() {
    return this-> nombre;
}
string MaterialBibliografico::getIsbn() {
    return this-> isbn;
}
string MaterialBibliografico::getAutor() {
    return this-> autor;
}
bool MaterialBibliografico::getPrestado() {
    return this-> prestado;
}

void MaterialBibliografico::setPrestado(bool estado) {
    prestado = estado;
}

MaterialBibliografico::~MaterialBibliografico(){}


void MaterialBibliografico::mostrarInformacion(){
    cout << "nombre: " << nombre << endl;
    cout << "isbn: " << isbn << endl;
    cout << "prestado: " << (prestado ? "Sí" : "No") << endl;

}