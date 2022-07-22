bool nodePresent(Node* root, int a){
        if(root == NULL){
            return false;
        }
        if(root->data == a){
            return true;
        }
        return nodePresent(root->left,a) || nodePresent(root->right,a);
    }
    int find(Node* root, int a){
        if(root == NULL){
            return 0;
        }
        if(root->data == a){
            return 0;
        }
        return 1 + find(root->left,a);
        return 1 + find(root->right,a);
    }
    
    bool search(Node* root, int target){
        if(root == NULL){
            return false;
        }
        if(root->data == target){
            return true;
        }
        bool check1 = search(root->left,target);
        if(check1) return true;
        bool check2 = search(root->right,target);
        return check2;
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root == NULL){
            return NULL;
        }
        if(root->data == n1 || root->data == n2){
            return root;
        }
        if((search(root->left,n1) && search(root->right,n2)) || (search(root->left,n2) && search(root->right,n1))){
            return root;
        }
        
        Node* p = lca(root->left,n1,n2);
        if(p != NULL) return p;
        Node* q = lca(root->right,n1,n2);
        return q;
    }
    
    int findLevel(Node* root, int k, int level){
    if (root == NULL)
        return -1;
    if (root->data == k)
        return level;
 
    int left = findLevel(root->left, k, level + 1);
    if (left == -1)
        return findLevel(root->right, k, level + 1);
    return left;
}
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* common;
        if(nodePresent(root,a) && nodePresent(root,b)){
             common =  lca(root,a,b);
        }
        
        int d1 = findLevel(common,a,0);
        int d2 = findLevel(common,b,0);
        return d1+d2;
        
    }
