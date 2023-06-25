// Bismillah hir-rahman nir-raheem
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
#define   _rasbaris_  ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
// cout << "Case "<<q<<": ";
using namespace std;
const ll MAX = 1e6;
const ll MOD = 1e9+7;

// 4 direction
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


#define BASE 29

ll H[MAX];
ll po[MAX];

void GenPreHash(string &s)
{

    H[0] = s[0];
    for(int i=1; i<= s.size() ; i++)
    {
        H[i] = ((  H[i-1] * BASE  ) + s[i] ) % MOD;
    }
    po[0] = 1;
    for(int i=1; i<= s.size() ; i++)
    {
        po[i] = ( po[i-1] * BASE  ) % MOD;
    }

}


ll GenHash ( string &s) // gens hash to compare PreHash
{

    ll h = 0 ;
    for( auto &i:s)
    {

        h = ( h *BASE ) + (i) ;
        h = h % MOD ;


    }
    return h;
}



ll GetHash ( ll l, ll r) // fetches hash of B wrt A's size
{

    if(l==0) return H[r];
    return ( H[r] - ( H[l-1] * po[r-l+1]%MOD)+MOD)%MOD;
}




int main()
{
    //  _rasbaris_

    ll sz ;
    while(cin>>sz)
    {
        string a, b ;
        cin >> a >> b ;
        GenPreHash(b);
        ll fhash = GenHash(a);
        vector<ll>ar;
        for(int i = 0 ; i + a.size()<= b.size(); i++)
        {

            if( GetHash( i, i +  a.size()-1) == fhash )
            {
                ar.pb(i);
            }
        }
        if(ar.empty())cout<<'\n';
        else if(!ar.empty())for(auto i:ar)cout<<i<<'\n';
    }
    return 0;
}



