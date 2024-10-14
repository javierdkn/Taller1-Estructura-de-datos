#include <iostream>
#include <vector>
#include <string>
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"

//función agrega los material en la primera posición disponible de la lista:
void agregarBiblioteca(MaterialBibliografico* biblioteca[], MaterialBibliografico* nuevoMaterial) {
    for (int i = 0; i < 100; ++i) {
        if (biblioteca[i] == nullptr) {  
            biblioteca[i] = nuevoMaterial;
            return;
        }
    }
}

//función agrega los usuario en la primera posición disponible de la lista:
void agregarUsuarios(Usuario* usuarios[], Usuario* nuevoUsuario) {
    for (int i = 0; i < 50; ++i) {
        if (usuarios[i] == nullptr) {  
            usuarios[i] = nuevoUsuario;
            return;
        }
    }
}

// agregar material bibliografico de manera permanente
void cargarMaterialPermanente(MaterialBibliografico* biblioteca[]) {
    MaterialBibliografico* mate1 = new Libro("El Quijote", "978-3-16-148410-0", "Miguel de Cervantes", "1605", "Un hidalgo se vuelve loco por los libros de caballería.");
    MaterialBibliografico* mate2 = new Libro("Cien Años de Soledad", "978-0-06-088328-7", "Gabriel García Márquez", "1967", "Saga de la familia Buendía en Macondo.");
    MaterialBibliografico* mate3 = new Libro("1984", "978-0-452-28423-4", "George Orwell", "1949", "Distopía sobre un régimen totalitario.");
    MaterialBibliografico* mate4 = new Libro("Moby Dick", "978-1-85326-008-7", "Herman Melville", "1851", "Aventura de un capitán buscando una ballena blanca.");
    MaterialBibliografico* mate5 = new Libro("Orgullo y Prejuicio", "978-0-19-953556-9", "Jane Austen", "1813", "Romance y crítica social en la Inglaterra del siglo XIX.");
    MaterialBibliografico* revista1 = new Revista("National Geographic", "978-0-01-234567-8", "Varios Autores", 200, "Octubre");
    MaterialBibliografico* revista2 = new Revista("Science", "978-0-02-345678-9", "AAAS", 3045, "Marzo");
    MaterialBibliografico* revista3 = new Revista("Nature", "978-0-03-456789-0", "Springer Nature", 786, "Abril");
    MaterialBibliografico* revista4 = new Revista("TIME", "978-0-04-567890-1", "Redacción de TIME", 992, "Noviembre");
    MaterialBibliografico* revista5 = new Revista("Forbes", "978-0-05-678901-2", "Redacción de Forbes", 1234, "Julio");

    agregarBiblioteca(biblioteca , mate1);
    agregarBiblioteca(biblioteca , mate2);
    agregarBiblioteca(biblioteca , mate3);
    agregarBiblioteca(biblioteca , mate4);
    agregarBiblioteca(biblioteca , mate5);
    agregarBiblioteca(biblioteca , revista1);
    agregarBiblioteca(biblioteca , revista2);
    agregarBiblioteca(biblioteca , revista3);
    agregarBiblioteca(biblioteca , revista4);
    agregarBiblioteca(biblioteca , revista5);
}

// agregar usuario de manera permanente
void cargarUsuarioPermanente(Usuario* usuarios[]) {

    Usuario* usuario1 = new Usuario("Ana López", 101);
    Usuario* usuario2 = new Usuario("Carlos García", 102);
    Usuario* usuario3 = new Usuario("María Fernández", 103);
    Usuario* usuario4 = new Usuario("Jorge Pérez", 104);
    Usuario* usuario5 = new Usuario("Lucía Rodríguez", 105);

    agregarUsuarios(usuarios , usuario1);
    agregarUsuarios(usuarios , usuario2);
    agregarUsuarios(usuarios , usuario3);
    agregarUsuarios(usuarios , usuario4);
    agregarUsuarios(usuarios , usuario5);

}

// se crea un libro por datos a traves de teclado y se guarda en la lista MaterialBibliografico
void agregarLibro(MaterialBibliografico* biblioteca[]) {
    string nombre, isbn, autor, fechaPublicacion, resumen;

    cout << "--------------------------------------------------\n";
    cout << "Ingrese el nombre del libro: ";
    cin.ignore();  
    getline(cin, nombre);

    cout << "Ingrese el ISBN del libro: ";
    getline(cin, isbn);

    cout << "Ingrese el autor del libro: ";
    getline(cin, autor);

    cout << "Ingrese la fecha de publicacion del libro: ";
    getline(cin, fechaPublicacion);

    cout << "Ingrese el resumen del libro: ";
    getline(cin, resumen);

    MaterialBibliografico* nuevoLibro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);

    for (int i = 0; i < 100; ++i) {
        if (biblioteca[i] == nullptr) {
            biblioteca[i] = nuevoLibro;
            cout << "Libro agregado con exito en la posicion " << i << "." << endl;
            return;
        }
    }

    cout << "No hay espacio disponible en la biblioteca para agregar mas libros." << endl;
}

