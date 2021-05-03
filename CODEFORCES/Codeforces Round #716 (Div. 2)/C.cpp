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


int main()
{
    FAST
    ll n;
    cin>>n;

    vector<ll> v;
    v.push_back(1);
    ll cnt = 0;
    ll cnt2 = 0;
    ll mod = 1;
    for(ll i = 2;i<n;i++)
    {
        if(__gcd(n,i)!=1)
            continue;
        mod = (mod*i)%n;
        //cout<<mod<<endl;
        v.push_back(i);
        cnt2++;
        if(mod==1)
        {
            cnt = cnt2;
        }
       // cout<<i<<" "<<mod<<" "<<cnt<<endl;
    }
    cout<<cnt+1<<endl;
    for(ll i = 0;i<=cnt;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}

