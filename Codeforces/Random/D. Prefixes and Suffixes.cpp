#include<bits/stdc++.h>
using namespace std;


vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{

    string s;
    cin>>s;
    int n = s.length();
    vector <int> z = z_function(s);

    int ans = 0;
    map<int,int> m;
    int arr[n+1];

    memset(arr,0,sizeof(arr));

    for(int i=0;i<n;i++)
    {
       //cout<<i<<" "<<z[i]<<endl;
       if(z[i]!=0)
       {
            m[z[i]]++;
            arr[z[i]]++;
       }
    }

    map<int,int> :: iterator it;

    //cout<<endl;

    /*for(it= m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<endl;*/

    for(int i=n-1;i>=0;i--)
    {
       arr[i] += arr[i+1];
    }

    /*cout<<endl;

    for(int i=1;i<=n;i++)
    {
       cout<<i<<" "<<arr[i]<<endl;
    }*/

    vector< pair<int,int> > v;

    for(int i=n-1;i>=0;i--)
    {
      if(z[i]+i==n)
      {
          v.push_back(make_pair(z[i],arr[z[i]]));
      }
    }

    cout<<v.size()<<endl;

    for(int i=0;i<v.size();i++)
    {
       cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    return 0;
}
