
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
int tbl[6][100009];
int n;
int ans = INT_MAX;
void f(int i,int mn, int mx)
{

    if(i==n)
    {
        ans = min(ans,abs(mx-mn));
        return;
    }

    for(int j = 0;j<6;j++)
    {

        f(i+1,min(mn,tbl[j][i]),max(mx,tbl[j][i]));
    }
}

int main()
{
    FAST

    int arr[6];

    for(int i=0;i<6;i++)
    {
        cin>>arr[i];
    }

    cin>>n;

    int arr2[n];

    for(int i = 0;i<n;i++)
    {
        cin>>arr2[i];
    }

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<n;j++)
        {
            tbl[i][j] = arr2[j]- arr[i];
        }
    }

    f(0,INT_MAX,INT_MIN);

    cout<<ans<<endl;


    return 0;
}
