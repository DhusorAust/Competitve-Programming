#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

int bs(int l, int r)
{
    int ans = -1;
    while(r>l)
    {
        cout<<"? "<<l<<" "<<r<<endl<<flush;
        int x1;
        cin>>x1;
        if(r-l==1)
        {
            if(x1==l)
                ans = r;
            else
                ans = l;
            break;
        }
        int m = (l+r)/2;
        if(x1<=m)
        {
            cout<<"? "<<l<<" "<<m<<endl<<flush;
            int x2;
            cin>>x2;
            if(x1==x2)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        else
        {
            cout<<"? "<<m<<" "<<r<<endl<<flush;
            int x2;
            cin>>x2;
            if(x1==x2)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
    }

    return ans;
}


int main()
{
    FAST

    int n;
    cin>>n;
    int x = bs(1,n);
    cout<<"! "<<x<<endl<<flush;


    return 0;
}
