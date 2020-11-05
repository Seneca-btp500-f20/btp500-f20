#include <cstdlib>
#include <iostream>
#include <fstream>
#include "timer.h"
using namespace std;

const int threshold=16;

int partition(int array[],int left, int right){

   int location = left + (rand()%(right-left+1));
   int pivot = array[location];
   array[location] = array[right];
   array[right] = pivot;            //move the pivot out of the way
   int i=left-1;
   for(int j=left;j<right;j++){
      if(array[j]<=pivot){
         i=i+1;
         int tmp=array[i];
         array[i]=array[j];
         array[j]=tmp;
      }
   }
   int tmp=array[i+1];
   array[i+1]=array[right];
   array[right]=tmp;
   return i+1;
}

/*performs the insertion sort algorithm on array from index
left to index right inclusive.  You don't need to change this function*/
void insertionSort(int arr[],int left,int right){
   int curr;
   int i, j;
   for(i=left+1;i<=right;i++){
      curr=arr[i];
      for(j=i;j>0 && arr[j-1] > curr;j--){
         arr[j]=arr[j-1];
      }
      arr[j]=curr;
   }
}

void quickSort(int arr[], int left, int right){
   if(right-left <= threshold){
      insertionSort(arr,left,right);
   }
   else{
      int i = partition(arr,left,right);
      quickSort(arr,left,i-1);
      quickSort(arr,i+1,right);
   }
}
void quickSort(int arr[],int size){
   quickSort(arr,0,size-1);
}
int main(int argc, char* argv[]){
  int size=atoi(argv[1]);
  int* myarr=new int[size];
  Timer stopwatch;
  ofstream log("quicklog.txt");
  for(int i=0;i<size;i++){
     myarr[i]=rand();
//      myarr[i]=i+1;
  }
  stopwatch.start();
  quickSort(myarr,size);
  stopwatch.stop();
  cout << stopwatch.currtime() << endl;
  for(int i=0;i<size;i++){
    log <<myarr[i]<< endl;
  }
  delete [] myarr;
  return 0;
}
