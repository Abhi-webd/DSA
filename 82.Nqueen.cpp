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
