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
    //根据名字name属性删除
    void delete_by_name(Student stu);
    //全部删除
    void delete_all();
    //添加记录
    void add_stu(Student stu);
    //用stu2更新stu1
    void update(Student stu1, Student stu2);
    //查询所有记录，用vector<Student>存储并返回
    vector<Student> select_all();
    //根据name属性返回一个Student对象
    Student select_by_name(Student stu);
    //显示当前所有记录
    void display_all();

    
    //连接
    void connection(const string& host, const string& user, const string& passwd, const string& database);

    StudentManager();
    ~StudentManager();

};
