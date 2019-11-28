#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

bool PalindromPermutation(string &&str)
{
	map<char,int> m;
	int realSize = 0;
	
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	
	for(char c : str)
	{
		if(c==' ')
			continue;
		m[c]++;
		realSize++;
	}
	
	int oddCount = realSize % 2;
	
	for(auto elem : m)
	{
		oddCount -= (elem.second % 2);
		if(oddCount < 0)
			return false;
	}
	return true;
}

int main()
{
	cout<<PalindromPermutation("Tact Coa")<<endl;
	return 0;
}
