#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 999999
#define mx 100001
int arr[mx];
struct node
{
    ll sum,prop;
}tree[mx * 3];
// 1 indexed tree
void init(int low, int high, int pos)
{
    if (low == high)
    {
        tree[pos].sum = arr[low];
        return;
    }
    int Left = pos * 2;
    int Right = pos * 2 + 1;
    int mid = (low + high) / 2;
    init(low, mid, Left);
    init(mid+1, high, Right);
    tree[pos].sum = tree[Left].sum + tree[Right].sum;
    //tree[node] = min(tree[Left] , tree[Right]);
}
ll query(ll low,ll high,ll from,ll to,ll pos,ll c = 0)
{
    if (from > high || to < low)
        return 0;
    if (low >= from && high <= to)
        return tree[pos].sum + c * (high-low+1);
    ll mid = (low + high) / 2;
    ll p1 = query(low,mid,from,to,2*pos,c+tree[pos].prop);
    ll p2 = query(mid+1,high,from,to,2*pos+1,c+tree[pos].prop);
    return p1 + p2;
}

void update(ll low,ll high,ll from,ll to,ll val,ll pos)
{
    if(from > high || to < low)
        return;
    if(low >= from && high <= to)
    {
        tree[pos].sum += ((high - low + 1)*val);
        tree[pos].prop += val;
        return;
    }
    ll mid = (low + high)/2;
    update(low,mid,from,to,val,2*pos);
    update(mid+1,high,from,to,val,2*pos+1);
    tree[pos].sum = tree[2*pos].sum + tree[2*pos+1].sum + (high-low+1)*tree[pos].prop;
}

int main()
{
    ll n,q,b,t,a,w,c;
    scanf("%lld",&t);
    for(ll tc=1; tc<=t; tc++)
    {
        scanf("%lld %lld",&n,&q);

       // for(int i=1; i<=n; i++)
          //  scanf("%d",&arr[i]);
        //init(1,n,1);
        //printf("Case %d:\n",tc);
        while(q--)
        {
            scanf("%lld",&w);
            if(w==1)
            {
                scanf("%lld %lld",&a,&b);
                printf("%lld\n",query(1,n,a,b,1));
            }
            else if(w==0)
            {
                scanf("%lld %lld %lld",&a,&b,&c);
                update(1,n,a,b,c,1);
            }
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
