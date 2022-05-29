#include "Array.h"

template<typename T>
Array<T>::Array() {
	arr = new T[size];
}

template<typename T>
Array<T>::Array(unsigned int size) {
	this->size = size;
	arr = new T[size];
}

template<typename T>
Array<T>::~Array() {
	this->size = nullptr;
	delete[] this->arr;
}

template<typename T>
void Array<T>::push(T* obj) {
	delete[] this->arr;
	this->arr = new T[++this->size];
}