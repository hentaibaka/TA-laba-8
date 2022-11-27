#include "element.h"

Element::Element(string key, t value) {
	Key = key;
	Value = value;
	Next = nullptr;
}