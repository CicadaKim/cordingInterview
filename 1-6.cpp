#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string zipString(string& s)
{
	map<char,int> counts;
	for(char c : s)
	{
		if(counts.find(c) != counts.end())
			counts[c]++;
		else
			counts[c] = 1;
	}
	
	string ret = "";
	
	for(auto count : counts)
	{
		ret.push_back(count.first);
		ret.push_back( count.second + '0' );
	}
	if(ret.size() > s.size())
		return s;
	
	return ret;
	
}

int main()
{
	string s = "wqkeasdzxca";
	cout<<zipString(s);
	
	return 0;
}
