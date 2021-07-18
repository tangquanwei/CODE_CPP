#include <iostream>
#include <string>
#include <vector>

#include <windows.h> //* sleep  // unistd.h in linux
#include <fstream>   //* 1.包含头文件
using std::cout;
using std::endl;
/* 文本文件读写 */
void file_write()
{
    std::ofstream ofs;                      //* 2.创建流对象
    ofs.open("./txt/a.txt", std::ios::out); //* 3.打开文件
    //*打开方式 ios::in(读) out(写) ate(文件尾) app(追加) trunc(先删除再创建) binary(二进制)  |(或)
    ofs << "唐权威写的code\n"; //* 4.写数据
    ofs.close();               //* 5.关闭文件
}
void file_read()
{
    std::ifstream ifs;                     //* 2.创建流对象
    ifs.open("./txt/a.txt", std::ios::in); //* 3.打开文件,并判断是否成功
    if (!ifs.is_open())
        throw "文件打开失败!";
    // { //* 4.1 读文件
    //     char buf[1024] = {0};
    //     while (ifs >> buf)
    //         cout << buf << endl;
    // }
    // { //* 4.2 读文件
    //     char buf[1024] = {0};
    //     while (ifs.getline(buf, sizeof(buf)))
    //         cout << buf << endl;
    // }
    // { //* 4.3 读文件
    //     std::string buf;
    //     while (std::getline(ifs, buf))
    //         cout << buf << endl;
    // }
    { //* 4.4 读文件
        char c;
        while ((c = ifs.get()) != EOF)
        {
            Sleep(100); // 毫秒
            cout << c;
        }
    }

    ifs.close(); //* 5.关闭文件
}
/* 二进制文件读写 */
struct Person
{
    std::string m_name;
    int m_age;
};
void b_file_write()
{
    std::ofstream ofs("./txt/person.txt", std::ios::out | std::ios::binary);
    //* 2.创建流对象,并以二进制写方式打开
    Person p{"权威", 18};
    ofs.write((const char *)&p, sizeof(Person)); //* 3.写文件
    ofs.close();                                 //* 4.关闭文件
}
void b_file_read()
{
    std::ifstream ifs;                                             //* 2.创建流对象
    ifs.open("./txt/person.txt", std::ios::in | std::ios::binary); //* 3.以二进制读方式打开
    if (!ifs.is_open())
        throw "文件打开失败!";

    Person p;
    ifs.read((char *)&p, sizeof(Person)); //* 4.读文件
    cout << "mane: " << p.m_name << "\nage: " << p.m_age << endl;
    ifs.close(); //* 5.关闭文件
}
void file_ptr(){
    std::ofstream ofs("a.txt",std::ios::ate);
    size_t location=ofs.tellp(); //取得写指针的位置
    location=10L;
    ofs.seekp(location); //移动到10个字节处
    ofs.seekp(location,std::ios::beg);// 开头+location处
    ofs.seekp(location,std::ios::cur);//当前位置+location处
    ofs.seekp(location,std::ios::end);

}
/* 异常 */
double devide(double x, double y)
{

    if (y == 0)
        throw "被除数不能为0"; //* 1.显示地抛出异常
    return x / y;              //*异常之后的代码不执行
}
void exception()
{
    try
    {
        cout << devide(2, 0); //* 2.执行可能出现异常的代码
    }
    catch (const char *error) //* 3.根据类型捕获异常
    {
        cout << error << endl;
    }
    catch (...) //* 所有异常
    {
    }
    cout << "over" << endl;
}
void loop_io()
{
    // Person* p=new Person{"唐权威", 18};
    // cout << p->m_name << "--" << p->m_age << endl;
    // delete p;
    /* new */
    std::vector<Person *> vp{new Person{"唐权威", 18},
                             new Person{"qdqhf", 20},
                             new Person{"tadbag", 28}};
    /* write */
    std::ofstream ofs("./txt/loop_io.txt", std::ios::out | std::ios::binary);
    for (auto &&i : vp)
    {
        ofs.write((const char *)i, sizeof(Person));
        ofs.write("\n", sizeof(char));
    }
    ofs.close();
    /* read */
    std::ifstream ifs;
    ifs.open("./txt/loop_io.txt", std::ios::in | std::ios::binary);
    Person *q = new Person;
    char buf[1024];

    while (buf, 1024)
    { //把p所指的类容转换成char
        q = (Person *)buf;
        cout << q->m_name << "--" << q->m_age << endl;
        vp.push_back(q);
    }
    ifs.close();
    /* detete */
    for (auto &&i : vp)
    {
        cout << i->m_name << "--" << i->m_age << endl;
        delete i;
    }
}
int main()
{
    loop_io();
    return 0;
}
