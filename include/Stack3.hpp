#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

template <typename T>
class Stack
{
private:
	T * array_;
	size_t array_size_;
	size_t count_;

public:
	Stack();
	Stack(const Stack<T>& Object); 
	size_t count() const;
	size_t array_size() const; 
	void push(T const &); 
	void pop();
	T top() 
	T last() const; 
	void print();
	Stack<T>& operator=(const Stack<T>& Object);
	void swap(Stack<T>&); 
	bool empty() const 


};



template <typename T>
Stack<T>::Stack() {
	array_ = nullptr;
	array_size_ = 0;
	count_ = 0;
}


template <typename T>
Stack<T>::Stack(const Stack<T>& Object)
{
	T* temp = new T[Object.array_size_];
	array_size_ = Object.array_size_;
	count_ = Object.count_;
	array_ = temp;

	try
	{
		copy(Object.array_, Object.array_ + count_, array_);
	}

	catch (...)
	{
		cerr << "ERROR" << endl;
		delete[] array_;
		throw;
	}
}


template <typename T>
size_t Stack<T>::count() const {
	return count_;

}


template <typename T>
size_t Stack<T>::array_size() const {
	return array_size_;

}

template <typename T>
void Stack<T>::push(T const& value) {

	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_]();
	}
	else if (array_size_ == count_)
	{

		try {
			array_size_ *= 2;
			T * array_new = new T[array_size_]();
			copy(array_, array_ + count_, array_new);
			delete[] array_;
			array_ = array_new;
		}

		catch (std::bad_alloc)
		{
			cerr << "bad_alloc caught" << endl;
		}

	}
	array_[count_++] = value;
}

template <typename T>
void Stack<T>::pop() {

	if (empty())
		throw "Stack is empty";
	count_--;
}

template <typename T>
T Stack<T>::top() {

	if (empty())
	{
		throw "Stack is empty!";
	}
	else return array_[count_- 1];
}

template <typename T>
T Stack<T>::last()const
{
	if (count_ == 0)
		throw logic_error("Stack is empty");
	else return array_[count_ - 1];
}

template <typename T>
void Stack<T>::print()
{
	for (unsigned int i = 0; i < count_; ++i)
		cout << array_[i] << " ";
	cout << endl;
}




template <typename T>
void Stack<T>::swap(Stack<T>& Object)
{
	std::swap(array_, Object.array_);
	std::swap(array_size_, Object.array_size_);
	std::swap(count_, Object.count_);
}

template <typename T>
bool Stack<T>::empty() const {
	return (count_ == 0);
}
