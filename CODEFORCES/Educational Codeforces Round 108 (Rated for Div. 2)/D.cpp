#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
//priority_queue<int, vector<int>, greater<int> > min_q;

ll m1[200009],m2[200009];

int main()
{
    FAST
    ll t;
    cin>>t;

    while(t--)
    {
        ll n, l, r;
        cin>>n>>l>>r;
        ll arr[n];
        for(ll i =0 ;i<n;i++)
        {
            cin>>arr[i];
        }
        for(ll i = 0;i<=n;i++)
        {
            m1[i] = 0;
            m2[i] = 0;
        }
        set<ll> s1, s2;
        for(ll i = 0;i<l;i++)
        {
            m1[arr[i]]++;
            s1.insert(arr[i]);
        }

        for(ll i = l;i<n;i++)
        {
            m2[arr[i]]++;
            s2.insert(arr[i]);
        }
        if(l>=r)
        {
            for(auto a = s1.begin();a!=s1.end();a++)
            {
                ll x = m1[*a];
                ll y = m2[*a];
                m1[*a]-= min(x,y);
                m2[*a]-=min(x,y);
                if(m1[*a]==0)
                    s1.erase(*a);
                if(m2[*a]==0)
                    s2.erase(*a);
            }
            ll diff = l-r;
            ll x = diff/2;
            ll cost = 0;
            for(auto a = s1.begin();a!=s1.end();a++)
            {
                ll y = m1[*a];
                y/=2;
                ll z = min(y,x);
                cost+=z;
                m1[*a]-=z;
                x-=z;
            }

            ll sum = 0;
            for(auto a = s1.begin();a!=s1.end();a++)
            {
                sum+=m1[*a];
            }
            cout<<cost+sum<<endl;
        }
        else
        {
            for(auto a = s2.begin();a!=s2.end();a++)
            {
                ll x = m1[*a];
                ll y = m2[*a];
                m1[*a]-= min(x,y);
                m2[*a]-=min(x,y);
                if(m1[*a]==0)
                    s1.erase(*a);
                if(m2[*a]==0)
                    s2.erase(*a);
            }
            for(auto a = s1.begin();a!=s1.end();a++)
            {
                cout<<*a<<" "<<m1[*a]<<endl;
            }
            for(auto a = s2.begin();a!=s2.end();a++)
            {
                cout<<*a<<" "<<m2[*a]<<endl;
            }
            ll diff = r-l;
            ll x = diff/2;
            ll cost = 0;
            for(auto a = s2.begin();a!=s2.end();a++)
            {
                ll y = m2[*a];
                y/=2;
                ll z = min(y,x);
                cost+=z;
                m2[*a]-=z;
                x-=z;
            }
            cout<<cost<<endl;
            cout<<"s1"<<endl;
            for(auto a = s1.begin();a!=s1.end();a++)
            {
                cout<<*a<<" "<<m1[*a]<<endl;
            }
            cout<<"s2"<<endl;
            for(auto a = s2.begin();a!=s2.end();a++)
            {
                cout<<*a<<" "<<m2[*a]<<endl;
            }
            ll sum = 0;
            for(auto a = s2.begin();a!=s2.end();a++)
            {
                sum+=m2[*a];
            }
            cout<<cost+sum<<endl;
        }
    }

    return 0;
}
/*
1
6 2 4
1 1 2 2 2 2
*/

