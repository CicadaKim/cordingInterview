#include <iostream>

using namespace std;

class TreeNode
{
public:
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    int value;

    TreeNode(int val) : value(val){}
};

bool compareTwoTree(TreeNode* t1, TreeNode* t2)
{
    if(t1==nullptr || t2==nullptr)
        return false;

    if(t1->value != t2->value)
        return false;
    
    bool result = true;

    if(!(t1->left==nullptr && t2->left==nullptr))
        result = result && compareTwoTree(t1->left,t2->left);
    if(!(t1->right==nullptr && t2->right==nullptr))
        result = result && compareTwoTree(t1->right,t2->right);
    
    return result;
}



int main()
{


    return 0;
}