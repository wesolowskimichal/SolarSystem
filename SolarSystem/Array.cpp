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
	this->size = 0;
	delete[] this->arr;
}

template<typename T>
void Array<T>::push(T obj) {
	T* Temp = new T[++this->size];
	std::copy(*T, *(T + this->size - 1), *Temp);
	delete[] this->arr;
	this->arr = new T[this->size];
	std::copy(*Temp, *(Temp + this->size), *arr);
	delete[]  Temp;
}

template<typename T>
T Array<T>::get(unsigned int id) {
	return *(arr + id);
}
