#include "StudentManager.h"
 // 添加此头文件

void StudentManager::delete_by_name(Student stu)
{
    PreparedStatement* pstmt = nullptr;
    pstmt = conn->prepareStatement("DELETE FROM student WHERE name = ?");

    pstmt->setString(1, stu.getName());

    pstmt->executeUpdate();
    cout << "删除完成" << endl;

    if (pstmt != nullptr) delete pstmt;
}

void StudentManager::delete_all()
{
    PreparedStatement* pstmt = nullptr;
    pstmt = conn->prepareStatement("DELETE FROM student");

    pstmt->executeUpdate();
    cout << "删除单个完成" << endl;

    if (pstmt != nullptr) delete pstmt;
}

void StudentManager::add_stu(Student stu)
{
    PreparedStatement* pstmt = nullptr;
    pstmt = conn->prepareStatement("INSERT INTO student (name, age) VALUES (?, ?)");

    pstmt->setString(1, stu.getName());
    pstmt->setInt(2, stu.getAge());
    pstmt->executeUpdate();
    cout << "插入完成" << endl;

    if (pstmt != nullptr) delete pstmt;
}

vector<Student> StudentManager::select_all()
{
    PreparedStatement* pstmt = nullptr;
    ResultSet* res = nullptr;
    vector<Student> students;
    pstmt = conn->prepareStatement("SELECT * FROM  student");
    res = pstmt->executeQuery();
    while (res->next()) {
        Student stu;
        stu.setName(res->getString("name"));
        stu.setAge(res->getInt("age"));
        students.push_back(stu);
    }

    if (res != nullptr) delete res;
    if (pstmt != nullptr) delete pstmt;
    return students;
}

void StudentManager::display_all()
{
    cout << "查询当前全部记录" << endl;
    auto students = this->select_all();
    for (auto& i : students) {
        cout << i << endl;
    }
}

Student StudentManager::select_by_name(Student stu)
{
    PreparedStatement* pstmt = nullptr;
    ResultSet* res = nullptr;
    Student temp;
    pstmt = conn->prepareStatement("SELECT * FROM  student where name= ?");
    pstmt->setString(1, stu.getName());
    res = pstmt->executeQuery();
    if (res->next()) {
        temp.setName(res->getString("name"));
        temp.setAge(res->getInt("age"));
    }
    if (res != nullptr) delete res;
    if (pstmt != nullptr) delete pstmt;
    return temp;
}


void StudentManager::update(Student stu1, Student stu2)
{
    cout << "更新记录" << endl;
    PreparedStatement* pstmt = nullptr;
    pstmt= conn->prepareStatement("UPDATE student SET name = ? ,age = ? WHERE name= ?");
    pstmt->setString(1,stu2.getName());
    pstmt->setInt(2, stu2.getAge());
    pstmt->setString(3, stu1.getName());

    pstmt->executeUpdate();
    
    if (pstmt != nullptr) delete pstmt;
}

void StudentManager::connection(const string& host, const string& user, const string& passwd, const string& database)
{
    conn =  driver->connect(host, user, passwd);
    std::cout << "成功连接到MySQL服务器！" << std::endl;
    conn->setSchema(database);
    conn->setClientOption("characterSetResults", "utf8mb4");
}

StudentManager::StudentManager()
{
    driver = get_driver_instance();
}

StudentManager::~StudentManager()
{
    if(!conn) delete conn;
}
