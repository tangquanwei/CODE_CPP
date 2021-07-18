#include <algorithm>
#include <iostream>
#include <list>
#include <typeinfo>
#include <vector>
using namespace std;

template <typename Container>
void test01(Container c) {
	//容器元素类型 = 迭代器的value_type
	using valueType = typename iterator_traits<typename Container::iterator>::value_type;
	cout << typeid(valueType).name() << endl;
}

// template <typename T, template <class> class Container>
// class Test02 { // template template parameter
// private:
// 	Container<T> c;
// pubilc :
//     Test02() {
// 		for (size_t i=0;i<SIZE;++i)
//         c.insert(c.end(),T());

// 	}
// };

auto cmp = [](const int t, const int s) -> int { return t - s; };//加()直接调用

auto hello(){return "adaj";}

int main() {
	test01(list<size_t>());

	// template <typename T>
	// using Vec =vector<T, allocator<T>> ; //在function 外
	// test02<int64_t, > c1;

	vector<decltype(hello)> vc;
	vc.push_back(hello());
	for_each(vc.begin(), vc.end(), [](auto i) { cout << i << "\t"; });


	return 0;
}