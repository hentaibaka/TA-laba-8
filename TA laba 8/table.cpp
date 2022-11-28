#include "table.h"

template <Type T>
Table<T>::Table(int size) {
	Array = new Element*[size];
	for (int i = 0; i < size; i++) Array[i] = nullptr;
	Size = size;
}
template <Type T>
unsigned int Table<T>::GetHash(string s) {
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
template <Type T>
bool Table<T>::Add(string key, t value) {
	Element* el = new Element(key, value);
	unsigned int hash = GetHash(el->Key);

	if (!Array[hash]) {
		Array[hash] = el;
	}
	else if (T == LINKING) {
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
	else if (T == DIRECT_INDEXING) {
		hash = 0;
		while (Array[hash] && hash < Size) hash++;
		if (hash < Size && !Array[hash]) Array[hash] = el;
		else cout << "Невозможно добавить, не осталось свободного места\n";
	}
	return true;
}
template <Type T>
bool Table<T>::Delete(string key) {
	unsigned int hash = GetHash(key);

	Element* temp = Array[hash];
	Element* tempPrev = nullptr;
	if (temp) {
		if (T == LINKING) {
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
		else if (T == DIRECT_INDEXING) {
			if (temp->Key == key) {
				Array[hash] = nullptr;
				delete temp;
			}
			else {
				hash = 0;
				while (hash < Size) {
					if (Array[hash] && Array[hash]->Key == key) break;
					hash++;
				}
				if (hash < Size && Array[hash]->Key == key) {
					temp = Array[hash];
					Array[hash] = nullptr;
					delete temp;
				}
			}
		}
	}
	return false;
}
template <Type T>
Element* Table<T>::Find(string key) {
	unsigned int hash = GetHash(key);

	Element* temp = Array[hash];

	if (T == LINKING) {
		while (temp) {
			if (temp->Key == key) break;
			temp = temp->Next;
		}
	}
	else if (T == DIRECT_INDEXING) {
		if (temp && temp->Key != key) {
			hash = 0;
			while (hash < Size) {
				if (Array[hash] && Array[hash]->Key == key) {
					temp = Array[hash];
					break;
				}
				hash++;
			}
		}
	}
	return temp;
}
template <Type T>
bool Table<T>::ChangeValue(string key, t value) {
	Element* temp = Find(key);

	if (!temp) {
		//Add(key, value);
		return false;
	}
	temp->Value = value;
	return true;

}
template <Type T>
void Table<T>::Show(bool empty) {
	cout << "Array size: " << Size << "\n";
	for (int i = 0; i < Size; i++) {
		Element* temp = Array[i];
		if (temp) {
			while (temp) {
				cout << i << " | key: " << temp->Key << " | value: " << temp->Value << " | should be at: " << GetHash(temp->Key) << "\n";
				temp = temp->Next;
			}
		}
		else if (empty) {
			cout << i << ") ---\n";
		}
	}
	cout << "\n";
}

