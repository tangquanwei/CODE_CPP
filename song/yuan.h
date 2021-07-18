#ifndef YUAN_H
#define YUAN_H

#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Classroom {
public:
	string num;			//教室编号
	string name;		//教室所在教学楼名字
	string desk_number; //教室中课桌数量
	string user;		//教室使用情况
	friend istream& operator>>(istream& in, Classroom& c);
	friend ostream& operator<<(ostream& out, const Classroom& c);
	Classroom() = default;
	Classroom(string nu, string na, string de, string us) {
		num = nu;
		name = na;
		desk_number = de;
		user = us;
	}
	void showInfo() {
		cout << this->num << '\n'
			 << this->name << '\n'
			 << this->desk_number << '\n'
			 << this->user << '\n'
			 << "类型: " << getType()
			 << endl;
	}
	virtual string getType() {
		return "Class Room";
	}
};
//派生出阶梯教室类
class JietiClassRoom : public Classroom {
public:
	JietiClassRoom() = default;
	JietiClassRoom(string num, string name, string desk_number, string user) : Classroom(num, name, desk_number, user) {}
	~JietiClassRoom() {}
	string getType() {
		return "阶梯教室";
	}
};
class CommonClassRoom : public Classroom {
	CommonClassRoom() = default;
	CommonClassRoom(string num, string name, string desk_number, string user) : Classroom(num, name, desk_number, user) {}
	~CommonClassRoom() {}
	string getType() {
		return "阶梯教室";
	};

	class ClassManage {
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

#endif