template <typename T>
class Queue{
	void grow(){
		int newCap=capacity_*2;
		T* newArray=new T[newCap];
		int j=front_;
		for(int i=0;i<used_;i++){
			newArray[i]=data_[j];
			j=(j+1)%capacity_;
		}
		delete [] data_;

		data_=newArray;
		capacity_=newCap;
		front_=0;
		back_=used_;
	}
	T* data_;   // the array
	int used_;  // represents how many pieces of data are currently in array
	int capacity_; //capacity is capacity of the array (how much declared)

	int front_;  //index of first/oldest/front  item in queue
	int back_;	 //index of where the next item will be added
public:
	Queue(int cap=10){
		data_=new T[cap];
		used_=0;
		capacity_=cap;
		back_=0;
		front_=0;	
	}
	void enqueue(const T& data){
		//add to back of array
		if(used_==capacity_){
			grow();
		}
		data_[back_]=data;
		back_++;
		if(back_==capacity_){
			back_=0;
		}
		used_++;
	}
	void dequeue(){
		front_=(front_+1)%capacity_;  //alternative to if method
		used_--;
	}
	T front() const{
		return data_[front_];
	}
	bool isEmpty(){
		return used_==0;
	}
};