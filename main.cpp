#include <iostream>
#include <string>
#include "StudentManager.h"
#include "Student.h"

using namespace std;
int main() {
    
    string host = "tcp://127.0.0.1:3306";//主机地址
    string user = "root";//用户名
    string passwd = "password";//密码
    string database = "database";//数据库

    //测试用例
    Student stu1("Bob", 22), stu2("Anna", 23),stu3("Lily",18);

    StudentManager sm;
    sm.connection(host, user, passwd, database);

    sm.add_stu(stu1);
    sm.add_stu(stu2);

    sm.display_all();
    sm.update(stu1, stu3);
    sm.display_all();
    cout << "查询单个记录" << endl;
    cout << sm.select_by_name(stu2)<<endl;
    sm.add_stu(stu1);
    sm.delete_by_name(stu2);
    sm.display_all();
    sm.delete_all();
    return 0;
}