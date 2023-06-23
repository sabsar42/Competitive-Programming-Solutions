#include<bits/stdc++.h>
#include <tuple>
using namespace std;
#define   ll          long long
#define   pb          push_back
#define   ff          first
#define   ss          second
#define   tc()        ll t; cin>>t; while(t--)
#define   endll       "\n"
#define   debug(x)    cout << " >> " << #x << " : " << x << endl
#define   yes         cout <<"YES\n"
#define   no          cout << "NO\n"
#define   PI          3.141592653589793238
#define   all(v)      (v).begin(),(v).end()
#define   _rasbaris()  ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
// cout << "Case "<<q<<": ";
using namespace std;
const ll M = 1e5;

// 4 direction
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ll tree[M*4];
ll lazy[M*4];
ll v[M];

void build(ll node, ll bg, ll en)
{

    if(bg == en)
    {
        tree[node] = v[bg];
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (bg+en)/2;
    build(left, bg, mid);
    build(right, mid+1, en);
    tree[node] = tree[left] + tree[right];

}


ll query(ll node, ll bg, ll en, ll i, ll j)
{
    if( i>en || j<bg )
    {
        return 0;
    }
    //update remaining
    if(lazy[node]!=0)
    {
        tree[node] += (en-bg+1)*lazy[node];

        if(bg!=en)
        {
            ll left = node*2;
            ll right = node*2+1;
            lazy[left] +=  lazy[node];
            lazy[right] +=  lazy[node];
        }
        lazy[node] =0 ;
    }


    if( i<=bg && j>=en )
    {
        return tree[node];
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (bg+en)/2;

    ll p1 = query(left, bg, mid, i, j);
    ll p2 = query(right, mid+1, en, i, j);

    return p1+p2;

}



void update(ll node, ll bg, ll en, ll i, ll j, ll newval)
{

    // remaining updates

    if(lazy[node]!=0)
    {
        tree[node] += (en-bg+1)*lazy[node];

        if(bg!=en)
        {
            ll left = node*2;
            ll right = node*2+1;
            lazy[left] +=  lazy[node];
            lazy[right] +=  lazy[node];
        }
        lazy[node] = 0 ;
    }


    if(bg>j || i>en)
    {
        return;
    }

    if(bg>=i && en<=j)
    {

        tree[node] += (en-bg+1)*newval;
        if(bg!=en)
        {

            ll left = node*2;
            ll right = node*2+1;
            lazy[left] +=  newval;
            lazy[right] +=  newval;

        }
        return;
    }

    ll left = node*2;
    ll right = node*2+1;
    ll mid = (bg+en)/2;

    update(left, bg, mid, i,j, newval);
    update(right, mid+1, en, i,j, newval);
    tree[node] = tree[left] + tree[right];
}
int main()
{

    _rasbaris()
    ll q=1;
    tc()
    {
        ll n ;
        ll que;
        cin >> n ;
        cin >>  que ;
        for(int i=1; i<=n; i++)v[i]=0;


        memset(lazy,0,sizeof(lazy));

        build(1,1,n);

        cout << "Case "<<q++<<": \n";
        while(que--)
        {
            ll num ;
            cin >> num ;
            if(num == 0)
            {
                ll x,y,v;
                cin >> x >> y >> v ;
                update(1,1,n,x+1,y+1,v);
            }
            else if (num == 1)
            {
                ll x, y ;
                cin >> x >> y ;
                cout << query(1,1,n,x+1,y+1) << endl;

            }


        }
    }
    return 0;
}

