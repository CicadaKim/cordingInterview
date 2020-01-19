#include <iostream>
#include <list>
#include <vector>
using namespace std;

class TreeNode
{
	public:
		int value;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
};

vector<list<TreeNode*>> listOfDepths;

void ExtractLevelList(TreeNode* node, int depth)
{
	if(node == nullptr)
		return;
	
	if(listOfDepths.size() < depth)
	{
		listOfDepths.push_back(list<TreeNode*>());
	}
	
	listOfDepths[depth].push_back(node);
	
	ExtractLevelList(node->left, depth + 1);
	ExtractLevelList(node->right, depth + 1);
}

int main()
{
	return 0;
}
