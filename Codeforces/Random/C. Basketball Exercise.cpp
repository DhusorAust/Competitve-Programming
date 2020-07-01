#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
ll ans1[100009],ans2[100009];
int main()
{
    FAST

    ll n;
    cin>>n;

    ll arr1[n];
    ll arr2[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }

    if(n==1)
    {
        cout<<max(arr1[0],arr2[0])<<endl;
        return 0;
    }


    ans1[0] = arr1[0];
    ans2[0] = arr2[0];

    ans1[1] = arr1[1]+ans2[0];
    ans2[1] = arr2[1]+ans1[0];

    ll ans3 = max(ans1[1],ans2[1]);

    for(int i=2;i<n;i++)
    {
        ll tmp1 = max(ans2[i-1],ans2[i-2]);
        ll tmp2 = max(ans1[i-1],ans1[i-2]);

        ans1[i] = arr1[i]+tmp1;
        ans2[i] = arr2[i]+tmp2;

        ans3 = max(ans2[i],ans1[i]);
    }

    cout<<ans3<<endl;

    return 0;
}

