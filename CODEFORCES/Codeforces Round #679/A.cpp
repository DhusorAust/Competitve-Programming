
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
        {
            cin>>arr[i];
        }

        for(int i=0, j=n-1;i<n;i++,j--)
        {
            if(i<n/2)
            {
                if(arr[i]>0)
                {
                    cout<<abs(arr[j])<<" ";
                }
                else
                {
                    cout<<"-"<<abs(arr[j])<<" ";
                }
            }
            else

            {
                if(arr[i]>0)
                {
                    cout<<"-"<<abs(arr[j])<<" ";
                }
                else
                {
                    cout<<abs(arr[j])<<" ";
                }
            }
        }
        cout<<endl;



    }

    return 0;
}
