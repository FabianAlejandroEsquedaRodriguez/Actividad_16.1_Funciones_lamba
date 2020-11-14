#include <iostream>
#include "Laboratorio.h"

using namespace std;

int main(){
    Laboratorio lab;//En esta instancia, se crea nuestro vector de computadoras

    string opc;

    while(true){
        cout<<"\t\t\tMENU DE OPCIONES\n\n";
        cout<<"1. Agregar Computadora"<<endl;
        cout<<"2. Mostrar"<<endl;    
        cout<<"3. Respaldar"<<endl;    
        cout<<"4. Recuperar"<<endl;    
        cout<<"5. Insertar"<<endl; 
        cout<<"6. Inicializar"<<endl;
        cout<<"7. Eliminar"<<endl;   
        cout<<"8. Ordenar por nombre"<<endl;   
        cout<<"9. Ordenar por SO"<<endl;
        cout<<"10. Ordenar por precio"<<endl;
        cout<<"11. Ordenar por memoria RAM"<<endl;
        cout<<"12. Eliminar ultimo"<<endl;
        cout<<"10. Buscar"<<endl;
        cout<<"0. Salir"<<endl<<endl; 

        cout<<"Digita una opcion: ";
        getline(cin, opc);
        system("cls");

        if(opc == "1"){
            Computadora compu;
            cout<<"\t\t\tAGREGAR COMPUTADORA"<<endl<<endl;
            cin>>compu;//La sobrecarga del operador >> ya esta hecha en la clase Computadora

            lab.agregarComputadora(compu);
            cin.ignore();
        }

        else if(opc == "2"){
            lab.mostrar();
        }
        
        else if(opc == "3"){
            cout<<"\t\t\tRESPALDAR LAS COMPUTADORAS AGREGADAS\n\n";
            lab.respaldar();//Respaldar en un txt
        }
        
        else if(opc == "4"){
            cout<<"\t\t\tRECUPERAR LAS COMPUTADORAS AGREGADAS\n\n";
            lab.recuperar();
        }

        else if(opc == "5"){
            Computadora compu;

            size_t pos;

            cout<<"\t\t\tINSERTAR EN UNA POSICION VALIDA\n\n";

            cin>>compu;//Se hace uso de la sobrecarga del operador >>

            cout<<endl<<"Digita una posicion: ";
            cin>>pos;

            cin.ignore();

            if(pos >= lab.size()){
                cout<<endl<<"Posicion no valida"<<endl;
            }
            else{
                lab.insertar(compu, pos);
            }
            
        }

        else if(opc == "6"){
            Computadora compu;

            size_t n;
            cout<<"\t\t\tINICIALIZAR EL VECTOR\n\n";

            cin>>compu;//Se hace uso de la sobrecarga del operador >>

            cout<<endl<<"Numero de veces a repetir la computadora: ";
            cin>>n;

            cin.ignore();

            lab.inicializar(compu, n);
        }

        else if(opc == "7"){
            size_t pos;
            cout<<"\t\t\tELIMINAR UNA COMPUTADORA\n\n\n";

            cout<<"Digita una posicion a eliminar:";
            cin>>pos;
            cin.ignore();

            if(pos >= lab.size()){
                cout<<endl<<"Posicion no valida";
            }
            else{
                lab.eliminar(pos);
            }
        }

        else if(opc == "8"){
            cout<<"\t\t\tORDENANDO POR NOMBRE EL VECTOR DE COMPUTADORAS\n\n";
            //En la clase computadora se sobrecargo el operador < para poder hacer el ordenamiento usando el metodo sort()
            lab.ordenar();
        }

        else if(opc == "9"){
            cout<<"\t\t\tORDENANDO POR SO EL VECTOR DE COMPUTADORAS\n\n";

            lab.ordenarSO();
        }

        else if(opc == "10"){
            cout<<"\t\t\tORDENANDO POR PRECIO EL VECTOR DE COMPUTADORAS\n\n";

            lab.ordenarPrecio();
        }
        
        else if(opc == "11"){
            cout<<"\t\t\tORDENANDO POR MEMORIA RAM EL VECTOR DE COMPUTADORAS\n\n";

            lab.ordenarRAM();
        }

        else if(opc == "12"){
            cout<<"\t\t\tELIMINANDO ULTIMO ELEMENTO\n\n";
            if(lab.size() <= 0){
                cout<<"\nEl vector esta vacio"<<endl;
            }
            else{
                lab.eliminar_ultimo();
            }
            
        }

        else if(opc == "10"){
            cout<<"\t\t\tBUSCAR UNA COMPUTADORA\n\n";
            Computadora compu;
            cin>>compu;

            cin.ignore();

            Computadora *ptr = lab.buscar(compu);

            if (ptr == nullptr){
                cout<<"\n\nNo se encontro"<<endl;
            }
            else{
                cout<<endl<<*ptr<<endl;//Se hace la referenciacion para que pueda imprimir la computadora
            }
        }

        else if(opc == "0"){
            break;
        }
    
    cout<<"\n\n\n";
    system("pause"); system("cls");
    }


    return 0;
}