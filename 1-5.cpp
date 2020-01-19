#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isOneDifference(string& s1, string& s2)
{
	if(abs(s1.size() - s2.size())>1)
		return false;
	if( s1.size() < s2.size())
		return isOneDifference(s2,s1);
		
	if(s1.size() == s2.size())
	{
		for()
	}
	else if(s1.size() > s2.size())
	{
		
	}
	
	return false;
}

int main()
{
	
	
	return 0;
}
