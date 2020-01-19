#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
ostream& operator << (ostream& os, const pair<T,T>& p )
{
	os<<p.first<<" "<<p.second;
	return os;
}

template <typename T>
ostream& operator << (ostream& os, const vector<T> &v)
{
	for(auto e : v)
		os<<e<<endl;
	return os;
}


void set0(vector<vector<int> >& matrix)
{
	set<int> removeX;
	set<int> removeY;
	
	for(int y=0; y<matrix.size(); y++)
	{
		if(removeY.find(y) != removeY.end())
			continue;
		for(int x=0; x<matrix[y].size(); x++)
		{
			if(removeX.find(x) != removeX.end())
				continue;
			
			if(matrix[y][x] == 0)
			{
				removeY.insert(y);
				removeX.insert(x);
			}	
		}
	}
	
	for(auto ry : removeY)
	{
		for(int x=0; x<matrix[0].size(); x++)
			matrix[ry][x] = 0;
	}
	for(auto rx : removeX)
	{
		for(int y=0; y<matrix.size(); y++)
			matrix[y][rx] = 0;
	}
}

int main()
{
	vector<vector<int> > matrix{ {1,2,3},{4,5,6},{7,8,9},{0,1,2},{3,4,0} };
	set0(matrix);
	cout<<matrix<<endl;
	return 0;
}
