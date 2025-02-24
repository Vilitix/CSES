#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{ 
    ll t;
    cin >> t;
    for(ll n =1;n<=t;n++){
    ll res = n*n*(n*n-1)/2;
    res-= (n-2)*4*(n-1);
    cout << res << endl;
    }

    
} 

int main()
{
    fastio();
    solve();

    return 0;
}