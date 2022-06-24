#include <bits/stdc++.h>
using namespace std;
#define M 3
#define N 4

class node{
    public:
    char s;
    unordered_map<char,node*> child;
    string word;
    bool isTerminal;

    node(char s){
        this->s =s;
        isTerminal =  false;
        word = "";
    }
};

class trie{
    public:
    node* root;
    trie(){
        root = new node('\0');
    }

    void addWord(string word){
        node* temp = root;
        for(auto ch : word){
            if(temp->child.count(ch) == 0){
                temp->child[ch] = new node(ch);
            }
            temp = temp->child[ch];
        }
        temp->isTerminal = true;
        temp->word = word; 
    }
};


void dfs (char board[M][N], node* nod, int i, int j, bool visited[][N], unordered_set<string> & output){
    //base case
    char ch = board[i][j];
    if(nod->child.count(ch) == 0){
        return;
    }
    visited[i][j] = true;
    nod = nod->child[ch];

    if(nod->isTerminal){
        output.insert(nod->word);
    }

    int dx[] = {0,1,1,1,0,-1,-1,-1};
    int dy[] = {-1,-1,0,1,1,1,0,-1};

    for(int k = 0 ; k < 8 ; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni >=0 && nj >=0 && ni < M && nj < N && !visited[ni][nj]){
            dfs(board,nod,ni,nj,visited,output);
        }
    }
    visited[i][j] = false;
}



int main(){

    string words[] = {"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};

    char boggle[M][N] = {{'S','E','R','T'},
    {'U','N','K','S'},
    {'T','C','A','T'}};

    trie t;
    for(auto w:words){
        t.addWord(w);
    }

    unordered_set<string> output; //there can be more thn one wayy to ignore duplicates

    //dfs search 8 way  
    bool visited[M][N] = {0};
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            dfs(boggle,t.root,i,j,visited,output);
        }
    }

    for(auto word:output){
        cout<<word<<" ";
    }
    return 0; 
}
