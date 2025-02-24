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
    int a,b;
    cin >> a >> b;
    double x = (2.*a - b) / 3.;
    double y = (2.*b - a) / 3.;
    string res = (x>=0. && y>=0. && floor(x)==x && floor(y)==y)?"YES":"NO";
    cout <<  res << endl;
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