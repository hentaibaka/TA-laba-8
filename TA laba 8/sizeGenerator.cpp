#include "sizeGenerator.h"

int Fib(int n)
{
	static vector<int> c;

	if (n >= c.size()) c.resize(n + 1);

	return n <= 1 ? n : c[n] != 0 ? c[n] : c[n] = Fib(n - 1) + Fib(n - 2);
}