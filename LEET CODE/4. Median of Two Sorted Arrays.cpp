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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> v;
    int n1 = nums1.size();
    int n2 = nums2.size();
    nums1.push_back(INT_MAX);
    nums2.push_back(INT_MAX);
    for(int i = 0,j1 = 0, j2 = 0;i<n1+n2;i++)
    {
        if(nums1[j1]<nums2[j2])
        {
            v.push_back(nums1[j1]);
            j1++;
        }
        else
        {
            v.push_back(nums2[j2]);
            j2++;
        }
    }
    int n = n1+n2;
    if(n%2==1)
        return v[n/2];
    return ((double)v[n/2]+(double)v[n/2-1])/2.0;
}


int main()
{
    FAST
    int n1;
    cin>>n1;
    vector<int> v1;
    for(int i = 0;i<n1;i++)
    {
        int x;
        cin>>x;
        v1.push_back(x);
    }

    int n2;
    cin>>n2;
    vector<int> v2;
    for(int i = 0;i<n2;i++)
    {
        int x;
        cin>>x;
        v2.push_back(x);
    }

    cout<<findMedianSortedArrays(v1,v2)<<endl;


    return 0;
}

