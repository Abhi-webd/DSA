int findClosetBST(node* root , int target){
    int closet;
    int diff = INT_MAX;

    node* temp = root;
    while(temp != NULL){
        int cdiff = abs(temp->data - target);
        if(cdiff == 0){
            return temp->data;
        }
        if(cdiff < diff){
            diff = cdiff;
            closet = temp->data;
        } 
        if(temp->data > target){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return closet;
}
