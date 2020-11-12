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
	void insert(Node* stroot,const T& data){
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

	//destructor
	~BST(){

	}
};