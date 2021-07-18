#ifndef __CONTROL_H__
#define __CONTROL_H__
#include <vector>
#include <memory> // unique_ptr
#include "Spy.h"


class Control {
public:
	//func
	Control();
	~Control();
	int ShowMenu_GetChoice() const;
	void ExitSystem() const;
	void AddSpy();
	void SubAdd(int id, std::string name, int gender, float gpa, int dep);
	void Save();
	void Init();
	void ShowAll() const;
	void DeleteSpy();
	int IsExist(int) const; // id->spy
	void Modify();
	void Find() const;
	void SortSpyId();
	void Clear();
	void ShowCNMBless() const;
	void ShowCopyRight() const;
	void ShowQuote() const;
	void ShowMyName() const;
	void ProgressBar(bool)const;

	//attr
	std::vector<Spy*> m_spy_vector;
	std::vector<std::unique_ptr<Spy>> m_up_spy_vector; //声明
	using ups=std::unique_ptr<Spy>; //alias
	bool isEmpty;
};

#endif