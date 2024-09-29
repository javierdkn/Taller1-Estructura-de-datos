#include "Usuario.h"

Usuario::Usuario(string nombre, int id){

    this -> nombre = nombre;
    this -> id = id;
    for (int i = 0; i < 5; ++i) {
        materialesPrestados[i] = nullptr; 
    }
}


string Usuario::getNombre() {
    return nombre;
}


int Usuario::getId() {
    return id;
}


bool Usuario::prestarMaterial(MaterialBibliografico* material) {
    for (int i = 0; i < 5; ++i) {
        if (materialesPrestados[i] == nullptr) {
            materialesPrestados[i] = material;
            return true;
        }
    }
    return false;  
}


bool Usuario::devolverMaterial(MaterialBibliografico* material) {
    for (int i = 0; i < 5; ++i) {
        if (materialesPrestados[i] == material) {
            materialesPrestados[i] = nullptr;
            return true;
        }
    }
    return false;  
}


void Usuario::mostrarMaterialesPrestados() {
    for (int i = 0; i < 5; ++i) {
        if (materialesPrestados[i] != nullptr) {
            materialesPrestados[i]->mostrarInformacion();  
        }
    }
}


void Usuario::limpiarMaterialesPrestados() {
    for (int i = 0; i < 5; ++i) {
        if (materialesPrestados[i] != nullptr) {
            materialesPrestados[i] = nullptr;  
        }
    }
}


Usuario::~Usuario() {
    limpiarMaterialesPrestados();  
}