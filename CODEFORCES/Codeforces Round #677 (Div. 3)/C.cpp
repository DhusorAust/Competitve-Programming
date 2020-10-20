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

       int arr[n], arr2[n];


       for(int i =0;i<n;i++)
       {
           cin>>arr[i];
           arr2[i] = arr[i];
       }

       if(n==1)
       {
           cout<<1<<endl;
           continue;
       }


        sort(arr,arr+n);
        int ans = -1;
        for(int i=1;i<n-1;i++)
        {
           if(arr2[i]==arr[n-1] && (arr2[i]>arr2[i-1] || arr2[i]>arr2[i+1] ))
              {
                  ans = i+1;
                  break;
              }
        }

        if(arr2[0]== arr[n-1] && arr2[1]<arr2[0])
            ans = 1;
        if(arr2[n-1]== arr[n-1] && arr2[n-2]<arr2[n-1])
            ans = n;

        cout<<ans<<endl;





    }

    return 0;
}

