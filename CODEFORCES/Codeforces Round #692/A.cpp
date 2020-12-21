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
        ll cnt = 0;
        for(ll i = n-1;i>=0;i--)
        {
            if(s[i]!=')')
                break;
            cnt++;
        }

        ll rem = n-cnt;

      //  cout<<rem<<" "<<cnt<<endl;
        if(cnt>rem)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }

    return 0;
}

