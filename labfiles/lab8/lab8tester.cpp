#include "lab8.h"
#include <iostream>

/************************************************************/
/*  Lab 8 tester                                            */
/*  To compile:                                             */
/*     g++ lab8tester.cpp -std=c++0x                        */
/*  To run:                                                 */
/*     ./a.out                                              */
/************************************************************/

template <typename T>
bool BST<T>::operator==(const BST<T>& rhs) const{
	return isSame(root_,rhs.root_);
}

template <typename T>
bool BST<T>::isSame(const typename BST<T>::Node* left, const typename BST<T>::Node* right) const{
	bool rc;
	if(!left && !right){
		rc=true;
	}
	else if(left && right){
		if(left->data_ == right->data_){
			rc=isSame(left->left_,right->left_) && isSame(left->right_,right->right_);
		}
		else{
			rc=false;
		}
	}
	else{
		rc=false;
	}
	return rc;
}

int main(void){
	const int numTrees = 11;
	const int numNodes = 19;
	BST<int> testTree[numTrees];
	BST<int> correctTree[numTrees];
	BST<int> correctCopies[numTrees];
	int dataset[numNodes]={18,8,28,4,10,20,34,2,6,14,24,32,36,12,16,22,26,30,38};



	int resultset[numTrees][numNodes]={
		{},
		{8},
		{28},
		{18,8,28,4,10,20,34,6,14,24,32,36,12,16,22,26,30,38}, //remove 2: a leaf 
		{18,8,28,4,10,20,34,2,6,14,24,36,12,16,22,26,30,38},  //remove 32: node with only left child
		{18,8,28,4,10,20,34,2,6,14,24,32,12,16,22,26,30,38},  //remove 36: node with only right child
		{18,8,28,4,20,34,2,6,14,24,32,36,12,16,22,26,30,38},  //remove 10: node with right child, right child has subtree 
		{18,8,30,4,10,20,34,2,6,14,24,32,36,12,16,22,26,38},  //remove 28: node with 2 children, inorder successor has no children
		{18,8,28,6,10,20,34,2,14,24,32,36,12,16,22,26,30,38}, //remove 4: node with 2 children, inorder successor is right child
		{18,10,28,4,20,34,2,6,14,24,32,36,12,16,22,26,30,38}, //remove 8: node with 2 children, inorder successor is right child who has children
		{20,8,28,4,10,34,2,6,14,24,32,36,12,16,22,26,30,38}  //remove 18: remove the root
	};


	BST<int>* copies[numTrees];
	int removeValues[numTrees]={18,18,18,2,32,36,10,28,4,8,18};
	testTree[0].insert(18);  //tree with just root
	correctCopies[0].insert(18);
	int depthTest[numNodes+10]={18,8,28,4,10,20,34,2,6,14,24,32,36,12,16,22,26,30,38, 1, 5, 7, 11,13,19,21,25,40, 31};
	int correctDepth[numNodes+10]{0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, -1, -1, -1,-1,-1,-1,-1,-1,-1,-1};
	testTree[1].insert(18);  //tree with root + left child
	testTree[1].insert(8);
	correctCopies[1].insert(18);
	correctCopies[1].insert(8);


	testTree[2].insert(18);  //tree with root + right child
	testTree[2].insert(28);
	correctCopies[2].insert(18);
	correctCopies[2].insert(28);
	//create the 8 identical trees
	for(int i=3;i<numTrees;i++){
		for(int j=0;j<numNodes;j++){
			testTree[i].insert(dataset[j]);
			correctCopies[i].insert(dataset[j]);
		}
	}




	//create the trees with the correct results
	correctTree[1].insert(resultset[1][0]);
	correctTree[2].insert(resultset[2][0]);

	for(int i=3;i<numTrees;i++){
		for(int j=0;j<numNodes-1;j++){
			correctTree[i].insert(resultset[i][j]);

		}
	}
	bool passtest=true;

	std::cout << "Test depth()" << std::endl;
	for(int i=0;i<numNodes + 10;i++){
		int rc=testTree[3].depth(depthTest[i]);
		if(rc != correctDepth[i]){
			std::cout << "Depth of " << depthTest[i] << " is " << correctDepth[i] << std::endl;
			std::cout << "Your function returns: " << rc << std::endl;
			passtest=false;
		}
		else{
			std::cout << "depth(" << depthTest[i] << ") = " << rc << std::endl;

		}
	}


	std::cout << "Test copy constructors: " << std::endl;
	//use copy constructor to create duplicates of every tree
	for(int i=0;passtest && i<numTrees;i++){
		copies[i]=new BST<int>(testTree[i]);
	}
	for(int i=0;i<numTrees;i++){
		if(*(copies[i]) == correctCopies[i]){
			std::cout << "testTree [ "  << i << " ] was copied" << std::endl;
		}
		else{
			std::cout << "testTree [ "  << i << " ] is not the same as its copy" << std::endl;
			std::cout << "Your Tree:" << std::endl;
			copies[i]->print();
			std::cout << std::endl << std::endl;
			std::cout << "Correct Tree:" << std::endl;
			correctCopies[i].print();			
			passtest=false;
		}
	}

	std::cout << "Test remove(): " << std::endl;
	//remove one node from each tree
	for(int i=0;passtest && i<numTrees;i++){
		testTree[i].remove(removeValues[i]);
	}

	for(int i=0;passtest && i<numTrees;i++){
		std::cout << "Test " << i+1 << " : ";
		if(testTree[i]==correctTree[i]){
			std::cout << "remove(" << removeValues[i] << ") was correctly done." << std::endl;
			std::cout << "preOrder() :";
			testTree[i].printPreOrder();
			std::cout << "inOrder() :";
			testTree[i].printInOrder();
		}
		else{
			std::cout << "remove(" << removeValues[i] << ") was not correct" << std::endl;
			std::cout << "Your Tree:" << std::endl;
			testTree[i].print();
			std::cout << std::endl << std::endl;
			std::cout << "Correct Tree:" << std::endl;
			correctTree[i].print();
			passtest=false;
		}
	}

	std::cout << "Make sure deep copies were made: " << std::endl;
	//use copy constructor to create duplicates of every tree
	for(int i=0;passtest && i<numTrees;i++){
		if(*(copies[i]) == correctCopies[i]){
			std::cout << "testTree [ "  << i << " ] was copied" << std::endl;
		}
		else{
			std::cout << "testTree [ "  << i << " ] is not the same as its copy" << std::endl;
			std::cout << "Your Tree:" << std::endl;
			copies[i]->print();
			std::cout << std::endl << std::endl;
			std::cout << "Correct Tree:" << std::endl;
			correctCopies[i].print();			
			passtest=false;
		}
	}


	if(passtest){
		std::cout << "Lab 7 tests successfully completed" << std::endl;
	}
	else{
		std::cout << "Lab 7 tests were not completed" << std::endl;
	}


	return 0;
}
