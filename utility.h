#ifndef MY_TEMPLATES
#define MY_TEMPLATES

#include <iostream>
#include <string>
using namespace std;

class Item {
private:
	int val;

public:
	Item(int v = 0) { val = v; }
	int key() const { return val; }
	void set_key(int v) { val = v; }
	bool operator==(const Item& other) {
		if (val == other.key()) return true;
		return false;
	}
	bool operator!=(const Item& other) {
		if (val != other.key()) return true;
		return false;
	}
	bool operator<=(const Item& other) {
		if (val <= other.key()) return true;
		return false;
	}
	bool operator>=(const Item& other) {
		if (val >= other.key()) return true;
		return false;
	}
	bool operator<(const Item& other) {
		if (val < other.key()) return true;
		return false;
	}
	bool operator>(const Item& other) {
		if (val > other.key()) return true;
		return false;
	}
	Item operator+(const Item& other) { return val + other.key(); }
	Item operator-(const Item& other) { return val - other.key(); }
	Item operator*(const Item& other) { return val * other.key(); }
	Item operator/(const Item& other) { return val / other.key(); }
	void operator=(const Item& other) { val = other.key(); }
};

inline ostream& operator<<(ostream& os, const Item& it) { return os << it.key(); }

template <typename T> void arrayPrint(T* v, int dim) {
	for (int i = 0; i < dim; i++) cout << "[" << v[i] << "] ";
	cout << endl ;
}

template <typename T, typename E> void arrayFill_auto(T* v, int dim, E max_n) {
	T value;
	for (int i = 0; i < dim; i++) {
		value = rand() / (RAND_MAX / max_n);
		v[i] = value;
	}
}

template <typename T> T sum_array(T* v, int dim) {
	T sum = 0;
	for (int i = 0; i < dim; i++) sum += v[i];
	return sum;
}

#endif // !MY_TEMPLATES
