#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;

class Revista : public MaterialBibliografico {
    private:
        
        int numeroEdicion;
        string mesPublicacion;

    public:

        Revista (string,string,string,int,string);
        int getNumeroEdicion();
        string getMesPublicacion();
        void mostrarInformacion() override;
        ~Revista();

};