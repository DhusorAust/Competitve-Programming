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

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        if(n%2==0)
        {
            ll x = n/2;
            ll y = sqrt(x);
            if(y*y==x)
            {
                cout<<"YES"<<endl;
                continue;
            }
        }
        if(n%4==0)
        {
            ll x = n/4;
            ll y = sqrt(x);
            if(y*y==x)
            {
                cout<<"YES"<<endl;
                continue;
            }

        }
        cout<<"NO"<<endl;
    }

    return 0;
}

