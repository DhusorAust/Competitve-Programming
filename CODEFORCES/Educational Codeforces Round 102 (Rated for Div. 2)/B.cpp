#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;

bool isDiv(string a, string b)
{
    if(b.size()>a.size())
        return false;
    for(int i=0;i<a.size()-b.size()+1;i++)
    {
        bool bol = true;
        for(int k = 0,j = i;k<b.size();k++,j++)
        {
            if(a[j]!=b[k])
            {
                bol = false;
                break;
            }
        }
        if(bol)
            return true;
    }
    return false;
}

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;

        int n1 = s1.size();
        int n2 = s2.size();

        int lcm = (n1*n2)/__gcd(n1,n2);



        int dv = lcm/min(n1,n2);
        string s3;
        if(n1<n2)
        {

            for(ll i =0;i<dv;i++)
            {
                s3+=s1;
            }
        }
        else
        {
            for(ll i =0;i<dv;i++)
            {
                s3+=s2;
            }
        }

        bool bol1 = true, bol2= true;

        for(ll i = 0,j = 0;i<lcm;i++)
        {
            if(s3[i]!=s1[j])
            {
                bol1 = false;
                break;
            }
            j = (j+1)%n1;
        }

        for(ll i = 0,j = 0;i<lcm;i++)
        {
            if(s3[i]!=s2[j])
            {
                bol2 = false;
                break;
            }
            j = (j+1)%n2;
        }

        if(bol1 && bol2)
            cout<<s3<<endl;
        else
            cout<<-1<<endl;
    }

    return 0;
}


