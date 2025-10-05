#include"Student.h"

Student::Student(const string &name, const int &age)
{
    this->name=name;
    this->age=age;
}

Student::Student()
{
}

void Student::setName(const string& name)
{
    this->name = name;
}

void Student::setAge(const int& age)
{
    this->age = age;
}

string Student::getName()
{
    return name;
}

int Student::getAge() const
{
    return age;
}

Student::~Student()
{
    
}
