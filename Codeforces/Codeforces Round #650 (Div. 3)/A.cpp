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
 
        for(int i=0;i<s.size();i+=2)
            cout<<s[i];
        cout<<s[s.size()-1]<<endl;
    }
    return 0;
}