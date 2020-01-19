#include <iostream>

using namespace std;

class TreeNode
{
	public:
		TreeNode* left=nullptr;
		TreeNode* right=nullptr;
		int value;
}

int checkHeight(TreeNode& root)
{
	if(root == nullptr)
		return 0;
	
	int leftHeight = checkHeight(root.left);
	int rightHieght = checkHeight(root.right);
	
	if(abs(leftHeight - rightHeight) > 1)
		return -99999;
	
	return max(leftHeight,rightHeight)+1;
}



int main()
{
	
	
	return 0;
}
