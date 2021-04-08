
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> twoSum(vector<int>& nums, int target)
{
   unordered_map<int,int> m;
   vector<int> ans;
   for(int i = 0;i<nums.size();i++)
   {
       if( m[nums[i]] == 0)
           m[nums[i]] = i+1;
       else
       {
           if(nums[i]*2==target)
           {
               ans.push_back(m[nums[i]]-1);
               ans.push_back(i);
               return ans;
           }
       }
   }
   for(int i = 0;i<nums.size();i++)
   {
       if( m[nums[i]]!=0 && m[target-nums[i]]!=0 && m[nums[i]] != m[target-nums[i]])
       {
           ans.push_back(m[nums[i]]-1);
           ans.push_back(m[target-nums[i]]-1);
           return ans;
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

