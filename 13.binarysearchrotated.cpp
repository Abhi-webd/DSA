//Search an Element in a Sorted and Pivoted Array
int Search(vector<int> vec, int K) {
    //code here
    int s = 0;
    int e = vec.size() - 1;
    
    while(s <= e){
        int mid = (s+e)/2;
        if(vec[mid] == K){
            return mid;
        }
        if(vec[s] <= vec[mid]){
            if(K <= vec[mid] && K >= vec[s]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        else{
            if(K >= vec[mid] && K <= vec[e]){
                s = mid + 1;
            }
            else{
                e = mid -1;
            }
        }
    }
    return -1;
}
