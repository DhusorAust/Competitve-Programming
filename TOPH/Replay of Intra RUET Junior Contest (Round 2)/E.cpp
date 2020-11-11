#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

double pi = acos(-1);


int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        double b;
        cin>>b;

        double a = 35.730091830127577;

        double ans = (100.00/a)*b;

        ans= sqrt(ans);

        printf("%.10f\n",ans);

    }


    return 0;
}

