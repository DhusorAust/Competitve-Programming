#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
//priority_queue<int, vector<int>, greater<int> > min_q;
ll A[10000005];
ll B[10000005];
int main()
{
    FAST
    ll N = 10000000;
    for(ll i=1;i<=N;i++)
    {
        for(ll j = i; j<=N; j += i)
        {
            A[j]+=i;
        }
    }
    for(ll i = 1;i<=N;i++)
    {
        if(A[i]<=N && B[A[i]]==0)
            B[A[i]] = i;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(B[n]==0) cout<<-1<<endl;
        else cout<<B[n]<<endl;
    }
    return 0;
}
