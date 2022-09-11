#include "Student.h"

using namespace std;
Student::Student()
{

}
Student::Student(std::string n, int c, std::string d)
{
    name=n;
    code=c;
    degree= d;
}

void Student::setName(std::string n)
{
    name=n;
}

void Student::setCode(int c)
{
    code = c;
}

void Student::setDegree(std::string d)
{
    degree = d;
}

string Student::getName()
{
    return name;
}

int Student::getCode()
{
    return code;
}

string Student::getDegree()
{
    return degree;
}

