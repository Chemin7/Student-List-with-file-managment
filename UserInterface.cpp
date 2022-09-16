#include "UserInterface.h"
#include <iostream>
#include <string>

using namespace std;
UserInterface::UserInterface() {
    myList = new List();
    }

void UserInterface::menu() {

    int opc;




    while(opc!=5) {

        cout<<"---------MENU--------\n"
            <<"1) Agregar un estudiante\n"
            <<"2) Mostrar\n"
            <<"3) Eliminar\n"
            <<"4) Buscar estudiante\n"
            <<"5) Salir\n"
            <<"Selecciona una opcion: ";
        cin>>opc;



        switch(opc) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                deleteSt();
                break;
            case 4:
                searchSt();
                break;
            case 5:
                break;
            default:
                cout<<"opcion invalida"<<endl;

            }
        system("cls");

        }
    }

void UserInterface::add() {
    string name,degree;
    int code ;

    cin.ignore();
    cout<<"Nombre: ";
    getline(cin,name);
    cout<<"Codigo: ";
    cin>>code;
    cin.ignore();
    cout<<"Carrera: ";
    getline(cin,degree);

    Student s(name,code,degree);
    myList->add(s);

    }

void UserInterface::display() {
    myList->display();
    system("pause");
    }

void UserInterface::searchSt() {
    int code;
    cout<<"Ingrese el codigo del estudiante a buscar: ";
    cin>>code;

    cout<<myList->searchStudent(code)->getStudent().getName();
    system("pause");
    }

void UserInterface::deleteSt() {
    int code;
    cout<<"Ingrese el codigo del estudiante a eliminar: ";
    cin>>code;

    myList->deleteStudent(code);
    }
