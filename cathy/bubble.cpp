#include <cstdlib>
#include <iostream>
#include <fstream>
#include "timer.h"
/*
let n represent size of array
let T(n) repsent the number of operations it takes to bubblesort array of size n




*/

using namespace std;
void bubbleSort(int arr[],int size){
  int tmp;                          
  int i;
  int j;
  for (i=0; i<size-1; i++) {      //1 +(n-1)+(n-1) + (n-1)

    for (j=0; j<size-1-i; j++){   // 1(n-1) + 4((n-1)+(n-2)+(n-3)..+1)

      if (arr[j+1] < arr[j]) {    //2 ((n-1)+(n-2)+(n-3)..(1))       
        tmp = arr[j];             //(n-1)+(n-2)+(n-3)..(1)      
        arr[j] = arr[j+1];        //2 (((n-1)+(n-2)+(n-3)..(1)))
        arr[j+1] = tmp;           //2((n-1)+(n-2)+(n-3)..(1))
      }
    }
  }
}

/*
  T(n) = 1 +(n-1)+(n-1) + (n-1) +   1(n-1) + 4((n-1)+(n-2)+(n-3)..+1) + ....
       = 1 + 4(n-1) +  11 ((n-1)+(n-2)+(n-3)..+(1)) 
       = 1 + 4n - 4 + 11 (n^2 - n)/2
       = 4n - 3 + 11/2 (n^2 - n)
       = 4n - 3 + 11/2 n^2 - 11/2 n
       = 8/2n - 3 + 11/2 n^2 - 11/2 n
       = 11/2 n^2 -3/2 n -3

dominating term is 11/2 n^2
thus,
T(n) is O(n^2)

*/

int main(int argc, char* argv[]){
  int size=atoi(argv[1]);
  int *myarr=new int[size];
  Timer stopwatch;
  ofstream log("bubblelog.txt");
  for(int i=0;i<size;i++){
    myarr[i]=rand();
  }
  stopwatch.start();
  bubbleSort(myarr,size);
  stopwatch.stop();
  cout << stopwatch.currtime() << endl;
  /*for(int i=0;i<size;i++){
    log <<myarr[i]<< endl;
  }*/
  delete [] myarr;
  return 0;
}

