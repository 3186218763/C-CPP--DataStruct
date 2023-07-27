//顺序：父 左 右
void pre_order(treeNode *root)
{
    if (root == nullptr) return;
    cout<<root->data; //访问数据
    pre_order(root->left);
    pre_order(root->right);
}
