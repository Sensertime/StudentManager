#pragma once
#include<string>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include"Student.h"
using namespace std;
using namespace sql;
class StudentManager
{
private:
    /* data */
    Driver* driver;
    Connection* conn;
public:
    //��������name����ɾ��
    void delete_by_name(Student stu);
    //ȫ��ɾ��
    void delete_all();
    //��Ӽ�¼
    void add_stu(Student stu);
    //��stu2����stu1
    void update(Student stu1, Student stu2);
    //��ѯ���м�¼����vector<Student>�洢������
    vector<Student> select_all();
    //����name���Է���һ��Student����
    Student select_by_name(Student stu);
    //��ʾ��ǰ���м�¼
    void display_all();

    
    //����
    void connection(const string& host, const string& user, const string& passwd, const string& database);

    StudentManager();
    ~StudentManager();

};
