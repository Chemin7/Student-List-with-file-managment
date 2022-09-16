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


    //texto

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

    if(!aux){
        cout<<"La Lista esta vacia..."<<endl;
        return;
    }

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
    char ch;
    ifstream myFile;
    myFile.open("file01.txt");

    myFile.seekg(0,ios::end);
    int length=myFile.tellg();
    myFile.seekg(0,ios::beg);

    if(length == 0 ) {

        myFile.close();
        return;
        }
    else {

        while(!myFile.eof()) {

            getline(myFile,name,'|');

            getline(myFile,str_code,'|');

            getline(myFile,degree,'*');



            code = stoi(str_code);
            Student s(name,code,degree);
            addNode(s);



            if(myFile.tellg()== length)
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

Node* List::searchStudent(int code) {
    Node* aux(head);
    while(aux) {
        if(aux->getStudent().getCode() == code )
            return aux;
        aux=aux->getNext();
        }
    return nullptr;
    }

void List::deleteStudent(int code ) {
    Node* temp(searchStudent(code));



    if(temp == head)
        head = head->getNext();
    else if(!temp) {
        cout<<"Estudiante no encontrado"<<endl;
        system("pause");
        }
    else {
        Node* aux(getPredecessor(temp));
        aux->setNext(temp->getNext());
        }

    delete temp;

    replaceFile();



    }

Node* List::getPredecessor(Node* n) {
    if(n==head)
        return nullptr;
    Node* aux(head);

    while(aux != nullptr and aux->getNext() != n)
        aux = aux->getNext();

    return aux;

    }

void List::replaceFile() {
    Node* aux(head);

    fstream myFile;
    myFile.open("file01.txt",ios::out);

    while(aux) {
        myFile<<aux->getStudent().getName();
        myFile<<"|";
        myFile<<aux->getStudent().getCode();
        myFile<<"|";
        myFile<<aux->getStudent().getDegree();
        myFile<<"*";

        aux=aux->getNext();
        }
    myFile.close();
    }


