#include <functional>
#include <iostream>
using namespace std;
// Variadic Template

/* 1. print */
namespace print {
	void print() {}
	// 特化
	template <typename T, typename... Types>
	void print(const T& firstArg, const Types&... args) {
		cout << typeid(firstArg).name() << ' ' << firstArg << endl;
		print(args...);
	}

	template <typename... Types>
	void print(const Types&... args) {
		cout << 2 << endl;
	}
}

string input(const string& s) {
	cout << s << endl;
	string t;
	cin >> t;
	return t;
}

/* 2. my_printf */
namespace my_printf {
	void my_printf(const char* s) {
		while (*s) {
			if (*s == '%' && *(++s) != '%')
				throw std::runtime_error("invalid string format");
			std::cout << *s++;
		}
	}
	template <typename T, typename... Arges>
	void my_printf(const char* s, T value, Arges... args) {
		while (*s) {
			if (*s == '%' && *(++s) != '%') {
				std::cout << value;
				my_printf(++s, args...);
				return;
			}
			std::cout << *s++;
		}
		throw std::logic_error("extra arguments provided to my_printf");
	}
}
/* 3. max */
namespace max {
	struct __Iter_less_iter {
		template <typename _Iterator>
		bool operator()(_Iterator __it1, _Iterator __it2) const { return *__it1 < *__it2; }
	};
	inline __Iter_less_iter __iter_less_iter() { return __Iter_less_iter(); }
	template <typename _ForwardIterator>
	inline _ForwardIterator max_element(_ForwardIterator __first, _ForwardIterator __last) {
		return __max_element(__first, __last, __iter_less_iter());
	}
	template <typename _ForwardIterator, typename _Compare>
	_ForwardIterator __max_element(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp) {
		if (__first == __last)
			return __first;
		_ForwardIterator __result = __first;
		while (++__first != __last)
			if (__comp(__result, __first))
				__result = __first;
		return __result;
	}
	template <typename _Tp>
	inline _Tp max(initializer_list<_Tp> __l) { return *max_element(__l.begin(), __l.end()); } // 顺序 定义在调用前
}
/* 4. maximum */
namespace maximum {
	template <typename T>
	T maximum(T n) { return n; } //剩一个

	template <typename T, typename... Args>
	T maximum(T n, Args... args) { return std::max(n, maximum(args...)); }
}

/* 5. print_tuple */
namespace print_tuple {
	// IDX index
	template <int IDX, int MAX, typename... Args>
	struct PRINT_TUPLE {
		static void print(std::ostream& os, const tuple<Args...>& t) {
			os << get<IDX>(t) << (IDX + 1 == MAX ? "" : ", ");
			PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
		}
	};

	template <int MAX, typename... Args>
	//                 IDX==MAX
	struct PRINT_TUPLE<MAX, MAX, Args...> {
		static void print(std::ostream& os, const tuple<Args...>& t) {}
	};

	template <typename... Args>
	ostream& operator<<(std::ostream& os, const tuple<Args...>& t) {
		os << '[';
		PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
		return os << ']';
	}
}

/* tuple: recursive inheritance */
namespace my_tuple {
	template <typename... Values>
	class tuple;
	template <>
	class tuple<> {};

	template <typename Head, typename... Tail>
	class tuple<Head, Tail...> : private tuple<Tail...> {
		typedef tuple<Tail...> inherited;

	protected:
		Head m_head;

	public:
		tuple() {}
		tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}
		//       返回值
		/* typename Head::type */
		decltype(m_head) head() { return m_head; }
		inherited& tail() { return *this; } //转型
	};

	void test01() {
		my_tuple::tuple<int, float, string,string> t(12, 12.5, "quanwei","tang");
		cout << "sizeof(t) = " << sizeof(t) << endl;
		cout << t.head() << endl;
		cout << t.tail().head() << endl;
		cout << t.tail().tail().head() << endl;
		cout << t.tail().tail().tail().head() << endl;
	}

}

/* recursive composition */
namespace my_tup {
	template <typename... Values>
	class tup;

	template <>
	class tup<> {};

	template <typename Head, typename... Tail>
	class tup<Head, Tail...> {
		typedef tup<Tail...> composited;

	protected:
		Head m_head;
		composited m_tail; //复合

	public:
		tup() {}
		tup(Head v, Tail... vtail) : m_head(v), m_tail(vtail...) {}
		Head head() { return m_head; }
		composited& tail() { return m_tail; }
	};

	void test01() {
		tup<int, float, string, string> tp(1, 23.4, "Tang", "Quanwei");
		cout << "sizeof(tp) = " << sizeof(tp) << endl;
		cout << tp.head() << endl;
		cout << tp.tail().head() << endl;
		cout << tp.tail().tail().head() << endl;
		cout << tp.tail().tail().tail().head() << endl;
	}
}

int main() {

	// int a = 0;
	// print(1, 2, string("Hello"), "word", 12.5);

	// cout << input("请输入名字:") << endl;
	// my_printf("%s\t%d", "word", 12);

	// cout << max::max({ 1, 3, 9 });

	// cout << maximum::maximum(1, 3, 2, 100, 9) << endl;

	// using namespace print_tuple;
	// cout << make_tuple(1, "Tang", "Quanwei");

	my_tuple::test01();


	my_tup::test01();



	return 0;
}
