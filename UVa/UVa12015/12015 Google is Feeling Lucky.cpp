#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cases,count,line;
    string input;
    cin>>cases;
    for(int i=1;i <= cases;i++)
    {
        map<int,vector<string> > ans;
        line = 10;
        while(line--)
        {
            cin>>input>>count;
            ans[count].push_back(input);
        }
        cout<<"Case #"<<i<<":\n";
        for(auto &P:ans.rbegin()->second)
            cout<<P<<"\n";
    }
    return 0;
}



