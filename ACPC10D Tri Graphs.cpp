#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
#define vi vector<int>
#define vll vector<ll>
const ll MAX = 9999999;
#define MOD 10000000007

ll a[111111][3];

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //FILE*f=freopen("input.txt","r",stdin);
    //FILE*o=freopen("output.txt","w",stdout);
    int n,tc=1;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++)
                cin>>a[i][j];
        a[1][0]+=a[0][1];
        a[0][2]+=a[0][1];
        a[1][1]+=min(min(a[1][0],a[0][1]),a[0][2]);
        a[1][2]+=min(min(a[1][1],a[0][1]),a[0][2]);
        for(int i=2;i<n;i++)
        {
            a[i][0]+=min(a[i-1][0],a[i-1][1]);
            a[i][1]+=min(min(min(a[i-1][0],a[i-1][1]),a[i][0]),a[i-1][2]);
            a[i][2]+=min(min(a[i-1][1],a[i-1][2]),a[i][1]);
        }
        cout<<tc++<<". "<<a[n-1][1]<<endl;
    }
    //fclose(f);
    //fclose(o);

    return 0;
}
