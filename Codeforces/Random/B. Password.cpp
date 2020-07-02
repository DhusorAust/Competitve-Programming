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
    string s;
    cin>>s;
    int n = s.length();
    vector <int> z = z_function(s);

    string s2 = s;
    s2.pop_back();
    s2.push_back('$');

    vector <int> z2 = z_function(s2);

    int maax = INT_MIN;
    for(int i=1;i<n;i++)
    {
        maax = max(maax,z2[i]);
    }
    bool bol = false;
    int len;

    for(int i=0;i<n;i++)
    {
        if(i+z[i]==n && z[i]<=maax)
        {
            bol = true;
            len = z[i];
            break;
        }
    }


    if(bol)
    {
       for(int i=0;i<len;i++)
            cout<<s[i];
       cout<<endl;
    }
    else
    {
        cout<<"Just a legend"<<endl;
    }

    return 0;
}
