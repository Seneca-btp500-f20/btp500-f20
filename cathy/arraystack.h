template <typename T>
class Stack{
	void grow(){
		int newCap=capacity_*2;
		T* newArray=new T[newCap];
		for(int i=0;i<used_;i++){
			newArray[i]=data_[i];
		}
		delete [] data_;

		data_=newArray;
		capacity_=newCap;

	}
	T* data_;   // the array
	int used_;  // represents how many pieces of data are currently in array
	int capacity_; //capacity is capacity of the array (how much declared)

public:
	Stack(int cap=10){
		data_=new T[cap];
		used_=0;
		capacity_=cap;		
	}
	void push(const T& data){
		//add to back of array
		if(used_==capacity_){
			grow();
		}
		data_[used_++] = data;
	}
	void pop(){
		used_--;
	}
	T top() const{
		return data_[used_-1];
	}
	bool isEmpty(){
		return used_==0;
	}
};