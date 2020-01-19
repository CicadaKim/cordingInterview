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

int findKstBehind(list<int> list, int k)
{
	auto kth = list.begin();
	auto cont = next(list.begin(),k);
	
	if(cont == prev(list.end(),1) )
		return *kth; // kth dose not exist
	
	for( ; cont != list.end(); cont++)
		kth++;
		
	return *kth;
}

int main()
{
	list<int> lst{1,2,3,4,5};
	cout<<findKstBehind(lst,2)<<endl;
	return 0;
}

