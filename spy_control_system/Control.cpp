#include <algorithm>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <conio.h> // _getch

#include "Control.h"
using namespace std;
constexpr auto FILENAME = "./txt/spy.txt";

struct Deleter { //function-like class
	template <class T> // function templet
	void operator()(T* p) { delete p; }
};

Control::Control() {
	// 1. 文件不存在初始化
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->isEmpty = true;
		ifs.close();
		return;
	}
	//2. 文件为空
	char c;
	ifs >> c;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->isEmpty = true;
		ifs.close();
		return;
	}
	//3. 文件不为空
	this->ProgressBar(false); //关闭进度条
	this->isEmpty = false;
	this->Init();
}


Control::~Control() {
	for_each(m_spy_vector.begin(), m_spy_vector.end(), Deleter());
	this->m_spy_vector.clear();
}

int Control::ShowMenu_GetChoice() const {
	int cnt{ 0 }, c1, c2;
	while (1) {
		cout << R"( ________________________________________________________ )" << endl;
		cout << R"(|　By_Quanwei                               [－][口][×]| |)" << endl;
		cout << R"(|________________________________________________________|)" << endl;
		cout << R"(|               _欢迎使用间谍控制系统_                   |)" << endl;
		if (cnt == 0)
			cout << R"(|            ==> 0. 退出系统                             |)" << endl;
		else
			cout << R"(|                0. 退出系统                             |)" << endl;
		if (cnt == 1)
			cout << R"(|            ==> 1. 添加间谍信息                         |)" << endl;
		else
			cout << R"(|                1. 添加间谍信息                         |)" << endl;
		if (cnt == 2)
			cout << R"(|            ==> 2. 显示间谍信息                         |)" << endl;
		else
			cout << R"(|                2. 显示间谍信息                         |)" << endl;
		if (cnt == 3)
			cout << R"(|            ==> 3. 删除间谍信息                         |)" << endl;
		else
			cout << R"(|                3. 删除间谍信息                         |)" << endl;
		if (cnt == 4)
			cout << R"(|            ==> 4. 修改间谍信息                         |)" << endl;
		else
			cout << R"(|                4. 修改间谍信息                         |)" << endl;
		if (cnt == 5)
			cout << R"(|            ==> 5. 查找间谍信息                         |)" << endl;
		else
			cout << R"(|                5. 查找间谍信息                         |)" << endl;
		if (cnt == 6)
			cout << R"(|            ==> 6. 按编号排序	                         |)" << endl;
		else
			cout << R"(|                6. 按编号排序	                         |)" << endl;
		if (cnt == 7)
			cout << R"(|            ==> 7. 清空所有文档                         |)" << endl;
		else
			cout << R"(|                7. 清空所有文档                         |)" << endl;
		cout << R"(|                                                        |)" << endl;
		cout << R"(|                请输入选项:)" << cnt << R"(                            |)" << endl;
		cout << R"(|________________________________________________________|)" << endl;
		c1 = _getch();
		if (c1 == 13) // enter
			return cnt;
		if (c1 >= 49 && c1 < 56)
			return c1 - 48;
		c2 = _getch();
		switch (c2) {
		case 72: // up
			--cnt;
			break;
		case 80: // down
			++cnt;
			break;
		case 75: // left
		case 77: // right
			return cnt;
		}
		system("cls");
	}
}


void Control::ExitSystem() const {
	system("cls");
	cout << R"( ________________________________________________________)" << endl
		<< R"(|　By_Quanwei                               [－][口][×]| |)" << endl
		<< R"(|________________________________________________________|)" << endl
		<< R"(|                   Are you sure quit?                   |)" << endl
		<< R"(|                                                        |)" << endl
		<< R"(|                                                        |)" << endl
		<< R"(|                        ----------                      |)" << endl
		<< R"(|                       |    YES   |                     |)" << endl
		<< R"(|                        ----------                      |)" << endl
		<< R"(|________________________________________________________|)" << endl;
	system("pause");
	cout << "欢迎下次使用 :)" << endl;
	exit(0);
}


void Control::AddSpy() {
	int add_num, not_added{ 0 };
	cout << "请输入要添加的间谍人数:";
	cin >> add_num;
	if (add_num > 0) {
		//添加新的
		for (int i = 0; i < add_num; ++i) {
			string name;
			int id, dep, gender;
			float credit;
			cout << "请输入第" << i + 1 << "个间谍的编号 姓名 诚信度" << endl;
			cin >> id >> name >> credit;
			cout << "请选择间谍的性别: 1. 男\t2.女 ";
			cin >> gender;
			cout << "\n请选择间谍的学院: 1. 本科间谍部\t2.研究间谍部 ";
			cin >> dep;
			if (IsExist(id) != -1) {
				cout << "编号重复,添加失败! :(" << endl;
				++not_added;
				continue;
			}
			SubAdd(id, name, gender, credit, dep);
		}
		//保存数据
		this->Save();
		this->isEmpty = false;
		//提示添加成功
		cout << "成功添加" << add_num - not_added << "位间谍" << endl;
	}
	else
		cout << "输入有误" << endl;
	system("pause");
	system(("cls"));
}

