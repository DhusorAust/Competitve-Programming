#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll k;
    cin>>k;
    string s = "codeforces";
    ll arr[10];
    for(int i=0;i<10;i++)
        arr[i] = 1;
    ll sum = 1;
    while(true)
    {
        if(sum>=k)
            break;
        for(int i=0;i<10;i++)
        {
            sum/=arr[i];
            arr[i]++;
            sum*=arr[i];
            if(sum>=k)
                break;
        }
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<arr[i];j++)
            cout<<s[i];
    cout<<endl;
    return 0;
}
