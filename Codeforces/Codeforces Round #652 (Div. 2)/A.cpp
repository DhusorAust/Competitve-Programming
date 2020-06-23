#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;
        int one  = n;
        int zero  = -1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                one  = i;
                break;
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                zero  = i;
                break;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(i>=one && i<zero)
                continue;
            cout<<s[i];
        }

        cout<<endl;

    }
    return 0;
}
