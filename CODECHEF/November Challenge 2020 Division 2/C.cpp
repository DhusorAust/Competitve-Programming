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

    ll t;
    cin>>t;

    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        n++;
        char s[n];
        s[0] = '_';
        for(ll i  = 1 ; i<n;i++)
        {
            cin>>s[i];
        }

        ll sheet[n];
        ll block[n];

        for(ll i=0;i<n;i++)
        {
            sheet[i] = 0;
            block[i] = 0;
        }

        for(int i = 0;i<n;i++)
        {
            if(s[i]==':')
                sheet[i] =1;
            if(s[i]=='X')
                block[i] = 1;
        }

        for(ll i = 1;i<n;i++)
        {
            block[i] =block[i]+block[i-1];
            sheet[i] =sheet[i]+sheet[i-1];
        }

        ll cnt = 0;
        for(ll i = 1,j= 1;(i<n) && (j<n);)
        {
            if(s[i]=='I' && s[j]=='M')
            {
                ll temp = k+1-abs(i-j)-(sheet[max(i,j)]-sheet[min(i,j)-1]);
                if(temp>0 && (block[max(i,j)]-block[min(i,j)-1])<1 )
                {
                    cnt++;
                    i++;
                    j++;
                }
                else
                {
                    if(i>j)
                        j++;
                    else
                        i++;
                }
            }
            else if (s[i]=='I' && s[j]!='M')
            {
                j++;
            }
            else if (s[i]!='I' && s[j]=='M')
            {
                i++;
            }
            else if (s[i]!='I' && s[j]!='M')
            {
                i++;
                j++;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}

