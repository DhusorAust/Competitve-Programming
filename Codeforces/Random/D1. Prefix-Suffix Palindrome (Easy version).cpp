#include<bits/stdc++.h>
using namespace std;
string s;
bool check_pal(int i,int j)
{
    for(;i<j;i++,j--)
    {
        if(s[i]!=s[j])
            return false;
    }
    return true;
}

int main()
{

    int t;
    cin>>t;

    while(t--)
    {

        cin>>s;
        int n = s.length();

        int cnt = 0;
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            if(s[i]==s[j])
            {
                cnt++;
                continue;
            }
            else
            {
                break;
            }
        }
        int fst = cnt;
        int lst = n-cnt-1;

        vector<int> v1,v2;
        for(int i=fst;i<=lst;i++)
        {
            if(s[i]==s[lst])
                v1.push_back(i);
            if(s[i]==s[fst])
                v2.push_back(i);
        }

        int ix1 = n,ix2 = -1;
        for(int i=0;i<v1.size();i++)
        {
            if(check_pal(v1[i],lst))
            {
                ix1 = v1[i];
                break;
            }
        }
        for(int i=v2.size()-1;i>=0;i--)
        {
            if(check_pal(fst,v2[i]))
            {
                ix2 = v2[i];
                break;
            }
        }

        if(ix2-fst>lst-ix1)
        {
            for(int i=0;i<cnt;i++)
                cout<<s[i];
            for(int i=fst;i<=ix2;i++)
                cout<<s[i];
            for(int i=n-cnt;i<n;i++)
                cout<<s[i];
            cout<<endl;

        }
        else
        {
            for(int i=0;i<cnt;i++)
                cout<<s[i];
            for(int i=ix1;i<=lst;i++)
                cout<<s[i];
            for(int i=n-cnt;i<n;i++)
                cout<<s[i];
            cout<<endl;
        }

    }

    return 0;
}
