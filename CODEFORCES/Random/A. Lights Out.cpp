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
    ll arr[3][3],  arr2[3][3];
    for(ll i = 0;i<3;i++)
    {
        for(ll j = 0;j<3;j++)
        {
            cin>>arr[i][j];
            arr2[i][j] = arr[i][j];
        }
    }
    for(ll i = 0;i<3;i++)
    {

        for(ll j = 0;j<3;j++)
        {
            ll x = 0;
            if(i-1>=0)
                x+= arr2[i-1][j];
            if(i+1<3)
                x+= arr2[i+1][j];
            if(j+1<3)
                x+= arr2[i][j+1];
            if(j-1>=0)
                x+= arr2[i][j-1];
            arr[i][j]+=x;
        }
    }
    for(ll i = 0;i<3;i++)
    {
        for(ll j = 0;j<3;j++)
        {
            if(arr[i][j]%2==0)
                cout<<1;
            else
                cout<<0;
        }
        cout<<endl;
    }

    return 0;
}

