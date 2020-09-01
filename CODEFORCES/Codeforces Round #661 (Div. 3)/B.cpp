#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
#define pb push_back

int main()
{
    FAST



        ll t;
        cin>>t;

        while(t--)
        {
            ll n;
            cin>>n;

            ll A[n],B[n];

            ll minA = 10000000000, minB = 10000000000;
            ll arr1[n],arr2[n];
            for(ll i = 0;i<n;i++)
            {
                cin>>A[i];
                minA =min(minA,A[i]);

                arr1[i] =0;
                arr2[i] =0;
            }

            for(ll i = 0;i<n;i++)
            {
                cin>>B[i];
                minB =min(minB,B[i]);
            }

            for(ll i = 0;i<n;i++)
            {
                arr1[i] = A[i]-minA;
                arr2[i] = B[i]-minB;
            }

            ll sum = 0;
            for(ll i = 0;i<n;i++)
            {
                sum+=max(arr1[i],arr2[i]);
            }

            cout<<sum<<endl;


        }






    return 0;
}

