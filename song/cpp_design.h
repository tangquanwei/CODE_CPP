#ifndef __CPP_DESIGN
#define __CPP_DESIGN

#include <fstream>
#include <iostream>
#include <list>
using namespace std;
constexpr char PATH[]{ "./classroom.txt" }; //这是全局常量 :)

class Classroom {
public:
	string num;			//教室编号
	string name;		//教室所在教学楼名字
	string desk_number; //教室中课桌数量
	string user;		//教室使用情况
	friend istream& operator>>(istream& in, Classroom& c);
	friend ostream& operator<<(ostream& out, const Classroom& c);
	friend ifstream& operator>>(ifstream& in, Classroom& c);
	friend ofstream& operator<<(ofstream& out, const Classroom& c);
	static void* operator new(size_t size);
	static void* operator new[](size_t size);
	static void operator delete(void* pdead);
	static void operator delete[](void* pdead);
	virtual string getInfo() { return "ClassRoom"; }
	Classroom() {}
};
class JietiClassroom : public Classroom {
	string getInfo() { return "JietiClassRoom"; }
};
class CommonClassroom : public Classroom {
	string getInfo() { return "CommonClassRoom"; }
};


istream&
operator>>(istream& in, Classroom& c) {
	in >> c.num;
	in >> c.name;
	in >> c.desk_number;
	in >> c.user;
	return in;
}
ostream& operator<<(ostream& out, const Classroom& c) {
	out << "教室编号为:\t" << c.num << endl;
	out << "教室所在教学楼为:\t" << c.name << endl;
	out << "教室中课桌数量:\t" << c.desk_number << endl;
	out << "教室使用情况:\t" << c.user << "\n";
	return out;
}
ifstream& operator>>(ifstream& in, Classroom& c) {
	in >> c.num;
	in >> c.name;
	in >> c.desk_number;
	in >> c.user;
	return in;
}
ofstream& operator<<(ofstream& out, const Classroom& c) {
	out << c.num << endl;
	out << c.name << endl;
	out << c.desk_number << endl;
	out << c.user << "\n";
	return out;
}
//*member
static void* Classroom::operator new(size_t size) {
	Classroom* p = (Classroom*)malloc(size);
	return p;
}
static void Classroom::operator delete(void* pdead) {
	free(pdead);
}
static void* Classroom::operator new[](size_t size) {
	Classroom* p = (Classroom*)malloc(size);
	return p;
}
static void Classroom::operator delete[](void* pdead) {
	free(pdead);
}
//*override global
inline void* operator new(size_t size) {
	Classroom* p = (Classroom*)malloc(size);
	return p;
}
inline void operator delete(void* pdead) {
	free(pdead);
}
inline void* operator new[](size_t size) {
	Classroom* p = (Classroom*)malloc(size);
	return p;
}
inline void operator delete[](void* pdead) {
	free(pdead);
}
//* override placement
void* operator new(size_t size, int id) {
	Classroom* p = (Classroom*)malloc(size);
	return p;
}
void operator delete(void* pdead, int i) {
	free(pdead);
}
void* operator new[](size_t size, int id) {
	Classroom* p = (Classroom*)malloc(size);
	return p;
}
void operator delete[](void* pdead, int i) {
	free(pdead);
}

