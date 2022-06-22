class Pair{
    public:
    int inc;
    int exc;
};

Pair maxSubsetSum(node* root){
    Pair p,l,r;
    if(root == NULL){
        p.inc = 0;
        p.exc = 0;
        return p;
    }

    l = maxSubsetSum(root->left);
    r = maxSubsetSum(root->right);

    p.inc = root->data+l.exc+r.exc;
    p.exc = max(l.inc,l.exc)+max(r.inc,r.exc);
    return p;
}
