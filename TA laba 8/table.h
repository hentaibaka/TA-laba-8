#include "element.h"

struct Table {
	Element** Array;
	int Size;
	unsigned int GetHash(string);
	bool Add(string, t);
	bool Delete(string);
	Element* Find(string);
	bool ChangeValue(string, t);
	void Show(bool);
	Table(int);
};
