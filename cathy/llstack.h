#include "lab4b.h"  //lab4b is every function in lab 3
					//plus iterators from lab4
template <typename T>
class Stack{
	DList<T> data_;
public:
	Stack():data_(){}
	void push(const T& data){
		data_.push_front(data);
	}
	void pop(){
		data_.pop_front();
	}
	T top() const{
		return *(data_.cbegin());
	}
	bool isEmpty() const{
		return data_.cbegin()== data_.cend();
	}
};