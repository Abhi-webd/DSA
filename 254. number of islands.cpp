vector<int> dirx{-1,-1,-1,0,0,1,1,1};
     vector<int> diry{-1,0,1,-1,1,-1,0,1};
    void helper(vector<vector<char>>& grid, int i , int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        
        for(int k = 0 ; k < 8 ; k++){
            helper(grid,i+dirx[k],j+diry[k]);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
    int count = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == '1'){
                count++;
                helper(grid,i,j);
            }
        }
    }
    return count;
    }
