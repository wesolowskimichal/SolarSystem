#pragma once
template<typename T>
class Array{
private:
	T* arr;
	unsigned int size{};
public:
	Array();
	Array(unsigned int size);
	~Array();
	void push(T* obj);
};

