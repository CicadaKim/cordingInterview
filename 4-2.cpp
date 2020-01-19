#include <iostream>

using namespace std;

TreeNode* CreateMinimalBST(const int& array[], const int start, const int end)
{
	if(end < start)
		return null;
	
	int mid = (start + end) / 2;
	
	TreeNode root = new TreeNode();
	root.value = array[mid];
	root.left = CreateMinimalBST(array,start,mid-1);
	root.right = CreateMinimalBST(array,mid+1,end);
	return root;
}

int main()
{
	
	
	return 0;
}
