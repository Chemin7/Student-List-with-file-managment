#include "Node.h"

Node::Node()
{
    next=nullptr;
}
Node::Node(Student s)
{
    this->setStudent(s);
    this->setNext(nullptr);
}

void Node::setStudent(Student s)
{
    this->s=s;
}

void Node::setNext(Node* n)
{
    this->next= n;
}

Student Node::getStudent()
{
    return s;
}

Node* Node::getNext()
{
    return next;
}
