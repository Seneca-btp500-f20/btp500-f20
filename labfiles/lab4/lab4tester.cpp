/************************************************************/
/*  Lab 4 tester                                            */
/*  To compile:                                             */
/*     g++ lab4tester.cpp -std=c++0x                        */
/*  To run:                                                 */
/*     ./a.out                                              */
/************************************************************/

#include "lab4.h"
#include <iostream>

int main(void){
	DList<int> regular;
	Sentinel<int> sentinel;
	DList<int>::iterator a = regular.begin();
	Sentinel<int>::iterator b = sentinel.begin();

	if(a != regular.end() || a != regular.cend() ||
	   !(a==regular.end()) || !(a==regular.cend())){
		std::cout << "error: c/begin() or c/end() is not correctly written for DList" << std::endl;
		std::cout << "error could also be in == or !=" << std::endl;
	}
	else{
		std::cout << "test 1 pass" << std::endl;
	}
	if(b != sentinel.end() || b != sentinel.cend() || 
	   !(b==sentinel.end()) || !(b==sentinel.cend())){
		std::cout << "error: c/begin() or c/end() is not correctly written for Seninel" << std::endl;
		std::cout << "error could also be in == or !=" << std::endl;
	}
	else{
		std::cout << "test 2 pass" << std::endl;
	}

	for(int i=0;i<5;i++){
		regular.push_front(i);
	}
	DList<int>::const_iterator it;
	for(it=regular.cbegin();it!=regular.cend();++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	it=regular.cend();
	while(it != regular.cbegin()){
		std::cout << *(--it) << " ";
	}
	a=regular.begin();
	while(a!= regular.end()){
		*(a++)+=1;
	}

	for(it=regular.cbegin();it!=regular.cend();it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	a=regular.begin();
	while(++a!= regular.end()){
		*(a)+=1;
	}

	it=regular.cend();
	while(it != regular.cbegin()){
		it--;
		std::cout << *it << " ";
	}
	std::cout << std::endl;





	for(int i=0;i<5;i++){
		sentinel.push_front(i);
	}
	Sentinel<int>::const_iterator it2;
	for(it2=sentinel.cbegin();it2!=sentinel.cend();++it2){
		std::cout << *it2 << " ";
	}
	std::cout << std::endl;

	it2=sentinel.cend();
	while(it2 != sentinel.cbegin()){
		std::cout << *(--it2) << " ";
	}
	b=sentinel.begin();
	while(b!= sentinel.end()){
		*(b++)+=1;
	}

	for(it2=sentinel.cbegin();it2!=sentinel.cend();it2++){
		std::cout << *it2 << " ";
	}
	std::cout << std::endl;

	b=sentinel.begin();
	while(++b!= sentinel.end()){
		*(b)+=1;
	}

	it2=sentinel.cend();
	while(it2 != sentinel.cbegin()){
		it2--;
		std::cout << *it2 << " ";
	}
	std::cout << std::endl;

	return 0;
}
