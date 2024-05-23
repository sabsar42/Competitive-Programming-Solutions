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
const ll M = 1e9;

// 4 direction
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main()
{
    _rasbaris_
    //   tc()
    {
        int ar[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };

        // Transpose the matrix
        for (int i = 0; i < 3; ++i)
        {
            for (int j = i; j < 3; ++j)
            {
                swap(ar[i][j], ar[j][i]);
            }
        }


        // swap Left Index with Right Index
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                swap(ar[i][j], ar[i][3-j-1]);
                break;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << "[ "<<ar[i][j] << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}


