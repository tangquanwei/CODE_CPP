#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__
template <class T>
class ArrayList {
private:
	T* array = nullptr;
	size_t capacity;
	size_t cur;
	const static size_t DEFAULT_LENGTH;

public:
	ArrayList() {
		create(DEFAULT_LENGTH);
	}
	ArrayList(size_t n) {
		create(n);
	}
	ArrayList& create(size_t n) {
		capacity = n;
		cur = 0;
		array = new T[n];
		memset(array, 0, n * sizeof(T));
		return *this;
	}
	ArrayList& recreate() {
		T* a = new T[capacity * 2];
		memset(a, 0, capacity * 2 * sizeof(T));
		for (size_t i = 0, l = capacity; i < l; i++) {
			a[i] = array[i];
		}
		capacity *= 2;
		delete[] array;
		array = a;
		return *this;
	}
	size_t size() {
		return cur;
	}

	long long indexOf(const T& t) {
		for (size_t i = 0; i < cur; i++) {
			if (array[i] == t)
				return i;
		}
		return -1ll;
	}
	long long lastIndexOf(const T& t) {
		for (long long i = cur - 1; i >= 0; i--) {
			if (array[i] == t)
				return i;
		}
		return -1ll;
	}
	T& at(size_t i) {
		if (i >= capacity || i < 0)
			throw "Exception : Index out of range!";
		return array[i];
	}
	void add(const T& t) {
		if (cur == capacity)
			recreate();
		array[cur++] = t;
	}
	void insert(size_t i, const T& t) {
		if (cur >= capacity)
			recreate();
		for (size_t k = cur; k > i; k--) {
			array[k] = array[k - 1];
		}
		array[i] = t;
		cur++;
	}
	T remove(size_t i) {
		if (i >= capacity || i < 0)
			throw "Exception : Index out of range :(";
		T t = move(array[i]); // 不能返回引用
		for (size_t k = i; k < cur - 1; k++) {
			array[k] = array[k + 1];
		}
		--cur;
		return t;
	}
	bool empty() {
		return cur == 0 ? true : false;
	}
	~ArrayList() {
		delete[] array; // 还可以调用?
		array = nullptr;
	}
	friend std::ostream& operator<<(std::ostream& os, const ArrayList& l) {
		if (l.array != nullptr)
			for (size_t i = 0; i < l.cur; i++) {
				os << *(l.array + i) << " ";
			}
		else
			os << "null ";
		return os;
	}
	friend std::ostream& operator<<(std::ostream& os, const ArrayList* l) {
		if (l->array != nullptr)
			for (size_t i = 0; i < l->cur; i++) {
				os << *(l->array + i) << " ";
			}
		else
			os << "null ";
		return os;
	}
};
template <class T>
const size_t ArrayList<T>::DEFAULT_LENGTH = 8;

#endif