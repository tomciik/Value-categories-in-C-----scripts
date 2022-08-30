#include "performance.h"

int main() {
	//with temporary materialization
	{
		Performance performance;
		for(int i=0;i<1000000; i++){
			int j = sizeof(1.2);
		}
	}
	//without temporary materialization using lvalue
	{
		Performance performance;
		for(int i=0;i<1000000; i++){
			double k = 1.2;
			int l = sizeof(k);
		}
	}
}
