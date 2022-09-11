#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "Student.h"

class Node
{
    private:
        Node* next;
        Student s;

    public:
        Node();
        Node(Student);

        void setStudent(Student);
        void setNext(Node*);

        Student getStudent();
        Node* getNext();




};

#endif // NODE_H_INCLUDED
