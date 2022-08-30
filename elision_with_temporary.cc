#include "performance.h"

using namespace std;

class T {   
public:
	T() { cout << "ctor" << endl; }
	~T() { cout << "dtor" << endl; }

	T(const T&) { cout << "copy ctor" << endl; }
	T(T&&) noexcept { cout << "move ctor" << endl; }
	int num;
};

T make(){
	return T();
}

int main() {
	{
		Performance performance;
		int i = make().num;
	}
}
