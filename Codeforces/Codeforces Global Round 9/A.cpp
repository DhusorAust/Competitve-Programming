
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

struct node
{
    ll ix, val;
};
bool operator<(node a, node b)
{
    if(a.val== b.val)
        return a.ix>b.ix;

    return a.val>b.val;
}

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        ll arr[n];

        map<ll,ll> m;
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            m[arr[i]] ++;
        }

        map<ll,ll> :: iterator it;

      /*  for(it = m.begin();it!=m.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }*/

        node arr2[n+1];

        for(int i=0;i<=n;i++)
        {
            arr2[i].ix = i;
            arr2[i].val = m[i];
        }

      /*  cout<<endl;
        for(int i=0;i<=n;i++)
        {
           cout<<arr2[i].ix<<" "<<arr2[i].val<<endl;
        }*/

        priority_queue<node> q;

        for(int i=0;i<=n;i++)
        {
           q.push(arr2[i]);
        }

      /* cout<<endl;
       while(!q.empty())
        {
            cout<<q.top().ix<<" "<<q.top().val <<endl;
            q.pop();

        }
*/
        vector<ll> ans;

       ll cnt = 0;
       while(!q.empty())
        {
            if(cnt>=n)
                break;


            node A = q.top();
            q.pop();
            //cout<<A.ix<<" "<<A.val<<endl;
            if(A.ix==n)

            {
                ll ix = A.ix;
                ll val = A.val;
                ans.push_back(ix-1);

                A.val;
                q.push(A);

                arr2[ arr[ix-1]].val--;

                q.push(arr2[ arr[ix-1]]);
                cnt++;

                continue;
            }

            ll ix = A.ix;
            ll val = A.val;
            ans.push_back(ix);

            A.val++;
            q.push(A);

            arr2[ arr[ix]].val--;

            q.push(arr2[ arr[ix]]);
            cnt++;
        }

        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]+1<<" ";
        cout<<endl;












    }

    return 0;
}

