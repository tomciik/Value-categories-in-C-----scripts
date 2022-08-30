#include "performance.h"

using namespace std;

struct T
{
	int inc(int v) 
	{
		v++;
		return v;
	};
};

int main() {
	//with temporary materialization
	{
		Performance performance;
		int a = 1;
		for(int i=0; i<1000000; i++)
		{
			int v = T().inc(a);
		}
	}
	//without temporary materialization calling constructor earlier
	{
		Performance performance;
		int b = 1;
		for(int i=0; i<1000000; i++)
		{
			T t = T();
			int v = t.inc(b);
		}
	}
}
