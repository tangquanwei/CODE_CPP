#ifndef __MAIN_H
#define __MAIN_H

#include <map>
#include <string>

class Student
{
private:
	std::string name{ "q" };
	unsigned age{ 1 };
	size_t stu_id{ 1 };
	std::map<std::string, unsigned> scores;

public:
	explicit Student() = default;
	explicit Student(std::string, unsigned, size_t);
	void show_scores();
	void show_info() ;
	size_t get_stu_id();
	Student* ths();
	std::map<std::string, unsigned>* get_scores();
};

void show_menu();
bool add();
bool del();
bool modify();
bool search();
bool show_all();
bool save();
bool load();

#endif // !__MAIN_H