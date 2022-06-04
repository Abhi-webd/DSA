#include <bits/stdc++.h>
using namespace std;
#define N 4

bool isSafe(int board[N][N], int row , int col){
    int i, j;

    for(int i = 0 ; i <row  ; i++){
        if(board[i][col] == 1){
            return false;
        }
    }

    i = row;
    j = col;
    while(row>=0 && col >=0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }

    i = row;
    j = col;
    while(row>=0 && col < N){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

bool solve(int board[N][N], int row){
    if(row >= N){
        return true;
    }

    for(int i = 0 ; i  < N ; i++){
        if(isSafe(board,row,i)){
            board[row][i] = 1;
            if(solve(board,row+1)){
                return true;
            }
            board[row][i] = 0;
        }
    }
    return false;
}

void solveNQ(){
    int board[N][N] = {{0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}};
    bool check = solve(board,0);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    
}

int main()
{
    solveNQ();
    return 0;
}


class Solution {
public:
    vector<vector<string>> sol;
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return sol;
    }
    
    bool isSafe(vector<string> &board, int row , int col ){
        int n = size(board);
        for(int i = 0 ; i < n ; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
            
            if(row-i>=0 && col-i>=0 &&board[row-i][col-i] == 'Q'){
                return false;
            }
            if(row-i>=0 && col+i<n &&board[row-i][col+i] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
    void solve(vector<string>&board, int row){
        if(row == size(board)){
            sol.push_back(board);
            return;
        }
        
        for(int col = 0 ; col < size(board) ; col++){
            if(isSafe(board,row,col)){
                board[row][col] = 'Q';
                solve(board,row+1);
                board[row][col] = '.';
            }
        }
    }
};
