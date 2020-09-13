#include <cstdlib>
#include <iostream>
#include <string>

/************************************************************/
/*  Lab 6 tester                                            */
/*  To compile:                                             */
/*     g++ lab6.cpp generatedata.cpp lab6tester.cpp         */
/*  To run:                                                 */
/*     ./a.out                                              */
/************************************************************/


void generateRandom(int array[],int size);
void generateSorted(int array[],int size);
void generateReversed(int array[],int size);
void generateOrganPipe(int array[],int size);
void generateRotated(int array[],int size);

void quickSortLast(int arr[],int size);
void quickSortMiddle(int arr[],int size);
void quickSortMedianOf3(int arr[],int size);
void quickSortRandom(int arr[],int size);
bool check0toNMinus1(int arr[],int size);
bool check0toHalf(int arr[],int size);
bool check01(int arr[],int size);
void printArray(int array[],int size);
typedef void (*GeneratorPtr)(int[], int);
typedef void (*SortPtr)(int[],int);
typedef bool (*CheckerFunction)(int[],int);

const int size=10000;
int main(void){
   int* arrays[5];
   for(int i=0;i<5;i++){
      arrays[i]=new int[size];
   }
   GeneratorPtr generators[5]={generateRandom, generateSorted, generateReversed,
                              generateOrganPipe, generateRotated};
   SortPtr sort[4]={quickSortLast,quickSortMiddle,quickSortMedianOf3,quickSortRandom};
   CheckerFunction check[5]{check0toNMinus1,check0toNMinus1,check0toNMinus1,
                                 check0toHalf,check0toNMinus1};
   std::string sortName[4]={"quickSortLast","quickSortMiddle", "quickSortMedianOf3", "quickSortRandom"};
   std::string dataName[5]={"random","sorted", "reversed", "organpipe","rotated"};
   bool rc=false;
   for(int i=0;i<4;i++){
      //seeding random number generator with same value, ensures the sequence
      //is the same.  This will ensure that different quicksort() work with same 
      //set of random values.
      srand(5);
      for(int j=0;j<5;j++){
         generators[j](arrays[j],size);
         sort[i](arrays[j],size);
         bool result=check[j](arrays[j],size);
         if(!result){
            std::cout << "bug in " << sortName[i] <<  " with " << dataName[j] << " data" << std::endl;
            printArray(arrays[j],size);
         }
         else{
            std::cout << sortName[i] << " works with " << dataName[j] << " data" << std::endl;
         }
      }
   }
   for(int i=0;i<5;i++){
      delete [] arrays[i];
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
bool check0toNMinus1(int arr[],int size){
   bool rc=true;
   for(int i=0;i<size;i++){
      if(arr[i]!=i){
         rc=false;
         break;
      }
   }
   return rc;
}

bool check0toHalf(int arr[],int size){
   bool rc=true;
   //loop will miss last element if size is odd, handled
   //after loop
   for(int i=0;i<size/2;i++){
      if(arr[i*2]!=i || arr[i*2+1]!=i){
         rc=false;
         break;
      }
   }
   if(rc && size%2 && arr[size-1]!=size/2){
      rc=false;
   }
   return rc;

}

