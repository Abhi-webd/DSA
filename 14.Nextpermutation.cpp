class Solution {
public:
    void nextPermutation(vector<int>& a) {
        if(a.size() == 0 || a.size() <=1){
            return;
        }
        int n = a.size();
        int s1 = -1;
        for(int i = n-2 ; i >=0 ; i--){
            if(a[i] < a[i+1]){
                s1 = i;
                break;
            }
        }
        int s2 = -1;
        
        if(s1>=0){
            for(int i = n-1; i >= 0 ; i--){
            if(a[i] > a[s1]){
                s2 = i;
                break;
            }
        }
            swap(a[s1],a[s2]);
        }
        // cout<<s1<<" "<<s2<<endl;
        reverse(a.begin()+s1+1,a.end());
    }
};
