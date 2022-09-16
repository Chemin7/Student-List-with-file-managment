#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "Node.h"
#include "Student.h"
#include <string>
#include <fstream>
#include <iostream>

class List {
    private:
        Node* head;
        Node* getLastPos();
        void addNode(Student);

    public:
        List();

        void add(Student);
        void display();
        void retrive();
        Node* searchStudent(int);
        Node* getPredecessor(Node*);
        void deleteStudent(int);

        void replaceFile();

        void cargar();


    };
#endif // LIST_H_INCLUDED
