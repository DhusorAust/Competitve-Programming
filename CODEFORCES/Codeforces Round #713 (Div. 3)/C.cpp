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
        ll a, b;
        cin>>a>>b;
        ll n = a+b;
        string s;
        cin>>s;
        if(a%2==1 && b%2==1)
        {
            cout<<-1<<endl;
            continue;
        }
        string s2;
        s2 = s;
        for(ll i = 0;i<n;i++)
        {
            if(s[i]=='?')
            {
                if(s[n-i-1]=='1')
                {
                    s2[i] = '1';
                }
                else if(s[n-i-1]=='0')
                {
                    s2[i] = '0';
                }
            }
        }
        ll A = 0; ll B = 0;
        for(ll i = 0; i<n;i++)
        {
            if(s2[i]=='0')
               A++;
            else if(s2[i]=='1')
               B++;
        }
       // cout<<"s2 = "<<s2<<endl;
        if(A>a || B>b)
        {
            cout<<"-1"<<endl;
            continue;
        }
        string s3 = s2;
        ll A2 = a-A;
        ll B2 = b-B;
        //cout<<A2<<" "<<B2<<endl;
        for(ll i = 0;i<n;i++)
        {
           // cout<<s2[i]<<endl;
            if(s2[i]=='?')
            {
               // cout<<n-i-1<<" "<<i<<endl;
                if(n-i-1 == i )
                {
                   // cout<<"what "<<A2<<endl;
                    if( (A2>=1) && (A2%2==1) )
                    {
                       // cout<<"what1 "<<s3<<endl;
                        s3[i] = '0';
                        A2--;
                    }
                    else if((B2>=1) && (B2%2==1))
                    {
                        s3[i] = '1';
                        B2--;
                    }
                   // cout<<s3<<endl;
                }
                else
                {
                    if(A2>=2)
                    {
                        s3[i] = '0';
                        s3[n-i-1] = '0';
                        A2-=2;
                    }
                    else if(B2>=2)
                    {
                        s3[i] = '1';
                        s3[n-i-1] = '1';
                        B2-=2;
                    }
                }
            }
        }
        if(A2!=0 || B2!=0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        bool bol = true;
        for(ll i = 0,j = n-1;i<n/2;i++,j--)
        {
            if(s3[i]!=s3[j])
                {
                    bol = false;
                    break;
                }
        }

       // cout<<s3<<endl;
        if(bol)
        cout<<s3<<endl;
        else
         cout<<"-1"<<endl;
    }

    return 0;
}
/*
1
0 3
1?1
*/
