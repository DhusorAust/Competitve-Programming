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

    int n;
    cin>>n;

    string s;
    cin>>s;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        string tmp = s.substr(i,n-i);
        vector <int> z = z_function(tmp);

        for(int i=0;i<z.size();i++)
        {
           ans = max(ans, min(i,z[i]));
        }

    }
    cout<<ans<<endl;

    return 0;
}
