pair<int,bool> isHeightBalance(node* root){
    pair<int,bool> p,l,r;
    if(root == NULL){
        p.first = 0;
        p.second = true;
        return p;
    }

    //rec case
    l = isHeightBalance(root->left);
    r = isHeightBalance(root->right);

    int height = max(l.first,r.first)+1;
    if(abs(l.first - r.first) <= 1 && l.second == true && r.second == true){
        return make_pair(height,true);
    }
    return make_pair(height,false);
}
