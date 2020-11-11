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

    ll n;
    cin>>n;

    if(n%3==0)
        cout<<n/3<<" 0 0"<<endl;
    else if( n>=5 && (n-5)%3==0)
    {
        cout<<(n-5)/3<<" 1 0"<<endl;
    }
    else if(n>=7 && (n-7)%3==0)
    {
        cout<<(n-7)/3<<" 0 1"<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}

