#include "cpp_design.h"

bool login() {
	string a;
	string b;
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

int main() {
	login();


	ClassManage s; //创建管理系统对象
	char key;	   //key接收一个值，根据key值的不同执行不同的功能
	while (true) {
		try {
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
			default:
				throw "你输入的有误";
			}
		}
		catch (const char* e) {
			cout << e << endl;
		}
		system("pause"); //暂停中止
		system("cls");	 //每次执行完毕，清屏
	}
}
