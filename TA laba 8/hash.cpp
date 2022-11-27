#include "hash.h"

unsigned int Hash1(string s) {
	int x = 29791, m = 1e9 + 7; // большие простые числа
	unsigned int sum = 0;
	long pow = 1;
	const size_t n = s.length();

	for (int i = 0; i < n; i++) {
		sum = (sum + (unsigned char)(s[i]) * pow) % m;
		pow = (pow * x) % m;
	}

	//cout << "key: " << s << " hash: " << sum << '\n';

	return sum;
}