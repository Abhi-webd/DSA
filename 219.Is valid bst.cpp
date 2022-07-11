class Solution {
public:
    
    bool valid(TreeNode* root,long long n,long long m){
        if(root==NULL) return true;
        if(root->val>=m||root->val<=n) return false;
        return valid(root->left,n,root->val)&&valid(root->right,root->val,m);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return false;
        }
        if(root->right == NULL && root->left == NULL){
            return true;
        }
        return valid(root,-1e12,1e12);
    }
};
