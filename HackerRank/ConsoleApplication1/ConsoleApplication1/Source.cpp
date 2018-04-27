#include "bits_stdc.h"

namespace {
	class Base {
	public:
		Base() {};
		Base& operator=(const Base& rhs);
	};
	
	class Derived {
	public:
		Derived() {};
		Derived& operator=(const Derived& rhs);
	};

	Base& Base::operator=(const Base& rhs) {
		cout << "In base class assignment";
		return *this;
	};

	Derived& Derived::operator=(const Derived& rhs) {
		cout << "In Derived class assignment";
		return *this;
	};

}

int main__xx() {
	Derived d1, d2;

	d1 = d2;
	return 0;
}