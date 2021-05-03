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


int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;

        string s;
        cin>>s;
        if(s[0]=='M')
        {
            cout<<"NO"<<endl;
            continue;
        }
        int M  = 0;
        for(ll i = 0;i<n;i++)
        {
            if(s[i]=='M')
                M++;
        }
        if(n/3!=M)
        {
            cout<<"NO"<<endl;
            continue;
        }

        int cnt = 0,cnt2=0;
        bool bol = false;
        for(ll i = 0;i<n;i++)
        {
            if(s[i]=='T')
                cnt++;
            else
                cnt2++;

            if(cnt-cnt2>n/3)
            {
                bol = true;
                break;
            }

             if(cnt2>cnt)
            {
                bol = true;
                break;
            }

        }
        if(bol)
        {
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;




    }

    return 0;
}

