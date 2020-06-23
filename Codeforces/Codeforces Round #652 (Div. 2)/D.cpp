#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll arr[2000009];
int main()
{
    arr[1] = 0;
    arr[2] = 0;
    for(ll i = 3;i<2000005;i++)
    {
       arr[i] = ((arr[i-2]*2) + arr[i-1])%mod;
       if(i%3==0)
         arr[i] = (arr[i]+ 1)%mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<(arr[n]*4)%mod<<endl;
    }
}

