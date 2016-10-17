//sifat shishir
//14-01-04-036
//aust cse
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define E 0.0001
#define MAX 99999

int prime[MAX];
int vis[MAX];
void sieve()
{
    for(int i=2;i<=MAX;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i+i;j<=MAX;j+=i)
                prime[j]=1;
        }
    }
}
struct pri
{
    char a[5];
    int cost;
};
int change(char x[])
{
    return (x[0]-'0')*1000+(x[1]-'0')*100+(x[2]-'0')*10+(x[3]-'0');
}
char cp[5];
int bfs(char a[],char b[])
{

    queue<pri>q;
    pri p;
    strcpy(p.a,a);
    p.cost=0;
    q.push(p);
    int s=change(a);
    vis[s]=1;
    int m=0;
    while(q.size()!=0)
    {
        p =q.front();
        q.pop();
        strcpy(cp,p.a);
        int v=p.cost;
        if(!strcmp(cp,b))
            return v;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<=9;j++)
            {
                if(i==0 && j==0)
                    continue;
                else
                    cp[i]=j+48;

                int x = change(cp);

                //cout<<x<<endl;
                if(!prime[x] && !vis[x])
                {
                    vis[x]=1;
                    pri next;
                    strcpy(next.a,cp);
                    next.cost=v+1;
                    q.push(next);
                    strcpy(cp,p.a);
                }
                else
                    strcpy(cp,p.a);
            }
        }
    }
}

int main()
{
    char a[5],b[5],c[20];
    sieve();
    int t;
    cin>>t;
    getchar();
    char ch;
    while(t--)
    {
        scanf("%s %s",&a,&b);

        cout<<bfs(a,b)<<endl;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
