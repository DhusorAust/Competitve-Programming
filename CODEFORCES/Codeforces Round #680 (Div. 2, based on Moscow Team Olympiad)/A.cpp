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
    int t;
    cin>>t;

    while(t--)
    {
        ll n, x;
        cin>>n>>x;

        ll arr1[n], arr2[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }

        for(int i=0;i<n;i++)
        {
            cin>>arr2[i];
        }

        bool bol = true;
        for(int i=0,j = n-1;i<n;i++,j--)
        {
            if(arr1[i]+arr2[j]>x)
            {
                bol = false;
                break;
            }
        }
        if(bol)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}

