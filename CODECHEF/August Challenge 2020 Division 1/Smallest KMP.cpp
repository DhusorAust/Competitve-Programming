#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s,p;
        cin>>s;
        cin>>p;

        string s2,p2;

        p2 = p;

        sort(s.begin(),s.end());

        sort(p2.begin(),p2.end());

        for(int i=0,j = 0;i<s.length();i++)
        {
            if(s[i]==p2[j])
            {
                s[i] = '$';
                j++;
            }
        }

        for(int i=0,j = 0;i<s.length();i++)
        {
            if(s[i] != '$')
            {
               s2.push_back(s[i]);
            }
        }

        int L1 = lower_bound(s2.begin(),s2.end(),p[0])-s2.begin();
        int L2 = upper_bound(s2.begin(),s2.end(),p[0])-s2.begin();

        string str1, str2;

        for(int i=0;i<L1;i++)
            str1.push_back(s2[i]);

        for(int i=0;i<p.length();i++)
            str1.push_back(p[i]);

        for(int i=L1;i<s2.length();i++)
            str1.push_back(s2[i]);

        for(int i=0;i<L2;i++)
            str2.push_back(s2[i]);

        for(int i=0;i<p.length();i++)
            str2.push_back(p[i]);

        for(int i=L2;i<s2.length();i++)
            str2.push_back(s2[i]);

        if(str1<str2)
            cout<<str1<<endl;
        else
            cout<<str2<<endl;

    }
    return 0;
}
