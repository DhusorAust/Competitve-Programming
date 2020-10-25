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
        ll n;
        cin>>n;

        ll arr[n][n];
        memset(arr, 0 , sizeof arr);


            for(int i=0;i<n;i++)
            {   for(int j=0;j<n;j++)
                {
                    if(i+j==n-1 || i==j)
                        arr[i][j] = 1;
                }
            }

            if(n%2!=0)
            {
                ll a = n/2;
                arr[a+1][a] = 1;
                arr[a-1][a] = 1;
                arr[a][a+1] = 1;
                arr[a][a-1] = 1;
            }




        for(int i=0;i<n;i++)
        {   for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }

            cout<<endl;

        }
    }

    return 0;
}

