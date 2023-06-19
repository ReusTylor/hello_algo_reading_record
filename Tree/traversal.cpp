vector<int> levelOrder(TreeNode *root){
    queue<TreeNode*> que;
    if(root != nullptr)
        que.push(root);
    
    vector<int> vec;
    
    while (!que.empty()) 
    {
        TreeNode* node = queue.front();
        queue.pop();
        vec.push_back(node -> val);
        if(node->left != nullptr) queue.push(node->left);
        if(node->right != nullptr) queue.push(node->right);
    }
    return vec;
}


// 前序
void preOrder(TreeNode* root){
    if(root == nullptr)
        return;
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}


// 中序
void inOrder(TreeNode* root){
    if(root == nullptr)
        return;
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

// 后序
void postOrder(TreeNode* root){
    if(root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}

