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
    int v, i;
};
bool cmp (node a, node b)
{
    return a.v<b.v;
}
vector<int> twoSum(vector<int>& nums, int target)
{
    int n = nums.size();
    vector<node> tmp;
    for(int i=0;i<n;i++)
    {
        node A;
        A.v = nums[i];
        A.i = i;
        tmp.push_back(A);
    }
    sort(tmp.begin(),tmp.end(),cmp);
    vector<int> ans;
    sort(nums.begin(),nums.end());
    for(int i = 0,j = n-1;i<j;)
    {
        if(tmp[i].v+tmp[j].v==target)
        {
            ans.push_back(tmp[i].i);
            ans.push_back(tmp[j].i);
            break;
        }
        else if(tmp[i].v+tmp[j].v<target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans;
}

int main()
{
    FAST
    ll n;
    cin>>n;
    vector<int> v;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int t;
    cin>>t;
    vector<int> v2;
    v2 = twoSum(v, t);
    for(int i = 0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;

    return 0;
}

