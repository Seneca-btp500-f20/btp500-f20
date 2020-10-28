/**************************************************************************/
/*                                                                        */
/*   A2 timing                                                            */
/*                                                                        */
/*   To compile: g++ a2timing timer.cpp -std=c++0x                        */
/*                                                                        */
/*   You are free to alter both tablepartD.h and the main to make it      */
/*   easier to get data for graphing.  This main outputs 1 timing,        */
/*   after every 1000 updates().  Only rule is that you should not        */
/*   alter the data generation and data usage (ie first 3 lines of main)  */
/*                                                                        */
/**************************************************************************/

#include "table.h"
#include "timer.h"
#include <string>
#include <iostream>
#include <cstdlib>

const int maxRecords=2000000;

void createData(string keys[],int data[],int max);
int main(int argc, char* argv[]){

	if(argc != 4){
		std::cout << "usage: a.out numrecords capacity maxLoadFactor" << std::endl;
		return 0;
	}

    std::string* keys = new std::string[maxRecords];        //list of test cases. 
    int* data=new int[maxRecords];
    createData(keys,data,maxRecords);

    int numrecords=atoi(argv[1]);
    size_t cap=atoi(argv[2]);

    double maxLoadFactor = atof(argv[3]);

    std::cout << "number of records: " << numrecords << std::endl;
    std::cout << "capacity: " << cap << std::endl;
    std::cout << "max load factor: " << maxLoadFactor << std::endl;

    LPTable<int> table(cap,maxLoadFactor);

    Timer T;
 

    for(int i=0;i<numrecords;i++){
    	T.start();
    	table.update(keys[i],data[i]);
    	T.stop();
    }
    std::cout << "Time: " << T.currtime() << std::endl;
}




void createData(std::string keys[],int data[],int max){
	FILE* fp=fopen("dictionary.txt","r");
	int i=0;
	std::string front="A_";
	char curr[50];
	while(fscanf(fp,"%s\n",curr)==1){
		keys[i]=curr;
		data[i]=rand()%100;
		i++;                      
	}
	int numWords=i;
	int j=0;
	while(i<max){
		keys[i]=front+keys[j];
		data[i]=rand()%100;
		i++;
		j++;
		if(j==numWords){
			front[0]+=1;
			j=0;
		}
	}
}