void Control::SubAdd(int id, string name, int gender, float credit, int dep) {
	Spy* spy = nullptr;
	switch (dep) {
	case 1:
		spy = new Undergraduate(id, name, gender, credit, dep);
		break;
	case 2:
		spy = new Postgraduate(id, name, gender, credit, dep);
		break;
	default:
		break;
	}
	//保存到vector中
	this->m_spy_vector.push_back(spy);
}


void Control::Save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (auto&& i : this->m_spy_vector) {
		ofs << i->m_id << '\t'
			<< i->m_name << '\t'
			<< i->m_gender << '\t'
			<< i->m_credit << '\t'
			<< i->m_dep_id << endl;
	}
	ofs.close();
}


void Control::Init() {
	ifstream ifs;
	string name;
	int id, dep, gender;
	float credit;
	ifs.open(FILENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs >> gender && ifs >> credit && ifs >> dep) {
		SubAdd(id, name, gender, credit, dep);
	}
	ifs.close();
	cout << R"( _____              _____                                          _ )" << endl
		<< R"((_____)            (_____)                _                  ____ (_))" << endl
		<< R"((_)__(_) _   _    (_)   (_) _   _   ____ (_)__   _   _   _  (____) _ )" << endl
		<< R"((_____) (_) (_)   (_)   (_)(_) (_) (____)(____) (_) ( ) (_)(_)_(_)(_))" << endl
		<< R"((_)__(_)(_)_(_)   (_)___(_)(_)_(_)( )_( )(_) (_)(_)_(_)_(_)(__)__ (_))" << endl
		<< R"((_____)  (____)    (___(__) (___)  (__)_)(_) (_) (__) (__)  (____)(_))" << endl
		<< R"(          __(_)          (_)                                         )" << endl
		<< R"(         (___)                                                       )" << endl;
}


void Control::ShowAll() const {
	cout << R"(██████╗ ██╗   ██╗ █████╗ ███╗   ██╗██╗    ██╗███████╗██╗	)" << endl
		<< R"(██╔═══██╗██║   ██║██╔══██╗████╗  ██║██║    ██║██╔════╝██║)" << endl
		<< R"(██║   ██║██║   ██║███████║██╔██╗ ██║██║ █╗ ██║█████╗  ██║)" << endl
		<< R"(██║▄▄ ██║██║   ██║██╔══██║██║╚██╗██║██║███╗██║██╔══╝  ██║)" << endl
		<< R"(╚██████╔╝╚██████╔╝██║  ██║██║ ╚████║╚███╔███╔╝███████╗██║)" << endl
		<< R"( ╚══▀▀═╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚══╝╚══╝ ╚══════╝╚═╝)" << endl;
	if (isEmpty)
		cout << "文件为空! :(" << endl;
	else {
		for (auto&& i : this->m_spy_vector)
			//i->ShowInfo();
			cout << i;
	}
	system("pause");
	system("cls");
}


void Control::DeleteSpy() {
	int id, ret;
	cout << "请输入id:";
	cin >> id;
	ret = IsExist(id);
	if (ret == -1)
		cout << "没有找到 :(" << endl;
	else {
		cout << "找到: \n";
		m_spy_vector[ret]->ShowInfo();
		cout << "确定删除吗? 1. 确定, 2. 取消 : ";
		int choice;
		cin >> choice;
		if (choice == 1) {
			delete m_spy_vector[ret];
			for (size_t i = ret + 1; i < m_spy_vector.size(); ++i)
				m_spy_vector[i - 1] = m_spy_vector[i];
			m_spy_vector.pop_back();
			this->Save();
			cout << "删除成功 :)" << endl;
		}
		else
			cout << "什么事情都没做" << endl;
	}
	system("pause");
	system("cls");
}


int Control::IsExist(int id) const {
	for (size_t i = 0; i < this->m_spy_vector.size(); ++i)
		if (m_spy_vector[i]->m_id == id)
			return i;
	return -1;
}


void Control::Modify() {
	if (isEmpty)
		cout << "文件记录为空! :(" << endl;
	else {
		cout << "请输入要修改的间谍的编号: ";
		int id, ret;
		cin >> id;
		ret = IsExist(id);
		if (ret != -1) { //find
			cout << "查到:\n";
			m_spy_vector[ret]->ShowInfo();
			delete this->m_spy_vector[ret];

			int dep, gender;
			string name;
			float credit;

			cout << "请输入新的姓名 诚信度" << endl;
			cin >> name >> credit;
			cout << "请选择间谍的性别: 1. 男\t2.女 ";
			cin >> gender;
			cout << "\n请选择间谍的学院: 1. 本科生院\t2.研究生院 ";
			cin >> dep;
			;
			Spy* s = nullptr;
			if (dep == 1)
				s = new Undergraduate(id, name, gender, credit, dep);
			else if (dep == 2)
				s = new Postgraduate(id, name, gender, credit, dep);
			this->m_spy_vector[ret] = s;
			this->Save();
			cout << "间谍 id: " << id << "修改成功" << endl;
		}
		else
			cout << "查无此人,修改失败! :(" << endl;
	}
	system("pause");
	system("cls");
}


