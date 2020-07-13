#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

vector<ll> Left,Right,L2,R2;

ll arr[200009];

void LFT(ll arr[], ll n)
{

    stack<ll> S,S2;

    for (ll i=0; i<n; i++)
    {
        while (!S.empty() && S.top() <= arr[i])
        {

            S2.pop();
            S.pop();
        }

        if (S.empty())
            Left.push_back(0);
        else
            Left.push_back(S2.top());

        S.push(arr[i]);
        S2.push(i);
    }
}

void RGHT(ll arr[], ll n)
{

    stack<ll> S,S2;

    for (ll i=n-1; i>=0; i--)
    {
        while (!S.empty() && S.top() <= arr[i])
        {

            S2.pop();
            S.pop();
        }

        if (S.empty())
            Right.push_back(0);
        else
            Right.push_back(S2.top());

        S.push(arr[i]);
        S2.push(i);
    }
    reverse(Right.begin(),Right.end());
}
///**********************************///
void LFT2(ll arr[], ll n)
{

    stack<ll> S,S2;

    for (ll i=0; i<n; i++)
    {
        while (!S.empty() && S.top() < arr[i])
        {

            S2.pop();
            S.pop();
        }

        if (S.empty())
            L2.push_back(0);
        else
            L2.push_back(S2.top());

        S.push(arr[i]);
        S2.push(i);
    }
}

void RGHT2(ll arr[], ll n)
{

    stack<ll> S,S2;

    for (ll i=n-1; i>=0; i--)
    {
        while (!S.empty() && S.top() < arr[i])
        {

            S2.pop();
            S.pop();
        }

        if (S.empty())
            R2.push_back(0);
        else
            R2.push_back(S2.top());

        S.push(arr[i]);
        S2.push(i);
    }
    reverse(R2.begin(),R2.end());
}
///**********************************///

bool isValidLeft(ll b,ll c)
{

    if(c<=L2[b])
        return false;

    return true;
}

bool isValidRight(ll b,ll c)
{
    if(c>=R2[b])
        return false;
    return true;
}
///************************************************///
ll tree_Right[800018];
ll tree_Left[800018];
ll lazy_Right[800018];
ll lazy_Left[800018];

void update_Right(ll  pos, ll  left, ll  right,ll  qleft, ll  qright, ll  val)
{
    if(lazy_Right[pos]!=0) // making sure if propagation is done. this should be before no overlap condition
    {
        tree_Right[pos]+= lazy_Right[pos] * (right-left+1);
        if(left!=right)//not a leaf node
        {
            lazy_Right[2*pos] += lazy_Right[pos];
            lazy_Right[2*pos+1] += lazy_Right[pos];
        }
        lazy_Right[pos] = 0;
    }
    if(left > right || qleft>right || qright<left ) //invalid and no overlap
    {
        return ;
    }
    if(qleft<=left && qright>=right)// total overlap
    {
        tree_Right[pos]+=val* (right-left+1);
        if(left!=right) //not a leaf node
        {
            lazy_Right[2*pos] += val;
            lazy_Right[2*pos+1] += val;
        }
        return ;
    }
    //partial overlap
    ll  mid = (left+right)/2;
    update_Right(2*pos,left,mid,qleft,qright,val);
    update_Right(2*pos+1,mid+1,right,qleft,qright,val);
    tree_Right[pos] = tree_Right[2*pos]+tree_Right[2*pos+1];
}

ll  point_query_Right(ll  pos,ll  left, ll  right, ll  att)
{
    if(lazy_Right[pos]!=0) // making sure if propagation is done
    {
        tree_Right[pos]+= lazy_Right[pos]* (right-left+1);
        if(left!=right)//not a leaf node
        {
            lazy_Right[2*pos] += lazy_Right[pos];
            lazy_Right[2*pos+1] += lazy_Right[pos];
        }
        lazy_Right[pos] = 0;
    }
    if(left==right)
    {
       return tree_Right[pos];
    }
    int mid = (left+right)/2;

    if(att<=mid)
        return point_query_Right(2*pos,left,mid,att);
    else
        return point_query_Right(2*pos+1,mid+1,right,att);
}

