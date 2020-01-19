#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class NodeWithMin
{
	public:
		NodeWithMin(int v, int minValue) : localMin(minValue), value(v)
		{
		}
		int localMin;
		int value;
};
		

class StackWithMin : public stack<NodeWithMin>
{
	public:
		
		int Min()
		{
			if(empty())
				return INT_MAX;
			return top().localMin;
		}
		
		void Push(int value)
		{
			int minValue = value;
			
			minValue = min(minValue,Min());
			
			push(NodeWithMin(value,minValue));
			cout<<Min()<<endl;
		}
		
		void Pop()
		{
			if(empty())
				return;
				
			pop();
				
			cout<<Min()<<endl;
		}
};

int main()
{
	StackWithMin minStack;
	minStack.Push(5);
	minStack.Push(6);
	minStack.Push(3);
	minStack.Push(7);
	minStack.Pop();
	minStack.Pop();
	
	return 0;
}
