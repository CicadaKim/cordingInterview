#include <iostream>

using namespace std;

class TreeNode
{
public:
    TreeNode *parent = nullptr;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    int value;    
};

TreeNode* FindLeftmost(TreeNode *node)
{
    while(node->left != nullptr)
        node = node->left;
    return node;
}

TreeNode* FindInOrderSuccesor(TreeNode *node)
{
    if(node->right != nullptr)
        return FindLeftmost(node);
    while(node != nullptr && node->parent != nullptr && node->parent->right == node)
        node = node->parent;
    
    return node;
}

int main()
{
    return 0;
}