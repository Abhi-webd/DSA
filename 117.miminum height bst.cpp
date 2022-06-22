node* sortedarrayBST(vector<int> a, int s, int e){
    if(s > e){
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(a[mid]);

    root->left = sortedarrayBST(a,s,mid-1);
    root->right = sortedarrayBST(a,mid+1,e);
    return root;
}
