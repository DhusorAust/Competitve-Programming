#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {

        int n;
        cin>>n;

        int arr[n];
        int arr2[n];


        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr2[i] = arr[i];

        }
        sort(arr2,arr2+n);

        bool bol = false;

        for(int i=1;i<n;i++)
        {
            if(arr2[i]==arr2[i-1])
            {
                bol= true;
                break;
            }
        }
        if(bol)
        {
            cout<<"YES"<<endl;
            continue;
        }

        for(int i=0,j = n-1;i<n;i++,j--)
        {
            if(arr2[j]!=arr[i])
            {
                bol= true;
                break;
            }
        }

        if(bol)
        {
            cout<<"YES"<<endl;
            continue;
        }

        cout<<"NO"<<endl;

    }

    return 0;
}

