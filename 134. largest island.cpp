#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i , int j , int m , int n){
    visited[i][j] = true;
    int cs = 1;

    int dx[] =  {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    for(int k = 0 ; k < 4 ; k++){
        int nx = dx[k] + i;
        int ny = dy[k] + j;

        if(nx >=0 &&  ny >= 0 && nx < m && ny < n && matrix[nx][ny] ==1 && !visited[nx][ny]){
            int size =  dfs(matrix,visited,nx,ny,m,n);
            cs += size;
        }
    }
    return cs;

}

int largest_island(vector<vector<int>> grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>>visited (m,vector<bool>(n,false));
    int largest = 0;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                int size  = dfs(grid,visited,i,j,m,n);
                if(size > largest){
                    largest = size;
                }
            }
        }
    }
    return largest;
}

int main()
{
    vector<vector<int>> grid = {
    {1,0,0,1,0},
    {1,0,1,0,0},
    {0,0,1,0,1},
    {1,0,1,1,1},
    {1,0,1,1,0}};
    cout<<largest_island(grid)<<endl;
    return 0;
}
