
#include<bits/stdc++.h>
using namespace std;

vector<int> odd_pal(string s)
{
    int n = s.length();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        {
            k++;
        }
        d1[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    return d1;
}

vector<int> even_pal(string s)
{
    int n = s.length();
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
        {
            k++;
        }
        d2[i] = k--;
        if (i + k > r)
        {
            l = i - k - 1;
            r = i + k ;
        }
    }
    return d2;
}

int main()
{
    string s;

    while(cin>>s)
    {
        int n = s.size();
        vector<int> d1,d2;

        d1 = odd_pal(s);
        d2 = even_pal(s);

        int ans = 0;

        for(int i=0;i<s.size();i++)
        {
            if(i+d1[i]==n)
            {
                ans = max(ans,2*d1[i]-1);
            }
        }

        for(int i=0;i<s.size();i++)
        {
            if(i+d2[i]==n)
            {
                ans = max(ans,2*d2[i]);
            }
        }

        ans = n-ans;
        cout<<s;

        for(int i = ans-1;i>=0;i--)
        {
            cout<<s[i];
        }

        cout<<endl;
    }
    return 0;
}
