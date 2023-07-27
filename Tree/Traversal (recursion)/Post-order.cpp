//顺序：左 右 父
void pre_order(treeNode *root)
{
    if (root == nullptr) return;
    pre_order(root->left);
    pre_order(root->right);
    cout<<root->data; //访问数据
}