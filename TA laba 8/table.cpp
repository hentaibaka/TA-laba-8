#include "table.h"

Table::Table(int size) {
	Array = new Element*[size];
	for (int i = 0; i < size; i++) Array[i] = nullptr;
	Size = size;
}
unsigned int Table::GetHash(string s) {
	int x = 29791; // большие простые числа
	unsigned int sum = 0;
	long pow = 1;
	const size_t n = s.length();

	for (int i = 0; i < n; i++) {
		sum = (sum + (unsigned char)(s[i]) * pow) % Size;
		pow = (pow * x) % Size;
	}

	//cout << "key: " << s << " hash: " << sum << '\n';

	return sum;
}
bool Table::Add(string key, t value) {
	Element* el = new Element(key, value);
	unsigned int hash = GetHash(el->Key);

	if (!Array[hash]) {
		Array[hash] = el;
	}
	else {
		Element* temp = Array[hash];
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
	unsigned int hash = GetHash(key);

	Element* temp = Array[hash];
	Element* tempPrev = nullptr;

	if (temp) {
		while (temp) {
			if (temp->Key == key) {
				if (tempPrev) tempPrev->Next = temp->Next;
				else Array[hash] = temp->Next;

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
	unsigned int hash = GetHash(key);

	Element* temp = Array[hash];
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
void Table::Show(bool empty) {
	cout << "Array size: " << Size << "\n";
	for (int i = 0; i < Size; i++) {
		Element* temp = Array[i];
		if (temp) {
			while (temp) {
				cout << i << ") key: " << temp->Key << " value: " << temp->Value << "\n";
				temp = temp->Next;
			}
		}
		else if (empty) {
			cout << i << ") ---\n";
		}
	}
	cout << "\n";
}

