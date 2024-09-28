#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;

class Libro : public MaterialBibliografico {
    private:
        
        string fechaPublicacion;
        string resumen;

    public:

        Libro (string,string,string,string,string);
        string getFechaPublicacion();
        string getResumen();
        void mostrarInformacion() override;
        ~Libro();

};