#include <iostream>
#include <stack>
using namespace std; 

class MyQueue
{
	private: 
	
	stack<int> prevStack;
	stack<int> nextStack;
	
	public:
		
	void Push(int value)
	{
		prevStack.push(value);
		cout<<Peek()<<endl;
	}
	
	int Pop()
	{
		ShiftStacks();
		auto v = nextStack.top();
		nextStack.pop();
		cout<<Peek()<<endl;
	}
	
	int Peek()
	{
		ShiftStacks();
		return nextStack.top();
	}
	
	void ShiftStacks()
	{
		if(!nextStack.empty())
			return;
		
		while(!prevStack.empty())	
		{
			nextStack.push(prevStack.top());
			prevStack.pop();
		}
	}
};

int main()
{
	MyQueue q;
	
	q.Push(0);
	q.Push(1);
	q.Push(2);
	q.Pop();
	q.Push(5);
	q.Pop();
	q.Pop();
	q.Push(8);
	q.Pop();
	
	return 0;
}
