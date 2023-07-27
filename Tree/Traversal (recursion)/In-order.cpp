//顺序：左 父 右
void pre_order(treeNode *root)
{
    if (root == nullptr) return;
    pre_order(root->left);
    cout<<root->data; //访问数据
    pre_order(root->right);
}