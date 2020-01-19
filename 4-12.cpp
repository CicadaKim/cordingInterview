#include <iostream>

using namespace std;

class TreeNode
{
public:
    shared_ptr<TreeNode> left = nullptr;
    shared_ptr<TreeNode> right = nullptr;
    int value;

    TreeNode(int val) : value(val){}
};

int countPathWithSum(shared_ptr<TreeNode> root, int sum)
{
    sum - root->value;
}

int main()
{
    return 0;
}