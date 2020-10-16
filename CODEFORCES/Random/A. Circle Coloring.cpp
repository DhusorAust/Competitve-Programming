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

        int arr1[n],arr2[n],arr3[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }

        for(int i=0;i<n;i++)
        {
            cin>>arr2[i];
        }

        for(int i=0;i<n;i++)
        {
            cin>>arr3[i];
        }

        cout<<arr1[0];
        int lst  = arr1[0];
        int fst = lst;

        for(int i=1;i<n;i++)
        {
            if(i==n-1)
            {
                if(arr1[i]!=lst && arr1[i]!=fst)
                {
                    cout<<" "<<arr1[i];
                }

                else  if(arr2[i]!=lst && arr2[i]!=fst)
                {
                    cout<<" "<<arr2[i];
                }

                else  if(arr3[i]!=lst && arr3[i]!=fst)
                {
                    cout<<" "<<arr3[i];
                }
            }
            else
            {
                if(arr1[i]!=lst)
                {
                    cout<<" "<<arr1[i];
                    lst = arr1[i];
                }
                else
                {
                    cout<<" "<<arr2[i];
                    lst = arr2[i];
                }

            }
        }

        cout<<endl;


    }

    return 0;
}

