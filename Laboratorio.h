#ifndef LABORATORIO_H
#define LABORATORIO_H

#include <iostream>
#include <vector>

#include "Computadora.h"

using namespace std;

class Laboratorio{

    //Metodos
public:
    //Constructor
    Laboratorio();

    //Comportamientos
    void agregarComputadora(const Computadora &comp);//Va a recibir una computadora como referencia constante
    void mostrar();
    void respaldar_tabla();//IMPRIME LOS ATRIBUTOS EN FORMA DE TABLA
    void respaldar();//IMPRIME LOS ATRIBUTOS LINEA POR LINEA
    void recuperar(); 

    void insertar(const Computadora &c, size_t pos);//Insertar en una posicion valida
    size_t size();
    void inicializar(const Computadora &c, size_t n);
    void eliminar(size_t pos);//Eliminar una posicion valida
    
    void ordenar();
    void ordenarSO();
    void ordenarPrecio();
    void ordenarRAM();
    
    Computadora* buscar(const Computadora &c);//Va a retornar un puntero de la posicion del vector donde esta el elemento que queremos buscar
    void eliminar_ultimo();

    friend Laboratorio & operator << (Laboratorio &l, const Computadora &c){

        l.agregarComputadora(c);//Llamamos a la funcion y mandamos una computadora
        return l;
    }

private:
    vector<Computadora> computadoras;//Vector de computadoras
};

#endif //LABORATORIO_H