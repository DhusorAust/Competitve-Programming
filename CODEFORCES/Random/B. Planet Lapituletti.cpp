#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;
ll H, M;
char f4(char c)
{
    if(c=='2')
        return '5';
    if(c=='5')
        return '2';
    return c;
}
bool f3(ll h, ll m)
{
    string s = to_string(h);
    if(s.size()==1)
        s = "0"+s;
    reverse(s.begin(),s.end());
    for(ll i = 0;i<s.size();i++)
    {
        s[i] = f4(s[i]);
    }
    h = stoi(s);
    s = to_string(m);
    if(s.size()==1)
        s = "0"+s;
    reverse(s.begin(),s.end());
    for(ll i = 0;i<s.size();i++)
    {
        s[i] = f4(s[i]);
    }
    m = stoi(s);
    if(m<H && h<M)
        return true;
    return false;
}
bool f1(ll a)
{
    if(a==0 || a == 1 || a== 2 || a==5 || a==8)
        return true;
    return false;
}
bool f(ll a)
{
    if(a==0)
        return true;
    while(a!=0)
    {
        if( !f1(a%10) )
            return false;
        a/=10;
    }
    return true;
}
int cnt(ll a)
{
    if(a==0)
        return 1;
    ll cnt = 0;
    while(a!=0)
    {
        a/=10;
        cnt++;
    }
    return cnt;
}
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {

        cin>>H>>M;
        string s;
        cin>>s;
        ll h = stoi(s.substr(0,2));
        ll m = stoi(s.substr(3,2));
        while(true)
        {
            if(f(h) && f(m) && f3(h,m))
                break;
            if(m==M-1)
            {
                m = 0;
                if(h==H-1)
                {
                    h = 0;
                }
                else
                {
                    h++;
                }
            }
            else
            {
                m++;
            }
        }
        if(cnt(h)==1)
        {
            cout<<0;
        }
        cout<<h<<":";
        if(cnt(m)==1)
        {
            cout<<0;
        }
        cout<<m<<endl;
    }
    return 0;
}

