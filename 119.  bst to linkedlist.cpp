class Linkedlist{
    public:
    node* head;
    node* tail;
};

Linkedlist tree2LL(node* root){
    Linkedlist l;
    if(root == NULL){
        l.head =  l.tail = NULL;
        return l;
    }

    if(root->left == NULL and root->right == NULL){
        l.head = l.tail = root;
        return l;
    }

    else if(root->left != NULL &&  root->right == NULL){
        Linkedlist leftLL = tree2LL(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
    }
    else if(root->left == NULL && root->right != NULL){
        Linkedlist rightLL = tree2LL(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
    }
    else{
         Linkedlist leftLL = tree2LL(root->left);
         Linkedlist rightLL = tree2LL(root->right);
         leftLL.tail->right = root;
         root->right = rightLL.head;
         l.head = leftLL.head;
         l.tail = rightLL.tail;
    }
    return l;
}
