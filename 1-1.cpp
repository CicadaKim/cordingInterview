#include <iostream>
#include <algorithm>
using namespace std;

bool IsUnique(string&& str)
{
	sort(str.begin(),str.end());
	
	for(int i=0; i<str.size()-1; i++)
	{
		if(str[i] == str[i+1])
			return false;
	}
	return true;
}

int main()
{
	cout<<IsUnique("abcdefga
	")<<endl;
	return 0;
}
