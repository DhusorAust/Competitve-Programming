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

    ll arr[3];

    cin>>arr[0]>>arr[1]>>arr[2];

    sort(arr, arr+3);

    ll sum = arr[0]+arr[1]+arr[2];

    sum/=3;

    cout<<min(sum,arr[0]+arr[1])<<endl;

    return 0;
}

