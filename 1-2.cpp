#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPermutation(string s1, string s2)
{
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	
	return s1==s2;
}

int main()
{
	cout<<isPermutation("abcdef","abcdfe")<<endl;
	
	return 0;
}
