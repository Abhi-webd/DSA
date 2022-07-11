class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    void insert(Node* root,  int val){
        Node* prev = NULL;
        Node* curr = root;
        Node* temp = newNode(val);
        while(curr != NULL){
            prev = curr;
            if(curr->data > val){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        if(prev->data > val){
            prev->left = temp;
        }
        else{
            prev->right = temp;
        }
    }
    
    Node* post_order(int pre[], int size)
    {
        //code here
        Node* root = newNode(pre[0]);
        for(int i = 1 ; i < size ; i++){
            insert(root,pre[i]);
        }
        return root;
    }
};
