#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int peekKeyBySmallestValue(const map<int,int>& in)
{
    auto it = min_element(in.begin(),in.end(),[](const auto& left, const auto& right) -> bool{return left.second < right.second;});
    
    return it->first;
}

int main()
{
    vector<vector<int>> out;
    map<int,int> in;

    int projects;
    cin>>projects;

    for(int i=0; i<projects; i++)
        in[i] = 0;

    out = vector<vector<int>>(projects);

    int dependencyNum;
    cin>>dependencyNum;

    for(int i=0; i<dependencyNum; i++)
    {
        int prev,next;
        cin>>prev>>next;
        out[prev].push_back(next);
        in[next]++;
    }

    vector<int> result;
    
    while(!in.empty())
    {
        int prev = peekKeyBySmallestValue(in);

        if(in[prev] != 0)
        {
            cout<<"impossible"<<endl;
            return 0;
        }

        for_each(out[prev].begin(), out[prev].end(), [&in](int dest){in[dest]--;});

        in.erase(prev);
        result.push_back(prev);
    }

    for_each(result.begin(), result.end(), [](int value){ cout<<value<<" "; });

    return 0;
}