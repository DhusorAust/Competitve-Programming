#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
//priority_queue<int, vector<int>, greater<int> > min_q;

struct node
{
    ll val, i;
};

bool cmp(node a, node b)
{
    return a.val <b.val;
}
int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        ll n, T;
        cin>>n>>T;

        node arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i].val;
            arr[i].i = i;
        }

        sort(arr,arr+n,cmp);

        ll ans[n+9];

        for(ll i = 0, j = n-1;i<=j;)
        {
            if(arr[i].val+arr[j].val==T)
            {
                ans[arr[j].i] = 1;
                ans[arr[i].i] = 0;

                j--;
                i++;

            }
            else if(arr[i].val+arr[j].val>T)
            {
                ans[arr[j].i] = 1;
                j--;
            }

            else if(arr[i].val+arr[j].val<T)
            {

                ans[arr[i].i] = 0;
                i++;
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }

        cout<<endl;






    }

    return 0;
}

