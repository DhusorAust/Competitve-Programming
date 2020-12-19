#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        string s;
        cin>>s;
        string str = "2020";

        string str2;
        str2.push_back(s[0]);
        str2.push_back(s[1]);
        str2.push_back(s[2]);
        str2.push_back(s[3]);

        if(str2==str)
        {
            cout<<"YES"<<endl;
            continue;
        }

        str2.clear();
        str2.push_back(s[n-4]);
        str2.push_back(s[n-3]);
        str2.push_back(s[n-2]);
        str2.push_back(s[n-1]);

        if(str2==str)
        {
            cout<<"YES"<<endl;
            continue;
        }


        str2.clear();
        str2.push_back(s[0]);
        str2.push_back(s[n-3]);
        str2.push_back(s[n-2]);
        str2.push_back(s[n-1]);

        if(str2==str)
        {
            cout<<"YES"<<endl;
            continue;
        }

        str2.clear();
        str2.push_back(s[0]);
        str2.push_back(s[1]);
        str2.push_back(s[n-2]);
        str2.push_back(s[n-1]);

        if(str2==str)
        {
            cout<<"YES"<<endl;
            continue;
        }

        str2.clear();
        str2.push_back(s[0]);
        str2.push_back(s[1]);
        str2.push_back(s[2]);
        str2.push_back(s[n-1]);

        if(str2==str)
        {
            cout<<"YES"<<endl;
            continue;
        }

        cout<<"NO"<<endl;
    }

    return 0;
}

