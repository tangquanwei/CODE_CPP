#ifndef _main_
#define _main_

#include<iostream>
#include<cctype>
#include<vector>
#include<cstdio>

using namespace std;

int my();

unsigned fact(unsigned n);

size_t count_calls();

int reset(int& i);

string::size_type find_char(const string& s, char c, string::size_type& occurs);

void hanoi(char a, char b, char c, int n);

inline void swap(int& a, int& b) {
	a ^= b ^= a ^= b;
}

void output(const int& n);

void output(const double& d);

int add(int a = 10, int b = 10, int c = 10);


#endif
