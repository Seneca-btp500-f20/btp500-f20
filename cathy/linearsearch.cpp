
//let n represent the size of the vector arr
//let T(n) represent the number of operations needed to perform a linear search and not finding
//the key


template <class TYPE>
int linearSearch(const vector<TYPE>& arr, const TYPE& key){
    int rc=-1;									// 1
    for(int i=0;i<arr.size()&& rc==-1;i++){		// 1 + 5n
        if(arr[i]==key){						// n
            rc=i;								// 0 because key not found
        }
    }
    return rc;									// 1
}


//T(n) = 1 + 1 + 5n + n + 1
//T(n) = 6n + 3
//T(n) is O(n)