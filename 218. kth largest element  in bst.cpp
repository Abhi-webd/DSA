class Solution
{
    void inorder(Node* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    public:
    int kthLargest(Node *root, int k)
    {
        vector<int> v;
        inorder(root,v);
        reverse(v.begin(),v.end());
        return v[k-1];
        return -1;
        
    }
};
