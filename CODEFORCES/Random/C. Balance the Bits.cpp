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

        if( !(s[0]=='1' && s[n-1]=='1') )
        {
            cout<<"NO"<<endl;
            continue;
        }
        ll cnt = 0;
        for(ll i = 0;i<n;i++)
        {
            if(s[i]=='0')
                cnt++;
        }
        if(cnt%2==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        cnt = n-cnt;
        ll one = 0, zero = 0;
        string s1, s2;
        for(ll i = 0;i<n;i++)
        {
            if(s[i]=='1')
            {
                one++;
                if(one<=cnt/2)
                {
                    s1.push_back('(');
                    s2.push_back('(');
                }
                else
                {
                    s1.push_back(')');
                    s2.push_back(')');
                }
            }
            else
            {
                zero++;
                if(zero%2==0)
                {
                    s1.push_back('(');
                    s2.push_back(')');
                }
                else
                {
                    s2.push_back('(');
                    s1.push_back(')');
                }
            }
        }
        cout<<s1<<endl;
        cout<<s2<<endl;
    }

    return 0;
}
