#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;

class Usuario {
    private:
        string nombre;
        int id; 
        MaterialBibliografico* materialesPrestados[5];  

    public:
        Usuario(string nombre, int id);
        string getNombre();
        int getId();
        bool prestarMaterial(MaterialBibliografico* material);
        bool devolverMaterial(MaterialBibliografico* material);
        void mostrarMaterialesPrestados();
        void limpiarMaterialesPrestados();
        ~Usuario();
};