void update_Left(ll  pos, ll  left, ll  right,ll  qleft, ll  qright, ll  val)
{
    if(lazy_Left[pos]!=0) // making sure if propagation is done. this should be before no overlap condition
    {
        tree_Left[pos]+= lazy_Left[pos] * (right-left+1);
        if(left!=right)//not a leaf node
        {
            lazy_Left[2*pos] += lazy_Left[pos];
            lazy_Left[2*pos+1] += lazy_Left[pos];
        }
        lazy_Left[pos] = 0;
    }
    if(left > right || qleft>right || qright<left ) //invalid and no overlap
    {
        return ;
    }
    if(qleft<=left && qright>=right)// total overlap
    {
        tree_Left[pos]+=val* (right-left+1);
        if(left!=right) //not a leaf node
        {
            lazy_Left[2*pos] += val;
            lazy_Left[2*pos+1] += val;
        }
        return ;
    }
    //partial overlap
    ll  mid = (left+right)/2;
    update_Left(2*pos,left,mid,qleft,qright,val);
    update_Left(2*pos+1,mid+1,right,qleft,qright,val);
    tree_Left[pos] = tree_Left[2*pos]+tree_Left[2*pos+1];
}

ll  point_query_Left(ll  pos,ll  left, ll  right, ll  att)
{
    if(lazy_Left[pos]!=0) // making sure if propagation is done
    {
        tree_Left[pos]+= lazy_Left[pos]* (right-left+1);
        if(left!=right)//not a leaf node
        {
            lazy_Left[2*pos] += lazy_Left[pos];
            lazy_Left[2*pos+1] += lazy_Left[pos];
        }
        lazy_Left[pos] = 0;
    }
    if(left==right)
    {
       return tree_Left[pos];
    }
    int mid = (left+right)/2;

    if(att<=mid)
        return point_query_Left(2*pos,left,mid,att);
    else
        return point_query_Left(2*pos+1,mid+1,right,att);
}

///************************************************///

int main()
{
    FAST

    ll n,q;
    cin>>n>>q;

    ll H[n+2];

    H[0]= 1000000000000;
    H[n+1] = 1000000000000;

    for(ll i=1;i<=n;i++)
    {
        cin>>H[i];
    }

    ///****************///
    LFT(H, n+2);
    RGHT(H, n+2);

    LFT2(H, n+2);
    RGHT2(H, n+2);
    ///****************///


    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        ll x = L2[i]+1;

        ll y = R2[i]-1;

        update_Right(1, 1, n,i, y, arr[i]);
        update_Left(1, 1, n,x, i, arr[i]);
    }

    for(ll i = 1;i<=q;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;

        if(a==1)
        {
            ll x = L2[b]+1;
            ll y = R2[b]-1;

            ll tmpR = arr[b];
            ll tmpL = arr[b];

            arr[b] = c;

            tmpR*=-1;
            tmpL*=-1;

            update_Right(1, 1, n,b, y,tmpR );
            update_Left(1, 1, n,x, b, tmpL);

            update_Right(1, 1, n,b, y, c);
            update_Left(1, 1, n,x, b, c);
        }
        else
        {
            if(b<=c)
            {
                if(isValidRight(b,c))
                {
                   ll F2 = point_query_Right(1,1,n,c);
                   ll F1 ;

                   if(Left[b]==0)
                        F1 = 0;
                   else
                        F1 = point_query_Right(1,1,n,Left[b]);

                   cout<<F2-F1<<endl;
                }
                else
                {
                    cout<<"-1"<<endl;
                }
            }
            else
            {
                if(isValidLeft(b,c))
                {
                    ll F2 = point_query_Left(1,1,n,c);
                    ll F1;
                    if(Right[b]==n+1)
                        F1 = 0;
                    else
                        F1 = point_query_Left(1,1,n,Right[b]);

                   cout<<F2-F1<<endl;
                }
                else
                {
                    cout<<"-1"<<endl;
                }
            }
        }
    }
    return 0;
}


