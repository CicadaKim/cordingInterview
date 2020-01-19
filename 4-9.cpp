#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class TreeNode
{
public:
    shared_ptr<TreeNode> left = nullptr;
    shared_ptr<TreeNode> right = nullptr;
    int value;

    TreeNode(int val) : value(val){}
};

void addBST(shared_ptr<TreeNode> root, shared_ptr<TreeNode> newNode)
{
    shared_ptr<TreeNode> current = root;
    while(current!=nullptr)
    {
        if(current->value > newNode->value)
        {
            if(current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            else    
            {
                current = current->left;
            }
        }
        else
        {
            if(current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            else    
                current = current->right;
        }
    }
}

int findAllWayToBuildRecursive(vector<shared_ptr<TreeNode>>& nexts)
{
    if(nexts.size() == 0)
        return 1;

    int sum = 0;
    for(const auto& node : nexts)
    {
        vector<shared_ptr<TreeNode>> deliver = nexts;
        deliver.erase(find(deliver.begin(),deliver.end(),node));
        if(node->left != nullptr)
            deliver.push_back(node->left);
        if(node->right != nullptr)    
            deliver.push_back(node->right);

        sum += findAllWayToBuildRecursive(deliver); 
        cout<<endl;  
    }
    return sum;
}

int findAllWayToBuild(shared_ptr<TreeNode> root)
{
    if(root == nullptr)
        return 0;

    vector<shared_ptr<TreeNode>> nexts;
    nexts.push_back(root);
    return findAllWayToBuildRecursive(nexts);
}

int main()
{
    shared_ptr<TreeNode> root(new TreeNode(50));
    addBST(root, shared_ptr<TreeNode>(new TreeNode(20)));
    addBST(root, shared_ptr<TreeNode>(new TreeNode(60)));
    addBST(root, shared_ptr<TreeNode>(new TreeNode(10)));
    addBST(root, shared_ptr<TreeNode>(new TreeNode(25)));
    
    cout<<findAllWayToBuild(root)<<endl;

    return 0;
}