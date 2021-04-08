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

    ll t;
    cin>>t;

    while(t--)
    {
        ll n, m, x;
        cin>>n>>m>>x;

        ll col = x/n;
        if(x%n!=0)
            col++;
        ll row = x%n;
        if(row==0)
            row = n;

       // cout<<row<<" "<<col<<endl;

        cout<<(row-1)*m+col<<endl;
    }

    return 0;
}

