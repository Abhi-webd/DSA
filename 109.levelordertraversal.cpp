#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

node* buildTree(){
    int temp;
    cin>>temp;

    if(temp == -1){
        return NULL;
    }

    node* n = new node(temp);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void levelorder(node* root){
    if(root == NULL){
        return;
    }

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main()
{
    node* root =  buildTree();
    levelorder(root);
    return 0;
}
