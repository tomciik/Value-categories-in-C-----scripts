#include "performance.h"

int main() {
	//with conversion
	{
		Performance performance;
		for(int i=0; i<1000000; i++)
		{
			int a = 2;
			int b = 3;
			int c = a * b;
		}
	}
	//without conversion
	{
		Performance performance;
		for(int i=0; i<1000000; i++)
		{
			int c = 2 * 3;
		}
	}
}
