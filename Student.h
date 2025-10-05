#pragma once
#include<string>
#include<iostream>
using namespace std;
class Student
{
private:
    string name;
    int age;
public:

    void setName(const string &name);
    void setAge(const int &age);
    string getName();
    int getAge() const;

    Student(const string& name, const int& age);
    Student();
    ~Student();
    //运算符重载
    friend ostream& operator <<(ostream& os, const Student& stu) {
        os << "姓名：" << stu.name << " 年龄：" << stu.age;
        return os;
    }
};
