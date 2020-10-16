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
        int arr[3];

        for(int i=0;i<3;i++)
        cin>>arr[i];

        sort(arr,arr+3);

        cout<<arr[2]<<endl;
    }

    return 0;
}

