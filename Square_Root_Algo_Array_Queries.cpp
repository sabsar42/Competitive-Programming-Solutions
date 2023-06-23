
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



int main()
{
    _rasbaris()
    ll q = 1 ;

    tc()
    {
        ll n, que ;
        cin >> n >> que;
        vector<ll>v(n);
        for(int i=0; i<n; i++)cin>>v[i];
        ll sq = 1+(sqrt(n));
        vector<ll>mn(sq,INT_MAX);
        for(int i=0; i<n; i++)
        {

            mn[i/sq]=(min( mn[i/sq],v[i]));

        }

        cout << "Case "<<q++<<":\n";
        while(que--)
        {
            ll f,l ;
            cin >> f >> l ;
            f=f-1;
            l=l-1;
            ll m = INT_MAX;
            for(int i=f; i<=l; )
            {
                if(i+sq-1<=l && (i%sq)==0)
                {
                    m = min(m, mn[i/sq]);
                    i=i+sq;
                }
                else
                {
                    m = min(m, v[i]);
                    i++;
                }

            }
            cout<<m<<endl;
        }

    }
    return 0;
}

