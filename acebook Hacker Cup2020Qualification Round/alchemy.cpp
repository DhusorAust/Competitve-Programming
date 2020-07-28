#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    FAST

    ifstream input;
    input.open("alchemy_input.txt");
    ofstream myfile;
    myfile.open ("example.txt");

    int t;
    input>>t;

    int cn  = 0;

    while(t--)
    {
        cn++;
        int n;
        input>>n;

        string s;
        input>>s;

        int cnt1 = 0, cnt2 = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='A')
                cnt1++;
            else
                cnt2++;
        }

        if(cnt1<cnt2)
            swap(cnt1,cnt2);

        if(cnt1-cnt2==1)
        {
            myfile <<"Case #"<<cn<<": Y"<<endl;
        }
        else
        {
            myfile <<"Case #"<<cn<<": N"<<endl;
        }
    }
    myfile.close();
    input.close();
    return 0;
}

