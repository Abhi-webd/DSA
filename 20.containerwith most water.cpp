class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        if(n == 0 || n == 1){
            return 0;
        }
        int s = 0 ;
        int e = n-1;
        
        int max = INT_MIN;
        while(s<e){
            int temp = min(a[s],a[e])*(e-s);
            if(temp > max){
                max = temp;
            }
            if(a[s] < a[e]){
                s++;
            }
            else{
                e--;
            }
            
        }
        
        return max;
    }
};
