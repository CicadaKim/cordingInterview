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

list<int> addList(list<int> a, list<int> b)
{
	int carry = 0;
	
	auto ai = a.begin();
	auto bi = b.begin();
	list<int> ret;
	while(ai!=a.end() || bi != b.end() )
	{
		int an,bn;
		an = bn = 0;
		if(ai != a.end())
		{
			an = *ai;
			ai++;
		}
		if(bi != b.end())
		{
			bn = *bi;
			bi++;
		}
		int cal = (carry+an+bn);
		if(cal >= 10)
			carry = 1;
		cal%=10;
		
		ret.push_back(cal);
	}
	
	return ret;
}

int main()
{
	cout<<addList({1,2,3,4},{3,2,7});
	
	return 0;
}
