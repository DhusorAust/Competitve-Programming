#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;


int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string b;
        cin>>b;
        string ans;
        ll last;
        ans.push_back('1');
        last = 1+(b[0]-48);

        for(ll i = 1;i<n;i++)
        {
            if(last==2)
            {
               if(b[i]=='1')
               {
                  ans.push_back('0');
                  last = 1;
               }

               else
               {
                   ans.push_back('1');
                   last = 1;
               }
            }
            else if(last == 1)
            {
               if(b[i]=='1')
               {
                  ans.push_back('1');
                  last = 2;
               }

               else
               {
                   ans.push_back('0');
                   last = 0;
               }
            }
            else
            {
               if(b[i]=='1')
               {
                  ans.push_back('1');
                  last = 2;
               }
               else
               {
                   ans.push_back('1');
                   last = 1;
               }
            }
        }
        cout<<ans<<endl;


    }
    return 0;
}

