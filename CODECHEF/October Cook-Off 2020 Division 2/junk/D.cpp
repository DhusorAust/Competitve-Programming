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
       int n;
       cin>>n;

       int arr[n];

       for(int i=0;i<n;i++)
           cin>>arr[i];

       int sum = 0;
       for(int i=0;i<n;i++)
       {
           int sum2 = 0;
           for(int j = i;j<n;j++)
           {

              int miin = INT_MAX;
              int gcd = 0;
              for(int k=i;k<=j;k++)
              {
                  miin = min(miin,arr[k]);
                  gcd = __gcd(gcd,arr[k]);
              }


              sum2+= miin-gcd;

              cout<<" "<<sum2<<endl;
           }
            sum+=sum2;
       }
       cout<<sum<<endl;
    }


    return 0;
}

