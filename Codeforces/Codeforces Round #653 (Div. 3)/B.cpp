#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }

        int cnt = 0, cnt1 =0;

        while(n%2==0)
        {
            n/=2;
            cnt++;
        }

        while(n%3==0)
        {
            n/=3;
            cnt1++;
        }

        if(n>1 || cnt>cnt1)
        {
            cout<<"-1"<<endl;
            continue;
        }

        cout<<cnt1+cnt1-cnt<<endl;

    }

    return 0;
}
