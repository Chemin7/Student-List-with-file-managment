#ifndef USERINTERFACE_H_INCLUDED
#define USERINTERFACE_H_INCLUDED
#include <iostream>
#include "List.h"

class UserInterface{
private:
    List* myList;
public:
    UserInterface();

    void menu();
    void add();
    void display();
    void searchSt();
    void deleteSt();


};

#endif // USERINTERFACE_H_INCLUDED
