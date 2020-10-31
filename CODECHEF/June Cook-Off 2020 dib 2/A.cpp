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
        int n,b,m;
        cin>>n>>b>>m;
        int arr[m];
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
        }
        int cnt = 0;
        int lst = INT_MAX;
        for(int i=0;i<m;i++)
        {
           int temp = arr[i]%b;
           int now = arr[i]-temp;
           if(now<lst)
           {
               lst = now;
               cnt++;
           }
           else if(now-lst>=b)
           {
                lst = now;
               cnt++;
           }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

