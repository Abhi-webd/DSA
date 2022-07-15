vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	   int n  = grid.size();
	   int m =  grid[0].size();
	   vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
	   queue<pair<int,int>>q;
	   vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
	   for(int i = 0 ; i < n ; i++){
	       for(int j = 0 ; j < m ; j++){
	           if(grid[i][j] == 1){
	               ans[i][j] = 0;
	               q.push({i,j});
	           }
	       }
	   }
	   
	   while(!q.empty()){
	       int x = q.front().first;
	       int y = q.front().second;
	       
	       q.pop();
	       
	       for(auto d : dir){
	           int a = x + d[0];
	           int b = y + d[1];
	           if(a >= 0 && b >=0 && a < n && b < m){
	               if(ans[a][b] > ans[x][y]+1){
	                   ans[a][b] = ans[x][y]+1;
	                   q.push({a,b});
	               }
	           }
	       }
	   }
	   return ans;
	}
