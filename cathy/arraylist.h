template <typename T>
class ArrayList{
	void grow(){
		int newCap=cap*2;
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
	ArrayList(unsigned int cap=10){
		data_=new T[cap];
		used_=0;
		capacity_=cap;
	}
	void push_front(const T& data){
		if(used_==capacity_){
			grow();
		}
		for(int i=used_-1;i>=0;i--){
			data_[i+1]=data_[i];
		}
		data_[0]=data;
		used_++;
	}
	void push_back(const T& data){
		if(used_==capacity_){
			grow();
		}
		data_[used_++] = data;
	}
	void insert(const T& data, int loc);
	void pop_front();
	void pop_back();
	void remove(int loc);
	~ArrayList();
};

int main(void){
	ArrayList<int> mylist(4);
	mylist.push_back(3);
	mylist.push_back(1);
	mylist.push_front(5);
	mylist.push_back(6);
}