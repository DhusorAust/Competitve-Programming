#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;



bool check(ll n)
{
    ll x = n;

    while(n!=0)
    {
        ll y = n%10;
        n/=10;
        if(y==0)
            continue;
        if(x%y!=0)
            return false;
    }

    return true;
}
int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        //cout<<check(n)<<endl;
        for(;;)
        {
            if(check(n))
                break;
            n++;
        }

        cout<<n<<endl;

    }

    return 0;
}

