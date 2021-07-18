#include "Spy.h"
#include <cstdlib> // malloc free
#include <iostream>
#include <string>
using namespace std;

Spy::Spy(int id, std::string& name, int gender, float credit, int dep)
	: m_id(id), m_gender(gender), m_dep_id(dep), m_credit(credit), m_name(name) {}

Spy::Spy(const Spy& s)
{
	this->m_id = s.m_id;
	this->m_gender = s.m_gender;
	this->m_dep_id = s.m_dep_id;
	this->m_credit = s.m_credit;
	this->m_name = s.m_name;
}

Spy::Spy(const Spy* sp)
{
	this->m_id = sp->m_id;
	this->m_gender = sp->m_gender;
	this->m_dep_id = sp->m_dep_id;
	this->m_credit = sp->m_credit;
	this->m_name = sp->m_name;
}

Spy::Spy(Spy&& s) noexcept
{
	this->m_id = s.m_id;
	this->m_gender = s.m_gender;
	this->m_dep_id = s.m_dep_id;
	this->m_credit = s.m_credit;
	this->m_name = move(s.m_name);
}

Spy& Spy::operator=(const Spy& s)
{
	this->m_id = s.m_id;
	this->m_gender = s.m_gender;
	this->m_dep_id = s.m_dep_id;
	this->m_credit = s.m_credit;
	this->m_name = s.m_name;
	return *this;
}

Spy& Spy::operator=(const Spy* sp)
{
	this->m_id = sp->m_id;
	this->m_gender = sp->m_gender;
	this->m_dep_id = sp->m_dep_id;
	this->m_credit = sp->m_credit;
	this->m_name = sp->m_name;
	return *this;
}

Spy& Spy::operator=(Spy&& s) noexcept
//: m_id(s.m_id), m_gender(s.m_gender), m_credit(s.m_credit), m_dep_id(s.m_dep_id), m_name(move(s.m_name))
{
	this->m_id = s.m_id;
	this->m_gender = s.m_gender;
	this->m_dep_id = s.m_dep_id;
	this->m_credit = s.m_credit;
	this->m_name = move(s.m_name);
	return (*this);
}

void Spy::ShowInfo() const
{
	cout << "编号: " << this->m_id << '\t'
		<< "姓名: " << this->m_name << '\t'
		<< "性别: " << (this->m_gender - 1 ? "female" : "male") << '\t'
		<< "诚信度: " << this->m_credit << '\t'
		<< "所属部门: " << this->GetDepName() << endl;
}
std::string Spy::Spy::GetDepName() const
{
	return "LANZHOU_SPY_UNIVERSITY";
}

void* Spy::operator new(size_t size)
{
	Spy* p = (Spy*)malloc(size);
	return p;
}

void Spy::operator delete(void* p)
{
	free(p);
}

std::ostream& operator<<(std::ostream& os, const Spy* s)
{ // global
	os << "编号: " << s->m_id << '\t'
		<< "姓名: " << s->m_name << '\t'
		<< "性别: " << (s->m_gender - 1 ? "female" : "male") << '\t'
		<< "诚信度: " << s->m_credit << '\t'
		<< "所属部门: " << s->GetDepName() << endl;
	return os;
}

Spy::~Spy() = default;

std::string Undergraduate::GetDepName() const
{
	return "本科间谍部门";
}

std::string Postgraduate::GetDepName() const
{
	return "研究间谍部门";
}