void Control::Find() const {
	if (isEmpty)
		cout << "文件记录为空! :(" << endl;
	else {
		cout << "请输入查找方式: " << '\n'
			<< "1. 按编号查找 " << '\n'
			<< "2. 按姓名查找" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			int id, ret;
			cout << "请输入要查找的间谍的编号:";
			cin >> id;
			ret = IsExist(id);
			if (ret == -1)
				cout << "查无此人! :(" << endl;
			else {
				cout << "查找成功! :)\n";
				m_spy_vector[ret]->ShowInfo();
			}
		}
		else if (choice == 2) {
			string name;
			bool flag{ false };
			cout << "请输入要查找的间谍的姓名:";
			cin >> name;
			for (auto&& i : m_spy_vector) {
				if (i->m_name == name) {
					cout << "查找成功! :)\n";
					i->ShowInfo();
					flag = true;
				}
			}
			if (!flag)
				cout << "查无此人! :(" << endl;
		}
		else {
			cout << "你输入的有误! :(" << endl;
		}
	}
	system("pause");
	system("cls");
}


void Control::SortSpyId() {
	cout << "请选择排序方式(按编号):\n"
		<< "1. 由小到大\n"
		<< "2. 由大到小" << endl;
	int choice;
	cin >> choice;
	std::sort(m_spy_vector.begin(), m_spy_vector.end(), [choice](Spy* i, Spy* j) {
		if (choice == 2)
			return i->m_id > j->m_id;
		return i->m_id < j->m_id;
		});
	this->Save();
	this->ShowAll();
	system("pause");
	system("cls");
}


void Control::Clear() {
	string cs;
	cout << "你真的要清除全部文档记录吗?(不可恢复!)\n"
		<< "确认请输入yes: ";
	cin >> cs;
	if (cs == string{ "yes" }) {
		this->~Control();
		this->Save();
		cout << "成功清除全部文档记录 :)" << endl;
	}
	else
		cout << "没有发生任何事 :)" << endl;
	system("pause");
	system("cls");
}

void Control::ShowCNMBless() const {
	system("cls");
	char str[] = { "Code is far away from bug with the animal protecting\n" };
	for (int i = 0; str[i] != '\0'; ++i) {
		cout << str[i];
		Sleep(50);
	}
	ifstream in(R"(txt\clf_egg.txt)", ios::in);
	char buf[256];
	while (in.getline(buf, sizeof(buf))) {
		cout << buf << endl;
		Sleep(100);
	}
	system("pause");
	system("cls");
}

void Control::ShowCopyRight() const {
	system("cls");
	char str[] = { "© 2002–2099 Copyright Tang Quanwei, Inc. All rights reserved." };
	for (int i = 0; str[i] != '\0'; ++i) {
		cout << str[i];
		Sleep(1);
	}
	cout << '\n';
	ifstream in(R"(txt\Copyright.txt)", ios::in);
	char buf[256];
	while (in.getline(buf, sizeof(buf))) {
		cout << buf << endl;
		Sleep(100);
	}
	system("pause");
	system("cls");
}

void Control::ShowQuote() const {
	system("cls");
	ifstream in(R"(txt\quote.txt)", ios::in);
	char buf[256];
	int cnt = 0;
	while (in.getline(buf, sizeof(buf))) {
		cout << buf << endl;
		if (cnt > 25)
			Sleep(300);
		++cnt;
	}
	system("pause");
	system("cls");
}

void Control::ShowMyName() const {
	system("cls");
	ifstream ifs(R"(txt\name.txt)", ios::in);
	char buf[256];
	for (int i = 1; ifs.getline(buf, sizeof(buf)); ++i) {
		cout << buf << endl;
		if (i % 11 == 0) {
			Sleep(500);
			system("cls");
		}
	}
	system("pause");
	system("cls");
}

void Control::ProgressBar(bool isOn) const {
	if (isOn)
	{
		constexpr int len = 100 / 4;
		for (int i = 0; i <= len; i++) {
			system("cls");
			cout << "\n正在加载数据...... \n";
			cout << '[';
			for (int j = 0; j <= i; ++j)
				cout << (j == i ? '>' : '=');
			for (int j = 0; j < len - i; ++j)
				cout << ' ';
			cout << ']' << i * 4 << "%" << endl;
			Sleep((len - 4 * i) > 0 ? len - 4 * i : 10);
		}
	}
	cout << "数据加载成功" << endl;
}
