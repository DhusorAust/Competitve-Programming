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
 ll a, b, t, k;
 ll arr[200009];
 void f(ll i, ll sum)
 {
     f(i+1,sum);
     f(i+1,sum+arr[i]);
 }

int main()
{
    FAST
    for(ll i = 0;i<100000;i++)
    {
        arr[i] = 1;
    }
    cin>>t>>k;
    while(t--)
    {
        cin>>a>>b;


    }

    return 0;
}

