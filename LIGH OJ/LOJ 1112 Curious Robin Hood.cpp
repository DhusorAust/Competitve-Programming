#include<bits/stdc++.h>
using namespace std;

int tree[100001];

void update(int ix, int val,int n)
{
    while(ix<=n)
    {
        tree[ix]+=val;
        ix += (ix & -ix);
    }
}
int query(int l, int r)
{
    l--;
    int sum = 0;
    while(r>0)
    {
        sum+=tree[r];
        r -= (r & -r);
    }
    while(l>0)
    {
        sum-=tree[l];
        l -= (l & -l);
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    int cnt2 = 0;
    while(t--)
    {
        cnt2++;
        printf("Case %d:\n",cnt2);
        int n,q;
        scanf("%d%d",&n,&q);
        int arr[n+1];
        for(int i = 0;i<=n;i++)
            tree[i] = 0;
        for(int i =1 ;i<=n;i++)
        {
            scanf("%d",&arr[i]);
            update(i,arr[i],n);
        }

        while(q--)
        {
            int a;
            scanf("%d",&a);
            if(a==1)
            {
                int i;
                scanf("%d",&i);
                int x = query(i+1,i+1);
                printf("%d\n",x);
                update(i+1,-x,n);
            }
            else if(a==2)
            {
                int i,v;
                scanf("%d%d",&i,&v);
                update(i+1,v,n);
            }
            else
            {
                int i,j;
                scanf("%d%d",&i,&j);
                printf("%d\n",query(i+1,j+1));
            }
        }
    }
    return 0;
}
/*
1
5 6
3 2 1 4 5
1 4
2 3 4
3 0 3
1 2
3 0 4
1 1
*/
