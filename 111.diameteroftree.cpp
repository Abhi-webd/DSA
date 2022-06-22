int height(node* root){
    if(root == NULL){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return max(l,r) + 1;
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int d1 = height(root->left)+height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1,max(d2,d3));
}
