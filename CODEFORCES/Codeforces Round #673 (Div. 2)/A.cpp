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
        int n,k;
        cin>>n>>k;

        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

            sort(arr,arr+n);

        int sum = 0;
        for(int i=1;i<n;i++)
        {
            int d = k-arr[i];

            sum += d/arr[0];
        }

        cout<<sum<<endl;
    }

    return 0;
}

