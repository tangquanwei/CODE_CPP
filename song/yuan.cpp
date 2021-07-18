//教室信息管理系统
#include "yuan.h"
constexpr char PATH[]{ "classroom.txt" };

//登录功能实现函数
bool login(string a, string b) {
	string password = "1234";
	cout << "     教室信息查询登录系统     " << endl;
	cout << "---------------------------------" << endl;
	cout << "账号：" << flush; //flush表示什么都不加直接输出
	cin >> a;
	cout << "密码：" << flush;
	//给予三次输入密码机会
	for (int i = 2; i >= 0; i--) {
		cin >> b;
		if (a == "abcd" && b == password) {
			cout << "登录成功！" << endl;
			system("pause");
			return true;
			break;
		}
		else if (i != 0) {
			cout << "密码错误,请重新输入（你还有" << i << "次输入机会）" << endl;
			cout << "密码：" << flush;
		}
		else {
			cout << "3次输入错误，您无权访问该管理系统！" << endl;
			return false;
		}
	}
}

void Add() {
	Classroom* c = nullptr;

	switch (chioce) {
	case 1:
		c = new JietiClassRoom(nu,name,desk_number,user);
		break;
	case 2:
		c = new CommonClassRoom(nu,name,desk_number,user);
		break;
	default:
		break;
	}
}
istream& operator>>(istream& in, Classroom& c) //重载运算符
{
	in >> c.num;
	in >> c.name;
	in >> c.desk_number;
	in >> c.user;
	return in;
}
ostream& operator<<(ostream& out, const Classroom& c) {
	out << "教室编号为:" << c.num << endl;
	out << "教室所在教学楼为：" << c.name << endl;
	out << "教室中课桌数量：" << c.desk_number << endl;
	out << "教室使用情况：" << c.user << "\n";
	return out;
}



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
			cout << "教室信息重复，请重新输入：" << endl
				 << endl;
			goto A;
		}
	cout << "请输入该教室的信息：" << endl;
	cout << "教室所在教学楼名：";
	cin >> c.name;
	cout << "教室中课桌数量：";
	cin >> c.desk_number;
	cout << "教室使用情况(占用或空闲)：";
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
		cout << "编号为" << it->num << "教室的基本信息如下：" << endl;
		cout << "\t教室所在教学楼为     " << it->name << endl;
		cout << "\t教室中课桌数量     " << it->desk_number << endl;
		cout << "\t教室使用情况 " << it->user << "\n";
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
			;
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
int main() {
	string ID;
	string in;
	bool x;
	// x = login(ID, in);
	if (x = true) //todo
	{
		ClassManage s; //创建管理系统对象
		char key;	   //key接收一个值，根据key值的不同执行不同的功能
		while (true) {
			s.Menu(); //显示功能菜单
			cout << endl
				 << "请输入需要执行的功能" << endl;
			cin >> key;
			cout << endl;

			switch (key) {
			case '1':
				s.Display();
				break;
			case '2':
				s.Add();
				break;
			case '3':
				s.Search();
				break;
			case '4':
				s.Modify();
				break;
			case '5':
				s.Delete();
				break;
			case '6':
				return 0;
			}
			system("pause"); //暂停中止
			system("cls");	 //每次执行完毕，清屏
		}
	}
	return 0;
}
