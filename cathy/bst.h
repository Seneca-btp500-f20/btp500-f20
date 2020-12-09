#include "arrayqueue.h"
#include <iostream>

template<typename T>
class BST{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data=T{},Node* left=nullptr, Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;
		}
	};

	Node* root_;

	//actual recursive function
	//stroot is the root of the subtree we want 
	//to insert the data into
	void insert(Node*& stroot,const T& data){
		if(stroot == nullptr){
			stroot=new Node(data);
		}
		else{
			if(data < stroot->data_){
				insert(stroot->left_,data);
			}
			else{
				insert(stroot->right_,data);
			}
		}
	}
	//this function prints the tree with root
	//stroot in an inorder manner
	void print(const Node* stroot) const{
		if(stroot){
			print(stroot->left_);
			std::cout << stroot->data_ << " ";
			print(stroot->right_);
		}
	}
	//this function deallocates the subtree
	//with root stroot
	void clear(Node* stroot){
		if(stroot){
			clear(stroot->left_);
			clear(stroot->right_);
			delete stroot;
		}
	}



public:
	//creates empty BST
	BST(){
		root_=nullptr;
	}
	//adds data to tree
	void insertRecursive(const T& data){
		insert(root_,data);
	}

	//adds data to tree
	void insertIterative(const T& data){
		if(root_==nullptr){
			root_=new Node(data);
		}
		else{
			bool isAdded=false;
			Node* curr=root_;
			while(!isAdded){
				if(data < curr->data_){
					if(curr->left_ == nullptr){
						curr->left_=new Node(data);
						isAdded=true;
					}
					else{
						curr=curr->left_;
					}
				}

				else{
					if(curr->right_ == nullptr){
						curr->right_=new Node(data);
						isAdded=true;
					}
					else{						
						curr=curr->right_;
					}
				}
			}
		}
	}


	/*returns true if data is in tree, 
	false otherwise*/
	bool isPresent(const T& data){

	}
	//prints out every value in tree
	//in a sorted manner
	void print()const {
		print(root_);
	}

	//breadthfirst traversals are not 
	//implemented recursively
	void breadthFirstPrint()const{
		//create an empty queue 
		//to keep track of which node
		//to deal with next
		Queue<Node*> currentQ;

		//Do we allow nullptrs to 
		//to be added to the queue
		//a) check for nullptrs before enqueue
		//b) check for nullptrs on dequeue
		if(root_){
			//priming the queue
			currentQ.enqueue(root_);

			while(!currentQ.isEmpty()){
				Node* curr=currentQ.front();
				currentQ.dequeue();
				std::cout << curr->data_ << " ";
				if(curr->left_){
					currentQ.enqueue(curr->left_);
				}
				if(curr->right_){
					currentQ.enqueue(curr->right_);
				}
			}
		}
		std::cout << std::endl;

	}

	
	//destructor
	~BST(){
		clear(root_);
	}
};