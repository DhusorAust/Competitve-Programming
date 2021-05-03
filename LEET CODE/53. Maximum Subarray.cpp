#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
//priority_queue<int, vector<int>, greater<int> > min_q;

 int maxSubArray(vector<int>& nums) {

     int n = nums.size();
     int ans = nums[0];
     int ans2 = ans;
     for(int i =1;i<n;i++)
     {
         ans = max(nums[i],nums[i]+ans);
         ans2 = max(ans,ans2);
     }
     return ans2;
}


int main()
{
    FAST
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<maxSubArray(v)<<endl;
    return 0;
}
/*
5
5 4 -1 7 8

*/

