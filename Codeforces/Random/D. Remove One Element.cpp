#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll n;
    cin>>n;
    ll arr[n],len[n],flag[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        len[i] = 1;
        flag[i] = 0;
    }
    if(arr[n-2]<arr[n-1])
    {
        len[n-2] += 1;
    }
    ll maxl = max(len[n-1],len[n-2]);
    for(ll i= n-3;i>=0;i--)
    {
        ll tmp1 = 0,tmp2 = 0;
        if(arr[i]<arr[i+1])
            tmp1 = len[i+1];
        if(arr[i]<arr[i+2])
            tmp2 = len[i+2];

        if(tmp1>=tmp2)
        {
            len[i] += tmp1;
            maxl = max(maxl,len[i]);
            if(flag[i+1]==1 && tmp1 !=0)
                flag[i] = 1;
        }
        else
        {
            if(flag[i+2]==0)
            {
                 len[i] += tmp2;
                 maxl = max(maxl,len[i]);
                 flag[i]=1;
            }
            else
            {
                if(tmp1>=1)
                {
                     len[i] += tmp1;
                     maxl = max(maxl,len[i]);
                     if(flag[i+1]==1)
                         flag[i] = 1;
                }
                else
                {
                     len[i] += 1;
                     maxl = max(maxl,len[i]);
                     flag[i]=1;
                }

            }
        }
    }

    cout<<maxl<<endl;

    return 0;
}

