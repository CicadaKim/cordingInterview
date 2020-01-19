#include <iostream>
#include <map>
#include <random>
using namespace std;

class TreeNode
{
public:
    shared_ptr<TreeNode> left = nullptr;
    shared_ptr<TreeNode> right = nullptr;
    int value;
    int leftCount = 0;
    int rightCount = 0;

    TreeNode(int val) : value(val){}
};

class RandomBST
{
public:
    shared_ptr<TreeNode> root = nullptr;

    void insert(int val)
    {
        insert(shared_ptr<TreeNode>(new TreeNode(val)));
    }

    void insert(shared_ptr<TreeNode> newNode)
    {
        if(root == nullptr)
        {
            root = newNode;
            return;
        }

        shared_ptr<TreeNode> current = root;

        while(current!=nullptr)
        {
            if(current->value > newNode->value)
            {
                current->leftCount++;
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
                current->rightCount++;
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

    shared_ptr<TreeNode> getRandomNode()
    {
        random_device rnd;
        mt19937 randGenerator(rnd());
        uniform_int_distribution<int> range(1, root->leftCount + root->rightCount + 1);

        int findValue = range(randGenerator);
        return getRandomNodeRec(root, findValue);
    }
private:
    shared_ptr<TreeNode> getRandomNodeRec(shared_ptr<TreeNode> root, int findValue)
    {
        int finder = findValue - root->leftCount;
        if(finder == 1)
            return root;
        else if(finder <= 0)
            return getRandomNodeRec(root->left, findValue);
        else
            return getRandomNodeRec(root->right, findValue - root->leftCount - 1);
    }
};

int main()
{
    RandomBST bst;
    bst.insert(50);
    bst.insert(20);
    bst.insert(35);
    bst.insert(40);
    bst.insert(70);
    bst.insert(80);

    map<int,int> cnt;

    for(int i=0; i<10000; i++)
    {
        cnt[bst.getRandomNode()->value]++;
    }

    for(auto& elem:cnt)
    {
        cout<<elem.first<<" : "<<elem.second<<endl;
    }

    return 0;
}