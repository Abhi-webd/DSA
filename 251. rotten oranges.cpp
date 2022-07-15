int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size(); 
	    int n = grid[0].size(); 
	    vector<vector<int>> res(m, vector<int>(n, INT_MAX)); 
	    queue<pair<int, int>> q; 
	    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	    
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    q.push({i, j}); 
                    res[i][j] = 0; 
                }
                if (grid[i][j] == 0){
                    res[i][j] = 0; 
                }
        }}
        int ans = INT_MIN;
        while(!q.empty()){
            int x = q.front().first; 
            int y = q.front().second; 
            q.pop(); 
            
            for(auto &d: dir){
                int a = d[0] + x; 
                int b = d[1] + y;
                if (a >= 0 and b >= 0 and a < m and b < n){
                    if (res[a][b] > res[x][y] + 1){
                        res[a][b] = res[x][y] + 1;
                        q.push({a, b}); 
                    }
                }
            }
        }
        for(auto i : res){
            for(auto j : i){
                ans = max(ans,j);
            }
        }
        return ans == INT_MAX ? -1 : ans;
         
    }
