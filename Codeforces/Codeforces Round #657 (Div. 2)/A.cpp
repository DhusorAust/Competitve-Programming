#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

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

int check(vector<int>& z)
{
       int cnt = 0;
       for(int i=8;i<z.size();i++)
       {
           if(z[i]==7)
           {
               cnt++;
           }
       }

      return cnt;
}

void print(string s,int n)
{
   cout<<"YES"<<endl;
   for(int i=0;i<n;i++)
   {
       if(s[i]=='?')
        s[i]='z';
   }
   cout<<s<<endl;
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

        string s;
        cin>>s;
        string s2 = "abacaba";
        string s3 = "abacaba";

        s2.push_back('$');
        s2 = s2+s;

        vector<int> z;
        z = z_function(s2);

      int cnt = check(z);
       if(cnt==1)
       {
           print(s,n);
           continue;
       }
       if(cnt>1)
       {
           cout<<"NO"<<endl;
           continue;
       }

          vector<int> v;

           for(int i=0;i<n-6;i++)
           {
               bool bol2= true;
               for(int j=0,k = i;j<7;j++,k++)
               {
                   if(s[k]!=s3[j] && s[k]!='?' )
                   {
                      bol2 = false;
                      break;
                   }
               }
                if(bol2)
                {
                   v.push_back(i);
                }
           }



          if(v.size()==0)
          {
              cout<<"NO"<<endl;
              continue;
          }

          bool bol = true;
          for(int i=0;i<v.size();i++)
          {
              string tmp = s;

              for(int j=v[i],k = 0;k<7;j++,k++)
              {
                  tmp[j] = s3[k];
              }
              string s2 = s3+"$"+tmp;
              vector <int> z = z_function(s2);

              if(check(z)==1)
              {
                  print(tmp,n);
                  bol = false;
                  break;
              }
          }

          if(bol)
          {
              cout<<"NO"<<endl;
          }
    }
    return 0;
}


