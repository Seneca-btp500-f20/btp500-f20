#include <cstdlib>
#include <iostream>
#include <fstream>
#include "timer.h"

using namespace std;
void selectionSort(int arr[],int size){
  int i,j;
  int min;  //index of smallest value in the unsorted array

  for(int i=0;i<size-1;i++){
    min=i;
    for(int j=i+1;j<size;j++){
      if(arr[j] < arr[min]){
        min=j;
      }
    }
    if(min!=i){
      int tmp=arr[min];
      arr[min]=arr[i];
      arr[i]=tmp;
    }
  }

}


int main(int argc, char* argv[]){
  int size=atoi(argv[1]);
  int *myarr=new int[size];
  Timer stopwatch;
  ofstream log("selectionlog.txt");
  for(int i=0;i<size;i++){
    myarr[i]=rand();
  }
  stopwatch.start();
  selectionSort(myarr,size);
  stopwatch.stop();
  cout << stopwatch.currtime() << endl;
  /*for(int i=0;i<size;i++){
    log <<myarr[i]<< endl;
  }*/
  delete [] myarr;
  return 0;
}

