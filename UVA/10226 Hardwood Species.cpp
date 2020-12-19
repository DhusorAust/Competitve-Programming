#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
int main()
{
   // FAST
     // ofstream myfile;
  //myfile.open ("example.txt");

    int t;
    cin>>t;
    getchar();
    string s;
    getline(cin,s);
    while(t--)
    {
        map<string, int> m;
        int cnt = 0;
        while(true)
        {
            getline(cin,s);
            if(s.size()==0)
                break;
            m[s]++;
            cnt++;
        }
        for(auto a = m.begin();a!=m.end();a++)
        {
            double tmp = (((double)a->second)/((double)cnt))*100.00;
            cout<<a->first<<" "<<fixed<<setprecision(4)<<tmp<<endl;
            //myfile <<a->first<<" "<<fixed<<setprecision(4)<<tmp<<endl;
        }
        if(t!=0)
        {
            cout<<endl;
            //myfile <<endl;
        }

    }

  //myfile.close();
    return 0;
}

