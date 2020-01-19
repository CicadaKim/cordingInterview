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

void removeOverlap(list<int>& lst)
{
	for(auto anchor = lst.begin(); anchor!=lst.end(); anchor++)
	{
		for(auto compare = next(anchor,1); compare!=lst.end(); compare++)
		{
			if(*compare == *anchor)
				compare = lst.erase(compare);
		}
	}
}

int main()
{
	list<int> lst{1,2,3,4,5,4,5,4};
	removeOverlap(lst);
	
	cout<<lst;
	return 0;
}
