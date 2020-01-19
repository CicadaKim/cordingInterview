#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
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

template <typename T>
ostream& operator << (ostream& os, const list<T> &v)
{
	for(auto e : v)
		os<<e<<endl;
	return os;
}

list<int> alignList(list<int>& lst, int x)
{
	list<int> align;
	
	for(auto e : lst)
	{
		if(e>=x)
			align.push_back(e);
		else
			align.push_front(e);
	}
	return align;
}

int main()
{
	list<int> lst{1,2,4,5,7,6,5,8,1,2};
	cout<<alignList(lst,5)<<endl;
	
	return 0;
}
