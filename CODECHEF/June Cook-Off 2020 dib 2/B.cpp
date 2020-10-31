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
        int n,m;
        cin>>n>>m;

        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        sort(arr,arr+n);

        int cnt = 0,cnt2 = 0;
        int k = 1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==k && k<m)
            {
                cnt++;
                k++;
            }
            if(arr[i]==m)
                cnt2++;
        }

        if(cnt==m-1)
        {
            cout<<n-cnt2<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }



    }
    return 0;
}

