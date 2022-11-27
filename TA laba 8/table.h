#include "element.h"
template <int T>
struct Table {
private:
	Element** Array;
	int Size;
	unsigned int (*GetHash)(string s);
	int GetId(int hash, int size);
	void ResizeArray();
	int Count();
	bool AddToArray(Element* el, Element** array, int size);
public:
	bool Add(string key, t value);
	bool Delete(string key);
	Element* Find(string key);
	bool ChangeValue(string key, t value);
	void Show();
	Table<T>(unsigned int (*hash)(string));
};
