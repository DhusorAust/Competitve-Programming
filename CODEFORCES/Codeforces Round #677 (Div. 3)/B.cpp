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

        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        int I1,I2;
        for(int i = 0;i<n;i++)
        {
            if(arr[i]==1)
            {
                I1 = i;
                break;
            }
        }

         for(int i = n-1;i>=0;i--)
        {
            if(arr[i]==1)
            {
                I2 = i;
                break;
            }
        }
           int cnt = 0;
        for(int i =I1;i<=I2;i++)
        {
            if(arr[i]==0)
                cnt++;
        }

        cout<<cnt<<endl;




    }

    return 0;
}

