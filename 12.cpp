#include <iostream>
#include <algorithm>
using namespace std;

bool CheckPermutation(string&& str1, string&& str2)
{
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	return str1==str2;
}

int main()
{
	cout<<CheckPermutation("asdsaqwewq","dsasaqwewq");
	return 0;
}
