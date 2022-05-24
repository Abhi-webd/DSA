pair<long long, long long> getMinMax(long long a[], int n) {
    long  long  max = INT_MIN;
    long long  min = INT_MAX;
    
    for(int i = 0 ; i < n ; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    pair<long long, long long > p;
    p.first = min;
    p.second = max;
    return p;
}
