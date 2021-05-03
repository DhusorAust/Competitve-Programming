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

char f(ll a)
{
    return a+96;
}

int main()
{
    FAST
   // cout<<f(26)<<endl;
    ll n, k;
    cin>>n>>k;

    string s;
    ll j = 1;
    ll a = 1;
    for(ll i = 2;i<=k-1;i++)
    {

    }
    for(ll i = 0;i<n;)
    {
        if(j==k+1 || j==0)
        {
            a*=-1;
            j+=a;
            continue;
        }
        //cout<<j<<endl;
        s.push_back(f(j));
        j+=a;
        i++;
    }
    cout<<s<<endl;


    return 0;
}

