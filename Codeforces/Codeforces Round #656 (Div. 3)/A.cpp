
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll arr[3];

        for(int i=0;i<3;i++)
        {
           cin>>arr[i];
        }

        sort(arr,arr+3);

        if(arr[0]!=arr[1] && arr[1]!=arr[2] && arr[0]!=arr[2])
        {
            cout<<"NO"<<endl;
        }

        else if(arr[0]==arr[1] && arr[1]==arr[2] && arr[0]==arr[2])
        {
            cout<<"YES"<<endl;
            cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        }

        else if(arr[2]==arr[0] || arr[2]==arr[1])
        {
            cout<<"YES"<<endl;
            cout<<arr[2]<<" "<<arr[0]<<" "<<arr[0]<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }




    }

    return 0;
}

