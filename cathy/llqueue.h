template <typename T>
class Queue{
	DList<T> data_;
public:
	Queue():data_(){}
	void enqueue(const T& data){
		data_.push_back(data);
	}
	void dequeue(){
		data_.pop_front();
	}
	T front() const{
		*(data_.cbegin());
	}
	bool isEmpty() const{
		return data_.cbegin()== data_.cend();
	}
};