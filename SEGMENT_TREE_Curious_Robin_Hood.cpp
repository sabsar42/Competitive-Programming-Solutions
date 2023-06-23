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
vector<ll>tree(M*4);

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
    else if( i<=bg && j>=en )
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



void update(ll node, ll bg, ll en, ll i, ll newval,ll num)
{

    if( i>en || i<bg )
    {
        return ;
    }
    if( i<=bg && i>=en )
    {
        if (num == 1)
        {
            tree[node]=0;
        }
        else
        {
            tree[node]+=newval;
        }
        return;
    }
    ll left = node*2;
    ll right = node*2+1;
    ll mid = (bg+en)/2;

    update(left, bg, mid, i, newval,num);
    update(right, mid+1, en, i, newval,num);
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
        cin >> que ;
        for(int i=1 ; i<=n ; i++) cin >>v[i];
        build(1,1,n);
        cout << "Case "<<q++<<": \n";
        while(que--)
        {
            ll num ;
            cin >> num ;


            if(num==1)
            {
                ll ind;
                cin >> ind ;
                cout << query(1,1,n,ind+1,ind+1) <<endl;
                update(1,1,n,ind+1,0,num);
            }
            else if(num==2)
            {
                ll ind;
                ll val ;
                cin >> ind ;
                cin >> val ;
                update(1,1,n,ind+1,val,num);
                // cout << query(0,0,n-1,ind,ind) <<endl;
            }
            else if(num==3)
            {
                ll start ;
                ll ded ;
                cin >> start ;
                cin >> ded ;
                cout << query(1,1,n,start+1,ded+1) << endl;
            }



        }


    }
    return 0;
}
