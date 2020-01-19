#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool has_path(vector<vector<int> > graph, int i, int j )
{
	vector<bool> visit( graph.size() , false );
	queue<int> q;
	q.push(i);
	visit[i] = true;
	
	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		
		for(int next : graph[current])
		{
			if(visit[next])
				continue;
			if(next == j)
				return true;
			q.push(next);
			visit[next] = true;
		}
	}
	return false;
}


int main()
{
	cout<<has_path( {{1,3} , {2} , {3,4} , {1} ,{2,3} },0,4 )<<endl;
	
	return 0;
}
