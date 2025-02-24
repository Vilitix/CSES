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
    ll x,y;
    cin >> y >> x;
    x--,y--;
    if (x>y){
    if (x%2==0){
        ll res = x*(x+2) +1 - y;
        cout << res << endl;
        return;
    }
    else{
        ll res = (x-1)*(x+1)+2 +y;
        cout << res << endl;
        return;
    }
    }
    else{
        if (y%2==1){
        ll res = y*(y+2) +1 - x;
        cout << res << endl;
        return;
    }
    else{
        ll res = (y-1)*(y+1)+2 +x;
        cout << res << endl;
        return;
    }
}
}
int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}