// se crea un libro por datos a traves de teclado y se guarda en la lista MaterialBibliografico
void agregarRevista(MaterialBibliografico* biblioteca[]) {
    string nombre, isbn, autor, mesPublicacion;
    int numeroEdicion;

    cout << "--------------------------------------------------\n";
    cout << "Ingrese el nombre de la revista: ";
    cin.ignore();  
    getline(cin, nombre);

    cout << "Ingrese el isbn de la revista: ";
    getline(cin, isbn);

    cout << "Ingrese la autor de la revista: ";
    getline(cin, autor);

    cout << "Ingrese el numero de edición de la revista: ";
    cin >> numeroEdicion;
    cin.ignore();

    cout << "Ingrese el mes de publicacion de la revista: ";
    getline(cin, mesPublicacion);

    
    MaterialBibliografico* nuevaRevista = new Revista(nombre, isbn, autor, numeroEdicion, mesPublicacion);

    
    for (int i = 0; i < 100; ++i) {
        if (biblioteca[i] == nullptr) {
            biblioteca[i] = nuevaRevista;
            cout << "Revista agregada con exito en la posicion " << i << "." << endl;
            return;
        }
    }

    cout << "No hay espacio disponible en la biblioteca para agregar mas revistas." << endl;
}

// es una funcion que desplegar un menu donde se selecciona el tipo de material bibliografico (libro,revista).
void agregarMaterial(MaterialBibliografico* biblioteca[]){
    int opcion = 0;
    do {
        cout << "    Que tipo de material es:\n";
        cout << "    1. Libro\n";
        cout << "    2. Revista\n";
        cout << "    3. Salir\n";  
        cout << "Seleccione una opcion: ";
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
                cout << "Opcion incorrecta, por favor ingrese una opcion valida" << endl;
                cin.clear();
                break;
        }
    } while (opcion != 3);
}

// funcion para desplegar una los materiales bibliograficos 
void mostrarMaterial(MaterialBibliografico* biblioteca[]) {
    cout << "Material de la biblioteca:" << endl;

    for (int i = 0; i < 100; ++i) {
        if (biblioteca[i] != nullptr) {
            biblioteca[i]->mostrarInformacion();  
        }
    }
    
}

// funcion que de busca por el titulo el material bibliografico y te retorna un tipo MaterialBibliografico
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

// funcion que de busca por el id al usuario y te retorna un tipo Usuario
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

// funcion para cambiar el estado de prestado a "true" si el usuario y el matrial cumpla con los requisitos
void prestar(MaterialBibliografico* biblioteca[], Usuario* usuarios[]) {
    string inputTitulo;
    int inputId;

    cout << "--------------------------------------------------\n";
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
        cout << "El material ya esta prestado." << endl;
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
        cout << "El usuario ya ha alcanzado el limite de materiales prestados." << endl;
    }
}

// funcion para cambiar el estado de prestado a "false" si el usuario y el matrial cumpla con los requisitos
void devolver(MaterialBibliografico* biblioteca[], Usuario* usuarios[]) {
    string inputTitulo;
    int inputId;

    cout << "--------------------------------------------------\n";
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
        cout << "El material no esta prestado actualmente." << endl;
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

// se crea un usuario por datos a traves de teclado y se guarda en la lista Usuarios
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

// para eliminar el usuario
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

// es una funcion que desplegar un menu donde se selecciona el lo que se desea hace con usuario
void gestionUsuario(Usuario* usuarios[]){
    int opcion = 0;
    do {
        cout << "--------------------------------------------------\n";
        cout<<"    Gestion de usuario: \n";
        cout<<"    1. Agregar nuevo usuario\n";
        cout<<"    2. Eliminar usuario\n";
        cout<<"    3. Salir\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        switch(opcion) {
            case 1:
                agregarUsuario(usuarios);        
                break;
            case 2:
                eliminarUsuario(usuarios);
                break;
            case 3:
            cout << "Saliendo..." << endl;
                break;
            default:
                cout<<"Opcion incorrecta, por favor ingrese una opcion valida"<<"\n"<<endl;
                cin.clear();
                cin.ignore();
        }
    } while(opcion != 3);

}

// funcion para desplegar el menu de opciones
void menu(MaterialBibliografico* biblioteca[], Usuario* usuarios[]) {
    int opcion = 0;
    do {
        cout << "--------------------------------------------------\n";
        cout << "    1. Agregar Material a la biblioteca\n";
        cout << "    2. Mostrar informacion de la biblioteca\n";
        cout << "    3. Prestar material\n";
        cout << "    4. Devolver material\n";
        cout << "    5. Gestion de usuario\n";
        cout << "    6. Salir\n";
        cout << "Seleccione una opcion: ";
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
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion incorrecta, por favor ingrese una opcion valida" << endl;
                cin.clear();
                cin.ignore();
        }
    } while (opcion != 6);
}


int main() {

    MaterialBibliografico* biblioteca[100] = {nullptr};
    Usuario* usuarios[50] = {nullptr};
    cargarMaterialPermanente(biblioteca);
    cargarUsuarioPermanente(usuarios);
    menu(biblioteca, usuarios);
    return 0;
}