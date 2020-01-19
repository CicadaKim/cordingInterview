#include <iostream>

using namespace std;

class TreeNode
{
	public:
		TreeNode* left=nullptr;
		TreeNode* right=nullptr;
		int value;
}

bool IsBST(TreeNode* root, int min, int max)
{
	if(root == nullptr)
		return true;
	
	
	return IsBST(root->left,min,root->value) && IsBST(root->right,root->value,max);	
}

int main()
{
	
	
	return 0;
}
