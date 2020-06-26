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
        string s;
        cin>>s;
        int n = s.length();

        int one = 0, two = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                one++;
            else
                two++;
        }
        int cnt = min(one,two);
        if(cnt%2==0)
                cout<<"NET"<<endl;
            else
                cout<<"DA"<<endl;






    }


    return 0;
}
