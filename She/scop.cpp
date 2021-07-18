// date.h
#pragma once
#ifndef __DATE_H__
#define	__DATE_H__
#include <iostream>

class Date		// ������
{
public:
	Date(int year = 1, int month = 1, int day = 1);		// ���ꡢ�¡��չ�������
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;			// �жϵ����ж�����
	bool isLeapYear() const			// �жϵ����Ƿ�Ϊ����
	{
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
	void show() const;				// �����ǰ����

	// ������������֮��������
	int operator-(const Date &date) const	
	{
		return totalDays - date.totalDays;
	}

	// �ж��������ڵ�ǰ��˳��
	bool operator<(const Date &date) const
	{
		return totalDays < date.totalDays;
	}
private:
	int year;
	int month;
	int day;
	int totalDays;		// �������Ǵӹ�Ԫ 1 �� 1 �տ�ʼ�ĵڼ���
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
	// namespace ʹ����Ķ���ֻ�ڵ�ǰ�ļ�����Ч
	// �洢ƽ���е�ĳ���� 1 ��֮ǰ�ж����죬Ϊ���� getMaxDay  ������ʵ�֣���������һ��
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

class Accumulator	// ��ĳ����ֵ�����ۼ�
{
public:
	// ���캯����date Ϊ��ʼ�ۼӵ����ڣ�value Ϊ��ʼֵ
	Accumulator(const Date &date, double value): lastDate(date), value(value), sum(0){}
	// ������� date ���ۼӽ��
	double getSum(const Date &date) const
	{
		return sum + value * (date - lastDate);
	}
	// �� date ����ֵ���Ϊ value
	void change(const Date &date, double value)
	{
		sum = getSum(date);
		lastDate = date;
		this->value = value;
	}
	// ��ʼ���������ڱ�Ϊ date����ֵ��Ϊ value���ۼ�������
	void reset(const Date &date, double value)
	{
		lastDate = date;
		this->value = value;
		sum = 0;
	}
private:
	Date lastDate;	// �ϴα����ֵ������
	double value;	// ��ֵ�ĵ�ǰֵ
	double sum;		// ��ֵ�����ۼ�ֵ
	
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
class Account;				// ǰ������


class AccountException : public std::runtime_error
{
private:
	const Account *account;
public:
	AccountException(const Account *account, const std::string &msg)
		:runtime_error(msg), account(account) {}
	const Account *getAccount() const { return account; }
};


class AccountRecord			// ��Ŀ��¼
{
private:
	Date date;				// ����
	const Account *account; // �˻�
	double amount;			// ���
	double balance;			// ���
	string desc;			// ����
public:
	// ���캯��
	AccountRecord(const Date &date, const Account *account, double amount, 
		double balance, const string &desc);
	void show() const;		// �����ǰ��¼
};

// ���������洢��Ŀ��¼�Ķ���ӳ������
typedef multimap<Date, AccountRecord>RecordMap;

class Account	// �˻���
{
private:
	string id;				// �˺�
	double balance;			// ���
	static double total;	// �����˻����ܽ��
	static RecordMap recordMap;		// ��Ŀ��¼

protected:
	// ����������õĹ��캯����id Ϊ�˻�
	Account(const Date &date, const string &id);
	// ��¼һ���ˣ�date Ϊ���ڣ� amount Ϊ�� desc Ϊ˵��
	void record(const Date &date, double amount, const string &desc);
	// ���������Ϣ
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
	// �����ֽ�date Ϊ���ڣ�amount Ϊ��desc Ϊ����˵��
	virtual void deposit(const Date &date, double amount, const string &desc) = 0;
	// ȡ���ֽ�date Ϊ���ڣ�amount Ϊ��desc Ϊ����˵��
	virtual void withdraw(const Date &date, double amount, const string &desc) = 0;
	// ���㣨������Ϣ����ѵȣ���ÿ�½���һ�Σ�date Ϊ��������
	virtual void settle(const Date &date) = 0;
	// ��ʾ�˻���Ϣ
	virtual void show(std::ostream &out) const;
	//��ѯָ��ʱ���ڵ���Ŀ��¼
	static void query(const Date &begin, const Date &end);
};

class SavingAccount : public Account	// �����˻���
{
private:
	Accumulator acc;		// ����������Ϣ���ۼ���
	double rate;			// ����������
public:
	// ���캯��
	SavingAccount(const Date &date, const string &id, double rate);
	double getRate() const { return rate; }
	// �����ֽ�
	void deposit(const Date &date, double amount, const string &desc);
	// ȡ���ֽ�
	void withdraw(const Date &date, double amount, const string &desc);
	void settle(const Date &date);		// ������Ϣ��ÿ�� 1 �� 1 �յ���һ�θú���
};

class CreditAccount : public Account	// �����˻���
{
private:
	Accumulator acc;		// ����������Ϣ���ۼ���
	double credit;			// ���ö��
	double rate;			// Ƿ���������
	double fee;				// ���ÿ����
	double getDebt() const	// ���Ƿ���
	{
		double balance = getBalancee();
		return (balance < 0 ? balance : 0);
	}
public:
	// ���캯��
	CreditAccount(const Date &date, const string &id, double credit, double rate, double fee);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const	// ��ÿ������ö��
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
	// �����ֽ�
	void deposit(const Date &date, double amount, const string &desc);
	// ȡ���ֽ�
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

//Account ���ʵ��
RecordMap Account::recordMap;
Account::Account(const Date & date, const string & id) : id(id), balance(0)
{
	cout << date << "\t#" << id << "  created" << endl;
}

void Account::record(const Date & date, double amount, const string & desc)
{
	amount = floor(amount * 100 + 0.5) / 100;		// ����С�������λ
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

// SavingAccount ����س�Ա������ʵ��
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

// CreditAccount ����س�Ա������ʵ��
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

// AccountRecord ���ʵ��
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

class Controller				// �������������洢�˻��б�ʹ�������
{
private:
	Date date;					// ��ǰ����
	vector<Account*>accounts;	// �˻��б�
	bool end;					// �û��Ƿ��������˳�ָ��

public:
	Controller(const Date &date) : date(date), end(false) {}
	~Controller();
	const Date &getDate() const { return date; }
	bool isEnd() const { return end; }

	// ִ��һ��������ظ������Ƿ�ı��˵�ǰ״̬�����Ƿ���Ҫ��������
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
	case 'a':		// �����˻�
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

	case 'd':		// �����ֽ�
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->deposit(date, amount, desc);
		return true;

	case 'w':		// ȡ���ֽ�
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->withdraw(date, amount, desc);
		return true;

	case 's':		// ��ѯ���˻���Ϣ
		for (size_t i = 0; i < accounts.size(); i++)
		{
			cout << "[" << i << "]";
			accounts[i]->show(cout);
			cout << endl;
		}
		return false;

	case 'c':		// �ı�����
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

	case 'n':		// �����¸���
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

	case 'q':		// ��ѯһ��ʱ���ڵ���Ŀ
		str >> date1 >> date2;
		Account::query(date1, date2);
		return false;
	case 'e':		// �˳�
		end = true;
		return false;
	}
	cout << "Invalid command: " << cmdLine << endl;
	return false;
}

int main()
{
	Date date(2008, 11, 1);		// ��ʼ����
	Controller controller(date);
	string cmdLine;
	const char *FILE_NAME = "command.txt";
	ifstream fileIn(FILE_NAME);		// ��ֻ����ʽ���ļ�
	if (fileIn)					// ��������򿪣���ִ���ļ���ÿһ��ָ��
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
		fileIn.close();			// �ر��ļ�
	}

	ofstream fileOut(FILE_NAME, ios_base::app);		// ��׷�ӷ�ʽ���ļ�
	cout << "(a) add account (d) deposit (w) withdraw (s) show (c) change day (n) next month (q)query(e) exit" << endl;
	while (! controller.isEnd())	// �ӱ�׼����������ֱ���˳�
	{
		cout << controller.getDate() << "\tTotal: " << Account::getTotal() << "\tcommand>";
		string cmdLine;
		getline(cin, cmdLine);
		try
		{
			if (controller.runCommand(cmdLine))
			{
				fileOut << cmdLine << endl; // ������д���ļ�
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


