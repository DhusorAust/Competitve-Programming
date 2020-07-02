#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {


        string s;
        cin>>s;
        int n = s.length();
        vector <int> z = z_function(s);

        int ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            bool bol = false;
            if(z[i] !=0 && n%z[i]==0 && i+z[i]==n)
            {
               bol = true;
               int cnt = 2;
               for(int j = i-z[i];j>=0;)
               {
                   if(z[j]==cnt*z[i])
                   {
                       j-=z[i];
                   }
                   else
                   {
                       bol  = false;
                       break;
                   }
                   cnt++;
               }
            }
            if(bol)
            {   ans = z[i];
                break;
            }
        }
        cout<<ans<<endl;

        if(t!=0)
            cout<<endl;
    }


    return 0;
}
