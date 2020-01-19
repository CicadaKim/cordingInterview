#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cctype>
using namespace std;


bool isPofPalindrome(string &s)
{
	s.erase(remove(s.begin(),s.end(),' '),s.end());
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	
	int numOdd = 0;
	if(s.size() % 2 == 1)
		numOdd = 1;
	
	map<char,int> counts;
	
	for(char c : s)
	{
		if(counts.find(c) != counts.end())
			counts[c]++;
		else
			counts[c] = 1;
	}
	
	for(auto it = counts.begin(); it!=counts.end(); it++ )
	{
		if( it->second % 2 == 1)
		{
			numOdd--;
			if(numOdd<0)
				return false;
		}
	}
		
	return true;
}

int main()
{
	string s = "Tact Coa";
	cout<<isPofPalindrome(s);
	return 0;
}
