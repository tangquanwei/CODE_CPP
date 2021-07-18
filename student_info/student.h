#ifndef STUDENT_H
#define STUDENT_H
#include <string>

struct Scores {
	int math{ 0 };
	int cpp{ 0 };
	int python{ 0 };
	int english{ 0 };
};

class Person {
private:
	int id;
	int age;
	int gender;
	std::string name;

public:
	Person(int id, std::string name) Person(id, 0, 0, name) {}
	Person(int id, int age, int gender, std::string name) : id(id), age(age), gender(gender), name(name) {}
	virtual std::string type() { return "Person"; }
};

class Student : public Person {
	std::string type() { return "Student"; }
}

#endif