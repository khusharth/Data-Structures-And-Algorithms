#include<iostream>
using namespace std;
template <typename T, typename V>

class Pair {
	T x;
	V y;

	public:

	// Setter
	void setX(T x) {
		this -> x = x;
	}

	// Getter
	T getX() {
		return x;
	}

	void setY(V y) {
		this -> y = y;
	}

	V getY() {
		return y;
	}
};

int main() {
	
	Pair<int, double> p1;
	p1.setX(100.34);
	p1.setY(100.34);

	cout << p1.getX() << " " <<p1.getY() << endl;
	}

