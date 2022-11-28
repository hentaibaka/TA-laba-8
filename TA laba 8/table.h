#include "element.h"

enum Type {
	LINKING,
	DIRECT_INDEXING,
};

template <Type T>
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
