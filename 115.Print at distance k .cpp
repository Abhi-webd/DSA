void printlevelK(node* root,int k){
    if(root == NULL ){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
    }
    printlevelK(root->left,k-1);
    printlevelK(root->right,k-1);
}

int printNodesAtDistanceK(node* root , node* target  , int k){
    if(root ==  NULL){
        return -1;
    }

    if(root == target){
        printlevelK(target,k);
        return 0;
    }

    int DL = printNodesAtDistanceK(root->left,target,k);
    if(DL != -1){
        if(DL + 1 == k){
            cout<<root->data;
        }
        else{
            printlevelK(root->right,k-2-DL);
        }
        return 1 + DL;
    }

    int DR = printNodesAtDistanceK(root->right,target,k);
    if(DR != -1){
        if(DR+1 == k){
            cout<<root->data;
        }
        else{
            printlevelK(root->left,k-DR-2);
        }
        return 1+DR;
    }
    return -1;
}
