/**
 * 集合栈计算机（The Set Stack Computer，ACM/ICPC NWERC2006，UVa12096
 * 有一个专门为了集合运算而设计的“集合栈”计算机。该机器有一个初始为空的栈，并且
 * 支持以下操作。
 * PUSH：空集“{}”入栈。
 * DUP：把当前栈顶元素复制一份后再入栈。
 * UNION：出栈两个集合，然后把二者的并集入栈。
 * INTERSECT：出栈两个集合，然后把二者的交集入栈。
 * ADD：出栈两个集合，然后把先出栈的集合加入到后出栈的集合中，把结果入栈
 * 每次操作后，输出栈顶集合的大小（即元素个数）。
 * 例如，栈顶元素是A={{}，{{}}}，下一个元素是B={{}，{{{}}}}，则：
 * UNION操作将得到{{}，{{}}，{{{}}}}，输出3。
 * INTERSECT操作将得到{{}}，输出1。
 * ADD操作将得到{{}，{{{}}}，{{}，{{}}}}，输出3。
 * 输入不超过2000个操作，并且保证操作均能顺利进行（不需要对空栈执行出栈操作）。
 * 【分析】
 * 本题的集合并不是简单的整数集合或者字符串集合，而是集合的集合。为了方便起见，
 * 此处为每个不同的集合分配一个唯一的ID，则每个集合都可以表示成所包含元素的ID集合，
 * 这样就可以用STL的set<int>来表示了，而整个栈则是一个stack<int>。 
 * */
#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
using namespace std;
typedef set<int> Set;
map<Set, int> IDcache; //把集合映射成ID
vector<Set> Setcache;  //根据ID 取集合
//查找给定集合x的ID。如果找不到，分配一个新ID
int ID(Set x) {
	if (IDcache.count(x))
		return IDcache[x];
	Setcache.push_back(x); //添加新集合
	return IDcache[x] = Setcache.size() - 1;
}
stack<int> s; //题目中的栈
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;
		if (op[0] == 'P')
			s.push(ID(Set()));
		else if (op[0] == 'D')
			s.push(s.top());
		else {
			Set x1 = Setcache[s.top()];
			s.pop();
			Set x2 = Setcache[s.top()];
			s.pop();
			Set x;
			if (op[0] == 'U')
				set_union(ALL(x1), ALL(x2), INS(x));
			if (op[0] == 'I')
				set_intersection(ALL(x1), ALL(x2), INS(x));
			if (op[0] == 'A') {
				x = x2;
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
	}
}
