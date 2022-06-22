node* levelorderBuild(){
    int d;
    cin>>d;

    node* root = new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        if(l != -1){
            temp->left = new node(l);
            q.push(temp->left);
        }
        if(r != -1){
            temp->right = new node(r);
            q.push(temp->right);
        }
    }
    return root;
}
