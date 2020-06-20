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
        int m;
        cin>>m;
        int arr[m];
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
        }
        int n = s.length();
        sort(s.begin(),s.end());

        int j = n-1;
        int cnt = 0;
        char ans[m];
        while(cnt<m)
        {

            vector<int> v;
            for(int i=0;i<m;i++)
            {
               if(arr[i]==0)
               {
                   v.push_back(i);
                   cnt++;
                   arr[i] = -1;
               }
            }

            int w  = v.size();

            for(int i=j;i>=w-1;i--)
            {
                set <int>ss;
                for(int k = i,l=0;l<w;k--,l++)
                {
                    ss.insert(s[k]);
                }
                if(ss.size()==1)
                {
                    j = i;
                    break;
                }
            }

            for(int i=0;i<v.size();i++)
            {
                ans[v[i]]  = s[j];
                j--;
            }

            for(int i=0;i<m;i++)
            {
                for(int j = 0;j<v.size();j++)
                {
                    arr[i]-= abs(i-v[j]);
                }
            }
            while(s[j]==s[j+1])
            {
                j--;
            }
        }

        for(int i=0;i<m;i++)
            cout<<ans[i];
        cout<<endl;
    }

    return 0;
}
