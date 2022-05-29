class Solution {
public:
    void setZeroes(vector<vector<int>>& a){
        int m = a.size();
        int n = a[0].size();
        
        vector<vector<int>> v( m , vector<int> (n, 1)); 
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(a[i][j] == 0){
                    v[i][j] = 0;
                }
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(v[i][j] == 0){
                    int k = i;
                    int l = j;
                    while(k>=0){
                        if(v[k][j] != 0){
                           v[k][j] = -1; 
                        }
                        k--;
                    }
                    k = i;
                    while(k < m){
                        if(v[k][j] != 0){
                           v[k][j] = -1; 
                        }
                        k++;
                    }
                    while(l >= 0){
                        if(v[i][l] != 0){
                           v[i][l] = -1; 
                        }
                        l--;
                    }
                    l = j;
                    while( l < n){
                        if(v[i][l] != 0){
                           v[i][l] = -1; 
                        }
                        l++;
                    }
                }
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
               if(v[i][j] == -1){
                   a[i][j] = 0;
               }
            }
        }
        
    }
};
