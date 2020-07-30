#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        ll n = s.size();

        map<char,ll> m;
        ll ans = -1;
        for(ll i = 0;i<n;i++)
        {
            m[s[i]]++;
            ans = max(ans,m[s[i]]);

        }

        ans = n-ans;


        for(char c = '0';c<='9';c++)
        {

           for(char c2 = '0';c2<='9';c2++)
            {
                if(c==c2)
                    continue;
               ll cnt = 0, cnt2 = 0, cnt3 = 0,cnt4 = 0;
                for(int i = 0;i<n;i++)
                {
                    if(s[i]==c && cnt3==0)
                    {
                        cnt++;
                        cnt3 = 1;
                    }
                    else if(s[i]==c2 && cnt3==1)
                    {
                        cnt++;
                        cnt3 = 0;
                    }

                    if(s[i]==c2 && cnt4==0)
                    {

                        cnt2++;
                        cnt4 = 1;
                    }
                    else if(s[i]==c && cnt4==1)
                    {
                        cnt2++;
                        cnt4 = 0;
                    }


                }
                  if(cnt3==1)
                       cnt--;
                  if(cnt4==1)
                       cnt2--;
          
                ans = min(ans,n-max(cnt,cnt2));
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}

