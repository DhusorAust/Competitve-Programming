#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    FAST
    ordered_set os;
    int n;
    cin>>n;
    int k;
    cin>>k;
    int pos = 0;
    int k2 = k-1;
    for(int i=1;i<=n;i++)
        os.insert(i);
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        pos = (pos+k2)%os.size();
        v.push_back(*os.find_by_order(pos));
        os.erase(os.find_by_order(pos));
    }
    for(int i=0;i<v.size()-1;i++)
        cout<<v[i]<<" ";
    cout<<v[v.size()-1]<<endl;
    return 0;
}

