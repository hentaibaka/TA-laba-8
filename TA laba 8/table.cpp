#include "table.h"

Table::Table(unsigned int (*hash)(string), int (*getNextSize)(int i)) {
	GetHash = hash;
	Array = new Element * [Size];

}
bool Table::Add(string key, t value) {
	Element* el = new Element(key, value);

	bool res = AddToArray(el, Array, Size);

	//ResizeArray();

	return res;
}
bool Table::AddToArray(Element* el, Element** array, int size) {
	int hash = GetHash(el->Key);
	int id = GetId(hash, size);

	if (!array[id]) {
		array[id] = el;
	}
	else {
		Element* temp = array[id];
		while (true) {
			if (temp->Key == el->Key) { //если такой ключ уже есть
				return false;
			}
			if (temp->Next) temp = temp->Next;
			else break;
		}
		temp->Next = el;
	}
	return true;
}
bool Table::Delete(string key) {
	int hash = GetHash(key);
	int Id = GetId(hash, Size);

	Element* temp = Array[Id];
	Element* tempPrev = nullptr;

	if (temp) {
		while (temp) {
			if (temp->Key == key) {
				if (tempPrev) tempPrev->Next = temp->Next;
				else Array[Id] = temp->Next;

				delete temp;
				return true;
			}
			tempPrev = temp;
			temp = temp->Next;
		}
	}
	return false;
}
Element* Table::Find(string key) {
	int hash = GetHash(key);
	int Id = GetId(hash, Size);

	Element* temp = Array[Id];
	while (temp) {
		if (temp->Key == key) break;
		temp = temp->Next;
	}
	return temp;
}
bool Table::ChangeValue(string key, t value) {
	Element* temp = Find(key);

	if (!temp) {
		//Add(key, value);
		return false;
	}
	temp->Value = value;
	return true;

}
int Table::GetId(int hash, int size) {
	return hash % size;
}
void Table::Show() {
	cout << "Array size: " << Size << "\n";
	for (int i = 0; i < Size; i++) {
		Element* temp = Array[i];
		if (temp) {
			while (temp) {
				cout << i << ") key: " << temp->Key << " value: " << temp->Value << "\n";
				temp = temp->Next;
			}
		}
		else {
			cout << i << ") ---\n";
		}
	}
	cout << "\n";
}
int Table::Count() {
	int count = 0;
	for (int i = 0; i < Size; i++) {
		Element* temp = Array[i];
		while (temp) {
			count++;
			temp = temp->Next;
		}
	}
	return count;
}
void Table::ResizeArray() {
	float coef = Count() / Size;

	if (coef >= Coef) {

		int newSize = GetNextSize(SizeIt++);
		Element** newArray = new Element*[newSize];
		for (int i = 0; i < newSize; i++) newArray[i] = nullptr;
		Element* temp;
		Element* tempPrev;

		for (int i = 0; i < Size; i++) {

			temp = Array[i];

			while (temp) {

				tempPrev = temp;
				temp = temp->Next;
				tempPrev->Next = nullptr;

				AddToArray(tempPrev, newArray, newSize);

			}
		}
		Array = newArray;
		Size = newSize;
	}
}

