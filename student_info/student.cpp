#include "student.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memoary>
#include <vector>
using namespace std;

constexpr char PATH[]{ "./student" };
constexpr int SIZE{ 256 };

vector<unique_ptr<Student>> up_student_vector;

void synchronize() {
	ofstream ofs(PATH, ios_base::out, ios_base::binary);
	for_each(up_student_vector.begin(), up_student_vector.end(), [](auto i) {
		ofs.write((char*)&(*i), SIZE);
	})
}
void load(){
    ifstream ifs(PATH, ios_base::in,ios_base::binary);
    char buf[SIZE];
    while(ifs.read(buf,SIZE)){
        (unique_ptr<Student>*)buf;
    }
}

int main() {
	up_student_vector = {
		make_unique<student>(1, "Tang"),
		make_unique<student>(2, "Quanwei")
	}

	return 0;
}