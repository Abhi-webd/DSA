class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node* root, vector<int>&arr)
   {
       if(root)
       {
           inorder(root->left, arr);
           arr.push_back(root->data);
           inorder(root->right, arr);
       }
   }
   Node* insert(Node* node, int k)
   {
       if(node==NULL)
       {
           Node* p = new Node(k);
           return p;
       }
       else
       {
           if(node->data > k)
           {
               node->left = insert(node->left, k);
           }
           else if(node->data < k)
           {
               node->right = insert(node->right, k);
           }
       }
   }
   
   Node *binaryTreeToBST (Node *root)
   {
       //Your code goes here
       vector<int> arr;
       inorder(root,arr);
       Node* node = NULL;
       for(int i=0;i<arr.size();i++)
       {
           node = insert(node,arr[i]);
       }
       return node;
   }
};
