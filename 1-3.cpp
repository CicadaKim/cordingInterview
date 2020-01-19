#include <iostream>
#include <string>
using namespace std;

string convertBlank(string& s)
{
	string ret="";
	for(auto c : s)
	{
		if(c==' ')
			ret.append("%20");
		else
			ret.push_back(c);
	}	
	return ret;
}

int main()
{
	string s = "a sad qweqwe asdasd";
	cout<<convertBlank(s)<<endl;
	
	return 0;
}
