#include <cstdlib>
#include <iostream>

void generateRandom(int array[],int size){
	for(int i=0;i<size;i++){
		array[i]=i;
	}
	for(int i=0;i<size;i++){
		//pick random position out of first part of array
		int pick=rand()%(size-i);
		//swap it with last element
		std::swap(array[pick],array[size-1-i]);
	}
}
void generateSorted(int array[],int size){
	for(int i=0;i<size;i++){
		array[i]=i;		
	}	
}
void generateReversed(int array[],int size){
	for(int i=0;i<size;i++){
		array[i]=size-1-i;
	}
}

void generateOrganPipe(int array[],int size){
	int j=0;
	for(int i=0;i<size/2;i++){
		array[i]=j++;
	}
	j=(size%2)?size/2:size/2-1;
	for(int i=size/2;i<size;i++){
		array[i]=j--;
	}
}
void generateRotated(int array[],int size){
	for(int i=1;i<size;i++){
		array[i-1]=i;
	}
	array[size-1]=0;
}
