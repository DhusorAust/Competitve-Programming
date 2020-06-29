#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
//priority_queue<int, vector<int>, greater<int> > min_q;
int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        int cnt = 0;
        int miin = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                cnt++;
            else
                cnt--;
            miin = min(cnt,miin);
        }

        cout<<miin*-1<<endl;
    }

    return 0;
}

