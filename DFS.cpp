// Bismillah hir-rahman nir-raheem
// Shakib Absar - (_rasbaris)

#include<bits/stdc++.h>
#include <tuple>
using namespace std;
#define   ll          long long
#define   ld          long double
#define   pb          push_back
#define   ff          first
#define   ss          second
#define   tc()        ll t; cin>>t; while(t--)
#define   endl        '\n'
#define   debug(x)    cout << " >> " << #x << " : " << x << endl
#define   yes         printf("Yes\n")
#define   no          printf("No\n")
#define   PI          acos(-1.0)
#define   Case(csNo)  cout <<"Case "<<csNo++<<": ";
#define   all(v)      (v).begin(),(v).end()
#define   print(v)    for(auto &i:v)cout<<i<<' ';
#define   _rasbaris_  ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
// cout << "Case "<<q<<": ";
using namespace std;
const ll M = 1e5+7;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
ll N;
vector<ll> adj[M];
vector<bool> vis(M);
vector<ll> dis(M);
ll cnt;
void dfs(ll node)
{
    vis[node] = true;
    ll ok = 1;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            ok = 0;
            dfs(i);
        }

    }

    if(ok)cnt++;
}
int main()
{
    tc()
    {

        memset(adj,0,sizeof(adj));
        cnt = 0;
        ll n,m ;
        cin >> n ;
        m = n-1;

        while(m--)
        {
            ll a,b ;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        ll ans = 0;

        for (ll i=0; i<=n; i++)
        {
            if(adj[i].size()==1)ans++;
        }
        cout <<(ans+1)/2 << endl;

        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = false;
        }
    }

    return 0;
}
