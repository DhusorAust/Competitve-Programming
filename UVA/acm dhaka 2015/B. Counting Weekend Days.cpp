#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

ll day(string s)
{
    if(s=="JAN" || s=="MAR" || s=="MAY" || s=="JUL" || s=="AUG" || s=="OCT" || s =="DEC")
         return 31;
    if(s=="FEB")
         return 28;
    return 30;
}

ll val(string s)
{
    if(s=="SAT")
        return 1;
    if(s=="SUN")
        return 2;
    if(s=="MON")
        return 3;
    if(s=="TUE")
        return 4;
    if(s=="WED")
        return 5;
    if(s=="THU")
        return 6;
    return 7;
}

int main()
{
    FAST
    ll t;
    cin>>t;

    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;

        ll diff;
        ll ans = 0;
        if( val("FRI") >= val(s2) )
            diff = val("FRI") - val(s2)+1;
        else
            diff = val("FRI") - val(s2) +7+1;

        ans+= (day(s1)-diff)/7+1;

        if( val("SAT") >= val(s2) )
            diff = val("SAT") - val(s2)+1;
        else
            diff = val("SAT") - val(s2) +7+1;

        ans+= (day(s1)-diff)/7+1;

        cout<<ans<<endl;

    }
    return 0;
}

