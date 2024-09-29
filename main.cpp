#include <iostream>
#include <vector>
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"




void agregarLibro(MaterialBibliografico* biblioteca[]) {
    string nombre, isbn, autor, fechaPublicacion, resumen;

    
    cout << "Ingrese el nombre del libro: ";
    cin.ignore();  
    getline(cin, nombre);

    cout << "Ingrese el isbn del libro: ";
    getline(cin, isbn);

    cout << "Ingrese la autor del libro: ";
    getline(cin, autor);

    cout << "Ingrese el fecha de publicaion del libro: ";
    getline(cin, fechaPublicacion);

    cout << "Ingrese el resumen  del libro: ";
    getline(cin, resumen);

    
    MaterialBibliografico* nuevoLibro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);

    
    for (int i = 0; i < 100; ++i) {
        if (biblioteca[i] == nullptr) {
            biblioteca[i] = nuevoLibro;  
            cout << "Libro agregado con éxito en la posición " << i << "." << endl;
            return;
        }
    }

    
    cout << "No hay espacio disponible en la biblioteca para agregar más libros." << endl;
}

void agregarRevista(MaterialBibliografico* biblioteca[]) {
    string nombre, isbn, autor, mesPublicacion;
    int numeroEdicion;

    cout << "Ingrese el nombre de la revista: ";
    cin.ignore();  
    getline(cin, nombre);

    cout << "Ingrese el isbn de la revista: ";
    getline(cin, isbn);

    cout << "Ingrese la autor de la revista: ";
    getline(cin, autor);

    cout << "Ingrese el número de edición de la revista: ";
    cin >> numeroEdicion;
    cin.ignore();

    cout << "Ingrese el mes de publicacion de la revista: ";
    getline(cin, mesPublicacion);

    
    MaterialBibliografico* nuevaRevista = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);

    
    for (int i = 0; i < 100; ++i) {
        if (biblioteca[i] == nullptr) {
            biblioteca[i] = nuevaRevista;  
            cout << "Revista agregado con éxito en la posición " << i << "." << endl;
            return;
        }
    }

    
    cout << "No hay espacio disponible en la biblioteca para agregar más revista." << endl;
}

void agregarMaterial(MaterialBibliografico* biblioteca[]){
    int opcion = 0;
    do {
        cout << "    Que tipo de material es:\n" << endl;
        cout << "    1. Libro\n" << endl;
        cout << "    2. Revista\n" << endl;
        cout << "    3. Salir\n" << endl;  
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarLibro(biblioteca);  
                break;
            case 2:
                agregarRevista(biblioteca);
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción incorrecta, por favor ingrese una opción válida" << endl;
                cin.clear();  // Limpia el estado de error
                break;
        }
    } while (opcion != 3);
}

void mostrarMaterial(MaterialBibliografico* biblioteca[]) {
    cout << "Material de la biblioteca:" << endl;

    for (int i = 0; i < 100; ++i) {
        if (biblioteca[i] != nullptr) {
            biblioteca[i]->mostrarInformacion();  
        }
    }
}


MaterialBibliografico* buscarMaterial(string inputTitulo, MaterialBibliografico* biblioteca[]) {
    for (int i = 0; i < 100; ++i) {
        if (biblioteca[i] != nullptr) {  
            if (biblioteca[i]->getNombre() == inputTitulo) {  
                return biblioteca[i];  
            }
        }
    }
    return nullptr;  
}

Usuario* buscarUsuario(int inputId,Usuario* usuarios[]){
    for (int i = 0; i < 50; ++i) {
        if (usuarios[i] != nullptr) {  
            if (usuarios[i]->getId() == inputId) {  
                return usuarios[i];  
            }
        }
    }
    return nullptr;  
}


void prestar(MaterialBibliografico* biblioteca[], Usuario* usuarios[]) {
    string inputTitulo;
    int inputId;

    cout << "Ingrese el nombre del material que desea prestar: ";
    cin.ignore();
    getline(cin, inputTitulo);

    cout << "Ingrese el id del usuario: ";
    cin >> inputId;

    
    MaterialBibliografico* m = buscarMaterial(inputTitulo, biblioteca);
    if (m == nullptr) {
        cout << "El material no fue encontrado en la biblioteca." << endl;
        return;
    }

    
    if (m->getPrestado()) {
        cout << "El material ya está prestado." << endl;
        return;
    }

    
    Usuario* u = buscarUsuario(inputId, usuarios);
    if (u == nullptr) {
        cout << "El usuario no fue encontrado." << endl;
        return;
    }

    
    if (u->prestarMaterial(m)) {
        cout << "Material prestado exitosamente." << endl;
    } else {
        cout << "El usuario ya ha alcanzado el límite de materiales prestados." << endl;
    }
}

