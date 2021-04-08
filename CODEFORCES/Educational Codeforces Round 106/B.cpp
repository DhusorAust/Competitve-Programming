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
        string s;
        cin>>s;
        ll n = s.size();
        int prev = -2;
        bool bol = true;;
        char last = s[0];
        for(ll i = 1;i<n;i++)
        {
            if(s[i]<last && i-prev>1)
            {
                prev = i;
            }
            else if(s[i]<last && i-prev<=1)
            {
                bol = false;
                break;
            }
            else if(s[i]>last && i-prev>1)
            {
                prev = i;
            }
            else
            {
                last = s[i];
            }
        }
        //cout<<"1 "<<bol<<endl;
        if(bol)
        {
            cout<<"YES"<<endl;
            continue;
        }
        prev = 0;
        bol = true;;
        last = '0';
        for(ll i = 1;i<n;i++)
        {
            if(s[i]<last && i-prev>1)
            {
                prev = i;
            }
            else if(s[i]<last && i-prev<=1)
            {
                //cout<<last<<" "<<s[i]<<" "<<i<<" "<<prev<<endl;
                //cout<<"what "<<i<<endl;
                bol = false;
                break;
            }
            else if(s[i]>last && i-prev>1)
            {
                prev = i;
            }
            else
            {
                last = s[i];
            }
           // cout<<"eta "<<i<<" "<<last<<endl;
        }
      //  cout<<"2 "<<bol<<endl;
        if(bol)
        {
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }

    return 0;
}


