class Solution{
public:
void inorder(Node* root, int l ,int h, int &count){
    if(root == NULL){
        return;
    }
    inorder(root->left,l,h,count);
    if(l <= root->data && h >= root->data){
        count +=1;
    }
    inorder(root->right,l,h,count);
}
    int getCount(Node *root, int l, int h)
    {
      // your code goes here  
      int count=0;
      inorder(root,l,h,count);
      return count;
    }
};