void devolver(MaterialBibliografico* biblioteca[], Usuario* usuarios[]) {
    string inputTitulo;
    int inputId;

    cout << "Ingrese el nombre del material que desea devolver: ";
    cin.ignore();
    getline(cin, inputTitulo);

    cout << "Ingrese el id del usuario: ";
    cin >> inputId;

    MaterialBibliografico* m = buscarMaterial(inputTitulo, biblioteca);
    if (m == nullptr) {
        cout << "El material no fue encontrado en la biblioteca." << endl;
        return;
    }

    if (!m->getPrestado()) {
        cout << "El material no está prestado actualmente." << endl;
        return;
    }

    Usuario* u = buscarUsuario(inputId, usuarios);
    if (u == nullptr) {
        cout << "El usuario no fue encontrado." << endl;
        return;
    }

    if (u->devolverMaterial(m)) {
        m->setPrestado(false);  
        cout << "Material devuelto exitosamente." << endl;
    } else {
        cout << "El usuario no tiene este material prestado." << endl;
    }
}

void agregarUsuario(Usuario* usuarios[]) {
    string nombre;
    int id;

    cout << "Ingrese el nombre del usuario: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el ID del usuario: ";
    cin >> id;

    
    for (int i = 0; i < 50; ++i) {
        if (usuarios[i] == nullptr) { 
            usuarios[i] = new Usuario(nombre, id);
            cout << "Usuario agregado con éxito." << endl;
            return;
        }
    }

    cout << "No se pueden agregar más usuarios, el arreglo está lleno." << endl;
}

void eliminarUsuario(Usuario* usuarios[]) {
    int id;
    cout << "Ingrese el ID del usuario a eliminar: ";
    cin >> id;

    Usuario* usuario = buscarUsuario(id, usuarios);
    if (usuario == nullptr) {
        cout << "No se encontró un usuario con el ID proporcionado." << endl;
        return;
    }

    usuario->limpiarMaterialesPrestados();

    for (size_t i = 0; i < 50; ++i) {
        if (usuarios[i] == usuario) {
            delete usuarios[i];
            usuarios[i] = nullptr;
            cout << "Usuario eliminado con éxito." << endl;
            return;
        }
    }
}

void gestionUsuario(Usuario* usuarios[]){
    int opcion = 0;
    do {
        cout<<"    1. Agregar nuevo usuario\n"<<endl;
        cout<<"    2. Eliminar usuario\n"<<endl;
        cout<<"Seleccione una opción: "<<endl;
        cin>>opcion;
        switch(opcion) {
            case 1:
                agregarUsuario(usuarios);        
                break;
            case 2:
                eliminarUsuario(usuarios);
                break;
             default:
                cout<<"Opción incorrecta, por favor ingrese una opción válida"<<"\n"<<endl;
                cin.clear();
                cin.ignore();
        }
    } while(opcion != 6);

}


void menu(MaterialBibliografico* biblioteca[], Usuario* usuarios[]) {
    int opcion = 0;
    do {
        cout << "    1. Agregar Material a la biblioteca\n" << endl;
        cout << "    2. Mostrar información de la biblioteca\n" << endl;
        cout << "    3. Prestar material\n" << endl;
        cout << "    4. Devolver material\n" << endl;
        cout << "    5. Gestión de usuario" << endl;
        cout << "    6. Volver atrás" << endl;
        cout << "Seleccione una opción: " << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarMaterial(biblioteca);
                break;
            case 2:
                mostrarMaterial(biblioteca);
                break;
            case 3:
                prestar(biblioteca, usuarios);
                break;
            case 4:
                devolver(biblioteca, usuarios);
                break;
            case 5:
                gestionUsuario(usuarios);
                break;
            case 6:
                cout << "Volviendo..." << endl;
                break;
            default:
                cout << "Opción incorrecta, por favor ingrese una opción válida" << endl;
                cin.clear();
                cin.ignore();
        }
    } while (opcion != 6);
}


int main() {
    MaterialBibliografico* biblioteca[100];
    Usuario* usuarios[50];
    menu(biblioteca, usuarios);
    return 0;
}