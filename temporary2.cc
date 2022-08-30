#include "performance.h"

int add(const int& a, const int& b){
	return a + b;
}

int add2(int&& a, int&& b){
	return a + b;
}

int main() {
	//with temporary materialization using const l-reference
	{
		Performance performance;
		for(int i=0;i<1000000; i++){
			int c = add(1,2);
		}
	}
	//with temporary materialization using r-reference
	{
		Performance performance;
		for(int i=0;i<1000000; i++){
			int c = add2(1,2);
		}
	}
	//without temporary materialization using operator+
	{
		Performance performance;
		for(int i=0;i<1000000; i++){
			int c = 1 + 2;
		}
	}
}
