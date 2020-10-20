#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;

struct node
{
    int i;
    int val;
};
struct node2
{
    int x;
    int y;
};
bool compare(node a, node b)
{
    return a.val<b.val;
}
int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        node arr[n+1];

        set<int> s;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i].val;
            arr[i].i = i;
            s.insert(arr[i].val);
        }
        if(s.size()==1)
        {
            cout<<"NO"<<endl;
            continue;
        }

        sort(arr+1,arr+n+1,compare);

        vector<node2> ans;


            for(int j = 2;j<=n;j++)
            {

                if(arr[1].val!=arr[j].val)
                {
                    node2 A;
                    A.x = arr[1].i;
                    A.y = arr[j].i;
                    ans.push_back(A);
                }
            }


            for(int j = 2;j<n;j++)
            {
                if(arr[j].val!=arr[1].val)
                    break;
                if(arr[j].val!=arr[n].val && arr[j].val==arr[1].val)
                {
                    node2 A;
                    A.x = arr[j].i;
                    A.y = arr[n].i;
                    ans.push_back(A);
                }
            }

            cout<<"YES"<<endl;
            for(int i=0;i<ans.size();i++)
             cout<<ans[i].x<<" "<<ans[i].y<<endl;





    }

    return 0;
}

