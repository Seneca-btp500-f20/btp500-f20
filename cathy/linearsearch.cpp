template <class TYPE>
int linearSearch(const vector<TYPE>& arr, const TYPE& key){
    int rc=-1;
    for(int i=0;i<arr.size()&& rc==-1;i++){
        if(arr[i]==key){
            rc=i;
        }
    }
    return rc;
}
