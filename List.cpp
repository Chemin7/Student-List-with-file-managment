#include "List.h"
#include "Node.h"
#include <iomanip>

using namespace std;
List::List()  {
    head=nullptr;
    retrive();
    }
void List::add(Student s) {
    fstream myFile;

    Node* aux(new Node(s));
    Node* last = getLastPos();

    if(head==nullptr)
        head=aux;
    else
        last->setNext(aux);


    myFile.open("file01.txt",ios::app);

    myFile<<aux->getStudent().getName();
    myFile<<"|";
    myFile<<aux->getStudent().getCode();
    myFile<<"|";
    myFile<<aux->getStudent().getDegree();
    myFile<<"*";

    myFile.close();

    }

void List::display() {
    Node* aux(head);

    cout<<left
        <<setw(20)<<"Nombre"
        <<setw(11)<<"|Codigo"
        <<setw(21)<<"|Carrera"<<endl;
    while(aux) {

        cout<<left
            <<setw(20)<<aux->getStudent().getName()
            <<"|"<<setw(10)<<aux->getStudent().getCode()
            <<"|"<<setw(20)<<aux->getStudent().getDegree()<<endl;

        aux=aux->getNext();

        }

    }

Node* List::getLastPos() {
    Node* aux(head);
    if(!head)
        return nullptr;

    while(aux->getNext())
        aux=aux->getNext();


    return aux;
    }


void List::retrive() {
    string name,degree,str_code,check;
    int code;
    ifstream myFile;
    myFile.open("file01.txt",ios::in);

    if(!myFile.get()) {

        myFile.close();
        return;
        }
    else {

        while(myFile) {

            getline(myFile,name,'|');

            getline(myFile,str_code,'|');

            getline(myFile,degree,'*');



            code = stoi(str_code);
            Student s(name,code,degree);
            addNode(s);

            if(myFile.get() == '\n')
                break;


            }
        myFile.close();
        }

    }

void List::addNode(Student s) {
    Node* aux(new Node(s));
    Node* last = getLastPos();

    if(head==nullptr)
        head=aux;
    else
        last->setNext(aux);
    }
