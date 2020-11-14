#include <iostream>
#include <fstream>
#include <algorithm>

#include "Laboratorio.h"

using namespace std;

Laboratorio::Laboratorio(){}

void Laboratorio::agregarComputadora(const Computadora &comp){
    computadoras.push_back(comp);//Copiar en vector, el personaje que estamos mandando
}

void Laboratorio::mostrar(){

    cout << left;
    cout << "\n";
    cout << setw(22)<<"Sistema Operativo";
    cout << setw(15)<<"Memoria RAM";
    cout << setw(18)<<"Nombre";
    cout << setw(15)<<"Precio";
    cout << endl << endl;

    for (size_t i = 0; i < computadoras.size(); i++) {

        Computadora &c = computadoras[i];//Estamos guardando una referencia a lo que hay en las posiciones del arreglo
        cout<<c;//Imprimir el objeto de la forma que esta en el computadora.h

        /*cout<<"SISTEMA OPERATIVO: "<<c.getSistemaOperativo()<<endl;
        cout<<"MEMORIA RAM: "<< c.getMemoriaRAM()<<endl;
        cout<<"NOMBRE DEL EQUIPO: "<<c.getNombreEquipo()<<endl;
        cout<<"PRECIO: "<<c.getPrecio()<<endl;
        */
        cout<<endl;
    }
    
}

void Laboratorio::respaldar_tabla(){
    ofstream archivo ("computadoras_tabla.txt");

    if (archivo.is_open()){//Validar si el archivo pudo ser creado
    
        archivo << left;
        archivo << "\n";
        archivo << setw(22)<<"Sistema Operativo";
        archivo << setw(15)<<"Memoria RAM";
        archivo << setw(18)<<"Nombre";
        archivo << setw(15)<<"Precio";
        archivo << endl << endl;

        for (size_t i = 0; i < computadoras.size(); i++) {
        Computadora &c = computadoras[i];
        archivo<<c;//Imprime cada comptadora del arreglo en el archivo
        }
    }
    archivo.close();
}

void Laboratorio::respaldar(){
    ofstream archivo ("computadoras.txt");

    if (archivo.is_open()){//Validar si el archivo pudo ser creado

        for (size_t i = 0; i < computadoras.size(); i++) {
        Computadora &c = computadoras[i];
        //Imprime cada computadora del arreglo en el archivo
            archivo<<c.getSistemaOperativo()<<endl;
            archivo<<c.getMemoriaRAM()<<endl;
            archivo<<c.getNombreEquipo()<<endl;
            archivo<<c.getPrecio()<<endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar(){
    ifstream archivo("computadoras.txt");//Va a abrir este archivo que es donde tenemos las computadoras linea por linea
    if(archivo.is_open()){
        string tempo;
        float precio;
        Computadora c;

        while(true){
            getline(archivo, tempo);//Para leer el sistema operativo
            if(archivo.eof()){//Verificar si el archivo ya llego al final
                break;
            }
            c.setSistemaOperativo(tempo);//Asignar el sistema operativo
            
            getline(archivo, tempo);//Leer la memoria ram
            c.setMemoriaRAM(tempo);//Establecer la memoria ram
            
            getline(archivo, tempo);//Leer el nombre
            c.setNombreEquipo(tempo);//Establecer el nombre

            getline(archivo, tempo);//Leer el precio
            precio = stof(tempo);//string-to-float // convertir una cadena a flotantes
            c.setPrecio(precio);//Establecer el precio

            agregarComputadora(c);
        }
    }
    archivo.close();
}

void Laboratorio::insertar(const Computadora &c, size_t pos){
    //usar el metodo insert y se va a insertar una computadora 
    //desde la posicion inicial mas la posicion que le mandamos
    computadoras.insert(computadoras.begin()+pos, c);
}

size_t Laboratorio::size(){
    return computadoras.size();//Nos retorna la cantidad de elementos que tiene el vector de computadoras
}

void Laboratorio::inicializar(const Computadora &c, size_t n){
    //Ahora nuestro arreglo de computadoras va a ser un vector de computadoras, repetidas n veces
    computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t pos){
    //Se va a eliminar del arreglo de computadoras la posicion que le mandemos 
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratorio::ordenar(){
    sort(computadoras.begin(), computadoras.end());//Ordenar desde el inicio del vector hasta el final del mismo
}

void Laboratorio::ordenarSO(){//Funcion lamba
    sort(computadoras.begin(), computadoras.end(), 
    [](Computadora c1, Computadora c2){return c1.getSistemaOperativo() < c2.getSistemaOperativo();});
}

void Laboratorio::ordenarPrecio(){//Funcion lamba
    sort(computadoras.begin(), computadoras.end(), 
    [](Computadora c1, Computadora c2){return c1.getPrecio() < c2.getPrecio();});
}

void Laboratorio::ordenarRAM(){//Funcion lamba
    sort(computadoras.begin(), computadoras.end(),
    [](Computadora c1, Computadora c2){return c1.getMemoriaRAM() < c2.getMemoriaRAM();});
}

Computadora* Laboratorio::buscar(const Computadora &c){
    //vector<Computadora>::iterator = auto it
    auto it = find(computadoras.begin(), computadoras.end(), c);//Recorre todo el vector y busca la computadora c

    if (it == computadoras.end()){//Si el iterador esta apuntando al final del vector
        return nullptr;
    }
    else{
        //Accede a la posicion y con & quiero que me regrese la direccion de memororia donde esta esa computadora
        return &(*it);//Vamos a acceder al elemento referenciando a un puntero
    }
}

void Laboratorio::eliminar_ultimo(){
        computadoras.pop_back();
    
}