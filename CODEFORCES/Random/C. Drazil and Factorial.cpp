#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll n;
    cin>>n;

    string s;
    cin>>s;

    vector<int> v;

    for(int i=0;i<n;i++)
    {
        int tmp = s[i]-48;

        if(tmp<=1)
            continue;

       if(tmp==2 || tmp==3 || tmp==5 || tmp==7)
       {
           v.push_back(tmp);
       }
       else if(tmp==9)
       {
           v.push_back(3);
           v.push_back(3);
           v.push_back(2);
           v.push_back(7);
       }

        else if(tmp==4)
        {
            v.push_back(3);
            v.push_back(2);
            v.push_back(2);
        }

        else if(tmp==6)
        {
            v.push_back(5);
            v.push_back(3);
        }

        else if(tmp==8)
        {
            v.push_back(7);
            v.push_back(2);
            v.push_back(2);
            v.push_back(2);
        }

    }

    sort(v.begin(),v.end(), greater<int>());

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }

    cout<<endl;

    return 0;
}
