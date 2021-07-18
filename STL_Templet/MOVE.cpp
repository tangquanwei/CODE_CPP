#include <iostream>
#include <list>
#include <vector>
#include <cstring>

using namespace std;

template <class T>
void process(T& t) {
	cout << "pass by &  =" << t << endl;
}

template <class T>
void process(T&& t) { //named object
	cout << "pass by && =" << t << endl;
	process(t); //t变成了左值 --> 不完美的转发
}

class MyString {
public:
	static size_t DCtor; //default ctor
	static size_t Ctor;
	static size_t CCtor;
	static size_t CAsign;
	static size_t MCtor;
	static size_t MAsign;
	static size_t Dtor;

private:
	char* data;
	size_t len;
	void init_data(const char* s) {
		data = new char[len + 1];
		memcpy(data, s, len);
		data[len] = '\0';
	}

public:
	MyString() : data(nullptr), len(0) { ++DCtor; }
	MyString(const char* p) : len(strlen(p)) {
		++Ctor;
		init_data(p);
	};
	MyString(const MyString& str) : len(str.len) {
		++CCtor;
		init_data(str.data);
	}
	MyString(MyString&& str) noexcept
		: data(str.data), len(str.len) {
		++MCtor;
		str.data = nullptr; //!重要 没有这一步 临时对象的值会被 Dtor delete
		str.len = 0;
	}

	MyString& operator=(const MyString& str) {
		++CAsign;
		if (*this != str) { // 自我赋值检查
			if (data)
				delete data;
			len = str.len;
			init_data(str.data);
		}
		return *this;
	}
	MyString& operator=(MyString&& str) noexcept {
		++MAsign;
		if (*this != str) { // 自我赋值检查
			if (data)
				delete data;
			len = str.len;
			data = str.data; // 指针
			str.data = nullptr;
			str.len = 0;
		}
		return *this;
	}
	virtual ~MyString() {
		++Dtor;
		if (data)
			delete data;
	}
	bool operator<(const MyString& rhs) const { //for set
		return string(this->data) < string(rhs.data);
	}
	bool operator==(const MyString& rhs) const {
		return string(this->data) == string(rhs.data);
	}
	bool operator!=(const MyString& rhs) const {
		return string(this->data) != string(rhs.data);
	}
	char* get() const { return data; }
};
size_t MyString::DCtor; //default ctor
size_t MyString::Ctor;
size_t MyString::CCtor;
size_t MyString::CAsign;
size_t MyString::MCtor;
size_t MyString::MAsign;
size_t MyString::Dtor;



int main() {
	//have a pointer
	// string s1, s2;
	// s1 + s2 = "hello";
	// cout << "s1: " << s1 << endl;
	// cout << "s2: " << s2 << endl;
	// string() = "world";

	/* 	 lvalue -> move -> rvalue*/
	// process(1);
	// int a = 9;
	// process(a);
	// process(move(a));

	vector<MyString> vs1, vs2;
	vs1.push_back(MyString("hello"));
	vs2.swap(vs1);
	cout << vs2.at(0).get()<<endl;
	cout<<__cplusplus<<endl;
	return 0;
}