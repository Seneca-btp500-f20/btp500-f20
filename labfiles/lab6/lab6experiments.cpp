#include <cstdlib>
#include <iostream>
#include <string>
#include "timer.h"
/********************************************************************/
/*  Lab 6 main                                                      */
/*  To compile:                                                     */
/*     g++ lab6.cpp generatedata.cpp timer.cpp lab6experiments.cpp  */
/*  To run:                                                         */
/*     ./a.out                                                      */
/*                                                                  */
/*  Feel free to modify this main to output data in a way that      */
/*  is easy for you.                                                */ 
/********************************************************************/



void generateRandom(int array[],int size);
void generateSorted(int array[],int size);
void generateReversed(int array[],int size);
void generateOrganPipe(int array[],int size);
void generateRotated(int array[],int size);
void generateZeroOne(int array[],int size);
void quickSortLast(int arr[],int size);
void quickSortMiddle(int arr[],int size);
void quickSortMedianOf3(int arr[],int size);
void quickSortRandom(int arr[],int size);

void printArray(int array[],int size);
typedef void (*GeneratorPtr)(int[], int);
typedef void (*SortPtr)(int[],int);

int main(int argc, char* argv[]){
    if(argc!=3){
        std::cout << "Usage: a.out <array size> <pivot picking: 1-last, 2-middle, 3-medianOf3, 4-random" << std::endl;
        return 0;      
    }
    else{
        int size=atoi(argv[1]);
        int algchoice=atoi(argv[2]);
        if(algchoice < 1 || algchoice > 4){
           std::cout << "choose your pivot picking algorithm" << std::endl;
           std::cout << "Usage: a.out <array size> <pivot picking: 1-last, 2-middle, 3-medianOf3, 4-random" << std::endl;
           return 0;
        }
        int* arrays[5];
        GeneratorPtr generators[5]={generateRandom, generateSorted, generateReversed,generateOrganPipe,
                                         generateRotated};
        SortPtr sort[4]={quickSortLast,quickSortMiddle,quickSortMedianOf3,quickSortRandom};
        std::string dataName[5]={"random","sorted", "reversed", "organpipe","rotated"};
        Timer t;

        for(int i=0;i<5;i++){
            arrays[i]=new int[size];
            generators[i](arrays[i],size);
            t.reset();
            t.start();
            sort[algchoice-1](arrays[i],size);
            t.stop();
            std::cout << dataName[i] << " : " << t.currtime() << std::endl;
            delete [] arrays[i];
        }
    }
    return 0;
}
void printArray(int array[],int size){
    for(int i=0;i<size;i++){
        std::cout << array[i] << ", ";
        if(i%10 == 9){
           std::cout << std::endl;
        }
    }
}
