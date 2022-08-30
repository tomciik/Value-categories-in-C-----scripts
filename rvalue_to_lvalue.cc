#include <iostream>
#include "performance.h"

using namespace std;
template<typename T>
T& make_lvalue(T&& t){
	cout << __PRETTY_FUNCTION__ << endl;
	return t;
}

void foo(int& a){
	cout << __PRETTY_FUNCTION__ << endl;
}

int main() {
	struct A {int a =1;};
	int&& b = 3;

	foo(make_lvalue(A().a));
	foo(make_lvalue(2));
	foo(make_lvalue(b));
	
}
