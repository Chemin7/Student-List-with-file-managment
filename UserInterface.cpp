#include "UserInterface.h"
#include <iostream>
#include <string>

using namespace std;
UserInterface::UserInterface() {
    myList = new List();
    }

void UserInterface::menu() {

    int opc;

    while(opc!=3) {

        cout<<"---------MENU--------\n"
            <<"1) Agregar un estudiante\n"
            <<"2) Mostrar\n"
            <<"3) Salir\n"
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
                break;


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
