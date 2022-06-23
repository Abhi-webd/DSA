#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    unordered_map<char,node*> m;
    bool isterminal;

    node(char d){
        data = d;
        isterminal = false;
    }
};

class trie{
    node* root;
    public:
    trie(){
        root = new node('\0');
    }
    void insert(string word){
        node* temp = root;
        for(auto ch : word){
            if(temp->m.count(ch) == 0){
                node* n = new node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isterminal  = true;
    };
    bool search(string word){
        node* temp = root;
        for(auto ch:word){
            if(temp->m.count(ch) == 0){
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isterminal; 
    };
};

int main()
{
    string words[] = {"apple","ape","no","news","not","never"};
    trie t;
    for(auto w:words){
        t.insert(w);
    }

    int q;
    cin>>q;

    string sword;
    while(q--){
        cin>>sword;
        if(t.search(sword)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }

    return 0;
}
