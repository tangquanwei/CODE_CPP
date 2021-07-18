#include <iostream>
#include <fstream>
#include <vector>
#include "main.h"

using std::cin;
using std::cout;
using std::endl;

constexpr int BUF_SIZE = 1024;
constexpr char PATH[] = "./student_info.txt";

namespace data {
	std::vector<Student*> vs; //*vector 放Student*
}

int main() {
	if (!load())
		exit(1);
	int choice;
	std::vector<bool (*)()> v_func{ add, del, modify, search, show_all, save };
	int n = 10;
	bool ret;
	do {
		show_menu();
		cin >> choice;
		try {
			if ((int)choice > 6 || (int)choice < 1)
				throw "整数1-6";
			ret = v_func[choice - 1]();
		}
		catch (const char* e) {
			cout << e << endl;
		}
	} while (--n);

	return 0;
}

inline Student::Student(std::string name, unsigned age = 18, size_t stu_id = 0)
	: name(name), age(age), stu_id(stu_id) {
	std::string course;
	unsigned grade;
	unsigned n;
	cout << "请输入课程数: " << endl;
	cin >> n;
	while (n--) {
		cout << "请输入课程(空格)成绩: " << endl;
		cin >> course >> grade;
		scores[course] = grade;
	}
}
inline void Student::show_scores() {
	if (!scores.empty())
		for (auto&& i : scores)
			cout << "课程: " << i.first << "\t成绩: " << i.second << endl;
	else
		cout << "还没有相关课程信息" << endl;
}
inline void Student::show_info() { cout << "姓名: " << name << "\n年龄: " << age << endl; }
inline size_t Student::get_stu_id() { return this->stu_id; }
inline Student* Student::ths() { return this; }
inline std::map<std::string, unsigned>* Student::get_scores() { return &scores; }

inline void show_menu() {
	cout << "1.添加学生信息\n2.删除学生信息\n3.修改学生信息\n4.查询学生信息\n5.显示所有学生信息\n6.退出\n请输入选择(1-6): " << endl;
}

bool add() {
	unsigned n, age;
	std::string name;
	size_t stu_id;
	cout << "有多少个学生？";
	cin >> n;
	while (n--) {
		cout << "请输入名字(空格)年龄(空格)学号:" << endl;
		cin >> name >> age >> stu_id;
		Student* s = new Student(name, age, stu_id);
		data::vs.push_back(s);
	}
	return true;
}

bool modify() {
	size_t id;
	cout << "请输入学号:";
	cin >> id;
	for (auto&& i : data::vs)
		if (i->get_stu_id() == id) {
			std::string course;
			unsigned grade;
			auto scores = i->get_scores();
			cout << "请输入课程(空格)成绩: " << endl;
			cin >> course >> grade;
			(*scores)[course] = grade;
			return true;
		}
	cout << "请输入正确的学号" << endl;
	return false;
}

bool search() {
	size_t id;
	cout << "请输入学号:";
	cin >> id;
	for (auto&& i : data::vs)
		if (i->get_stu_id() == id) {
			i->show_info();
			return true;
		}
	cout << "没找到" << endl;
	return false;
}

bool del() {
	size_t id;
	cout << "请输入学号:";
	cin >> id;
	for (int i = 0; i < data::vs.size(); ++i)
		if (data::vs[i]->get_stu_id() == id) {
			delete data::vs[i]->ths();
			data::vs.erase(data::vs.begin() + i, data::vs.begin() + i + 1);
			return true;
		}
	return false;
}

bool show_all() {
	if (data::vs.empty())
		return false;
	for (auto&& i : data::vs) {
		i->show_info();
		i->show_scores();
	}
	return true;
}

bool save() {

	std::ofstream ofs(PATH, std::ios::app | std::ios::binary);

	for (auto&& i : data::vs) {
		ofs.write((const char*)i, sizeof(Student));
		delete i;
	}
	ofs.close();
	exit(0);
	return true; // not used
}
bool load() {
	std::fstream ifs;
	ifs.open(PATH, std::ios::in | std::ios::binary);
	// todo 流对象 -> vector_student*
	Student* q = new Student;
	char buf[BUF_SIZE];
	while (ifs.read(buf, BUF_SIZE)) {
		q = (Student*)buf;
		q->show_info();
		data::vs.push_back(q);
	}
	ifs.close();
	return true;
}