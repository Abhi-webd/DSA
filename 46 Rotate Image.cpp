class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
         vector<vector<int>> v( n , vector<int> (m, 0));
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                v[j][n-1-i] = a[i][j];
            }
        }
        
        for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            a[i][j] = v[i][j];
        }
    }
    }
};
