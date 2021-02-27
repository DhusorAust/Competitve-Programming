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
        ll n;
        ll d;
        cin>>n>>d;

        ll arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        for(ll i = 0;i<n;i++)
        {

           bool bl = false;
           for(ll j = 0;;j++)
           {
              if(arr[i]<=0 || bl)
                break;
              ll tmp = arr[i];
              while(tmp!=0)
              {
                  ll rem = tmp%10;
                  if( rem == d)
                  {
                      bl = true;
                      break;
                  }
                  tmp/=10;
              }

              arr[i]-=d;
           }
           if(bl)
            cout<<"YES"<<endl;
           else
            cout<<"NO"<<endl;
        }

    }

    return 0;
}


