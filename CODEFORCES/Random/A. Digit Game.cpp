#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int toInt(char c)
{
    return (c-48);
}

int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        if(n%2!=0)
        {

            bool bol = false;
            for(int i = 0 ;i<n;i+=2)
            {
                if(toInt(s[i])%2!=0)
                {
                    bol = true;
                    break;
                }
            }

            if(bol)
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<2<<endl;
            }
        }
        else
        {
            bool bol = false;
            for(int i = 1 ;i<n;i+=2)
            {
                if(toInt(s[i])%2==0)
                {
                    bol = true;
                    break;
                }
            }

            if(bol)
            {
                cout<<2<<endl;
            }
            else
            {
                cout<<1<<endl;
            }
        }



    }

    return 0;
}

