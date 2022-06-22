void traverseTree(node* root, int d,map<int,vector<int>> &m){
    if(root == NULL){
        return;
    }
    m[d].push_back(root->data);
    traverseTree(root->left,d-1,m);
    traverseTree(root->right,d+1,m);
}

void verticalOrderPrint(node* root){
    map<int,vector<int>> m;
    int d = 0;
    traverseTree(root,d,m);
    for(auto p : m){
        int key = p.first;
        vector<int> line = p.second;
        for(auto i:line){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
