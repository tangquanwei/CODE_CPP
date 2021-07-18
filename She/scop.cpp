// date.h
#pragma once
#ifndef __DATE_H__
#define	__DATE_H__
#include <iostream>

class Date		// 日期类
{
public:
	Date(int year = 1, int month = 1, int day = 1);		// 用年、月、日构造日期
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;			// 判断当月有多少天
	bool isLeapYear() const			// 判断当年是否为闰年
	{
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	void show() const;				// 输出当前日期

	// 计算两个日期之间差多少天
	int operator-(const Date &date) const	
	{
		return totalDays - date.totalDays;
	}

	// 判断两个日期的前后顺序
	bool operator<(const Date &date) const
	{
		return totalDays < date.totalDays;
	}
private:
	int year;
	int month;
	int day;
	int totalDays;		// 该日期是从公元 1 月 1 日开始的第几天
};
std::istream &operator >> (std::istream &in, Date &date);
std::ostream &operator << (std::ostream &out, const Date &date);

#endif // !__DATE_H__
// date.cpp
#include "date.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

namespace
{
	// namespace 使下面的定义只在当前文件中有效
	// 存储平年中的某个月 1 日之前有多少天，为便于 getMaxDay  函数的实现，该数组多出一项
	const int DAYS_BEFORE_MONTH[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304,
	334, 365 };
}

Date::Date(int year, int month, int day):year(year), month(month), day(day)
{
	if (day <= 0 || day > getMaxDay()) 
	{
		throw runtime_error("Invalid date");
	}
	int years = year - 1;
	totalDays = years * 365 + years / 4 - years / 100 + years / 400
		+ DAYS_BEFORE_MONTH[month - 1] + day;
	if (isLeapYear() && month > 2)
	{
		totalDays++;
	}
}

int Date::getMaxDay() const
{
	if (isLeapYear() && month == 2)
	{
		return 29;
	}
	else
	{
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
	}
}

void Date::show() const
{
	cout << getYear() << "-" << getMonth() << "-" << getDay();
}

std::istream & operator >> (std::istream & in, Date &date)
{
	int year, month, day;
	char c1, c2;
	in >> year >> c1 >> month >> c2 >> day;
	if (c1 != '-' || c2 != '-')
	{
		throw runtime_error("Bad time forman");
	}
	date = Date(year, month, day);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Date &date)
{
	out << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return out;
}
// accumulator.h
#pragma once
#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__
#include "date.h"

class Accumulator	// 将某个数值按日累加
{
public:
	// 构造函数，date 为开始累加的日期，value 为初始值
	Accumulator(const Date &date, double value): lastDate(date), value(value), sum(0){}
	// 获得日期 date 的累加结果
	double getSum(const Date &date) const
	{
		return sum + value * (date - lastDate);
	}
	// 在 date 将数值变更为 value
	void change(const Date &date, double value)
	{
		sum = getSum(date);
		lastDate = date;
		this->value = value;
	}
	// 初始化，将日期变为 date，数值变为 value，累加器清零
	void reset(const Date &date, double value)
	{
		lastDate = date;
		this->value = value;
		sum = 0;
	}
private:
	Date lastDate;	// 上次变更数值的日期
	double value;	// 数值的当前值
	double sum;		// 数值按日累加值
	
};

#endif // !__ACCUMULATOR_H__
// account.h
#pragma once
#include "date.h"
#include "accumulator.h"
#include <string>
#include <map>
#include <istream>
#include <stdexcept>
using namespace std;
class Account;				// 前置声明


class AccountException : public std::runtime_error
{
private:
	const Account *account;
public:
	AccountException(const Account *account, const std::string &msg)
		:runtime_error(msg), account(account) {}
	const Account *getAccount() const { return account; }
};


class AccountRecord			// 账目记录
{
private:
	Date date;				// 日期
	const Account *account; // 账户
	double amount;			// 金额
	double balance;			// 余额
	string desc;			// 描述
public:
	// 构造函数
	AccountRecord(const Date &date, const Account *account, double amount, 
		double balance, const string &desc);
	void show() const;		// 输出当前记录
};

// 定义用来存储账目记录的多重映射类型
typedef multimap<Date, AccountRecord>RecordMap;

class Account	// 账户类
{
private:
	string id;				// 账号
	double balance;			// 余额
	static double total;	// 所有账户的总金额
	static RecordMap recordMap;		// 账目记录

protected:
	// 供派生类调用的构造函数，id 为账户
	Account(const Date &date, const string &id);
	// 记录一笔账，date 为日期， amount 为金额， desc 为说明
	void record(const Date &date, double amount, const string &desc);
	// 报告错误信息
	void error(const string &msg) const;

public:
	const string &getId() const
	{
		return id;
	}
	double getBalancee() const
	{
		return balance;
	}
	static double getTotal()
	{
		return total;
	}
	// 存入现金，date 为日期，amount 为金额，desc 为款项说明
	virtual void deposit(const Date &date, double amount, const string &desc) = 0;
	// 取出现金，date 为日期，amount 为金额，desc 为款项说明
	virtual void withdraw(const Date &date, double amount, const string &desc) = 0;
	// 结算（计算利息、年费等），每月结算一次，date 为结算日期
	virtual void settle(const Date &date) = 0;
	// 显示账户信息
	virtual void show(std::ostream &out) const;
	//查询指定时间内的账目记录
	static void query(const Date &begin, const Date &end);
};

class SavingAccount : public Account	// 储蓄账户类
{
private:
	Accumulator acc;		// 辅助计算利息的累加器
	double rate;			// 存款的年利率
public:
	// 构造函数
	SavingAccount(const Date &date, const string &id, double rate);
	double getRate() const { return rate; }
	// 存入现金
	void deposit(const Date &date, double amount, const string &desc);
	// 取出现金
	void withdraw(const Date &date, double amount, const string &desc);
	void settle(const Date &date);		// 结算利息，每年 1 月 1 日调用一次该函数
};

class CreditAccount : public Account	// 信用账户类
{
private:
	Accumulator acc;		// 辅助计算利息的累加器
	double credit;			// 信用额度
	double rate;			// 欠款的日利率
	double fee;				// 信用卡年费
	double getDebt() const	// 获得欠款额
	{
		double balance = getBalancee();
		return (balance < 0 ? balance : 0);
	}
public:
	// 构造函数
	CreditAccount(const Date &date, const string &id, double credit, double rate, double fee);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const	// 获得可用信用额度
	{
		if (getBalancee() < 0)
		{
			return credit + getBalancee();
		}
		else
		{
			return credit;
		}
	}
	// 存入现金
	void deposit(const Date &date, double amount, const string &desc);
	// 取出现金
	void withdraw(const Date &date, double amount, const string &desc);
	void settle(const Date &date);
	void show(std::ostream &out) const;
};

inline std::ostream &operator<<(std::ostream &out, const Account &account)
{
	account.show(out);
	return out;
}
// account.cpp
#include "account.h"
#include <cmath>
#include <iostream>
#include <utility>
using namespace std;
using namespace std::rel_ops;

double Account::total = 0;

//Account 类的实现
RecordMap Account::recordMap;
Account::Account(const Date & date, const string & id) : id(id), balance(0)
{
	cout << date << "\t#" << id << "  created" << endl;
}

void Account::record(const Date & date, double amount, const string & desc)
{
	amount = floor(amount * 100 + 0.5) / 100;		// 保留小数点后两位
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

void Account::error(const string &msg) const
{
	throw AccountException(this, msg);
}

void Account::show(ostream &out) const
{
	cout << id << "\tBalance: " << balance;
}

void Account::query(const Date & begin, const Date & end)
{
	if (begin <= end)
	{
		RecordMap::iterator iter1 = recordMap.lower_bound(begin);
		RecordMap::iterator iter2 = recordMap.upper_bound(end);
		for (RecordMap::iterator iter = iter1; iter != iter2; ++iter)
		{
			iter->second.show();
		}
	}
}

// SavingAccount 类相关成员函数的实现
SavingAccount::SavingAccount(const Date & date, const string & id, double rate)
	: Account(date, id), rate(rate), acc(date, 0) {}

void SavingAccount::deposit(const Date & date, double amount, const string & desc)
{
	record(date, amount, desc);
	acc.change(date, getBalancee());
}

void SavingAccount::withdraw(const Date & date, double amount, const string & desc)
{
	if (amount > getBalancee())
	{
		error("not enough money");
	}
	else
	{
		record(date, -amount, desc);
		acc.change(date, getBalancee());
	}
}

void SavingAccount::settle(const Date & date)
{
	if (date.getMonth() == 1)
	{
		double interest = acc.getSum(date) * rate
			/ (date - Date(date.getYear() - 1, 1, 1));
		if (interest != 0)
		{
			record(date, interest, "interest");
		}
		acc.reset(date, getBalancee());
	}
}

// CreditAccount 类相关成员函数的实现
CreditAccount::CreditAccount(const Date & date, const string & id, double credit, double rate, double fee)
	:Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0) {}

void CreditAccount::deposit(const Date & date, double amount, const string & desc)
{
	record(date, amount, desc);
	acc.change(date, getDebt());
}

void CreditAccount::withdraw(const Date & date, double amount, const string & desc)
{
	if (amount - getBalancee() > credit)
	{
		error("not enough credit");
	}
	else
	{
		record(date, -amount, desc);
		acc.change(date, getDebt());
	}
}

void CreditAccount::settle(const Date & date)
{
	double interest = acc.getSum(date) * rate;
	if (interest != 0)
	{
		record(date, interest, "interest");
	}
	if (date.getMonth() == 1)
	{
		record(date, -fee, "annual fee");
		acc.reset(date, getDebt());
	}
}

void CreditAccount::show(ostream &out) const
{
	Account::show(out);
	cout << "\tAvailable credit: " << getAvailableCredit();
}

// AccountRecord 类的实现
AccountRecord::AccountRecord(const Date & date, const Account * account, double amount, 
	double balance, const string & desc): date(date), account(account), 
	balance(balance), desc(desc) {}

void AccountRecord::show() const
{
	cout << date << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "account.h"
#include <vector>
#include <algorithm>
using namespace std;

struct deleter
{
	template<class T>
	void operator()(T *p) { delete p; }
};

class Controller				// 控制器，用来存储账户列表和处理命令
{
private:
	Date date;					// 当前日期
	vector<Account*>accounts;	// 账户列表
	bool end;					// 用户是否输入了退出指令

public:
	Controller(const Date &date) : date(date), end(false) {}
	~Controller();
	const Date &getDate() const { return date; }
	bool isEnd() const { return end; }

	// 执行一条命令，返回该命令是否改变了当前状态（即是否需要保存该命令）
	bool runCommand(const string &cmdLine);
};

Controller::~Controller()
{
	for_each(accounts.begin(), accounts.end(), deleter());
}

bool Controller::runCommand(const string &cmdLine)
{
	istringstream str(cmdLine);
	char cmd, type;
	int index, day;
	double amount, credit, rate, fee;
	string id, desc;
	Account *account;
	Date date1, date2;

	str >> cmd;
	switch (cmd)
	{
	case 'a':		// 增加账户
		str >> type >> id;
		if (type == 's')
		{
			str >> rate;
			account = new SavingAccount(date, id, rate);
		}
		else
		{
			str >> credit >> rate >> fee;
			account = new CreditAccount(date, id, credit, rate, fee);
		}
		accounts.push_back(account);
		return true;

	case 'd':		// 存入现金
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->deposit(date, amount, desc);
		return true;

	case 'w':		// 取出现金
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->withdraw(date, amount, desc);
		return true;

	case 's':		// 查询各账户信息
		for (size_t i = 0; i < accounts.size(); i++)
		{
			cout << "[" << i << "]";
			accounts[i]->show(cout);
			cout << endl;
		}
		return false;

	case 'c':		// 改变日期
		str >> day;
		if (day < date.getDay())
		{
			cout << "You cannot specify a previous day";
		}
		else if (day > date.getMaxDay())
		{
			cout << "Invalid day";
		}
		else
		{
			date = Date(date.getYear(), date.getMonth(), day);
		}
		return true;

	case 'n':		// 进入下个月
		if (date.getMonth() == 12)
		{
			date = Date(date.getYear() + 1, 1, 1);
		}
		else
		{
			date = Date(date.getYear(), date.getMonth() + 1, 1);
		}
		for (vector<Account*>::iterator iter = accounts.begin();
			iter != accounts.end(); ++iter)
		{
			(*iter)->settle(date);
		}
		return true;

	case 'q':		// 查询一段时间内的账目
		str >> date1 >> date2;
		Account::query(date1, date2);
		return false;
	case 'e':		// 退出
		end = true;
		return false;
	}
	cout << "Invalid command: " << cmdLine << endl;
	return false;
}

int main()
{
	Date date(2008, 11, 1);		// 起始日期
	Controller controller(date);
	string cmdLine;
	const char *FILE_NAME = "command.txt";
	ifstream fileIn(FILE_NAME);		// 以只读方式打开文件
	if (fileIn)					// 如果正常打开，就执行文件中每一条指令
	{
		while (getline(fileIn, cmdLine))
		{
			try
			{
				controller.runCommand(cmdLine);
			}
			catch (const std::exception &e)
			{
				cout << "Bad line in" << FILE_NAME << ": " << cmdLine << endl;
				cout << "Error: " << e.what() << endl;
				return 1;
			}
		}
		fileIn.close();			// 关闭文件
	}

	ofstream fileOut(FILE_NAME, ios_base::app);		// 以追加方式打开文件
	cout << "(a) add account (d) deposit (w) withdraw (s) show (c) change day (n) next month (q)query(e) exit" << endl;
	while (! controller.isEnd())	// 从标准输入读入命令，直到退出
	{
		cout << controller.getDate() << "\tTotal: " << Account::getTotal() << "\tcommand>";
		string cmdLine;
		getline(cin, cmdLine);
		try
		{
			if (controller.runCommand(cmdLine))
			{
				fileOut << cmdLine << endl; // 将命令写入文件
			}
		}
		catch (AccountException &e)
		{
			cout << "Error(#" << e.getAccount()->getId() << "): " << e.what() << endl;
		}
		catch (const std::exception &e)
		{
			cout << "Error:" << e.what() << endl;
		}
		
	}

	system("pause");
	return EXIT_SUCCESS;
}


