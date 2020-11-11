#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;


int main()
{
    FAST

    ll n;
    cin>>n;

    string s;
    cin>>s;
    vector<ll> v;
    ll cnt = 1;
    for(ll i = 1;i<n;i++)
    {
        if(s[i]!=s[i-1])
        {


            v.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    v.push_back(cnt);
    /*for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;*/
    ll ans = 0;
    ll m = v.size();
    for(ll i = 0;i<m;i++)
    {
        bool bol = true;
        if(v[i]>1)
        {
            ans++;
            continue;
        }

        if(i==m-1)
        {
            ans++;
            break;
        }

        for(ll j = i+1;j<m;j++)
        {
            if(v[j]>1)
            {
                 v[j]--;
                 bol = false;
                 break;
            }
        }
        ans++;
        if(bol)
        {
           ll temp  = m-i-2;
           //cout<<"temp"<<" "<<temp<<" "<<ans<<" "<<i<<endl;
           if(temp%2==0)
            ans+=temp/2;
           else
            ans+=temp/2+1;
           break;

        }

    }

    cout<<ans<<endl;



    return 0;
}

