#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include <iostream>

class Student
{
    private:
        std::string name;
        int code;
        std::string degree;



    public:
        Student();
        Student(std::string,int,std::string);


        void setName(std::string);
        void setCode(int);
        void setDegree(std::string);

        std::string getName();
        int getCode();
        std::string getDegree();


};

#endif // STUDENT_H_INCLUDED
