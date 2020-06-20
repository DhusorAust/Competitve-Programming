#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string s,A,F;
        F = "FastestFinger";
        A = "Ashishgup";

        int n;
        cin>>n;

        if(n==1)
        {
            s = F;
        }
        else if(n==2)
        {
            s = A;
        }
        else if(n%2!=0)
        {
            s = A;
        }
        else
        {
            int cnt = 0;
            while(n%2 == 0)
            {
                n/=2;
                cnt++;
            }
            if(n==1)
            {
                s = F;
            }
            else if(cnt==1)
            {
                bool bol=true;
                for(int i=3;i*i<=n;i++)
                {
                    if(n%i==0)
                    {
                        bol = false;
                        break;
                    }
                }
                if(bol)
                {
                    s = F;
                }
                else
                {
                    s = A;
                }
            }
            else if(cnt>1)
            {
                s = A;
            }
        }

        cout<<s<<endl;
    }
    return 0;
}

