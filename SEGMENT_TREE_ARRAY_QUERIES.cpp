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

vector<ll>v(M);
vector<ll>tree(M*3);

void build(ll node, ll bg, ll en)
{

    if(bg == en)
    {
        tree[node] = v[bg];
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (bg+en)/2;
    build(left, bg, mid);
    build(right, mid+1, en);
    tree[node] = tree[left] + tree[right];
     debug();

}


ll query(ll node, ll bg, ll en, ll i, ll j)
{

    if( i>en || j<bg )
    {
        return 0;
    }
    if( i<=bg && j>=en )
    {
        return tree[node];
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (bg+en)/2;
    ll p1 = query(left, bg, mid, i, j);
    ll p2 = query(left, mid+1, en, i, j);

    return p1+p2;

}



int main()
{

    tc()
    {

        ll n ;
        cin >> n ;

        build(1,1,n);
      //  ll s = query(1,1,n,1,n);
        cout << query(1,1,n,1,n) << endl;


    }
    return 0;
}
