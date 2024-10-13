#pragma once
#include <iostream>

using namespace std;

class MaterialBibliografico{
    protected:

        string nombre;
        string isbn;
        string autor;
        bool prestado;
        
    public:
        MaterialBibliografico(string,string,string);
        string getNombre();
        string getIsbn();
        string getAutor();
        bool getPrestado();
        void setPrestado(bool estado);
        ~MaterialBibliografico();
        virtual void mostrarInformacion() = 0;
};