class ClassManage : public Classroom {
private:
	list<Classroom> classroomlist; //存储所有教室信息的容器
	// 将容器中所有信息写入文件函数
	void ofsallMess() {
		ofstream ofst; //以清空源文件内容方式打开文件
		ofst.open(PATH, ios::trunc);
		if (!ofst.is_open()) //判断文件是否打开成功
		{
			cout << "文件打开失败" << endl;
			return;
		}
		//将容器中所有信息写入文件中功能实现部分
		for (list<Classroom>::const_iterator it = classroomlist.begin(); it != classroomlist.end(); it++)
			ofst << endl
				 << it->num << endl
				 << it->name << endl
				 << it->desk_number << endl
				 << it->user << endl;
		ofst.close(); //关闭文件
	}

public:
	ClassManage();	//构造函数
	void Menu();	//功能菜单
	void Add();		//添加新的教室
	void Display(); //显示所有教室信息
	void Search();	//查询教室信息
	void Delete();	//删除教室信息
	void Modify();	//修改教室信息
};
ClassManage::ClassManage() //用于将文件中的内容按格式读取到list<Classroom>中去
{

	ifstream ifstr;
	ifstr.open(PATH, ios::in); //打开文件路径中的文件，如果打开失败则创建文件
	if (!ifstr.is_open()) {
		ofstream temp(PATH); //创建文件
		temp.open(PATH, ios::out);
		if (!temp.is_open()) //检测是否创建成功
		{
			cout << "创建文件失败，退出程序" << endl;
			exit(-1);
		}
		temp.close(); //文件创建成功则关闭文件
	}
	system("cls"); //清屏
	ifstream ifst; //将文件中所有内容读取到list容器中
	ifst.open(PATH, ios::in);
	char line[14]; //字符数组，用于存储教室属性信息
	Classroom temp;
	ifst.getline(line, sizeof(line));
	//按行读取文件中的内容
	//循环读取信息，并将信息插入到list容器中
	while (!ifst.eof()) //ifstream.eof()判断文件是否为空
	{
		//保存信息到临时教室temp中
		ifst.getline(line, sizeof(line));
		temp.num = line;
		ifst.getline(line, sizeof(line));
		temp.name = line;
		ifst.getline(line, sizeof(line));
		temp.desk_number = line;
		ifst.getline(line, sizeof(line));
		temp.user = line;
		classroomlist.push_back(temp); //将temp插入到教室容器中
	}
}
void ClassManage::Menu() {
	for (int i = 0; i < 10; i++) {
		cout << "*";
	}
	cout << "教室信息管理系统";
	for (int i = 0; i < 10; i++) {
		cout << "*";
	}
	cout << endl;
	cout << "*1.显示"
		 << "\t\t"
		 << "2.录入*" << endl;
	cout << "*3.查询"
		 << "\t\t"
		 << "4.修改*" << endl;
	cout << "*5.删除"
		 << "\t\t"
		 << "6.退出*" << endl;
	for (int i = 0; i < 32; i++) {
		cout << "*";
	}
	cout << endl;
}
void ClassManage::Add() {
	Classroom c; //创建一个教室结构体
A:
	cout << "编号：";
	cin >> c.num;
	//查重，读入编号时，遍历所有的教室编号信息，如果编号相同则输出并提示重新输入
	for (list<Classroom>::const_iterator it = classroomlist.begin(); it != classroomlist.end(); it++)
		if (it->num == c.num) {
			cout << "教室信息重复，请重新输入：" << endl;
			goto A;
		}
	cout << "请输入该教室的信息：" << endl;
	cout << "教室所在教学楼名：";
	cin >> c.name;
	cout << "教室中课桌数量：";
	cin >> c.desk_number;
	cout << "教室使用情况(空 或 占用)：";
	cin >> c.user;
	classroomlist.push_back(c); //将新添加的教室信息尾插到容器中
	ofstream ofst;				//创建写入流对象
	ofst.open(PATH, ios::app);	//在文件路径中以追加方式打开文件
	//将教室信息按顺序写入到文件中
	ofst << endl
		 << c.num << endl
		 << c.name << endl
		 << c.desk_number << endl
		 << c.user;
	ofst.close();
}
void ClassManage::Display() {
	cout << endl;
	for (list<Classroom>::const_iterator it = classroomlist.begin(); it != classroomlist.end(); it++) {
		cout << "编号为" << it->num << "教室的基本信息如下："
			 << "\n教室所在教学楼为\t" << it->name
			 << "\n教室中课桌数量\t\t" << it->desk_number
			 << "\n教室使用情况\t\t" << it->user << endl;
	}
}
void ClassManage::Search() {
	string find_num;
	cout << "请输入需要查找的教室的编号：";
	cin >> find_num;
	for (list<Classroom>::const_iterator it = classroomlist.begin(); it != classroomlist.end(); it++)
		if (it->num == find_num) {
			cout << "教室编号为:" << it->num << endl;
			cout << "教室所在教学楼为：" << it->name << endl;
			cout << "教室中课桌数量：" << it->desk_number << endl;
			cout << "教室使用情况：" << it->user << "\n";
			return;
		}
	cout << "没有找到编号为：" << find_num << "的教室" << endl;
}
void ClassManage::Delete() {
	//从容器中查找和需要删除教室的编号一样的编号，找到则删除，并刷新文件内容
	string delete_num;
	cout << "请输入需要删除的教室的编号：";
	cin >> delete_num;
	list<Classroom>::const_iterator it; //const_iterator用于读取容器内的元素
	for (list<Classroom>::const_iterator it = classroomlist.begin(); it != classroomlist.end(); it++)
		if (it->num == delete_num) {
			classroomlist.erase(it);
			ofsallMess(); //将容器中内容写入文件中
			cout << "已删除" << endl;
			return;
		}
	cout << "没有找到该编号的教室..." << endl;
}
void ClassManage::Modify() {
	string modify_num;
A:
	cout << "请输入需要修改的教室的编号：";
	cin >> modify_num;
	//接受编号后，先遍历一遍容器查看是否有该编号，如果没有则重新输入
	list<Classroom>::const_iterator it;
	for (it = classroomlist.begin(); it != classroomlist.end(); it++)
		if (it->num == modify_num)
			break;
	if (it == classroomlist.end()) {
		cout << "没有找到该编号...";
		goto A;
	}
	//修改教室信息
	for (list<Classroom>::iterator it = classroomlist.begin(); it != classroomlist.end(); it++)
		if (it->num == modify_num) {
			//先输出原信息
			cout << "该教室原来信息：" << endl;
			cout << "教室编号为:" << it->num << endl;
			cout << "教室所在教学楼为：" << it->name << endl;
			cout << "教室中课桌数量：" << it->desk_number << endl;
			cout << "教室使用情况：" << it->user << "\n";
			//再修改
			cout << "请输入修改后的学生信息：" << endl
				 << endl;
			cout << "教室编号为:";
			cin >> it->num;
			cout << "教室所在教学楼为：";
			cin >> it->name;
			cout << "教室中课桌数量：";
			cin >> it->desk_number;
			cout << "教室使用情况：";
			cin >> it->user;
			break;
		}
	ofsallMess(); //刷新文件中的信息
	cout << endl
		 << "修改成功" << endl;
}

#endif // !__CPP
