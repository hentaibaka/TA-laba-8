#include "include.h"

struct Element {
	string Key;
	t Value;
	Element* Next;
	Element(string key, t value);
};