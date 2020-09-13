#include <cstdlib>
#include <iostream>
#include <fstream>


using namespace std;




/*Only modify this function*/
void insertionSortModified(int arr[],int left,int right){
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


int partition(int array[],int left, int right){

   int pivot = 0;//fix this.
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



void quickSortModified(int arr[], int left, int right,int threshold){

   if(right-left <= threshold){
      insertionSortModified(arr,left,right);
   }
   else{
      int i = partition(arr,left,right);
      quickSortModified(arr,left,i-1, threshold);
      quickSortModified(arr,i+1,right, threshold);
   } 
}

void quickSortModified(int arr[],int size,int threshold){
   quickSortModified(arr,0,size-1,threshold);
}


/*performs the insertion sort algorithm on array from index
left to index right inclusive.  You don't need to change this function*/
void insertionSortStandard(int arr[],int left,int right){
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

void quickSortStandard(int arr[], int left, int right,int threshold){
   if(right-left <= threshold){
      insertionSortStandard(arr,left,right);
   }
   else{
      int i = partition(arr,left,right);
      quickSortStandard(arr,left,i-1, threshold);
      quickSortStandard(arr,i+1,right, threshold);
   }
}
void quickSortStandard(int arr[],int size,int threshold){
   quickSortStandard(arr,0,size-1,threshold);
}

