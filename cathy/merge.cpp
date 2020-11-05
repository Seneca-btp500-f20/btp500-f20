#include <cstdlib>
#include <iostream>
#include <fstream>
#include "timer.h"

using namespace std;
void merge(int arr[],int tmp[],int startA,int startB,int endB);

void mergeSort(int arr[],int tmp[],int start,int end){
  //if the array is more than one element big
  if(start<end){
    int mid=(start+end)/2;
    mergeSort(arr,tmp,start,mid);
    mergeSort(arr,tmp,mid+1,end);
    merge(arr,tmp,start,mid+1,end);
  }
}
/*function merges the two halfs of a sorted array together.
  The arrays are defined from arr[startA]to arr[startB-1] and arr[startB]
to arr[endB]*/

void merge(int arr[],int tmp[],int startA,int startB,int endB){
  int aptr=startA;   //1
  int bptr=startB;    //1 
  int idx=startA;     //1
  while(aptr < startB && bptr < endB+1){ //4 (n-1)
    if(arr[aptr] < arr[bptr]){           //1 (n-1)
       tmp[idx]=arr[aptr];               //1 (n-1)
       idx++;                            //1 (n-1)
       aptr++;                           //1 (n-1)
    }
    else{
       tmp[idx++]=arr[bptr];
       bptr++;
    }
  }
  //merge function only does one of the two following loops
  while(aptr<startB){     //1
    tmp[idx]=arr[aptr];
    idx++;
    aptr++;    
  }                        //note that all but 1 of
                           //of the array is done
  while(bptr < endB+1){    //2
    tmp[idx++]=arr[bptr];  //2
    bptr++;                //1
  }

  //copy back into arr
  for(int i=startA;i<=endB;i++){
    arr[i]=tmp[i];
  }
}

/*this is the wrapper function that "main" uses.  The world see's this and
  use this. The actual work is done by the other mergeSort() function*/
void mergeSort(int arr[],int size){
  int* tmp=new int[size];
  mergeSort(arr,tmp,0,size-1);
  delete [] tmp;
}


int main(int argc, char* argv[]){
  int size=atoi(argv[1]);
  int *myarr=new int[size];
  Timer stopwatch;
  ofstream log("mergelog.txt");
  for(int i=0;i<size;i++){
    myarr[i]=rand();
//    myarr[i]=i+1;
  }
  stopwatch.start();
  mergeSort(myarr,size);
  stopwatch.stop();
  cout << stopwatch.currtime() << endl;
/*  for(int i=0;i<size;i++){
    log <<myarr[i]<< endl;
  }*/
  delete [] myarr;
  return 0;
}

