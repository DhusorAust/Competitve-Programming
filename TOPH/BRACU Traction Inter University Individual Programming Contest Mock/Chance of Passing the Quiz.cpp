#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[52][52];

ll pw[52];


int main()
{
    pw[0] = 1;
    for(ll i = 1;i<52;i++)
    {
        pw[i] = 2*pw[i-1];
    }
    for(ll i = 0;i<52;i++)
    {
        arr[i][0] = 1;
    }
    
    arr[0][0] = 1;
    for(ll i = 1;i<52;i++)
    {
        for(ll j = 1;j<i;j++)
        {
            arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
        }
    }
    
  

    ll t;
    cin>>t;

    while(t--)
    {
        ll n,x;
        cin>>n>>x;

        ll tot = 0;
        for(ll i = 0;i<=n;i++)
        {
            if(i*100>=x*n)
            {
               // cout<<tot<<" ";
                tot+=arr[n+1][i];
            }
        }

     // cout<<tot<<" "<<pw[n]<<endl;
      double a,b;
      a = tot;
      b = pw[n];
      double ans = a/b;
      printf("%.2f\n",ans);




    }


}