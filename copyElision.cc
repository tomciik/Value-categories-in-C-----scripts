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

int inc(T t)
{
	return t.num++;
}

int main() {
	{
		Performance performance;
		int i = inc(T());	
	}
}
